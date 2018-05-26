#ifndef HTTP_RESPONSE_H
#define HTTP_RESPONSE_H

#include <stdint.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include "stdio.h"


typedef struct http_response_header{
    char content_type[20];
    char content_encoding[20];
    uint32_t content_length;
    char server[20];
    char date[20];
    char connection[20];
    char transfer_encoding[20];
} http_response_header;

typedef struct http_response_body{
    int res_fd;
    //char data[100];
} http_response_body;

typedef struct http_response{
    http_response_header header;
    http_response_body body;

} http_response;

http_response *create_temp_hr(); 

 size_t write_http_header(FILE *fp, http_response_header *header);

 size_t write_http_body(FILE *fp, http_response_body *header);

int write_http_response(int fd, http_response *header);

const char *get_current_time(); 

#endif
