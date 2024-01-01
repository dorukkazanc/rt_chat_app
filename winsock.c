//
// Created by pc on 01/01/2024.
//
#include<stdio.h>
#include<winsock.h>
#include "winsock.h"
#include <stdbool.h>

void socketCreate(SOCKET *sock, const int lastError) {
    *sock = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    if (*sock == INVALID_SOCKET) {
        printf("Socket cannot be created : %d", lastError);
    } else {
        printf("Socket created\n");
    }
}

int connectTcpServer(SOCKADDR_IN *server, SOCKET s) {
    if (connect(s , (struct sockaddr *)server , sizeof(*server)) < 0) {
        perror("Connection error");
        return 1;
    }
    return 0;
}

int initialize() {

}
