#ifndef ROOMHANDLER_H
#define ROOMHANDLER_H

#include "../../library/json.hpp"

using json = nlohmann::json;

class RoomHandler
{
public:
    RoomHandler();
    void requestListRoom();
    json responseListRoom();

    void requestJoinRoom(int room_id, bool is_private, std::string password);
    json responseJoinRoom();

    void requestReadyRoom(int room_id);
    json responseReadyRoom();

    void requestUnReadyRoom(int room_id);
    json responseUnReadyRoom();

    void requestStartRoom(int room_id);
    json responseStartRoom();
};

#endif // ROOMHANDLER_H
