#ifndef PRACTICEHANDLER_H
#define PRACTICEHANDLER_H

#include "../../library/json.hpp"

using json = nlohmann::json;

class PracticeHandler
{
public:
    PracticeHandler();

    void requestCreatePractice();
    json responseCreatePractice();

    void requestStartPractice(int room_id);
    json responseStartPractice();
};

#endif // PRACTICEHANDLER_H
