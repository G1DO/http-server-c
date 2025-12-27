#include "../include/socket.h"
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

/**
 * Creates a TCP socket
 * @return socket file descriptor on success, -1 on error
 */
int create_socket(void) {
    int sockfd;
    
    // Create socket: AF_INET = IPv4, SOCK_STREAM = TCP, 0 = default protocol
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    
    if (sockfd < 0) {
        perror("socket creation failed");
        return -1;
    }
    
    // Set socket option to reuse address (helps with "Address already in use" errors)
    int opt = 1;
    if (setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt)) < 0) {
        perror("setsockopt failed");
        close(sockfd);
        return -1;
    }
    
    return sockfd;
}

/**
 * Binds socket to a port
 * @param sockfd socket file descriptor
 * @param port port number to bind to
 * @return 0 on success, -1 on error
 */
int bind_socket(int sockfd, int port) {
    struct sockaddr_in server_addr;
    
    // Clear the structure
    memset(&server_addr, 0, sizeof(server_addr));
    
    // Set address family to IPv4
    server_addr.sin_family = AF_INET;
    
    // Bind to all available interfaces (INADDR_ANY)
    server_addr.sin_addr.s_addr = INADDR_ANY;
    
    // Set port (convert to network byte order)
    server_addr.sin_port = htons(port);
    
    // Bind socket to address
    if (bind(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("bind failed");
        return -1;
    }
    
    return 0;
}

/**
 * Sets socket to listen for connections
 * @param sockfd socket file descriptor
 * @param backlog maximum pending connections
 * @return 0 on success, -1 on error
 */
int listen_socket(int sockfd, int backlog) {
    if (listen(sockfd, backlog) < 0) {
        perror("listen failed");
        return -1;
    }
    
    return 0;
}

/**
 * Accepts a client connection
 * @param sockfd listening socket file descriptor
 * @return client socket file descriptor on success, -1 on error
 */
int accept_connection(int sockfd) {
    struct sockaddr_in client_addr;
    socklen_t client_len = sizeof(client_addr);
    int client_fd;
    
    // Accept incoming connection
    client_fd = accept(sockfd, (struct sockaddr *)&client_addr, &client_len);
    
    if (client_fd < 0) {
        perror("accept failed");
        return -1;
    }
    
    return client_fd;
}

