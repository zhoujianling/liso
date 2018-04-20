#include "liso_server.h"
#include <stdio.h>
#include <netinet/ip.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <string.h>
#include <unistd.h>
#include <stdbool.h>
#include <stdlib.h>

extern int start_http(http_mod* m);

static liso server;
liso* liso_init(struct arguments* arg) {
    http_mod* hm = http_init(arg->port);
    
    if (hm == NULL) {
        fprintf(stderr, "Initialize http module failed!\n");
        return NULL;
    } 
    server.http = hm;
    return &server;
}

int start_server(liso* server) {
    int http_ret = start_http(server->http);
    return 0;
}

