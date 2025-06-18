#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>
#include <arpa/inet.h>
#include <unistd.h>

void main() {
    int client;
    char buffer[1024];
    struct sockaddr_in servAddr;

    client = socket(AF_INET, SOCK_STREAM, 0);
    if (client < 0) {
        printf("Socket creation failed!\n");
        exit(1);
    }

    servAddr.sin_family = AF_INET;
    servAddr.sin_port = htons(6265);
    servAddr.sin_addr.s_addr = inet_addr("127.0.0.1");

    if (connect(client, (struct sockaddr *)&servAddr, sizeof(servAddr)) < 0) {
        printf("Connection failed!\n");
        exit(1);
    }

    printf("Enter a number: ");
    fgets(buffer, sizeof(buffer), stdin);
    send(client, buffer, strlen(buffer), 0);

    memset(buffer, 0, sizeof(buffer));
    recv(client, buffer, sizeof(buffer), 0);
    printf("Server: %s", buffer);

    close(client);
}
//Server
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>
#include <arpa/inet.h>
#include <unistd.h>

int is_prime(int num) {
    if (num < 2) return 0;
    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0) return 0;
    }
    return 1;
}

void main() {
    int server, newSock;
    char buffer[1024];
    struct sockaddr_in servAddr;
    struct sockaddr_storage store;
    socklen_t addrSize;

    server = socket(AF_INET, SOCK_STREAM, 0);
    if (server < 0) {
        printf("Socket creation failed!\n");
        exit(1);
    }

    servAddr.sin_family = AF_INET;
    servAddr.sin_port = htons(6265);
    servAddr.sin_addr.s_addr = inet_addr("127.0.0.1");

    if (bind(server, (struct sockaddr *)&servAddr, sizeof(servAddr)) < 0) {
        printf("Binding failed!\n");
        exit(1);
    }

    if (listen(server, 5) == 0)
        printf("Listening...\n");
    else {
        printf("Error in listening!\n");
        exit(1);
    }

    addrSize = sizeof(store);
    newSock = accept(server, (struct sockaddr *)&store, &addrSize);
    if (newSock < 0) {
        printf("Accept failed!\n");
        exit(1);
    }

    recv(newSock, buffer, sizeof(buffer), 0);
    int num = atoi(buffer);  // Convert received string to integer

    printf("Received number: %d\n", num);

    memset(buffer, 0, sizeof(buffer));
    if (is_prime(num))
        strcpy(buffer, "Prime Number\n");
    else
        strcpy(buffer, "Not a Prime Number\n");

    send(newSock, buffer, strlen(buffer), 0);
    close(newSock);
    close(server);
}
