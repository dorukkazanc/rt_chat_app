#include <stdio.h>
#include "winsock.h"

#define MAX 80
#define PORT 8080
#pragma comment(lib,"ws2_32.lib")


int main(int argc, char *argv[]) {
    printf("Hello, World!\n");
    initialize();
    return 0;
}
