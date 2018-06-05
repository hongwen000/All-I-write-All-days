#!/usr/local/bin/fish
flex calc.l
bison calc.y
g++ calc.tab.c lex.yy.c token.cpp main.cpp -g
