%{
#include<stdio.h>
#include"TS.h"
#include"syntax.tab.h"
extern YYSTYPE yylval;
int yycolumn = 1;
%}
%option yylineno
chaine      \"[^\"]*\"
idf                   [a-z]([a-z0-9]|_[a-z0-9])*
integer               \(([+-][0-9]+)\)|[0-9]+
float                  \(([+-][0-9]+\.[0-9]+)\)|[0-9]+\.[0-9]+
commentaireOneLine    %%.* 
commentaireMultiLine  "//*"(.|\n)*"*//"

%%


";"           { Rechercher(yytext,"Separateur","","",3); yycolumn += yyleng; return PVG;}
":"           { Rechercher(yytext,"Separateur","","",3); yycolumn += yyleng; return DPT;}
"|"           { Rechercher(yytext,"Separateur","","",3); yycolumn += yyleng; return PIPE;}
"{"           { Rechercher(yytext,"Separateur","","",3); yycolumn += yyleng; return ACCO;}
"}"           { Rechercher(yytext,"Separateur","","",3); yycolumn += yyleng; return ACCF;}
"["           { Rechercher(yytext,"Separateur","","",3); yycolumn += yyleng; return CROV;}
"]"           { Rechercher(yytext,"Separateur","","",3); yycolumn += yyleng; return CRMF;}
"("           { Rechercher(yytext,"Separateur","","",3); yycolumn += yyleng; return PARO;}
")"           { Rechercher(yytext,"Separateur","","",3); yycolumn += yyleng; return PARF;}


"<-"          { Rechercher(yytext,"Separateur","","",3); yycolumn += yyleng; return AFF;}
"+"           { Rechercher(yytext,"Separateur","","",3); yycolumn += yyleng; return PLUS;}
"-"           { Rechercher(yytext,"Separateur","","",3); yycolumn += yyleng; return MINS;}
"*"           { Rechercher(yytext,"Separateur","","",3); yycolumn += yyleng; return MULT;}
"/"           { Rechercher(yytext,"Separateur","","",3); yycolumn += yyleng; return DIV;}
"<="          { Rechercher(yytext,"Separateur","","",3); yycolumn += yyleng; return LEQ;}
">="          { Rechercher(yytext,"Separateur","","",3); yycolumn += yyleng; return GEQ;}
"<"           { Rechercher(yytext,"Separateur","","",3); yycolumn += yyleng; return LT;}
">"           { Rechercher(yytext,"Separateur","","",3); yycolumn += yyleng; return GT;}
"=="          { Rechercher(yytext,"Separateur","","",3); yycolumn += yyleng; return EQ;}
"="           { Rechercher(yytext,"Separateur","","",3); yycolumn += yyleng; return EGAL;}
"!="          { Rechercher(yytext,"Separateur","","",3); yycolumn += yyleng; return NEQ;}



"Setup"        { Rechercher(yytext,"Mot cle","","",2); yycolumn += yyleng; return mc_Setup;}
"BeginProject" { Rechercher(yytext,"Mot cle","","",2); yycolumn += yyleng; return mc_BeginProject;}
"Run"          { Rechercher(yytext,"Mot cle","","",2); yycolumn += yyleng; return mc_Run;}
"EndProject"   { Rechercher(yytext,"Mot cle","","",2); yycolumn += yyleng; return mc_EndProject;}
"define"       { Rechercher(yytext,"Mot cle","","",2); yycolumn += yyleng; return mc_define; }
"const"        { Rechercher(yytext,"Mot cle","","",2); yycolumn += yyleng; return mc_const;}
"if"           { Rechercher(yytext,"Mot cle","","",2); yycolumn += yyleng; return mc_if;}
"then"         { Rechercher(yytext,"Mot cle","","",2); yycolumn += yyleng; return mc_then;}
"else"         { Rechercher(yytext,"Mot cle","","",2); yycolumn += yyleng; return mc_else; }
"endIf"        { Rechercher(yytext,"Mot cle","","",2); yycolumn += yyleng; return mc_endIf; }
"loop while"   { Rechercher(yytext,"Mot cle","","",2); yycolumn += yyleng; return mc_loopwhile;}
"endloop"      { Rechercher(yytext,"Mot cle","","",2); yycolumn += yyleng; return mc_endloop;}
"for"          { Rechercher(yytext,"Mot cle","","",2); yycolumn += yyleng; return mc_for; }
"in"           { Rechercher(yytext,"Mot cle","","",2); yycolumn += yyleng; return mc_in;}
"to"           { Rechercher(yytext,"Mot cle","","",2); yycolumn += yyleng; return mc_to; }
"endfor"       { Rechercher(yytext,"Mot cle","","",2); yycolumn += yyleng; return mc_endfor;}
"out"          { Rechercher(yytext,"Mot cle","","",2); yycolumn += yyleng; return mc_out;}
"AND"          { Rechercher(yytext,"Mot cle","","",2); yycolumn += yyleng; return mc_AND; }
"OR"           { Rechercher(yytext,"Mot cle","","",2); yycolumn += yyleng; return mc_OR;}
"integer"      { Rechercher(yytext,"Mot cle","","",2); yycolumn += yyleng; return mc_integer;}
"float"        { Rechercher(yytext,"Mot cle","","",2); yycolumn += yyleng; return mc_float;}

{idf}          { yylval.str = strdup(yytext); 
                 if(yyleng > 14) {printf("erreur lexicale : idf trop long\n");} 
                    else {  yycolumn += yyleng;
                            Rechercher(yytext,"IDF","","",1);
                            return IDF;}}
{integer}      { yylval.entier= atoi(yytext);
                   if (yylval.entier > 32768 || yylval.entier < -32768) {
                    printf("erreur lexicale à la ligne %d, colonne %d : le chiffre n'appartient pas à [-32765 , 32768 ]\n", yylineno, yycolumn);
                    exit(1);
                } else {
                    yycolumn += yyleng;
                    return CST_INT;
                }}
{float}        { yylval.numvrg= atof(yytext); yycolumn += yyleng;return CST_FLOAT;}
{chaine}    {
                yycolumn += yyleng;
                yylval.str = strdup(yytext);
                return CHAINE;
            }


{commentaireOneLine}   {}
{commentaireMultiLine} {}


[ \t]+        { yycolumn += yyleng;}
\n            { yycolumn=1 ;}
.             { printf("Erreur lexicale a la ligne %d et colonne %d: '%s'", yylineno,yycolumn, yytext); }

%%
