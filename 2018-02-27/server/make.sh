#!/bin/sh
rm ./a.out
clang++ -O0 ./main.cpp ./server.cpp ./md5.cpp ./timestamp.cpp -L/usr/local/opt/openssl/lib -I/usr/local/opt/openssl/include -std=c++1z -lboost_system  -g
./a.out
