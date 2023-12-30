#include "UserRoom.hpp"

#include <vector>
#include <fstream>

#include "../../library/json.hpp"

#define USER_ROOM_JSON "../../../database/user_room.json"

using json = nlohmann::json;

std::vector<UserRoom> relationsUserRoom()
{
    std::ifstream user_room_json(USER_ROOM_JSON);
    json userRoomData;
    user_room_json >> userRoomData;
    user_room_json.close();

    std::vector<UserRoom> userRooms;

    for (auto& item : userRoomData["user_room"])
    {
        UserRoom userRoom;
        userRoom.user_id = item["user_id"];
        userRoom.room_id = item["room_id"];
        userRoom.is_owner = item["is_owner"];
        userRooms.push_back(userRoom);
    }
    return userRooms;
}