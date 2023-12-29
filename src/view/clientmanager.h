#ifndef CLIENTMANAGER_H
#define CLIENTMANAGER_H

#include <unistd.h>

class ClientManager {
public:
    static int client_sock;
    static void close_client_sock();
};

inline void ClientManager::close_client_sock()
{
    close(ClientManager::client_sock);
}

#endif // CLIENTMANAGER_H
