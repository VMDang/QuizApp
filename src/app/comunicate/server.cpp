#include "server.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <vector>
#include <algorithm>

#include "../server/ServerManager.hpp"

#define BUFF_SIZE 65536

int sendToClient(int client_fd, const char *buff)
{
    int sendBytes = 0;
    sendBytes = send(client_fd, buff, strlen(buff), 0);
    if (sendBytes <= 0)
    {
        perror("Error: Cannot send data to client!");

        pthread_mutex_lock(&ServerManager::mutex);
        ServerManager::client_auth.erase(std::remove_if(ServerManager::client_auth.begin(), ServerManager::client_auth.end(),
                             [client_fd](std::unordered_map<int, int>& clientUserMap) {
                                 return clientUserMap.find(client_fd) != clientUserMap.end();
                             }),
                ServerManager::client_auth.end());
        pthread_mutex_unlock(&ServerManager::mutex);

        close(client_fd);
    }

    return sendBytes;
}

int recvFromClient(int client_fd, char *buff)
{
    int rcvBytes = 0;
    rcvBytes = recv(client_fd, buff, BUFF_SIZE - 1, 0);
    if (rcvBytes <= 0)
    {
        perror("Error: Cannot received data from client!");

        pthread_mutex_lock(&ServerManager::mutex);
        ServerManager::client_auth.erase(std::remove_if(ServerManager::client_auth.begin(), ServerManager::client_auth.end(),
                             [client_fd](std::unordered_map<int, int>& clientUserMap) {
                                 return clientUserMap.find(client_fd) != clientUserMap.end();
                             }),
                ServerManager::client_auth.end());
        pthread_mutex_unlock(&ServerManager::mutex);

        close(client_fd);
    }
    buff[rcvBytes] = '\0';

    return rcvBytes;
}
