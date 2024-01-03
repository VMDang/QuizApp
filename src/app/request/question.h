#ifndef __QUESTION_H__
#define __QUESTION_H__

#include "vector"
#include "../../../library/json.hpp"
#include "../../Model/Question.hpp"
#include "../../Model/Option.hpp"
#include "type.h"
#include "route.h"

typedef struct 
{
    Question question;
    std::vector<Option> options;

    json toJson() {
        json result;
        for (Option &o : options)
        {
            result["options"].push_back(o.toJson());
        }
        result["question"] = question.toJson();
        return result;
    }
}QuestionContent;

typedef struct
{
    int category_id;
    std::vector<int> question_config;

    json toJson(){
        json q_config = question_config;
        return json{
            {"category_id", category_id},
            {"question_config", q_config},
        };
    }
}QuestionsExam;

#endif