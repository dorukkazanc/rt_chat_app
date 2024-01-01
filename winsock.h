/*
	Initialise Winsock
*/

#include<stdio.h>
#include<winsock2.h>

void socketCreate(SOCKET sock, const int lastError) {
    if((sock = socket(AF_INET, SOCK_STREAM, 0)) == INVALID_SOCKET)
    {
        printf("Socket cannot be created : %d", lastError);
    }else {
        printf("Socket created\n");

    }
}

int initialize()
{
    WSADATA wsa;
    SOCKET sock;

    printf("\nInitialising Winsock...");
    if (WSAStartup(MAKEWORD(2,2),&wsa) != 0)
    {
        printf("Failed. Error Code : %d",WSAGetLastError());
        return 1;
    }

    printf("Initialised.\n");
    socketCreate(sock, WSAGetLastError());

    return 0;
}

