#include "practicehandler.h"
#include "../app/comunicate/client.h"
#include "../app/request/practice.h"
#include "../../library/json.hpp"
#include "clientmanager.h"

PracticeHandler::PracticeHandler() {}

void PracticeHandler::requestCreatePractice()
{
    RequestCreatePractice request;
    request.header = ClientManager::authUser;
    request.body.category_id = 2;
    request.body.name = "Room Practice";
    request.body.time_limit = 2;

    sendToServer(request.toJson().dump().c_str());
}

json PracticeHandler::responseCreatePractice()
{
    char buff[BUFF_SIZE];
    recvFromServer(buff);

    return json::parse(buff);
}

void PracticeHandler::requestStartPractice(int room_id)
{
    RequestStartPractice request;
    request.header = ClientManager::authUser;
    request.param = room_id;

    sendToServer(request.toJson().dump().c_str());
}

json PracticeHandler::responseStartPractice()
{
    char buff[BUFF_SIZE];
    recvFromServer(buff);

    return json::parse(buff);
}
