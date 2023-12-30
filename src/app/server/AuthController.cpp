#include "AuthController.hpp"

#include <vector>
#include <pthread.h>
#include <algorithm>

#include "../request/login.h"
#include "../request/logout.h"
#include "../comunicate/server.h"
#include "../../Model/User.hpp"
 
std::vector<User> loggedUsers;
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

AuthController::AuthController() = default;

void AuthController::login(json request, int clientfd)
{
    std::string code = request["code"];
    std::string url = request["url"];
    std::string header = request["header"];
    std::string email = request["body"]["email"];
    std::string password = request["body"]["password"];

    User user = User::findByEmail(email);
    ResponseLogin responseLogin;

    if (user.email.empty())
    {
        responseLogin.status = FAILURE;
        responseLogin.body.message = "Account not exists.";
    }
    else
    {
        if (user.status == 0)
        {
            responseLogin.status = FAILURE;
            responseLogin.body.message = "Account has been locked.";
        }
        else if (password != user.password)
        {
            responseLogin.status = FAILURE;
            responseLogin.body.message = "Password incorrect.";
        }
        else if (password == user.password)
        {
            pthread_mutex_lock(&mutex);
            auto it = std::find_if(loggedUsers.begin(), loggedUsers.end(),
                                   [&user](const User &userIter)
                                   { return userIter.id == user.id; });
            if (it != loggedUsers.end())
            {
                responseLogin.status = FAILURE;
                responseLogin.body.message = "Account is logged in another location.";
            }
            else
            {
                responseLogin.status = SUCCESS;
                responseLogin.body.user = user;
                loggedUsers.push_back(user);
            }
            pthread_mutex_unlock(&mutex);
        }
    }

    sendToClient(clientfd, responseLogin.toJson().dump().c_str());
}

void AuthController::logout(json request, int clientfd)
{
    int userId = request["header"]["id"];

    pthread_mutex_lock(&mutex);
    loggedUsers.erase(
        std::remove_if(loggedUsers.begin(), loggedUsers.end(),
                       [userId](const User &user)
                       { return user.id == userId; }),
        loggedUsers.end());
    pthread_mutex_unlock(&mutex);

    ResponseLogout responseLogout;
    responseLogout.status = SUCCESS;
    responseLogout.message = "Loggout success!";

    sendToClient(clientfd, responseLogout.toJson().dump().c_str());
}