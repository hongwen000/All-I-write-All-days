%{
#include "token.h"
#define YYSTYPE char *
extern "C" {
    void yyerror (char const *s)
    {
      fprintf (stderr, "%s\n", s);
    }
    extern int yylex(void);
}
%}

%token ID
%token VAR
%token NUM 
%token PRINT 
%token PRINT_ALL 
%token ADD 
%token SUB 
%token MUL 
%token LPAREN 
%token RPAREN 
%token DERIVE 
%token EXP 
%token ASSIGN 
%token EQUAL

%left ADD SUB
%left MUL 
%left DERIVE
%right NEG

%%
S   :   ID ASSIGN E         
    |   E                   
    |   ID EQUAL ID         
    |   PRINT ID            
    |   PRINT_ALL           
    ;
E   :   NUM                 
    |   ID                  
    |   VAR                 
    |   NUM VAR             
    |   NUM VAR EXP NUM     
    |   E ADD E             
    |   E SUB E             
    |   E MUL E             
    |   E DERIVE            
    |   SUB E %prec NEG     
    |   LPAREN E RPAREN     
    ;
%%

