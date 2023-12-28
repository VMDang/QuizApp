#ifndef QUESTION_HPP
#define QUESTION_HPP

#include <iostream>
#include <fstream>
#include <vector>
#include "../../library/json.hpp"
#pragma once
using json = nlohmann::json;
extern std::string source;
class Question
{
public:
    int id;
    std::string title;
    int level;
    int category_id;

    Question();

    // Constructor without auto-increase id
    Question(int id, const std::string &title, int level, int category_id);

    // Constructor with auto-increase id
    Question(const std::string &title, int level, int category_id);

    static std::vector<Question> getAll();
    static Question findById(int id);
    static Question edit(const Question &updatedQuestion);
    static Question create(const Question &newQuestion);
    static void Delete(const Question &questionToDelete);
};

#endif // QUESTION_HPP
