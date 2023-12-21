#include <iostream>
#include <fstream>
#include <iomanip>
#include <vector>
#include "../../library/json.hpp"

using json = nlohmann::json;
std::string source = "../../database/questions.json";
class Question
{
public:
    int id;
    std::string title;
    int level;
    int category_id;

    Question() = default;

    Question(int id, const std::string &title, int level, int category_id)
        : id(id), title(title), level(level), category_id(category_id) {}

    static std::vector<Question> getAll();
    static Question findById(int questionId);
    static void edit(const Question &updatedQuestion);
    static void create(const Question &newQuestion);
    static void deleteQuestion(const Question &questionToDelete);
};

std::vector<Question> Question::getAll()
{
    std::vector<Question> questions;

    // Load existing questions from JSON
    json jsonData;
    std::ifstream inputFile(source);
    inputFile >> jsonData;
    inputFile.close();

    for (const auto &questionData : jsonData["questions"])
    {
        Question question;
        question.id = questionData["id"];
        question.title = questionData["title"];
        question.level = questionData["level"];
        question.category_id = questionData["category_id"];

        questions.push_back(question);
    }

    return questions;
}

Question Question::findById(int questionId)
{
    // Load existing questions from JSON
    json jsonData;
    std::ifstream inputFile(source);
    inputFile >> jsonData;
    inputFile.close();

    for (const auto &questionData : jsonData["questions"])
    {
        if (questionData["id"] == questionId)
        {
            Question question;
            question.id = questionData["id"];
            question.title = questionData["title"];
            question.level = questionData["level"];
            question.category_id = questionData["category_id"];

            return question;
        }
    }

    // Return an empty question if not found
    return Question();
}

void Question::edit(const Question &updatedQuestion)
{
    // Load existing questions from JSON
    json jsonData;
    std::ifstream inputFile(source);
    inputFile >> jsonData;
    inputFile.close();

    // Find and update the question with matching id
    for (auto &questionData : jsonData["questions"])
    {
        if (questionData["id"] == updatedQuestion.id)
        {
            questionData["title"] = updatedQuestion.title;
            questionData["level"] = updatedQuestion.level;
            questionData["category_id"] = updatedQuestion.category_id;
            break;
        }
    }

    // Write the updated data back to JSON file
    std::ofstream outputFile(source);
    outputFile << std::setw(4) << jsonData;
    outputFile.close();
}

void Question::create(const Question &newQuestion)
{
    // Load existing questions from JSON
    json jsonData;
    std::ifstream inputFile(source);
    inputFile >> jsonData;
    inputFile.close();

    // Add the new question to the JSON data
    json newQuestionJson;
    newQuestionJson["id"] = newQuestion.id;
    newQuestionJson["title"] = newQuestion.title;
    newQuestionJson["level"] = newQuestion.level;
    newQuestionJson["category_id"] = newQuestion.category_id;

    jsonData["questions"].push_back(newQuestionJson);

    // Write the updated data back to JSON file
    std::ofstream outputFile(source);
    outputFile << std::setw(4) << jsonData;
    outputFile.close();
}

void Question::deleteQuestion(const Question &questionToDelete)
{
    // Load existing questions from JSON
    json jsonData;
    std::ifstream inputFile(source);
    inputFile >> jsonData;
    inputFile.close();

    // Find and remove the question with matching id
    auto &questionsArray = jsonData["questions"];
    questionsArray.erase(std::remove_if(questionsArray.begin(), questionsArray.end(),
                                        [&questionToDelete](const auto &questionData)
                                        {
                                            return questionData["id"] == questionToDelete.id &&
                                                   questionData["title"] == questionToDelete.title &&
                                                   questionData["level"] == questionToDelete.level &&
                                                   questionData["category_id"] == questionToDelete.category_id;
                                        }),
                         questionsArray.end());

    // Write the updated data back to JSON file
    std::ofstream outputFile(source);
    outputFile << std::setw(4) << jsonData;
    outputFile.close();
}

int main()
{
    // Testing getAll function
    std::cout << "getAll() Function Test:\n";
    std::vector<Question> allQuestions = Question::getAll();
    for (const auto &question : allQuestions)
    {
        std::cout << "Question ID: " << question.id << ", Title: " << question.title << "\n";
    }
    std::cout << "\n";

    // Testing findById function
    std::cout << "findById() Function Test:\n";
    int questionIdToFind = 2;
    Question foundQuestion = Question::findById(questionIdToFind);
    if (foundQuestion.id != 0)
    {
        std::cout << "Found Question - ID: " << foundQuestion.id << ", Title: " << foundQuestion.title << "\n";
    }
    else
    {
        std::cout << "Question with ID " << questionIdToFind << " not found.\n";
    }
    std::cout << "\n";

    // Testing edit function
    std::cout << "edit() Function Test:\n";
    Question questionToEdit = foundQuestion; // Use the question found in the previous test
    questionToEdit.title = "Updated Question Title";
    questionToEdit.level = 2;
    Question::edit(questionToEdit);
    std::cout << "Question after editing:\n";
    Question editedQuestion = Question::findById(questionIdToFind);
    std::cout << "Edited Question - ID: " << editedQuestion.id << ", Title: " << editedQuestion.title << "\n";
    std::cout << "\n";

    // Testing create function
    std::cout << "create() Function Test:\n";
    Question newQuestion(4, "New Question", 3, 1);
    Question::create(newQuestion);
    std::cout << "Newly Created Question:\n";
    Question createdQuestion = Question::findById(4);
    std::cout << "Created Question - ID: " << createdQuestion.id << ", Title: " << createdQuestion.title << "\n";
    std::cout << "\n";

    // Testing deleteQuestion function
    std::cout << "deleteQuestion() Function Test:\n";
    Question questionToDelete = createdQuestion; // Use the question created in the previous test
    Question::deleteQuestion(questionToDelete);
    std::cout << "Question after deleting:\n";
    Question deletedQuestion = Question::findById(4);
    if (deletedQuestion.id != 0)
    {
        std::cout << "Question still found after deletion. Something went wrong!\n";
    }
    else
    {
        std::cout << "Question successfully deleted.\n";
    }

    return 0;
}
