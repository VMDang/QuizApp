#include <iostream>
#include <vector>
#include <algorithm>

#include "ResultController.hpp"
#include "ServerManager.hpp"
#include "../comunicate/server.h"
#include "../request/result.h"
#include "../../Model/Answer.hpp"
#include "../../Model/User.hpp"
#include "../../Model/Room.hpp"
#include "../../Model/Question.hpp"
#include "../../Model/RoomQuestion.hpp"
#include "../../Model/UserRoom.hpp"

ResultController::ResultController() = default;

void ResultController::redriect(json request, int clientfd)
{
    std::string url = request["url"];

    if (url == RequestRoomResultRouter)
    {
        room(request, clientfd);
    }
    else if (url == RequestHistoryResultRouter)
    {
        history(request, clientfd);
    }
}

void ResultController::room(json request, int clientfd)
{
    int room_id = request["param"];
    int auth_id = request["header"]["id"];

    std::vector<RoomQuestion> room_questions = relationsRoomQuestion();
    std::vector<UserRoom> user_rooms = relationsUserRoom();

    room_questions.erase(std::remove_if(room_questions.begin(), room_questions.end(),
                                        [room_id](const RoomQuestion &roomQuestion)
                                        {
                                            return roomQuestion.room_id != room_id;
                                        }),
                         room_questions.end());

    int max_score = 0;
    for (auto &r_q : room_questions)
    {
        Question q = Question::findById(r_q.question_id);
        max_score += q.level;
    }

    user_rooms.erase(std::remove_if(user_rooms.begin(), user_rooms.end(),
                                    [room_id, auth_id](const UserRoom &userRoom)
                                    {
                                        return !(userRoom.room_id == room_id && !userRoom.is_owner);
                                    }),
                     user_rooms.end());
    std::vector<Answer> answers = Answer::getAll();

    std::vector<RoomResult> roomResults;
    for (auto &u_r : user_rooms)
    {
        RoomResult r_r;
        User user = User::findById(u_r.user_id);
        r_r.username = user.name;
        int u_id = user.id;

        std::vector<Answer> filtered_answers;

        std::copy_if(answers.begin(), answers.end(), std::back_inserter(filtered_answers),
                     [room_id, u_id](const Answer &answer)
                     {
                         return answer.room_id == room_id && answer.user_id == u_id;
                     });

        int score = 0;
        int number_correct = 0;
        for (auto &a : filtered_answers)
        {
            if (a.result > 0)
            {
                number_correct++;
                score += a.result;
            }
        }
        r_r.score = score;
        r_r.number_question_correct = number_correct;

        roomResults.push_back(r_r);
    }

    auto compareByScore = [](const RoomResult &a, const RoomResult &b)
    {
        return a.score > b.score;
    };

    std::sort(roomResults.begin(), roomResults.end(), compareByScore);

    ResponseRoomResult response;
    response.status = SUCCESS;
    response.body.max_score = max_score;
    response.body.roomResults = roomResults;
    response.body.total_question = room_questions.size();

    sendToClient(clientfd, response.toJson().dump().c_str());
}

void ResultController::history(json request, int clientfd)
{
    int auth_id = request["header"]["id"];

    std::vector<RoomQuestion> room_questions = relationsRoomQuestion();
    std::vector<UserRoom> user_rooms = relationsUserRoom();
    std::vector<Answer> answers = Answer::getAll();

    user_rooms.erase(std::remove_if(user_rooms.begin(), user_rooms.end(),
                                    [auth_id](const UserRoom &u_r)
                                    {
                                        return u_r.user_id != auth_id;
                                    }),
                     user_rooms.end());

    std::vector<HistoryResult> historyResults;
    for (auto &u_r : user_rooms)
    {
        HistoryResult hr;
        Room room = Room::findById(u_r.room_id);
        int room_id = room.id;

        std::vector<Answer> filtered_answers;
        std::copy_if(answers.begin(), answers.end(), std::back_inserter(filtered_answers),
                     [room_id, auth_id](const Answer &answer)
                     {
                         return answer.room_id == room_id && answer.user_id == auth_id;
                     });

        int score = 0;
        int number_correct = 0;
        for (auto &a : filtered_answers)
        {
            if (a.result > 0)
            {
                number_correct++;
                score += a.result;
            }
        }

        std::vector<RoomQuestion> filteredRoomQuestions;
        std::copy_if(room_questions.begin(), room_questions.end(), std::back_inserter(filteredRoomQuestions),
                     [room_id](const RoomQuestion &rq)
                     {
                         return rq.room_id == room_id;
                     });

        int max_score = 0;
        for (auto &r_q : filteredRoomQuestions)
        {
            Question q = Question::findById(r_q.question_id);
            max_score += q.level;
        }

        hr.exam_name = room.name;
        hr.type = room.type;
        hr.start_time = room.start_time;
        hr.score = score;
        hr.number_question_correct = number_correct;
        hr.max_score = max_score;
        hr.number_question = filteredRoomQuestions.size();
        historyResults.push_back(hr);
    }
    std::sort(historyResults.begin(), historyResults.end(), 
                    [](const HistoryResult& a, const HistoryResult& b){
                        return a.start_time > b.start_time;
                    });

    ResponseHistoryResult response;
    response.body.historyResults = historyResults;
    response.status = SUCCESS;

    sendToClient(clientfd, response.toJson().dump().c_str());
}
