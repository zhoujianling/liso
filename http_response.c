#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <time.h>
#include <locale.h>
#include <sys/stat.h>

#include "http_response.h"
#include "http_df.h"


#define BUFFER_SIZE 4096

http_response hr_200 = {
    .header = {
        .status_code = 200,
        .reason_phrase = "OK",
        .content_length = 0,
        .content_type = "text/html",
        .server = "Liso v.0.0.2 alpha",
        .connection = "keep-alive"
    },
    .body = {
        STDERR_FILENO
    }
};

http_response hr_404 = {
    .header = {
        .status_code = 404,
        .reason_phrase = "Not Found",
        .content_length = 0,
        .content_type = "text/html",
        .server = "Liso v.0.0.2 alpha",
        .connection = "keep-alive"
    },
    .body = {
        STDERR_FILENO
    }
};

http_response hr_500 = {
    .header = {
        .status_code = 500,
        .reason_phrase = "Server Internal Error",
        .content_length = 0,
        .content_type = "text/html",
        .server = "Liso v.0.0.2 alpha",
        .connection = "keep-alive"
    },
    .body = {
        STDERR_FILENO
    }
};

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
    //strcpy(h->body.data, "<!DOCTYPE html><html><head><title>Hi</title></head> <body> <h1> Test Page! </h1> </body> </html>");

    memcpy(h, &hr_200, sizeof(http_response));
    strcpy(h->header.date, get_current_time());
    struct stat index_stat;
    h->body.res_fd = fileno(fopen("./html/index.html", "r"));
    fstat(h->body.res_fd, &index_stat);
    h->header.content_length = index_stat.st_size;
    return h;
}

size_t write_http_header(FILE *fp, http_response_header *header) {
    if (fp == NULL || header == NULL) {
        fprintf(stderr, "Write http response failed.\n");
        return -1;
    }
    size_t result_code = 0;
    fprintf(fp, "HTTP/1.1 %d %s\r\n", header->status_code, header->reason_phrase);
    fprintf(fp, "Server: %s\r\n", header->server);
    // fprintf(fp, "Date: Thu, 24 May 2018 11:28:45 GMT\r\n");
    fprintf(fp, "Content-Type: %s\r\n", header->content_type);
    fprintf(fp, "Content-Length: %d\r\n", header->content_length);
    // fprintf(fp, "Transfer-Encoding: chunked\n");
    fprintf(fp, "Connection: %s\r\n", header->connection); // keep-alive
    // fprintf(fp, "Content-Encoding: %s\r\n", header->content_encoding);
    // fprintf(fp, "Date: %s\n", header->date);
    fprintf(fp, "\r\n");
    // fprintf(stdout, "WRITEN HEADER!\n");
    fflush(fp);

    return result_code;
}

size_t write_http_body(FILE *fp, http_response_body *body) {
    if (fp == NULL || body == NULL) {
        fprintf(stderr, "Write http response failed.\n");
        return -1;
    }
    size_t result_code = 0;
    FILE *res_fp = fdopen(body->res_fd, "r");
    if (res_fp == NULL) { // only happened when cannot find 404.html
        fprintf(stderr, "Cannot find ./html/404.html!\n");
        write(fileno(fp), "404 FILE NOT FOUND.\n", 20);
        return -1;
    } else {
        uint8_t buffer[BUFFER_SIZE];
        int read_cnt;
        while ((read_cnt = read(body->res_fd, buffer, BUFFER_SIZE)) != 0) {
            write(fileno(fp), buffer, read_cnt);
        }
        fclose(res_fp);
    }
    //fprintf(fp, "%s\n", body->data);
    return result_code;
}

void write_http_500_response(int fd) {

}

int write_http_response(int fd, http_response *hr) {
    FILE *fp = fdopen(fd, "w");
    if (fp == NULL || hr == NULL) {
        fprintf(stderr, "Write http response failed. Null pointer.\n");
        return -1;
    }
    if (write_http_header(fp, &(hr->header)) != 0) {
        fprintf(stderr, "Failed to write http header.\n");  
        return -1;
    }
    if (write_http_body(fp, &(hr->body)) != 0) {
        fprintf(stderr, "Failed to write http body.\n");  
        return -1;
    }
    // fflush(fp);
    return 0;
}
