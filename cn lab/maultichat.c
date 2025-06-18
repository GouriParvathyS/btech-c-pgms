#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
#include<arpa/inet.h>
#include<sys/socket.h>

int main() {
    int server_socket, client_socket;
    char buffer[1024];
    struct sockaddr_in server_addr, client_addr;
    socklen_t addr_size;

    server_socket = socket(AF_INET, SOCK_STREAM, 0);
    
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(12345);
    server_addr.sin_addr.s_addr = INADDR_ANY;
    
    bind(server_socket, (struct sockaddr*)&server_addr, sizeof(server_addr));
    listen(server_socket, 1);
    printf("Waiting for connection...\n");

    addr_size = sizeof(client_addr);
    client_socket = accept(server_socket, (struct sockaddr*)&client_addr, &addr_size);
    printf("Client connected...\n");

    while (1) {
        memset(buffer, 0, sizeof(buffer)); // Clear buffer
        recv(client_socket, buffer, 1024, 0);
        buffer[strcspn(buffer, "\n")] = 0;
        printf("Client: %s\n", buffer); // Add `\n` for proper formatting
        if (strcmp(buffer, "exit") == 0) {
            break;
        }

        printf("Server: ");
        fgets(buffer, 1024, stdin);
        buffer[strcspn(buffer, "\n")] = 0; // Remove trailing newline
        send(client_socket, buffer, strlen(buffer), 0);

        if (strcmp(buffer, "exit") == 0) {
            break;
        }
    }

    close(client_socket);
    close(server_socket);
    return 0;
}
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
#include<arpa/inet.h>
#include<sys/socket.h>

int main() {
    int client_socket;
    char buffer[1024];
    struct sockaddr_in server_addr;

    client_socket = socket(AF_INET, SOCK_STREAM, 0);
    
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(12345);
    server_addr.sin_addr.s_addr = inet_addr("127.0.0.1"); // Use the correct IP

    connect(client_socket, (struct sockaddr*)&server_addr, sizeof(server_addr));
    printf("Connected to server...\n");

    while (1) {
        printf("Client: ");
        fgets(buffer, 1024, stdin);
        buffer[strcspn(buffer, "\n")] = 0; // Remove trailing newline
        send(client_socket, buffer, strlen(buffer), 0);
        if (strcmp(buffer, "exit") == 0) {
            break;
        }

        memset(buffer, 0, sizeof(buffer)); // Clear buffer
        recv(client_socket, buffer, 1024, 0);
        printf("Server: %s\n", buffer); // Ensure newline for formatting

        if (strcmp(buffer, "exit") == 0) {
            break;
        }
    }

    close(client_socket);
    return 0;
}
