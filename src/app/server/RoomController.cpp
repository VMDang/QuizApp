#include <vector>

#include "RoomController.hpp"
#include "../comunicate/server.h"
#include "../request/room.h"
#include "../../Model/Room.hpp"
#include "../../Model/UserRoom.hpp"

RoomController::RoomController() = default;

void RoomController::redriect(json request, int clientfd)
{
    std::string url = request["url"];

    if (url == RequestRoomListRouter)
    {
        list(request, clientfd);
    } else if (url == RequestRoomDetailRouter)
    {
        detail(request, clientfd);
    }
    
}

void RoomController::list(json request, int clientfd)
{
    std::vector<Room> rooms = Room::getAll();

    std::vector<Room> roomsLobby;

    rooms.erase(std::remove_if(rooms.begin(), rooms.end(),
                               [](Room& room) { return room.status != "Lobby" || room.type != "exam"; }),
                rooms.end());

    ResponseListRoomBody body;
    body.rooms = rooms;
    ResponseListRoom response;
    response.body = body;
    sendToClient(clientfd, response.toJson().dump().c_str());
}

void RoomController::detail(json request, int clientfd)
{
    std::cout << request.dump() << std::endl;
    int auth_id = request["header"]["id"];
    int room_id = request["param"];

    std::cout << auth_id << " -- " << room_id;

    std::vector<UserRoom> User_Room = relationsUserRoom();

    bool checkOwner = false;

    checkOwner = std::any_of(User_Room.begin(), User_Room.end(),
                             [auth_id, room_id](const UserRoom& item) {
                                 return item.user_id == auth_id &&
                                        item.room_id == room_id &&
                                        item.is_owner;
                             });
    ResponseDetailRoom response;
    response.body.is_owner = checkOwner;
    response.body.room = Room::findById(room_id);
    
    sendToClient(clientfd, response.toJson().dump().c_str());
}