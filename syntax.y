%{
    #include<stdio.h>
    #include<stdlib.h>
    int yylex();
    extern int yylineno; 
    void yyerror(char* s);
%}

%union{
    int integer;
    float real;
    char* str;
}

%token <integer>entier
%token <real>reel
%token <str>idf

%%
start:
    | start token
    ;

token:
      idf
    | entier
    | reel
    | ';'
    | ':'
    | '+' 
    | '-' 
    | '*' 
    | '/' 
    ;
%%



int main(){
    Initialization();
    yyparse();
    afficher();
return 0;
}
void yyerror(char* msg){
    printf("Erreur Syntaxique a la ligne : %d\n",yylineno);
}