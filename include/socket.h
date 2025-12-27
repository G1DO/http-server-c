#ifndef SOCKET_H
#define SOCKET_H

#include <sys/socket.h>
#include <netinet/in.h>

/**
 * Creates a TCP socket
 * @return socket file descriptor on success, -1 on error
 */
int create_socket(void);

/**
 * Binds socket to a port
 * @param sockfd socket file descriptor
 * @param port port number to bind to
 * @return 0 on success, -1 on error
 */
int bind_socket(int sockfd, int port);

/**
 * Sets socket to listen for connections
 * @param sockfd socket file descriptor
 * @param backlog maximum pending connections
 * @return 0 on success, -1 on error
 */
int listen_socket(int sockfd, int backlog);

/**
 * Accepts a client connection
 * @param sockfd listening socket file descriptor
 * @return client socket file descriptor on success, -1 on error
 */
int accept_connection(int sockfd);

#endif /* SOCKET_H */

