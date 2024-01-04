#include <iostream>
#include <vector>

#include "ServerManager.hpp"
#include "../comunicate/server.h"
#include "../../Model/User.hpp"
#include "RegistrationController.hpp"
#include "../request/type.h"
#include "../request/route.h"
#include "../request/registration.h"

RegistrationController::RegistrationController() = default;

void RegistrationController::redirect(json request, int clientfd) {
    std::string url = request["url"];
    if (url == RequestRegistrationRouter)
    {
        signup(request, clientfd);
    }
    
}

void RegistrationController::signup(json request, int clientfd) {
    std::string name = request["body"]["name"];
    std::string email = request["body"]["email"];
    std::string password = request["body"]["password"];

    User newUser = User(name, email, password);
    User::create(newUser);

    ResponseRegistration response;
    response.status = SUCCESS;
    response.body = newUser;

    sendToClient(clientfd, response.toJson().dump().c_str());
}