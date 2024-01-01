#include <stdio.h>
#include "winsock.h"

#define MAX 80
#define PORT 8080
#pragma comment(lib,"ws2_32.lib") //Winsock Library


int main() {
    printf("Hello, World!\n");
    initialize();
    return 0;
}
