%{
    #include "yacc.tab.h"
    extern "C" {
    int yywrap(void);
    int yylex(void);
    }

    int yywrap(void) {
        pos = 1;
        return 1;
    }
%}

%option header-file="scanner.h"
%option outfile="scanner.cpp"


%%
%%

