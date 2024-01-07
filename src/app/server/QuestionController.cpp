#include <iostream>
#include <unordered_map>
#include <vector>
#include <iomanip>
#include <chrono>
#include <ctime>
#include <sstream>

#include "QuestionController.hpp"
#include "RoomController.hpp"
#include "../comunicate/server.h"
#include "../request/room.h"
#include "../../Model/Room.hpp"
#include "../../Model/User.hpp"
#include "../../Model/UserRoom.hpp"
#include "../../Model/RoomQuestion.hpp"
#include "../../Model/Option.hpp"
#include "ServerManager.hpp"

QuestionController::QuestionController() = default;

void QuestionController::redirect(json request, int clientfd) {
    std::string url = request["url"];
    if (url == RequestCreateRoomRouter)
    {
        create(request, clientfd);
    }
    else if (url == RequestGetQuestionRouter) {
        get(request, clientfd);
    }
    else if (url == RequestUpdateQuestionRouter)
    {
        update(request, clientfd);
    }
    else if (url == RequestDeleteQuestionRouter)
    {
        Delete(request, clientfd);
    }
}

void QuestionController::create(json request, int clientfd) {
    std::string title = request["body"]["title"];
    int category_id = request["body"]["category_id"];
    int level = request["body"]["level"];

    // create new with auto increase id and save to database
    Question newQues = Question(title, level, category_id);
    Question::create(newQues);
    
    for (const auto& o : request["body"]["options"])
    {
        std::string content = o[0];
        bool correct = o[1];
        Option option = Option(newQues.id, content, correct);
        Option::create(option);
    }
    ResponseCreateQuestion response;
    response.status = SUCCESS;
    response.body = newQues;

    sendToClient(clientfd, response.toJson().dump().c_str());
}

void QuestionController::get(json request, int clientfd) {
    int room_id = request["room_id"];

    std::vector<RoomQuestion> relationsRQ = relationsRoomQuestion();
    std::vector<QuestionContent> questionsExam;
    std::vector<Option> options = Option::getAll();

    relationsRQ.erase(std::remove_if(relationsRQ.begin(), relationsRQ.end(),
                                     [room_id](const RoomQuestion &r_q)
                                     {
                                         return r_q.room_id != room_id;
                                     }),
                      relationsRQ.end());

    for (RoomQuestion &rq : relationsRQ)
    {
        Question q = Question::findById(rq.question_id);
        int q_id = q.id;
        std::vector<Option> filteredOptions;
        std::copy_if(options.begin(), options.end(), std::back_inserter(filteredOptions),
                     [q_id](const Option &option)
                     {
                         return option.question_id == q_id;
                     });
        QuestionContent qc;
        qc.question = q;
        qc.options = filteredOptions;

        questionsExam.push_back(qc);
    }

    ResponseGetQuestion response;
    response.status = SUCCESS;
    response.body.questions = questionsExam;

    sendToClient(clientfd, response.toJson().dump().c_str());
}

void QuestionController::update(json request, int clientfd) {
    int question_id = request["body"]["question_id"];
    std::string title = request["body"]["title"];
    int category_id = request["body"]["category_id"];
    int level = request["body"]["level"];

    // create new with auto increase id and save to database
    Question ques = Question::findById(question_id);
    ques.category_id = category_id;
    ques.level = level;
    ques.title = title;
    Question::edit(ques);

    // Update option of question
    // .... 
    // Đoạn này em chưa biết update kiểu gì, bởi vì nếu mà trong
    // request chỉ có cặp content với correct thì update không 
    // đúng id của option. Nếu find option theo content thì
    // không ổn bởi nó đã bị thay đổi rồi
}

void QuestionController::Delete(json request, int clientfd) {
    int question_id = request["question_id"];
    Question ques = Question::findById(question_id);
    Question::Delete(ques);

    ResponseDeleteQuestion response;
    response.status = SUCCESS;
    response.body.message = "Delete question success!";

    sendToClient(clientfd, response.toJson().dump().c_str());
}