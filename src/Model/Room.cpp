#include <iostream>
#include <fstream>
#include <vector>
#include "../../library/json.hpp"

using json = nlohmann::json;
std::string source = "../../database/rooms.json";

class Room
{
public:
    int id;
    std::string name;
    int capacity;
    std::string type;
    std::string start_time;
    std::string close_time;
    int status;
    int time_limit;

    Room() = default;

    Room(int id, const std::string &name, int capacity, const std::string &type,
         const std::string &start_time, const std::string &close_time,
         int status, int time_limit)
        : id(id), name(name), capacity(capacity), type(type),
          start_time(start_time), close_time(close_time),
          status(status), time_limit(time_limit) {}

    static std::vector<Room> getAll() {
        std::vector<Room> rooms;

        // Load existing rooms from JSON
        json jsonData;
        std::ifstream inputFile(source);
        inputFile >> jsonData;
        inputFile.close();

        for (const auto &roomData : jsonData["rooms"])
        {
            Room room;
            room.id = roomData["id"];
            room.name = roomData["name"];
            room.capacity = roomData["capacity"];
            room.type = roomData["type"];
            room.start_time = roomData["start_time"];
            room.close_time = roomData["close_time"];
            room.status = roomData["status"];
            room.time_limit = roomData["time_limit"];

            rooms.push_back(room);
        }

        return rooms;
    }

    static Room findById(int roomId)
    {
        // Load existing rooms from JSON
        json jsonData;
        std::ifstream inputFile(source);
        inputFile >> jsonData;
        inputFile.close();

        for (const auto &roomData : jsonData["rooms"])
        {
            if (roomData["id"] == roomId)
            {
                Room room;
                room.id = roomData["id"];
                room.name = roomData["name"];
                room.capacity = roomData["capacity"];
                room.type = roomData["type"];
                room.start_time = roomData["start_time"];
                room.close_time = roomData["close_time"];
                room.status = roomData["status"];
                room.time_limit = roomData["time_limit"];

                return room;
            }
        }

        // Return an empty room if not found
        return Room();
    }

    void edit(const Room &updatedRoom)
    {
        // Load existing rooms from JSON
        json jsonData;
        std::ifstream inputFile(source);
        inputFile >> jsonData;
        inputFile.close();

        // Find and update the room with matching id
        for (auto &roomData : jsonData["rooms"])
        {
            if (roomData["id"] == updatedRoom.id)
            {
                roomData["name"] = updatedRoom.name;
                roomData["capacity"] = updatedRoom.capacity;
                roomData["type"] = updatedRoom.type;
                roomData["start_time"] = updatedRoom.start_time;
                roomData["close_time"] = updatedRoom.close_time;
                roomData["status"] = updatedRoom.status;
                roomData["time_limit"] = updatedRoom.time_limit;
                break;
            }
        }

        // Write the updated data back to JSON file
        std::ofstream outputFile(source);
        outputFile << std::setw(4) << jsonData;
        outputFile.close();
    }

    void create(const Room &newRoom)
    {
        // Load existing rooms from JSON
        json jsonData;
        std::ifstream inputFile(source);
        inputFile >> jsonData;
        inputFile.close();

        // Add the new room to the JSON data
        json newRoomJson;
        newRoomJson["id"] = newRoom.id;
        newRoomJson["name"] = newRoom.name;
        newRoomJson["capacity"] = newRoom.capacity;
        newRoomJson["type"] = newRoom.type;
        newRoomJson["start_time"] = newRoom.start_time;
        newRoomJson["close_time"] = newRoom.close_time;
        newRoomJson["status"] = newRoom.status;
        newRoomJson["time_limit"] = newRoom.time_limit;

        jsonData["rooms"].push_back(newRoomJson);

        // Write the updated data back to JSON file
        std::ofstream outputFile(source);
        outputFile << std::setw(4) << jsonData;
        outputFile.close();
    }

    void Delete(const Room &roomToRemove)
    {
        // Load existing rooms from JSON
        json jsonData;
        std::ifstream inputFile(source);
        inputFile >> jsonData;
        inputFile.close();

        // Find and remove the room with matching id
        auto &roomsArray = jsonData["rooms"];
        roomsArray.erase(std::remove_if(roomsArray.begin(), roomsArray.end(),
                                        [&roomToRemove](const auto &roomData)
                                        {
                                            return roomData["id"] == roomToRemove.id &&
                                                   roomData["name"] == roomToRemove.name &&
                                                   roomData["capacity"] == roomToRemove.capacity &&
                                                   roomData["type"] == roomToRemove.type &&
                                                   roomData["start_time"] == roomToRemove.start_time &&
                                                   roomData["close_time"] == roomToRemove.close_time &&
                                                   roomData["status"] == roomToRemove.status &&
                                                   roomData["time_limit"] == roomToRemove.time_limit;
                                        }),
                         roomsArray.end());

        // Write the updated data back to JSON file
        std::ofstream outputFile(source);
        outputFile << std::setw(4) << jsonData;
        outputFile.close();
    }
};

int main()
{
    // Testing getAll function
    std::cout << "getAll() Function Test:\n";
    std::vector<Room> allRooms = Room::getAll();
    for (const auto &room : allRooms)
    {
        std::cout << "Room ID: " << room.id << ", Name: " << room.name << "\n";
    }
    std::cout << "\n";

    // Testing findById function
    std::cout << "findById() Function Test:\n";
    int roomIdToFind = 2;
    Room foundRoom = Room::findById(roomIdToFind);
    if (foundRoom.id != 0)
    {
        std::cout << "Found Room - ID: " << foundRoom.id << ", Name: " << foundRoom.name << "\n";
    }
    else
    {
        std::cout << "Room with ID " << roomIdToFind << " not found.\n";
    }
    std::cout << "\n";

    // Testing edit function
    std::cout << "edit() Function Test:\n";
    Room roomToEdit = foundRoom; // Use the room found in the previous test
    roomToEdit.name = "Updated Room B";
    roomToEdit.capacity = 25;
    roomToEdit.edit(roomToEdit);
    std::cout << "Room after editing:\n";
    Room editedRoom = Room::findById(roomIdToFind);
    std::cout << "Edited Room - ID: " << editedRoom.id << ", Name: " << editedRoom.name << "\n";
    std::cout << "\n";

    // Testing create function
    std::cout << "create() Function Test:\n";
    Room newRoom(4, "Room D", 18, "test", "2023-01-01T12:00:00", "2023-01-01T20:00:00", 1, 120);
    newRoom.create(newRoom);
    std::cout << "Newly Created Room:\n";
    Room createdRoom = Room::findById(4);
    std::cout << "Created Room - ID: " << createdRoom.id << ", Name: " << createdRoom.name << "\n";
    std::cout << "\n";

    // Testing Delete function
    std::cout << "Delete() Function Test:\n";
    Room roomToRemove = createdRoom; // Use the room created in the previous test
    roomToRemove.Delete(roomToRemove);
    std::cout << "Room after removing:\n";
    Room removedRoom = Room::findById(4);
    if (removedRoom.id != 0)
    {
        std::cout << "Room still found after removal. Something went wrong!\n";
    }
    else
    {
        std::cout << "Room successfully removed.\n";
    }

    return 0;
}
