#ifndef __SERVER_H__
#define __SERVER_H__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>
#include <unistd.h>

#define BUFF_SIZE 65536

int sendToClient(int client_fd, const char *buff)
{
    int sendBytes;
    sendBytes = send(client_fd, buff, strlen(buff), 0);
    if (sendBytes < 0)
    {
        perror("Error: Cannot send data to client!");
        close(client_fd);
    }

    return sendBytes;
}

int recvFromClient(int client_fd, char *buff)
{
    int rcvBytes;
    rcvBytes = recv(client_fd, buff, BUFF_SIZE - 1, 0);
    if (rcvBytes < 0)
    {
        perror("Error: Cannot received data from client!");
        close(client_fd);
    }
    buff[rcvBytes] = '\0';

    return rcvBytes;
}

#endif