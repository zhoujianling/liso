#include "liso_server.h"
#include <stdio.h>
#include <netinet/ip.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <string.h>
#include <unistd.h>
#include <stdbool.h>
#include <stdlib.h>


static liso server;
liso* liso_init(struct arguments* arg) {
    
    return &server;
}


int start_server(liso* server) {
    return 0;
}

