#ifndef __CLIENT_H__
#define __CLIENT_H__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>
#include <unistd.h>

#include "../../view/clientmanager.h"

#define BUFF_SIZE 65536

int sendToServer(const char *buff)
{
    int sendBytes;
    sendBytes = send(ClientManager::client_sock, buff, strlen(buff), 0);
    if (sendBytes < 0)
    {
        perror("Error: ");
        ClientManager::close_client_sock();
        exit(0);
    }

    return sendBytes;
}

int recvFromServer(const char *buff)
{
}

#endif