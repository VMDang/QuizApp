#ifndef __LOGIN_H__
#define __LOGIN_H__

#include "../../../library/json.hpp"
#include "type.h"
#include "route.h"
#include "../../Model/User.hpp"

using json = nlohmann::json;

typedef struct
{
    std::string email;
    std::string password;

    json toJson() {
        return json{
            {"email", email},
            {"password", password }
        };

    }

    void toStruct(const json &j) {
        j.at("email").get_to(email);
        j.at("password").get_to(password);
    }
} LoginBody;


typedef struct
{
    std::string code = REQUEST_CREATE_RESOURCE;
    std::string header;
    std::string url = LoginRouter;
    LoginBody body;
    
    json toJson() {
        return json{
            {"code", code},
            {"url", url},
            {"header", header },
            {"body", body.toJson()}
        };

    }
} RequestLogin;

typedef struct
{
    std::string code = RESPONSE_CREATE_RESOURCE;
    std::string status;
    std::string header;
    User user;

    json toJson() {
        return json{
            {"code", code},
            {"status", code},
            {"header", header },
            {"body", user.toJson()}
        };

    }
} ReponseLogin;

#endif
