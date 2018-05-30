#!/bin/sh
flex -o http_request_parser.c http_request_parser.l
cmake .
make clean && make
sudo ./liso
