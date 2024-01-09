#include "userhandler.h"

#include "../app/comunicate/client.h"
#include "../app/request/user.h"
#include "clientmanager.h"

UserHandler::UserHandler() {}

void UserHandler::requestListUser()
{
    RequestListUser request;
    request.header = ClientManager::authUser;

    sendToServer(request.toJson().dump().c_str());
}

json UserHandler::responseListUser()
{
    char buff[BUFF_SIZE];
    recvFromServer(buff);

    return json::parse(buff);
}

void UserHandler::requestActiveUser(int user_id, bool active)
{
    RequestActiveUser request;
    request.header = ClientManager::authUser;
    request.param = user_id;
    request.active = active;

    sendToServer(request.toJson().dump().c_str());
}

json UserHandler::responseActiveUser()
{
    char buff[BUFF_SIZE];
    recvFromServer(buff);

    return json::parse(buff);
}

void UserHandler::requestDeleteUser(int user_id)
{
    RequestListUser request;
    request.header = ClientManager::authUser;
    request.param = user_id;

    sendToServer(request.toJson().dump().c_str());
}

json UserHandler::responseDeleteUser()
{
    char buff[BUFF_SIZE];
    recvFromServer(buff);

    return json::parse(buff);
}
