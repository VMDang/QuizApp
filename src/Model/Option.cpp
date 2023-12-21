#include <iostream>
#include <fstream>
#include <iomanip>
#include <vector>
#include "../../library/json.hpp"

using json = nlohmann::json;
std::string source = "../../database/options.json";
class Option
{
public:
    int id;
    int question_id;
    std::string content;
    bool is_right;

    Option() = default;

    Option(int id, int question_id, const std::string &content, bool is_right)
        : id(id), question_id(question_id), content(content), is_right(is_right) {}

    static std::vector<Option> getAll();
    static Option findById(int optionId);
    static void edit(const Option &updatedOption);
    static void create(const Option &newOption);
    static void Delete(const Option &optionToDelete);
};

std::vector<Option> Option::getAll()
{
    std::vector<Option> options;

    // Load existing options from JSON
    json jsonData;
    std::ifstream inputFile(source);
    inputFile >> jsonData;
    inputFile.close();

    for (const auto &optionData : jsonData["options"])
    {
        Option option;
        option.id = optionData["id"];
        option.question_id = optionData["question_id"];
        option.content = optionData["content"];
        option.is_right = optionData["is_right"];

        options.push_back(option);
    }

    return options;
}

Option Option::findById(int optionId)
{
    // Load existing options from JSON
    json jsonData;
    std::ifstream inputFile(source);
    inputFile >> jsonData;
    inputFile.close();

    for (const auto &optionData : jsonData["options"])
    {
        if (optionData["id"] == optionId)
        {
            Option option;
            option.id = optionData["id"];
            option.question_id = optionData["question_id"];
            option.content = optionData["content"];
            option.is_right = optionData["is_right"];

            return option;
        }
    }

    // Return an empty option if not found
    return Option();
}

void Option::edit(const Option &updatedOption)
{
    // Load existing options from JSON
    json jsonData;
    std::ifstream inputFile(source);
    inputFile >> jsonData;
    inputFile.close();

    // Find and update the option with matching id
    for (auto &optionData : jsonData["options"])
    {
        if (optionData["id"] == updatedOption.id)
        {
            optionData["question_id"] = updatedOption.question_id;
            optionData["content"] = updatedOption.content;
            optionData["is_right"] = updatedOption.is_right;
            break;
        }
    }

    // Write the updated data back to JSON file
    std::ofstream outputFile(source);
    outputFile << std::setw(4) << jsonData;
    outputFile.close();
}

void Option::create(const Option &newOption)
{
    // Load existing options from JSON
    json jsonData;
    std::ifstream inputFile(source);
    inputFile >> jsonData;
    inputFile.close();

    // Add the new option to the JSON data
    json newOptionJson;
    newOptionJson["id"] = newOption.id;
    newOptionJson["question_id"] = newOption.question_id;
    newOptionJson["content"] = newOption.content;
    newOptionJson["is_right"] = newOption.is_right;

    jsonData["options"].push_back(newOptionJson);

    // Write the updated data back to JSON file
    std::ofstream outputFile(source);
    outputFile << std::setw(4) << jsonData;
    outputFile.close();
}

void Option::Delete(const Option &optionToDelete)
{
    // Load existing options from JSON
    json jsonData;
    std::ifstream inputFile(source);
    inputFile >> jsonData;
    inputFile.close();

    // Find and remove the option with matching id
    auto &optionsArray = jsonData["options"];
    optionsArray.erase(std::remove_if(optionsArray.begin(), optionsArray.end(),
                                      [&optionToDelete](const auto &optionData)
                                      {
                                          return optionData["id"] == optionToDelete.id &&
                                                 optionData["question_id"] == optionToDelete.question_id &&
                                                 optionData["content"] == optionToDelete.content &&
                                                 optionData["is_right"] == optionToDelete.is_right;
                                      }),
                       optionsArray.end());

    // Write the updated data back to JSON file
    std::ofstream outputFile(source);
    outputFile << std::setw(4) << jsonData;
    outputFile.close();
}

int main()
{
    // Testing getAll function
    std::cout << "getAll() Function Test:\n";
    std::vector<Option> allOptions = Option::getAll();
    for (const auto &option : allOptions)
    {
        std::cout << "Option ID: " << option.id << ", Content: " << option.content << "\n";
    }
    std::cout << "\n";

    // Testing findById function
    std::cout << "findById() Function Test:\n";
    int optionIdToFind = 2;
    Option foundOption = Option::findById(optionIdToFind);
    if (foundOption.id != 0)
    {
        std::cout << "Found Option - ID: " << foundOption.id << ", Content: " << foundOption.content << "\n";
    }
    else
    {
        std::cout << "Option with ID " << optionIdToFind << " not found.\n";
    }
    std::cout << "\n";

    // Testing edit function
    std::cout << "edit() Function Test:\n";
    Option optionToEdit = foundOption; // Use the option found in the previous test
    optionToEdit.content = "Updated Option Content";
    optionToEdit.is_right = true;
    Option::edit(optionToEdit);
    std::cout << "Option after editing:\n";
    Option editedOption = Option::findById(optionIdToFind);
    std::cout << "Edited Option - ID: " << editedOption.id << ", Content: " << editedOption.content << "\n";
    std::cout << "\n";

    // Testing create function
    std::cout << "create() Function Test:\n";
    Option newOption(4, 1, "New Option", false);
    Option::create(newOption);
    std::cout << "Newly Created Option:\n";
    Option createdOption = Option::findById(4);
    std::cout << "Created Option - ID: " << createdOption.id << ", Content: " << createdOption.content << "\n";
    std::cout << "\n";

    // Testing deleteOption function
    std::cout << "deleteOption() Function Test:\n";
    Option optionToDelete = createdOption; // Use the option created in the previous test
    Option::Delete(optionToDelete);
    std::cout << "Option after deleting:\n";
    Option deletedOption = Option::findById(4);
    if (deletedOption.id != 0)
    {
        std::cout << "Option still found after deletion. Something went wrong!\n";
    }
    else
    {
        std::cout << "Option successfully deleted.\n";
    }

    return 0;
}
