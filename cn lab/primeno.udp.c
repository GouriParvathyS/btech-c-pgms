#include <stdio.h>
#include <stdlib.h>
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

int main() {
    int server;
    char buffer[1024];
    struct sockaddr_in servAddr, clientAddr;
    socklen_t clientLen = sizeof(clientAddr);

    // Create UDP socket
    server = socket(AF_INET, SOCK_DGRAM, 0);
    if (server < 0) {
        perror("Socket error");
        exit(1);
    }

    servAddr.sin_family = AF_INET;
    servAddr.sin_port = htons(6265);
    servAddr.sin_addr.s_addr = inet_addr("127.0.0.1");

    // Bind socket
    if (bind(server, (struct sockaddr*)&servAddr, sizeof(servAddr)) < 0) {
        perror("Bind error");
        exit(1);
    }

    printf("UDP Server listening on port 6265...\n");

    while (1) {
        // Receive number from client
        recvfrom(server, buffer, sizeof(buffer), 0, (struct sockaddr*)&clientAddr, &clientLen);
        int num = atoi(buffer); // Convert to integer

        // Check if prime
        if (is_prime(num))
            strcpy(buffer, "Prime");
        else
            strcpy(buffer, "Not Prime");

        // Send response
        sendto(server, buffer, strlen(buffer), 0, (struct sockaddr*)&clientAddr, clientLen);
    }

    close(server);
    return 0;
}
//client
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>
#include <unistd.h>

int main() {
    int client;
    char buffer[1024];
    struct sockaddr_in servAddr;
    socklen_t addrSize = sizeof(servAddr);

    // Create UDP socket
    client = socket(AF_INET, SOCK_DGRAM, 0);
    if (client < 0) {
        perror("Socket error");
        exit(1);
    }

    servAddr.sin_family = AF_INET;
    servAddr.sin_port = htons(6265);
    servAddr.sin_addr.s_addr = inet_addr("127.0.0.1");

    // Get number from user
    printf("Enter a number: ");
    scanf("%s", buffer);

    // Send number to server
    sendto(client, buffer, strlen(buffer), 0, (struct sockaddr*)&servAddr, addrSize);
    
    // Receive response
    recvfrom(client, buffer, sizeof(buffer), 0, (struct sockaddr*)&servAddr, &addrSize);
    printf("Server response: %s\n", buffer);

    close(client);
    return 0;
}
