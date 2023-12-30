#ifndef __CLIENT_H__
#define __CLIENT_H__

#define BUFF_SIZE 65536

int sendToServer(const char *buff);

int recvFromServer(char *buff);

#endif