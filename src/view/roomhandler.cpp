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

void RoomHandler::requestDetailRoom(int id)
{
    ResquestDetailRoom request;
    request.header = ClientManager::authUser;
    request.param = id;
    sendToServer(request.toJson().dump().c_str());
}

json RoomHandler::responseDetailRoom()
{
    char buff[BUFF_SIZE];
    recvFromServer(buff);

    return json::parse(buff);
}
