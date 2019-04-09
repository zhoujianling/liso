#ifndef HTTP_MOD_H
#define HTTP_MOD_H
#include <stdint.h>
#include <sys/socket.h>
#include <sys/select.h>
#include <netinet/in.h>

#define MAX_CLIENT_FD_COUNT 1000

typedef struct http_mod {
    fd_set clean_fd_set;
    int client_fds[MAX_CLIENT_FD_COUNT];
    int max_client_fd;
    int sock_fd;
    struct sockaddr_in addr;
} http_mod;

http_mod* http_init(uint16_t port); 

#endif
