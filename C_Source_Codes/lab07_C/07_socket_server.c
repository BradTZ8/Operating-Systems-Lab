// IPC with Socket; Process 1: Server
// server.c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <sys/un.h>

#define SOCKET_PATH "/tmp/my_socket" // Path for UNIX domain socket

int main () {
    // file descriptors for clients and server sockets
    int server_fd, client_fd;
    // Address Structures
    struct sockaddr_un server_addr, client_addr;
    //Define client Address size
    socklen_t client_len = sizeof(client_addr);
    char buffer[256]; // buffer to put data in

    // Create socket file descriptor
    // AF_UNIX: Unix domain socket, SOCK_STREAM: TCP-like reliable socket
    server_fd = socket(AF_UNIX, SOCK_STREAM, 0);
    if (server_fd == -1) {
        perror("Socket creation failed");
        exit(1); }

    // Configure server address structure
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sun_family = AF_UNIX;
    // server socket address = your socket address
    strcpy(server_addr.sun_path, SOCKET_PATH);

    // Remove socket file if it exists from previous run
    unlink(SOCKET_PATH);

    // Bind socket to the specified address
    if (bind(server_fd, (struct sockaddr*)&server_addr, sizeof(server_addr)) == -1) {
        perror("Socket bind failed");
        exit(1); }

    // Listen for incoming connections
    // Backlog queue size: 5
    if (listen(server_fd, 5) == -1) {
        perror("Socket listen failed");
        exit (1); }
    printf("Server: Listening for connections...\n");

    // Accept incoming connection
    client_fd = accept(server_fd, (struct sockaddr*)&client_addr, &client_len);
    if (client_fd == -1) {
        perror("Socket accept failed");
        exit(1); }

    printf("Server: Client connected\n");

    // Read data from client
    int n = read(client_fd, buffer, sizeof(buffer)-1);
    if (n > 0) {
        buffer[n] = '\0'; // Null-terminate the string
        printf("Server: Received: %s\n", buffer);

        // Send response to client
        char *response = "Hello from server!";
        write(client_fd, response, strlen(response)); }

    // Close connections and clean up
    close(client_fd);
    close(server_fd);
    unlink(SOCKET_PATH); // Remove socket file

    return 0; }
