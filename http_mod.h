#ifndef HTTP_MOD_H
#define HTTP_MOD_H
#include <stdint.h>

typedef struct http_mod {
    int sockfd;
} http_mod;

http_mod* http_init(uint16_t port);

#endif