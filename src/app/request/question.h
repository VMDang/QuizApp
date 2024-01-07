#ifndef __QUESTION_H__
#define __QUESTION_H__

#include <vector>
#include <utility>
#include "../../../library/json.hpp"
#include "../../Model/Question.hpp"
#include "../../Model/Option.hpp"
#include "type.h"
#include "route.h"

typedef struct
{
    Question question;
    std::vector<Option> options;

    json toJson()
    {
        json result;
        for (Option &o : options)
        {
            result["options"].push_back(o.toJson());
        }
        result["question"] = question.toJson();
        return result;
    }
} QuestionContent;

typedef struct
{
    int category_id;
    std::vector<int> question_config;

    json toJson()
    {
        json q_config = question_config;
        return json{
            {"category_id", category_id},
            {"question_config", q_config}
        };
    }
} QuestionsExam;

typedef struct
{
    std::string title;
    int category_id;
    int level;
    std::vector<std::pair<std::string, bool>> options;

    json toJson()
    {
        return json{
            {"title", title},
            {"category_id", category_id},
            {"level", level},
            {"options", options}
        };
    }

} RequestCreateQuestionBody;

typedef struct
{
    std::string code = REQUEST_CREATE_RESOURCE;
    json header;
    std::string url = RequestCreateQuestionRouter;
    RequestCreateQuestionBody body;

    json toJson()
    {
        return json{
            {"code", code},
            {"url", url},
            {"header", header},
            {"body", body.toJson()}};
    }
} RequestCreateQuestion;

typedef struct
{
    std::string code = RESPONSE_CREATE_RESOURCE;
    json header;
    std::string status;
    std::string url = ResponseCreateQuestionRouter;
    Question body;

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
} ResponseCreateQuestion;

typedef struct {
    int question_id;
    std::string title;
    int category_id;
    int level;
    std::vector<std::pair<std::string, bool>> options;

    json toJson()
    {
        return json{
            {"question_id", question_id},
            {"title", title},
            {"category_id", category_id},
            {"level", level},
            {"options", options}
        };
    }
} RequestUpdateQuestionBody;

typedef struct {
    std::string code = REQUEST_CREATE_RESOURCE;
    json header;
    std::string url = RequestUpdateQuestionRouter;
    RequestUpdateQuestionBody body;

    json toJson() {
        return json {
            {"code", code},
            {"url", url},
            {"header", header},
            {"body", body.toJson()}
        };
    }
} RequestUpdateQuestion;


typedef struct {
    std::string code = RESPONSE_EDIT_RESOURCE;
    json header;
    std::string url;
    std::string status;
    std::string ResponseUpdateQuestionRouterr;
    Question body;

    json toJson()
    {
        return json {
            {"code", code},
            {"url", url},
            {"status", status},
            {"header", header},
            {"body", body.toJson()}
        };
    }
} ResponseUpdateQuestion;

typedef struct {
    std::string code = REQUEST_GET_RESOURCE;
    json header;
    std::string url = RequestGetQuestionRouter;
    int room_id;

    json toJson() {
        return json{
            {"code", code}, 
            {"header", header},
            {"url", url},
            {"room_id", room_id}
        };
    }
} RequesGetQuestion;


typedef struct 
{
    std::vector<QuestionContent> questions;

    json toJson()
    {
        json result;
        for (QuestionContent &q : questions)
        {
            result["questions"].push_back(q.toJson());
        }
        return result;
    }
}ResponseGetQuestionBody;


typedef struct {
    std::string code = RESPONSE_GET_RESOURCE;
    json header;
    std::string status;
    std::string url = ResponseGetQuestionRouter;
    ResponseGetQuestionBody body;

    json toJson(){
        return json{
            {"code", code},
            {"header", header},
            {"status", status},
            {"url", url},
            {"body", body.toJson()}
        };
    }
} ResponseGetQuestion;

typedef struct {
    std::string code = REQUEST_DELETE_RESOURCE;
    json header;
    std::string url = RequestDeleteQuestionRouter;
    int question_id;

    json toJson() {
        return json {
            {"code", code},
            {"header", header},
            {"url", url},
            {"question_id", question_id}
        };
    }
} RequestDeleteQuestion;

typedef struct{
    std::string message;

    json toJson() {
        return json{
            {"message", message},
        };
    }
}ResponseDeleteQuestionBody;
typedef struct {
    std::string code = RESPONSE_DELETE_RESOURCE;
    json header;
    std::string url = ResponseDeleteQuestionRouter;
    std::string status;
    ResponseDeleteQuestionBody body;

    json toJson(){
        return json {
            {"code", code},
            {"header", header},
            {"status", status},
            {"url", url},
            {"body", body.toJson()},
        };
    }

} ResponseDeleteQuestion;
#endif