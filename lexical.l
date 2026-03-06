%{
#include<stdio.h>
#include"TS.h"
#include"syntax.tab.h"
extern YYSTYPE yylval;
int yycolumn = 1;
%}
%option yylineno

idf                   [a-z]([a-z0-9]|_[a-z0-9])*
integer               \(([+-][0-9]+)\)|[0-9]+
float                  \(([+-][0-9]+\.[0-9]+)\)|[0-9]+\.[0-9]+
commentaireOneLine    %%.* 
commentaireMultiLine  "//*"(.|\n)*"*//"

%%


";"           { Rechercher(yytext,"Separateur","","",3); yycolumn += yyleng;}
":"           { Rechercher(yytext,"Separateur","","",3); yycolumn += yyleng;}
"|"           { Rechercher(yytext,"Separateur","","",3); yycolumn += yyleng;}
"{"           { Rechercher(yytext,"Separateur","","",3); yycolumn += yyleng;}
"}"           { Rechercher(yytext,"Separateur","","",3); yycolumn += yyleng;}
"["           { Rechercher(yytext,"Separateur","","",3); yycolumn += yyleng;}
"]"           { Rechercher(yytext,"Separateur","","",3); yycolumn += yyleng;}
"("           { Rechercher(yytext,"Separateur","","",3); yycolumn += yyleng;}
")"           { Rechercher(yytext,"Separateur","","",3); yycolumn += yyleng;}


"<-"          { Rechercher(yytext,"Separateur","","",3); yycolumn += yyleng;}
"+"           { Rechercher(yytext,"Separateur","","",3); yycolumn += yyleng;}
"-"           { Rechercher(yytext,"Separateur","","",3); yycolumn += yyleng;}
"*"           { Rechercher(yytext,"Separateur","","",3); yycolumn += yyleng;}
"/"           { Rechercher(yytext,"Separateur","","",3); yycolumn += yyleng;}
"<="          { Rechercher(yytext,"Separateur","","",3); yycolumn += yyleng;}
">="          { Rechercher(yytext,"Separateur","","",3); yycolumn += yyleng;}
"<"           { Rechercher(yytext,"Separateur","","",3); yycolumn += yyleng;}
">"           { Rechercher(yytext,"Separateur","","",3); yycolumn += yyleng;}
"=="          { Rechercher(yytext,"Separateur","","",3); yycolumn += yyleng;}
"="           { Rechercher(yytext,"Separateur","","",3); yycolumn += yyleng;}
"!="          { Rechercher(yytext,"Separateur","","",3); yycolumn += yyleng;}
"AND"         { Rechercher(yytext,"Mot cle","","",2); yycolumn += yyleng;}
"OR"          { Rechercher(yytext,"Mot cle","","",2); yycolumn += yyleng;}


"Setup"        { Rechercher(yytext,"Mot cle","","",2); yycolumn += yyleng;}
"BeginProject" { Rechercher(yytext,"Mot cle","","",2); yycolumn += yyleng;}
"Run"          { Rechercher(yytext,"Mot cle","","",2); yycolumn += yyleng;}
"EndProject"   { Rechercher(yytext,"Mot cle","","",2); yycolumn += yyleng;}
"define"       { Rechercher(yytext,"Mot cle","","",2); yycolumn += yyleng;}
"const"        { Rechercher(yytext,"Mot cle","","",2); yycolumn += yyleng;}
"if"           { Rechercher(yytext,"Mot cle","","",2); yycolumn += yyleng;}
"then"         { Rechercher(yytext,"Mot cle","","",2); yycolumn += yyleng;}
"else"         { Rechercher(yytext,"Mot cle","","",2); yycolumn += yyleng;}
"endIf"        { Rechercher(yytext,"Mot cle","","",2); yycolumn += yyleng;}
"loop while"   { Rechercher(yytext,"Mot cle","","",2); yycolumn += yyleng;}
"endloop"      { Rechercher(yytext,"Mot cle","","",2); yycolumn += yyleng;}
"for"          { Rechercher(yytext,"Mot cle","","",2); yycolumn += yyleng;}
"in"           { Rechercher(yytext,"Mot cle","","",2); yycolumn += yyleng;}
"to"           { Rechercher(yytext,"Mot cle","","",2); yycolumn += yyleng;}
"endfor"       { Rechercher(yytext,"Mot cle","","",2); yycolumn += yyleng;}
"out"          { Rechercher(yytext,"Mot cle","","",2); yycolumn += yyleng;}
"integer"      { Rechercher(yytext,"Mot cle","","",2); yycolumn += yyleng;}
"float"        { Rechercher(yytext,"Mot cle","","",2); yycolumn += yyleng;}

{idf}          { yylval.str = strdup(yytext); 
                 if(yyleng > 14) {printf("erreur lexicale : idf trop long\n");} 
                    else {  yycolumn += yyleng;
                            Rechercher(yytext,"IDF","","",1);
                            return idf;}}
{integer}      { yylval.integer= atoi(yytext);
                   if (yylval.integer > 32768 || yylval.integer < -32768) {
                    printf("erreur lexicale à la ligne %d, colonne %d : le chiffre n'appartient pas à [-32765 , 32768 ]\n", yylineno, yycolumn);
                    exit(1);
                } else {
                    yycolumn += yyleng;
                    return entier;
                }}
{float}        { yylval.real= atof(yytext); yycolumn += yyleng;return reel;}


{commentaireOneLine}   {}
{commentaireMultiLine} {}


[ \t]+        { yycolumn += yyleng;}
\n            { yycolumn=1 ;}
.             { printf("Erreur lexicale a la ligne %d et colonne %d: '%s'", yylineno,yycolumn, yytext); }

%%
