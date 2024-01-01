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
    WSADATA wsa;
    SOCKET sock;
    struct sockaddr_in server;
    server.sin_family = AF_INET;
    server.sin_addr.s_addr = inet_addr("127.0.0.1");
    server.sin_port = htons(80);

    printf("\nInitialising Winsock...");
    if (WSAStartup(MAKEWORD(2,2), &wsa) != 0) {
        printf("Failed. Error Code : %d", WSAGetLastError());
        return 1;
    }

    printf("Initialised.\n");
    socketCreate(&sock, WSAGetLastError());
    if (connectTcpServer(&server, sock) != 0) {
        return 1;
    }
}
