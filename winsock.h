//
// Created by pc on 01/01/2024.
//

#include <winsock.h>

#ifndef RT_CHAT_APP_TCP_SERVER_H
#define RT_CHAT_APP_TCP_SERVER_H

void socketCreate(SOCKET *sock, const int lastError);
int connectTcpServer(SOCKADDR_IN *server, SOCKET s);
int initialize();


#endif //RT_CHAT_APP_TCP_SERVER_H
