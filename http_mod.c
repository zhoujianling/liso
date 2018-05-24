#include "http_mod.h"
#include <stdlib.h>
#include <stdio.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netinet/ip.h>
#include <unistd.h>

#include "http_response.h"
#include "string.h"

#define BUFFER_SIZE 4096

http_mod* http_init(uint16_t port) {
    http_mod* m = (http_mod*) malloc(sizeof(http_mod*));
    m->sockfd = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    if (m->sockfd == -1) {
       fprintf(stderr, "Create socket failed.");
       free(m);
       return NULL;
    }

    m->addr.sin_family = AF_INET;
    m->addr.sin_port = htons(port);
    m->addr.sin_addr.s_addr = htonl(INADDR_ANY);

    int bind_ret = bind(m->sockfd, (struct sockaddr*) &(m->addr), sizeof(m->addr));
    if (bind_ret != 0) {
        fprintf(stderr, "bind to %d failed!", port);
        if(close(m->sockfd)) {
            fprintf(stderr, "Close socked failed!\n");
        }
        free(m);
        return NULL;
    }

    int listen_ret = listen(m->sockfd, 5);
    if (listen_ret != 0) {
        fprintf(stderr, "Failed to listen!\n");
        if(close(m->sockfd)) {
            fprintf(stderr, "Close socked failed!\n");
        }
        free(m);
        return NULL;
    }

    return m;
}


void handle_request_loop(int sock_fd) {
    int read_ret = 0;
    uint8_t buffer[BUFFER_SIZE];
    http_response *hr = create_temp_hr();
    char databuffer[200];
    strcpy(databuffer, "This is a test. \n");
    while (read_ret = recv(sock_fd, buffer, BUFFER_SIZE, 0) >= 1) {
        fprintf(stdout, "%s", buffer);
        fprintf(stdout, "Reading iter.... ...\n"); 
        write(sock_fd, databuffer, 17);
        // write_http_response(sock_fd, hr);
    }
}

int start_http(http_mod *http) {
    struct sockaddr_in client_sock_addr;
    socklen_t cs_size = sizeof(client_sock_addr);
    fprintf(stdout, "Waiting for a connection, local port: %d\n", ntohs(http->addr.sin_port));
    int new_sock = accept(http->sockfd, (struct sockaddr*)(&client_sock_addr), &cs_size);
    if (new_sock == -1) {
        fprintf(stderr, "Accept connections failed!\n");
        if (close(http->sockfd)) {
            fprintf(stderr, "Close socket failed!\n");
        }
        return -1;
    }
    fprintf(stdout, "start http successfully! \n"); 
    handle_request_loop(new_sock); 
    if (close(new_sock)) {
        fprintf(stderr, "Close real sock failed! \n'");
    }
    if (close(http->sockfd)) {
        fprintf(stderr, "Close sock failed! \n'");
    }
    fprintf(stdout, "Liso has stopped.\n");
    return 0;
}