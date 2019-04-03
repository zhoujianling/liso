#include <stdio.h>
#include <stdlib.h>
#include "arg_parser.h"
#include "liso_server.h"

#define SERVER_PORT 80
#define BUFFER_SIZE 4096

void start_parse();

int main(int argc, char** argv) {
    //freopen("/home/zjl/code/lex/http.txt", "r", stdin);
    //start_parse();
    //return 0;
    struct arguments* arg = parse_arugment(argc, argv);
    
    liso* server = liso_init(arg);
    if (server != NULL) {
        start_server(server);
    } else {
        fprintf(stderr, "Failed to start server, exit(2).\n");
        exit(2);
    }
    return 0;
}
