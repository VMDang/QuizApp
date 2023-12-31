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

    void requestDetailRoom(int id);
    json responseDetailRoom();

    void requestReadyRoom(int id);
    json responseReadyRoom();

    void requestUnReadyRoom(int id);
    json responseUnReadyRoom();
};

#endif // ROOMHANDLER_H
