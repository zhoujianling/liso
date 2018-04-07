#include <stdio.h>
#include <netinet/ip.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <string.h>
#include <unistd.h>
#include <stdbool.h>
#include <stdlib.h>
#include <argp.h>

#define SERVER_PORT 80
#define BUFFER_SIZE 4096

const char* argp_version = "v.0.0.1";
const char* argp_bug_address = "cquzjl@gmail.com";
static char doc[] = "No mannual.";
static char args_doc[] = "[PORT]";
static struct argp_option options[] = {
    {
        "port", 'p', "80", 0, "The port for HTTP server"
    },
    {
        "shit", 's', 0, 0, "The unknown arg"
    },
    {0}
};

struct arguments {
    uint16_t port;
    uint16_t shit;
};

static error_t parse_opt(int key, char *arg, struct argp_state *state) {
    struct arguments *arguments = state->input; 
    switch (key) {
        case 'p': 
            // printf("%s", arg);
            arguments->port = atoi(arg); 
        break;

    }
    return 0;
}

static struct argp a = {
    options, parse_opt, args_doc, doc, 0, 0, 0
};

int main(int argc, char** argv) {
    struct arguments arguments;
    argp_parse(&a, argc, argv, 0, 0, &arguments);
    printf("The port is: %d", arguments.port);
    return 0;
}