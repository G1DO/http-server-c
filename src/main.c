#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include "../include/socket.h"

#define PORT 8000
#define BACKLOG 5

int main(void) {
    int server_fd, client_fd;
    
    printf("Creating socket...\n");
    server_fd = create_socket();
    if (server_fd < 0) {
        fprintf(stderr, "Failed to create socket\n");
        exit(EXIT_FAILURE);
    }
    printf("Socket created successfully (fd: %d)\n", server_fd);
    
    printf("Binding socket to port %d...\n", PORT);
    if (bind_socket(server_fd, PORT) < 0) {
        fprintf(stderr, "Failed to bind socket\n");
        close(server_fd);
        exit(EXIT_FAILURE);
    }
    printf("Socket bound to port %d\n", PORT);
    
    printf("Setting socket to listen...\n");
    if (listen_socket(server_fd, BACKLOG) < 0) {
        fprintf(stderr, "Failed to listen\n");
        close(server_fd);
        exit(EXIT_FAILURE);
    }
    printf("Server listening on port %d...\n", PORT);
    
    // For Milestone 1: accept one connection and send "Hello World"
    printf("Waiting for client connection...\n");
    client_fd = accept_connection(server_fd);
    if (client_fd < 0) {
        fprintf(stderr, "Failed to accept connection\n");
        close(server_fd);
        exit(EXIT_FAILURE);
    }
    printf("Client connected!\n");
    
    // Send "Hello World" response with minimal HTTP headers
    const char *response = "HTTP/1.1 200 OK\r\n"
                           "Content-Length: 12\r\n"
                           "\r\n"
                           "Hello World\n";
    if (write(client_fd, response, strlen(response)) < 0) {
        perror("write failed");
    }
    
    // Close client connection
    close(client_fd);
    printf("Client disconnected\n");
    
    // Close the server socket (shut down the server)
    close(server_fd);
    printf("Server shutdown\n");
    
    return 0;
}

