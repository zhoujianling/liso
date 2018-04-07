#include <string.h>
#include <unistd.h>
#include <stdbool.h>
#include <stdlib.h>
#include <argp.h>
#include <stdio.h>
#include <netinet/ip.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include "arg_parser.h"

const char* argp_version = "v.0.0.1";
const char* argp_bug_address = "cquzjl@gmail.com";
static char doc[] = "No mannual.";
static char args_doc[] = "[PORT]";
static struct argp_option options[] = {
    {
        "port", 'p', "80", 0, "The port for HTTP"
    },
    {
        "https port", 's', "433", 0, "The port for HTTPS"
    },
    {
        "log file", 'l', "/var/log/liso.log", 0, "The log file name"
    },
    {
        "lock file", 'k', "/var/liso.lock", 0, "The lock file name"
    },
    {
        "www folder", 'w', "/var/www/html", 0, "The folder for www"
    },
    {
        "cgi paths", 'c', "/var/www/html", 0, "The CGI paths"
    },
    {
        "private key file", 'i', "/var/www/html", 0, "The private key"
    },
    {
        "certificate file", 'e', "/var/www/html", 0, "The certificate file"
    },
    {0}
};

static error_t parse_opt(int key, char *arg, struct argp_state *state) {
    struct arguments *arguments = state->input; 
    switch (key) {
        case 'p':{ 
            int parsed_port = atoi(arg);
            if (strcmp(arg, "0") == 0 || parsed_port == 0) {
                fprintf(state->err_stream, "The port number should be between [1, 65536].\n");
                return EINVAL;
            }
            arguments->port = parsed_port; 
        break;
        }
        case 's':
        arguments->https_port = atoi(arg);
        break;
        case 'l':
        arguments->log_file = arg;
        break;
        case 'k':
        arguments->lock_file = arg;
        break;
        case 'w':
        arguments->www_folder = arg;
        break;
        case 'c':
        arguments->cgi_path = arg;
        break;
        case 'e':
        arguments->private_key_file = arg;
        break;
        case 'i':
        arguments->certificate_file = arg;
        break;
    }
    return 0;
}

static struct argp a = {
    options, parse_opt, args_doc, doc, 0, 0, 0
};

struct arguments arguments;
struct arguments* parse_arugment(int argc, char **argv) {
    error_t parse_ret = argp_parse(&a, argc, argv, 0, 0, &arguments);
    if (parse_ret != 0) {
        const char *error_message = strerror(parse_ret);
        if (error_message != NULL) {
            fprintf(stderr, "%s, exit.\n", error_message);
        }
        errno = EINVAL;
        exit(1);
    }
    return &arguments;
}
