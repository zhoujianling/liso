#ifndef LISO_SERVER_H
#define LISO_SERVER_H
#include <stdio.h>
#include "arg_parser.h"
#include "http_mod.h"

typedef struct liso {
    http_mod* http;
    FILE* log_file;
    FILE* lock_file;
}liso;

/** create socket and bind to local HTTP(s) port. **/
liso* liso_init(struct arguments* arg);

/** called olif liso is successfully inited **/
int start_server(liso *);

#endif