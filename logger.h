#include "stdio.h"

#define DEBUG   0
#define INFO    1
#define WARN    2
#define ERROR   3
#define FATAL   4

extern void _log(int level, const char *msg); 

extern void _debug(const char *msg); 

extern void _info(const char *msg); 

extern void _warn(const char *msg); 

extern void _error(const char *msg); 

extern void _fatal(const char *msg); 


