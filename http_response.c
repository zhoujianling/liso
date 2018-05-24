#include "http_response.h"
#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "unistd.h"

http_response *create_temp_hr() {
    http_response *h = (http_response*) malloc(1 * sizeof(http_response));
    strcpy(h->header.content_encoding, "gzip");
    strcpy(h->header.content_type, "text/html");
    strcpy(h->header.server, "Liso v.0.0.0 alpha");
    return h;
}

size_t write_http_header(FILE *fp, http_response_header *header) {
    if (fp == NULL || header == NULL) {
        fprintf(stderr, "Write http response failed.\n");
        return -1;
    }
    size_t result_code = 0;
    fprintf(fp, "Content-Type:%s\n", header->content_type);
    fprintf(fp, "Content-Encoding:%s\n", header->content_encoding);
    fprintf(fp, "Server:%s\n", header->server);
    return result_code;
}

size_t write_http_body(FILE *fp, http_response_body *body) {
    if (fp == NULL || body == NULL) {
        fprintf(stderr, "Write http response failed.\n");
        return -1;
    }
    size_t result_code = 0;
    fprintf(fp, "%s", body->data);
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
    return 0;
}
