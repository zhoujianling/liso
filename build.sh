#!/bin/sh
cmake .
make clean && make
sudo ./liso
