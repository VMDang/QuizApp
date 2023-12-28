#include <iostream>
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include <stddef.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <openssl/sha.h>
#include <pthread.h>

// #include "../request/login.h"
#include "../request/type.h"
#include "../comunicate/server.h"
// #include "../../../library/json.hpp"
#include "../../Model/User.hpp"

#define BACKLOG 5

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

void *client_handler(void *arg) 
{
    int clientfd;
    int sendBytes, rcvBytes;

    pthread_detach(pthread_self());
    clientfd = *((int *)arg);
    free(arg);

    while (1)
    {
        char buff[BUFF_SIZE];
        
        rcvBytes = recvFromClient(clientfd, buff);
        
        if (strcmp(buff, "\0") == 0)
        {
            break;
        }
        printf("%s\n", buff);
        json requestLogin = json::parse(buff);
        std::string code = requestLogin["code"];
        std::string url = requestLogin["url"];
        std::string header = requestLogin["header"];
        std::string email = requestLogin["body"]["email"];
        std::string password = requestLogin["body"]["password"];

        User user = User::findById(1); // Error: Core var dump
        // std::cout << email << " --- " << password << std::endl;
        
        // if (user.id != 0 )
        // {
        //     std::cout << user.name << " -- " << user.email;
        // } else {
        //     printf("Donot have");
        // }
        
    }
    close(clientfd);
}

int main(int argc, char const *argv[])
{
    if (argc <= 1)
    {
        printf("PortNumber is required. Pleae enter PortNumber\n");
        return 0;
    }
    else if (argc >= 3)
    {
        printf("Enter only one PortNumber\n");
        return 0;
    }

    int listenfd;
    int *connfd;
    struct sockaddr_in server;
    struct sockaddr_in client;
    socklen_t sin_size;
    pthread_t tid;

    // Construct a TCP socket to listen connection request
    if ((listenfd = socket(AF_INET, SOCK_STREAM, 0)) == -1)
    {
        perror("\nError: ");
        return 0;
    }

    // Bind address to socket
    memset(&server, '\0', sizeof server);
    server.sin_family = AF_INET;
    server.sin_port = htons(atoi(argv[1]));
    server.sin_addr.s_addr = htonl(INADDR_ANY);
    if (bind(listenfd, (struct sockaddr *)&server, sizeof(server)) == -1)
    {
        perror("\nError: ");
        return 0;
    }

    // Listen request from client
    if (listen(listenfd, BACKLOG) == -1)
    {
        perror("\nError: ");
        return 0;
    }

    // Communicate with client
    while (1)
    {
        connfd = (int*)malloc(sizeof(int));
        sin_size = sizeof(struct sockaddr_in);
        if ((*connfd = accept(listenfd, (struct sockaddr *)&client, &sin_size)) == -1)
            perror("\nError: ");
        printf("You got a connection from %s\n", inet_ntoa(client.sin_addr)); /* prints client's IP */

        pthread_create(&tid, NULL, &client_handler, connfd);
    }

    close(listenfd);
    return 0;
}
