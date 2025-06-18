#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <time.h>

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
    servAddr.sin_port = htons(6265);  // Server port
    servAddr.sin_addr.s_addr = INADDR_ANY;

    // Bind socket
    if (bind(server, (struct sockaddr*)&servAddr, sizeof(servAddr)) < 0) {
        perror("Bind error");
        exit(1);
    }

    printf("UDP Time Server listening on port 6265...\n");

    while (1) {
        // Receive request from client
        recvfrom(server, buffer, sizeof(buffer), 0, (struct sockaddr*)&clientAddr, &clientLen);
        printf("Time request received\n");

        // Get system time
        time_t now = time(NULL);
        struct tm *timeInfo = localtime(&now);
        strftime(buffer, sizeof(buffer), "%Y-%m-%d %H:%M:%S", timeInfo);

        // Send current time to client
        sendto(server, buffer, strlen(buffer), 0, (struct sockaddr*)&clientAddr, clientLen);
    }

    close(server);
    return 0;
}







#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>
#include <unistd.h>

int main() {
    int client;
    char buffer[1024] = "TIME_REQUEST";
    struct sockaddr_in servAddr;
    socklen_t addrSize = sizeof(servAddr);

    // Create UDP socket
    client = socket(AF_INET, SOCK_DGRAM, 0);
    if (client < 0) {
        perror("Socket error");
        exit(1);
    }

    servAddr.sin_family = AF_INET;
    servAddr.sin_port = htons(6265);  // Connect to server port
    servAddr.sin_addr.s_addr = inet_addr("127.0.0.1");  // Server IP

    // Send time request to server
    sendto(client, buffer, strlen(buffer), 0, (struct sockaddr*)&servAddr, addrSize);
    
    // Receive response from server
    recvfrom(client, buffer, sizeof(buffer), 0, (struct sockaddr*)&servAddr, &addrSize);
    printf("Server Time: %s\n", buffer);

    close(client);
    return 0;
}
