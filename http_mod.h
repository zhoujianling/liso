#ifndef HTTP_MOD_H
#define HTTP_MOD_H
#include <stdint.h>
#include <sys/socket.h>
#include <netinet/in.h>

typedef struct http_mod {
    int sockfd;
    struct sockaddr_in addr;
} http_mod;

http_mod* http_init(uint16_t port); 

#endif