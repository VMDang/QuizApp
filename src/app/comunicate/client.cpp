#include "client.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>
#include <unistd.h>

#include "../../view/clientmanager.h"

int sendToServer(const char *buff)
{
    int sendBytes = 0;
    sendBytes = send(ClientManager::client_sock, buff, strlen(buff), 0);
    if (sendBytes <= 0)
    {
        perror("Error: Cannot send data to server!");
        ClientManager::close_client_sock();
        exit(0);
    }

    return sendBytes;
}

int recvFromServer(char *buff)
{
    int rcvBytes = 0;
    rcvBytes = recv(ClientManager::client_sock, buff, BUFF_SIZE - 1, 0);
    if (rcvBytes <= 0)
    {
        perror("Error: Cannot received data from server!");
        close(ClientManager::client_sock);
    }
    buff[rcvBytes] = '\0';

    return rcvBytes;
}