#include <stdio.h>
#include "winsock.h"

#define MAX 80
#define PORT 8080
#pragma comment(lib,"ws2_32.lib")


int main(int argc, char *argv[]) {
    printf("Hello, World!\n");
    WSADATA wsa;
    SOCKET sock;
    int c;
    char buffer[1024];
    struct sockaddr_in server;
    server.sin_family = AF_INET;
    server.sin_addr.s_addr = inet_addr("127.0.0.1");
    server.sin_port = htons(3131);

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

    memset(buffer, 0, sizeof (buffer));
    int bytes_received = recv(sock, buffer, sizeof (buffer), 0);
    if(bytes_received > 0) {
        printf("Gelen veri %s ", buffer);
        send(sock, "Aldım", strlen("Aldım"), 0);
    }
    else if (bytes_received == 0) {
        printf("Connection closed by server.\n");
    } else {
        printf("recv failed with error code: %d", WSAGetLastError());
    }

    closesocket(sock);
    WSACleanup();


    return 0;
}
