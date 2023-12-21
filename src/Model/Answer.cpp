#include <iostream>
#include <fstream>
#include <iomanip>
#include <vector>
#include "../../library/json.hpp"

using json = nlohmann::json;
std::string source = "../../database/answers.json";
class Answer
{
public:
    int id;
    int user_id;
    int room_id;
    int option_id;
    int result;

    Answer() = default;

    Answer(int id, int user_id, int room_id, int option_id, int result)
        : id(id), user_id(user_id), room_id(room_id), option_id(option_id), result(result) {}

    static std::vector<Answer> getAll();
    static Answer findById(int answerId);
    static void edit(const Answer &updatedAnswer);
    static void create(const Answer &newAnswer);
    static void deleteAnswer(const Answer &answerToDelete);
};

std::vector<Answer> Answer::getAll()
{
    std::vector<Answer> answers;

    // Load existing answers from JSON
    json jsonData;
    std::ifstream inputFile(source);
    inputFile >> jsonData;
    inputFile.close();

    for (const auto &answerData : jsonData["answers"])
    {
        Answer answer;
        answer.id = answerData["id"];
        answer.user_id = answerData["user_id"];
        answer.room_id = answerData["room_id"];
        answer.option_id = answerData["option_id"];
        answer.result = answerData["result"];

        answers.push_back(answer);
    }

    return answers;
}

Answer Answer::findById(int answerId)
{
    // Load existing answers from JSON
    json jsonData;
    std::ifstream inputFile(source);
    inputFile >> jsonData;
    inputFile.close();

    for (const auto &answerData : jsonData["answers"])
    {
        if (answerData["id"] == answerId)
        {
            Answer answer;
            answer.id = answerData["id"];
            answer.user_id = answerData["user_id"];
            answer.room_id = answerData["room_id"];
            answer.option_id = answerData["option_id"];
            answer.result = answerData["result"];

            return answer;
        }
    }

    // Return an empty answer if not found
    return Answer();
}

void Answer::edit(const Answer &updatedAnswer)
{
    // Load existing answers from JSON
    json jsonData;
    std::ifstream inputFile(source);
    inputFile >> jsonData;
    inputFile.close();

    // Find and update the answer with matching id
    for (auto &answerData : jsonData["answers"])
    {
        if (answerData["id"] == updatedAnswer.id)
        {
            answerData["user_id"] = updatedAnswer.user_id;
            answerData["room_id"] = updatedAnswer.room_id;
            answerData["option_id"] = updatedAnswer.option_id;
            answerData["result"] = updatedAnswer.result;
            break;
        }
    }

    // Write the updated data back to JSON file
    std::ofstream outputFile(source);
    outputFile << std::setw(4) << jsonData;
    outputFile.close();
}

void Answer::create(const Answer &newAnswer)
{
    // Load existing answers from JSON
    json jsonData;
    std::ifstream inputFile(source);
    inputFile >> jsonData;
    inputFile.close();

    // Add the new answer to the JSON data
    json newAnswerJson;
    newAnswerJson["id"] = newAnswer.id;
    newAnswerJson["user_id"] = newAnswer.user_id;
    newAnswerJson["room_id"] = newAnswer.room_id;
    newAnswerJson["option_id"] = newAnswer.option_id;
    newAnswerJson["result"] = newAnswer.result;

    jsonData["answers"].push_back(newAnswerJson);

    // Write the updated data back to JSON file
    std::ofstream outputFile(source);
    outputFile << std::setw(4) << jsonData;
    outputFile.close();
}

void Answer::deleteAnswer(const Answer &answerToDelete)
{
    // Load existing answers from JSON
    json jsonData;
    std::ifstream inputFile(source);
    inputFile >> jsonData;
    inputFile.close();

    // Find and remove the answer with matching id
    auto &answersArray = jsonData["answers"];
    answersArray.erase(std::remove_if(answersArray.begin(), answersArray.end(),
                                      [&answerToDelete](const auto &answerData)
                                      {
                                          return answerData["id"] == answerToDelete.id &&
                                                 answerData["user_id"] == answerToDelete.user_id &&
                                                 answerData["room_id"] == answerToDelete.room_id &&
                                                 answerData["option_id"] == answerToDelete.option_id &&
                                                 answerData["result"] == answerToDelete.result;
                                      }),
                       answersArray.end());

    // Write the updated data back to JSON file
    std::ofstream outputFile(source);
    outputFile << std::setw(4) << jsonData;
    outputFile.close();
}

int main()
{
    // Testing getAll function
    std::cout << "getAll() Function Test:\n";
    std::vector<Answer> allAnswers = Answer::getAll();
    for (const auto &answer : allAnswers)
    {
        std::cout << "Answer ID: " << answer.id << ", Result: " << answer.result << "\n";
    }
    std::cout << "\n";

    // Testing findById function
    std::cout << "findById() Function Test:\n";
    int answerIdToFind = 2;
    Answer foundAnswer = Answer::findById(answerIdToFind);
    if (foundAnswer.id != 0)
    {
        std::cout << "Found Answer - ID: " << foundAnswer.id << ", Result: " << foundAnswer.result << "\n";
    }
    else
    {
        std::cout << "Answer with ID " << answerIdToFind << " not found.\n";
    }
    std::cout << "\n";

    // Testing edit function
    std::cout << "edit() Function Test:\n";
    Answer answerToEdit = foundAnswer; // Use the answer found in the previous test
    answerToEdit.result = 1;
    Answer::edit(answerToEdit);
    std::cout << "Answer after editing:\n";
    Answer editedAnswer = Answer::findById(answerIdToFind);
    std::cout << "Edited Answer - ID: " << editedAnswer.id << ", Result: " << editedAnswer.result << "\n";
    std::cout << "\n";

    // Testing create function
    std::cout << "create() Function Test:\n";
    Answer newAnswer(4, 1, 2, 2, 0);
    Answer::create(newAnswer);
    std::cout << "Newly Created Answer:\n";
    Answer createdAnswer = Answer::findById(4);
    std::cout << "Created Answer - ID: " << createdAnswer.id << ", Result: " << createdAnswer.result << "\n";
    std::cout << "\n";

    // Testing deleteAnswer function
    std::cout << "deleteAnswer() Function Test:\n";
    Answer answerToDelete = createdAnswer; // Use the answer created in the previous test
    Answer::deleteAnswer(answerToDelete);
    std::cout << "Answer after deleting:\n";
    Answer deletedAnswer = Answer::findById(4);
    if (deletedAnswer.id != 0)
    {
        std::cout << "Answer still found after deletion. Something went wrong!\n";
    }
    else
    {
        std::cout << "Answer successfully deleted.\n";
    }

    return 0;
}
