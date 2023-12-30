#ifndef ROOMCONTROLLER_HPP
#define ROOMCONTROLLER_HPP

#include "../../../library/json.hpp"

using json = nlohmann::json;

class RoomController
{
public:
    RoomController();

    void redriect(json request, int clientfd);
    void list(json request, int clientfd);
    void detail(json request, int clientfd);
};

#endif