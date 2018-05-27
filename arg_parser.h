#ifndef ARG_PARSER_H
#define ARG_PARSER_H

#include <stdint.h>

struct arguments {
    uint16_t port;
    uint16_t https_port;
    const char* log_file;
    const char* lock_file;
    const char* www_folder;
    const char* cgi_path;
    const char* private_key_file;
    const char* certificate_file;
};

extern struct arguments* parse_arugment(int argc, char **argv); 

#endif