#ifndef USERHANDLER_H
#define USERHANDLER_H

#include "../../library/json.hpp"

using json = nlohmann::json;

class UserHandler
{
public:
    UserHandler();

    void requestListUser();
    json responseListUser();

    void requestActiveUser(int user_id, bool active);
    json responseActiveUser();

    void requestDeleteUser(int user_id);
    json responseDeleteUser();
};

#endif // USERHANDLER_H
