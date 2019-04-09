#include "logger.h"

#define BLUE  "\x1B[34m"
#define RED  "\x1B[31m"
#define YELLOW  "\x1B[33m"
#define CYN   "\x1B[36m"
#define WHITE   "\x1B[37m"
#define RESET "\x1B[0m"

const char *TAG_DEBUG = "DEBUG"; 
const char *TAG_INFO = "INFO"; 
const char *TAG_WARN = "WARN"; 
const char *TAG_ERROR = "ERROR"; 
const char *TAG_FATAL = "FATAL"; 

void _log(int level, const char *msg) {
    switch (level) {
        case DEBUG:
            fprintf(stderr, YELLOW"%s\t:%s\n"RESET, TAG_DEBUG, msg);
            break;
        case INFO:
            fprintf(stderr, BLUE"%s\t:%s\n"RESET, TAG_INFO, msg);
            break;
        case WARN:
            fprintf(stderr, CYN"%s\t:%s\n"RESET, TAG_WARN, msg);
            break;
        case ERROR:
            fprintf(stderr, RED"%s\t:%s\n"RESET, TAG_ERROR, msg);
            break;
        case FATAL:
            fprintf(stderr, WHITE"%s\t:%s\n"RESET, TAG_FATAL, msg);
            break;
    }
    fflush(stderr);
}

void _info(const char *msg) {
    _log(INFO, msg);
}

void _debug(const char *msg) {
    _log(DEBUG, msg);
}

void _warn(const char *msg) {
    _log(WARN, msg);
}

void _error(const char *msg) {
    _log(WARN, msg);
}

void _fatal(const char *msg) {
    _log(FATAL, msg);
}
