#!/bin/sh
flex -o http_request_parser.lex.c http_request_parser.l
cmake .
make clean && make
#sudo ./liso
