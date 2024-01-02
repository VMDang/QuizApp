#include "roomhandler.h"
#include "../app/comunicate/client.h"
#include "../app/request/room.h"
#include "../../library/json.hpp"
#include "clientmanager.h"

using json = nlohmann::json;

RoomHandler::RoomHandler() {}

void RoomHandler::requestListRoom()
{
    RequestListRoom requestListRoom;
    requestListRoom.header = ClientManager::authUser;
    sendToServer(requestListRoom.toJson().dump().c_str());
}

json RoomHandler::responseListRoom()
{
    char buff[BUFF_SIZE];
    recvFromServer(buff);

    return json::parse(buff);
}

void RoomHandler::requestJoinRoom(int room_id, bool is_private, std::string password)
{
    RequestJoinRoom request;
    request.header = ClientManager::authUser;
    request.param = room_id;
    request.body.is_private = is_private;
    request.body.password = password;
    sendToServer(request.toJson().dump().c_str());
}

json RoomHandler::responseJoinRoom()
{
    char buff[BUFF_SIZE];
    recvFromServer(buff);

    return json::parse(buff);
}

void RoomHandler::requestReadyRoom(int room_id)
{
    RequestReadyRoom request;
    request.header = ClientManager::authUser;
    request.param = room_id;
    sendToServer(request.toJson().dump().c_str());
}
json RoomHandler::responseReadyRoom()

{
    char buff[BUFF_SIZE];
    recvFromServer(buff);

    return json::parse(buff);
}

void RoomHandler::requestUnReadyRoom(int room_id)
{
    RequestUnReadyRoom request;
    request.header = ClientManager::authUser;
    request.param = room_id;
    sendToServer(request.toJson().dump().c_str());
}

json RoomHandler::responseUnReadyRoom()
{
    char buff[BUFF_SIZE];
    recvFromServer(buff);

    return json::parse(buff);
}

void RoomHandler::requestStartRoom(int room_id)
{
    RequestStartRoom request;
    request.header = ClientManager::authUser;
    request.body.room_id = room_id;
    sendToServer(request.toJson().dump().c_str());
}

json RoomHandler::responseStartRoom()
{
    char buff[BUFF_SIZE];
    recvFromServer(buff);

    return json::parse(buff);
}
