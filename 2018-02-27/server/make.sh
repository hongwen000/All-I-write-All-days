#!/bin/sh
rm ./a.out
clang++ ./main.cpp ./server.cpp ./md5.cpp -L/usr/local/opt/openssl/lib -I/usr/local/opt/openssl/include -std=c++1z -lboost_system  -g -lpthread
./a.out
