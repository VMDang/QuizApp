#include "Option.hpp"
#include <iostream>
#include <fstream>
#include <iomanip>
#include <vector>
#include "../../library/json.hpp"

using json = nlohmann::json;

Option::Option() = default;

// Constructor without auto-increase id
Option::Option(int id, int question_id, const std::string &content, bool is_right)
    : id(id), question_id(question_id), content(content), is_right(is_right) {}

// Constructor with auto-increase id
Option::Option(int question_id, const std::string &content, bool is_right)
    : question_id(question_id), content(content), is_right(is_right)
{
    std::vector<Option> options = getAll();
    // Auto-increment id based on the last option's id in the "../../database/options.json" file
    if (!options.empty())
    {
        id = options.back().id + 1;
    }
    else
    {
        id = 1; // If no one exist, start from id 1
    }
}

// Constructor with default value of is_right
Option::Option(int question_id, const std::string &content)
    : question_id(question_id), content(content) {
        std::vector<Option> options = getAll();
        // Auto-increment id based on the last option's id in the "../../database/options.json" file
        if (!options.empty()) {
            id = options.back().id + 1;
        } else {
            id = 1; // If no one exist, start from id 1
        }

        is_right = false;
    }

std::vector<Option> Option::getAll()
{
    std::vector<Option> options;

    // Load existing options from JSON
    json jsonData;
    std::ifstream inputFile("../../database/options.json");
    inputFile >> jsonData;
    inputFile.close();

    for (const auto &optionData : jsonData["options"])
    {
        Option option;
        option.id = optionData["id"];
        option.question_id = optionData["question_id"];
        option.content = optionData["content"];
        option.is_right = optionData["correct"];

        options.push_back(option);
    }

    return options;
}

Option Option::findById(int optionId)
{
    // Load existing options from JSON
    json jsonData;
    std::ifstream inputFile("../../database/options.json");
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
            option.is_right = optionData["correct"];

            return option;
        }
    }

    // Return an empty option if not found
    return Option();
}

Option Option::edit(Option &updatedOption)
{
    // Load existing options from JSON
    json jsonData;
    std::ifstream inputFile("../../database/options.json");
    inputFile >> jsonData;
    inputFile.close();

    // Find and update the option with matching id
    for (auto &optionData : jsonData["options"])
    {
        if (optionData["id"] == updatedOption.id)
        {
            optionData["question_id"] = updatedOption.question_id;
            optionData["content"] = updatedOption.content;
            optionData["correct"] = updatedOption.is_right;
            break;
        }
    }

    // Write the updated data back to JSON file
    std::ofstream outputFile("../../database/options.json");
    outputFile << std::setw(4) << jsonData;
    outputFile.close();

    return updatedOption;
}

Option Option::create(const Option &newOption)
{
    // Load existing options from JSON
    json jsonData;
    std::ifstream inputFile("../../database/options.json");
    inputFile >> jsonData;
    inputFile.close();

    // Add the new option to the JSON data
    json newOptionJson;
    newOptionJson["id"] = newOption.id;
    newOptionJson["question_id"] = newOption.question_id;
    newOptionJson["content"] = newOption.content;
    newOptionJson["correct"] = newOption.is_right;

    jsonData["options"].push_back(newOptionJson);

    // Write the updated data back to JSON file
    std::ofstream outputFile("../../database/options.json");
    outputFile << std::setw(4) << jsonData;
    outputFile.close();

    return newOption;
}

void Option::Delete(const Option &optionToDelete)
{
    // Load existing options from JSON
    json jsonData;
    std::ifstream inputFile("../../database/options.json");
    inputFile >> jsonData;
    inputFile.close();

    // Find and remove the option with matching id
    auto &optionsArray = jsonData["options"];
    optionsArray.erase(std::remove_if(optionsArray.begin(), optionsArray.end(),
                                      [&optionToDelete](const auto &optionData)
                                      {
                                          return optionData["id"] == optionToDelete.id;
                                      }),
                       optionsArray.end());

    // Write the updated data back to JSON file
    std::ofstream outputFile("../../database/options.json");
    outputFile << std::setw(4) << jsonData;
    outputFile.close();
}
