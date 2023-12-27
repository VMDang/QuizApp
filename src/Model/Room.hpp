#ifndef ROOM_HPP
#define ROOM_HPP

#include <iostream>
#include <fstream>
#include <vector>
#include "../../library/json.hpp"
#pragma once
using json = nlohmann::json;
extern std::string source;
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

    Room();

    // Constructor without auto-increase id
    Room(int id, const std::string &name, int capacity, const std::string &type,
         const std::string &start_time, const std::string &close_time,
         int status, int time_limit);

    // Constructor with auto-increase id
    Room(const std::string &name, int capacity, const std::string &type,
         const std::string &start_time, const std::string &close_time,
         int status, int time_limit);

    static std::vector<Room> getAll();
    static Room findById(int id);
    static Room edit(Room &updatedRoom);
    static Room create(const Room &newRoom);
    static void Delete(const Room &roomToDelete);
};

#endif // ROOM_HPP
