#ifndef HTTP_REQUEST_H
#define HTTP_REQUEST_H

typedef struct http_request {
    char method[10];
    char res[50];// requested resource location
    char host[20]; 
}http_request;

#endif