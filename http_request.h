#ifndef HTTP_REQUEST_H
#define HTTP_REQUEST_H

#include "http_df.h"

typedef struct http_request_ {
    char method[10];
    char res[MAX_HEADER_BYTES];// requested resource location
    char host[20]; 
    char http_version[4];
    char connection[20];
    
}http_request;

#endif
