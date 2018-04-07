#ifndef LISO_SERVER_H
#define LISO_SERVER_H
#include "arg_parser.h"

typedef struct liso {

}liso;

liso* liso_init(struct arguments* arg);
int start_server(liso *);

#endif