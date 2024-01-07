#ifndef __QUESTIONCONTROLLER_HPP__
#define __QUESTIONCONTROLLER_HPP__

#include "../../../library/json.hpp"

using json = nlohmann::json;

class QuestionController
{
public:
    QuestionController();

    void redirect(json request, int clientfd);
    void get(json request, int clientfd);
    void create(json request, int clientfd);
    void update(json request, int clientfd);
    void Delete(json request, int clientfd);
};

#endif