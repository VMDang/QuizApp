#include "RoomQuestion.hpp"

#include <vector>
#include <fstream>

#include "../../library/json.hpp"

#define ROOM_QUESTION_JSON "../../../database/room_question.json"

using json = nlohmann::json;

std::vector<RoomQuestion> relationsRoomQuestion()
{
    std::ifstream room_question_json(ROOM_QUESTION_JSON);
    json roomQuestionData;
    room_question_json >> roomQuestionData;
    room_question_json.close();

    std::vector<RoomQuestion> roomQuestions;

    for (auto& item : roomQuestionData["room_question"])
    {
        RoomQuestion r_q;
        r_q.question_id = item["question_id"];
        r_q.room_id = item["room_id"];
        roomQuestions.push_back(r_q);
    }
    return roomQuestions;
}