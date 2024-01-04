#ifndef REGISTRATION_HPP
#define REGISTRATION_HPP

#include "../../../library/json.hpp"

using json = nlohmann::json;

class RegistrationController 
{
public:
    RegistrationController();

    void redirect(json request, int clientfd);
    void signup(json request, int clientfd);
};
 
#endif