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

    void requestDetailRoom(int room_id);
    json responseDetailRoom();

    void requestReadyRoom(int room_id);
    json responseReadyRoom();

    void requestUnReadyRoom(int room_id);
    json responseUnReadyRoom();

    void requestStartRoom(int room_id);
    json responseStartRoom();
};

#endif // ROOMHANDLER_H
