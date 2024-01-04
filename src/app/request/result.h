#ifndef __RESULT_H__
#define __CATEGORY_H__

#include "vector"
#include "type.h"
#include "route.h"
#include "../../../library/json.hpp"
#include "../../Model/Category.hpp"

using json = nlohmann::json;

typedef struct
{
    std::string code = REQUEST_GET_RESOURCE;
    json header;
    std::string url = RequestRoomResultRouter;
    int param;

    json toJson()
    {
        return json{
            {"code", code},
            {"url", url},
            {"header", header},
            {"param", param}};
    }
} RequestRoomResult;

typedef struct 
{
    std::string username;
    int score;
    int number_question_correct;

    json toJson() {
        return json{
            {"username", username},
            {"score", score},
            {"number_question_correct", number_question_correct},
        };
    }
}RoomResult;

typedef struct 
{
    std::vector<RoomResult> roomResults;
    int max_score;
    int total_question;

    json toJson()
    {
        json result;
        for (RoomResult &r : roomResults)
        {
            result["roomResults"].push_back(r.toJson());
        }
        result["max_score"] = max_score;
        result["total_question"] = total_question;
        return result;
    }
} ResponseRoomResultBody;

typedef struct
{
    std::string code = RESPONSE_GET_RESOURCE;
    json header;
    std::string status;
    std::string url = ResponseRoomResultRouter;
    ResponseRoomResultBody body;

    json toJson()
    {
        return json{
            {"code", code},
            {"url", url},
            {"status", status},
            {"header", header},
            {"body", body.toJson()}
        };
    }
} ResponseRoomResult;

typedef struct
{
    std::string code = REQUEST_GET_RESOURCE;
    json header;
    std::string url = RequestHistoryResultRouter;
    int param;

    json toJson()
    {
        return json{
            {"code", code},
            {"url", url},
            {"header", header},
            {"param", param}};
    }
} RequestHistoryResult;

typedef struct 
{
    std::string exam_name;
    std::string type;
    std::string start_time;
    int score;
    int number_question_correct;
    int max_score;
    int number_question;

    json toJson() {
        return json{
            {"exam_name", exam_name},
            {"type", type},
            {"start_time", start_time},
            {"score", score},
            {"number_question_correct", number_question_correct},
            {"max_score", max_score},
            {"number_question", number_question}
        };
    }
}HistoryResult;

typedef struct
{
    std::vector<HistoryResult> historyResults;

    json toJson() {
        json result;
        for (HistoryResult &r : historyResults)
        {
            result["historyResults"].push_back(r.toJson());
        }
        return result;
    }
}ResponseHistoryResultBody;


typedef struct
{
    std::string code = RESPONSE_GET_RESOURCE;
    json header;
    std::string status;
    std::string url = ResponseHistoryResultRouter;
    ResponseHistoryResultBody body;

    json toJson()
    {
        return json{
            {"code", code},
            {"url", url},
            {"status", status},
            {"header", header},
            {"body", body.toJson()}
        };
    }
} ResponseHistoryResult;

#endif