#include "http_response.h"
#include "http_df.h"

#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "unistd.h"

#include "time.h"
#include "locale.h"

/** reference: http://en.cppreference.com/w/c/chrono/strftime **/
const char *get_current_time() {
    static char time_buff[70];
    time_t current_time;
    struct tm *current_tm;
    time(&current_time);
    current_tm = localtime(&current_time);

    //setlocale(LC_TIME, "")

    strftime(time_buff, sizeof(time_buff), "%a, %c ", current_tm);
    return time_buff;
}

http_response *create_temp_hr() {
    http_response *h = (http_response*) malloc(1 * sizeof(http_response));
    strcpy(h->body.data, "<!DOCTYPE html><html><head><title>Hi</title></head> <body> <h1> Test Page! </h1> </body> </html>");

    strcpy(h->header.content_encoding, "gzip");
    strcpy(h->header.content_type, "text/html");
    strcpy(h->header.connection, "keep-alive");
    strcpy(h->header.server, "Liso v.0.0.1 alpha");
    strcpy(h->header.date, get_current_time());
    h->header.content_length = strlen(h->body.data);
    return h;
}

size_t write_http_header(FILE *fp, http_response_header *header) {
    if (fp == NULL || header == NULL) {
        fprintf(stderr, "Write http response failed.\n");
        return -1;
    }
    size_t result_code = 0;
    fprintf(fp, "HTTP/1.1 200 OK\r\n");
    fprintf(fp, "Server: %s\r\n", header->server);
    // fprintf(fp, "Date: Thu, 24 May 2018 11:28:45 GMT\r\n");
    fprintf(fp, "Content-Type: %s\r\n", header->content_type);
    fprintf(fp, "Content-Length: %d\r\n", header->content_length);
    // fprintf(fp, "Transfer-Encoding: chunked\n");
    fprintf(fp, "Connection: %s\r\n", header->connection); // keep-alive
    // fprintf(fp, "Content-Encoding: %s\r\n", header->content_encoding);
    // fprintf(fp, "Date: %s\n", header->date);
    fprintf(fp, "\r\n");
    fprintf(stdout, "WRITEN HEADER!\n");
    // fflush(fp);
    return result_code;
}

size_t write_http_body(FILE *fp, http_response_body *body) {
    if (fp == NULL || body == NULL) {
        fprintf(stderr, "Write http response failed.\n");
        return -1;
    }
    size_t result_code = 0;
    fprintf(fp, "%s\n", body->data);
    // fflush(fp);
    return result_code;
}

int write_http_response(int fd, http_response *hr) {
    FILE *fp = fdopen(fd, "w");
    if (fp == NULL || hr == NULL) {
        fprintf(stderr, "Write http response failed. Null pointer.\n");
        return -1;
    }
    if (write_http_header(fp, &(hr->header)) != 0) {
        fprintf(stderr, "Failed to write http header.");  
        return -1;
    }
    if (write_http_body(fp, &(hr->body)) != 0) {
        fprintf(stderr, "Failed to write http body.");  
        return -1;
    }
    fflush(fp);
    exit(0);
    return 0;
}
