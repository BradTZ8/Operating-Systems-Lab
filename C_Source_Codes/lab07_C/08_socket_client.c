// IPC with Socket; Process 2: Client
// client.c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <sys/un.h>

#define SOCKET_PATH "/tmp/my_socket" // Must match server path

int main() {
    int sockfd;
    struct sockaddr_un server_addr;
    char buffer[256];

    // Create socket file descriptor
    sockfd = socket(AF_UNIX, SOCK_STREAM, 0);
    if (sockfd == -1) {
        perror("Socket creation failed");
        exit(1); }

    // Configure server address structure
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sun_family = AF_UNIX;
    strcpy(server_addr.sun_path, SOCKET_PATH);

    // Connect to server
    if (connect(sockfd, (struct sockaddr*)&server_addr, sizeof(server_addr)) == -1) {
        perror("Socket connect failed");
        exit(1); }

    printf("Client: Connected to server\n");

    // Send message to server
    char *message = "Hello from client!";
    write(sockfd, message, strlen(message));

    // Read response from server
    int n = read(sockfd, buffer, sizeof(buffer)-1);
    if (n > 0) {
        buffer[n] = '\0'; // Null-terminate the string
        printf("Client: Server response: %s\n", buffer); }

    // Close socket connection
    close(sockfd);

    return 0; }
