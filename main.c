#include <stdio.h>
#include <stdlib.h>
#include "arg_parser.h"
#include "liso_server.h"

#define SERVER_PORT 80
#define BUFFER_SIZE 4096


int main(int argc, char** argv) {
    struct arguments* arg = parse_arugment(argc, argv);
    liso* server = liso_init(arg);
    if (server != NULL) {
        start_server(server);
    } else {
        fprintf(stderr, "start server failed, exit.\n");
        exit(2);
    }
    // printf("port is : %d ", arg->port);
    return 0;
}