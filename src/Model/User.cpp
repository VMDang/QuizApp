#include <iostream>
#include <fstream>
#include <vector>
#include "../../library/json.hpp"

using json = nlohmann::json;
std::string source = "../../database/users.json";
class User
{
public:
    int id;
    std::string name;
    std::string email;
    std::string password;
    int status;
    int role;

    // Constructor
    User(int i, std::string n, std::string e, std::string p, int s, int r)
        : id(std::move(i)), name(std::move(n)), email(std::move(e)), password(std::move(p)), status(s), role(r) {}

    // Static function to get all users from the file
    static std::vector<User> getAll() {
        std::vector<User> users;
        std::ifstream file(source);

        if (file.is_open()) {
            json j;
            file >> j;
            file.close();

            for (const auto& user_json : j["users"]) {
                users.emplace_back(
                    user_json["id"],
                    user_json["name"],
                    user_json["email"],
                    user_json["password"],
                    user_json["status"],
                    user_json["role"]
                );
            }
        }

        return users;
    }

    // Static function to find user by ID
    static User findById(int id) {
        std::ifstream file(source);
        User user(0, "", "", "", 0, 0);

        if (file.is_open()) {
            json j;
            file >> j;
            file.close();

            for (const auto& user_json : j["users"]) {
                if (user_json["id"] == id) {
                    user = User(
                        user_json["id"],
                        user_json["name"],
                        user_json["email"],
                        user_json["password"],
                        user_json["status"],
                        user_json["role"]
                    );
                    break;
                }
            }
        }

        return user;
    }

    // Function to edit user without bcrypt password hashing
    void edit(const User &newUser)
    {
        // Load existing users from JSON
        json jsonData;
        std::ifstream inputFile(source);
        inputFile >> jsonData;
        inputFile.close();

        // Find and update the user with matching id
        for (auto &user : jsonData["users"])
        {
            if (user["id"] == id)
            {
                user["name"] = newUser.name;
                user["email"] = newUser.email;
                user["password"] = newUser.password;
                user["status"] = newUser.status;
                user["role"] = newUser.role;
                break;
            }
        }

        // Write the updated data back to JSON file
        std::ofstream outputFile(source);
        outputFile << std::setw(4) << jsonData;
        outputFile.close();
    }

    // Function to create a new user without bcrypt password hashing
    void create(const User &newUser)
    {
        // Load existing users from JSON
        json jsonData;
        std::ifstream inputFile(source);
        inputFile >> jsonData;
        inputFile.close();

        // Add the new user to the JSON data
        json newUserJson;
        newUserJson["id"] = newUser.id;
        newUserJson["name"] = newUser.name;
        newUserJson["email"] = newUser.email;
        newUserJson["password"] = newUser.password;
        newUserJson["status"] = newUser.status;
        newUserJson["role"] = newUser.role;

        jsonData["users"].push_back(newUserJson);

        // Write the updated data back to JSON file
        std::ofstream outputFile(source);
        outputFile << std::setw(4) << jsonData;
        outputFile.close();
    }

    void Delete(const User &userToDelete)
    {
        // Load existing users from JSON
        json jsonData;
        std::ifstream inputFile(source);
        inputFile >> jsonData;
        inputFile.close();

        // Find and remove the user with matching all fields, if need only matching id then remove others
        auto &usersArray = jsonData["users"];
        usersArray.erase(std::remove_if(usersArray.begin(), usersArray.end(),
                                        [&userToDelete](const auto &user)
                                        {
                                            return user["id"] == userToDelete.id &&
                                                   user["name"] == userToDelete.name &&
                                                   user["email"] == userToDelete.email &&
                                                   user["password"] == userToDelete.password &&
                                                   user["status"] == userToDelete.status &&
                                                   user["role"] == userToDelete.role;
                                        }),
                         usersArray.end());

        // Write the updated data back to JSON file
        std::ofstream outputFile(source);
        outputFile << std::setw(4) << jsonData;
        outputFile.close();
    }
};

int main() {

    User retrievedUser = User::findById(1);
    std::cout << retrievedUser.email << ", " << retrievedUser.name << std::endl;
    
    User newUser(3, "John Harking", "john-harking@example.com", "password123", 1, 2);
    newUser.create(newUser);

    User existingUser(3, "John Harking", "john-harking@example.com", "newpassword456", 0, 1);
    existingUser.edit(existingUser);

    existingUser.Delete(existingUser);
    return 0;
}