#ifndef __ROOM_H__
#define __ROOM_H__

#include "vector"
#include "../../../library/json.hpp"
#include "../../Model/Room.hpp"
#include "../../Model/User.hpp"
#include "type.h"
#include "route.h"

using json = nlohmann::json;

typedef struct
{
    std::string code = REQUEST_GET_RESOURCE;
    json header;
    std::string url = RequestRoomListRouter;
    std::string params;
    
    json toJson() {
        return json{
            {"code", code},
            {"url", url},
            {"header", header },
            {"params", params}
        };

    }
} RequestListRoom;

typedef struct 
{
    std::vector<Room> rooms;
    json toJson() {
        json result;
        for (Room& room : rooms)
        {
            result["rooms"].push_back(room.toJson());
        }
        return result;
    }
} ResponseListRoomBody;

typedef struct
{
    std::string code = RESPONSE_GET_RESOURCE;
    std::string header;
    std::string url = ResponseRoomListRouter;
    ResponseListRoomBody body;
    
    json toJson() {
        return json{
            {"code", code},
            {"url", url},
            {"header", header },
            {"body", body.toJson()}
        };

    }
} ResponseListRoom;

typedef struct
{
    std::string code = REQUEST_GET_RESOURCE;
    json header;
    std::string url = RequestRoomDetailRouter;
    int param;

    json toJson() {
        return json{
            {"code", code},
            {"url", url},
            {"header", header },
            {"param", param}
        };

    }
} ResquestDetailRoom;

typedef struct 
{
    Room room;
    bool is_owner;
    std::vector<User> usersReady;

    json toJson() {
        json result;
        for (User& user : usersReady)
        {
            result["usersReady"].push_back(user.toJson());
        }
        result["room"] = room.toJson();
        result["is_owner"] = is_owner;
        return result;
    };
} ResponseDetailRoomBody;

typedef struct
{
    std::string code = RESPONSE_GET_RESOURCE;
    json header;
    std::string url = ResponseRoomDetailRouter;
    ResponseDetailRoomBody body;

    json toJson() {
        return json{
            {"code", code},
            {"url", url},
            {"header", header },
            {"body", body.toJson()}
        };
    }
} ResponseDetailRoom;

typedef struct
{
    std::string code = REQUEST_GET_RESOURCE;
    json header;
    std::string url = RequestReadyRoomRouter;
    int param;

    json toJson() {
        return json{
            {"code", code},
            {"url", url},
            {"header", header },
            {"param", param}
        };
    }
} RequestReadyRoom;

typedef struct
{
    std::vector<User> usersReady;

    json toJson() {
        json result;
        for (User& user : usersReady)
        {
            result["usersReady"].push_back(user.toJson());
        }
        return result;
    }
}ResponseReadyRoomBody;

typedef struct
{
    std::string code = RESPONSE_GET_RESOURCE;
    json header;
    std::string status;
    std::string url = ResponseReadyRoomRouter;
    ResponseReadyRoomBody body;

    json toJson() {
        return json{
            {"code", code},
            {"status", status},
            {"url", url},
            {"header", header },
            {"body", body.toJson()}
        };
    }
} ResponseReadyRoom;

typedef struct
{
    std::string code = REQUEST_DELETE_RESOURCE;
    json header;
    std::string url = RequestUnReadyRoomRouter;
    int param;

    json toJson() {
        return json{
            {"code", code},
            {"url", url},
            {"header", header },
            {"param", param}
        };
    }
} RequestUnReadyRoom;

typedef struct
{
    std::string code = RESPONSE_DELETE_RESOURCE;
    json header;
    std::string status;
    std::string url = ResponseUnReadyRoomRouter;
    ResponseReadyRoomBody body;

    json toJson() {
        return json{
            {"code", code},
            {"status", status},
            {"url", url},
            {"header", header },
            {"body", body.toJson()}
        };
    }
} ResponseUnReadyRoom;

#endif