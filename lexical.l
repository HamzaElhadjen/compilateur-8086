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
commentaire    %%.* 
commentaireplus  "//*"(.|\n)*"*//"

%%


";"           { Rechercher(yytext,"Separateur","","",3); yycolumn += yyleng; return semicolon;}
":"           { Rechercher(yytext,"Separateur","","",3); yycolumn += yyleng; return colon;}
"|"           { Rechercher(yytext,"Separateur","","",3); yycolumn += yyleng; return pipe;}
"{"           { Rechercher(yytext,"Separateur","","",3); yycolumn += yyleng; return lbrace;}
"}"           { Rechercher(yytext,"Separateur","","",3); yycolumn += yyleng; return rbrace;}
"["           { Rechercher(yytext,"Separateur","","",3); yycolumn += yyleng; return lbracket;}
"]"           { Rechercher(yytext,"Separateur","","",3); yycolumn += yyleng; return rbracket;}
"("           { Rechercher(yytext,"Separateur","","",3); yycolumn += yyleng; return lparen;}
")"           { Rechercher(yytext,"Separateur","","",3); yycolumn += yyleng; return rparen;}


"<-"          { Rechercher(yytext,"Separateur","","",3); yycolumn += yyleng; return assign_arrow;}
"+"           { Rechercher(yytext,"Separateur","","",3); yycolumn += yyleng; return plus;}
"-"           { Rechercher(yytext,"Separateur","","",3); yycolumn += yyleng; return minus;}
"*"           { Rechercher(yytext,"Separateur","","",3); yycolumn += yyleng; return multiply;}
"/"           { Rechercher(yytext,"Separateur","","",3); yycolumn += yyleng; return divide;}
"<="          { Rechercher(yytext,"Separateur","","",3); yycolumn += yyleng; return less_equal;}
">="          { Rechercher(yytext,"Separateur","","",3); yycolumn += yyleng; return greater_equal;}
"<"           { Rechercher(yytext,"Separateur","","",3); yycolumn += yyleng; return less_than;}
">"           { Rechercher(yytext,"Separateur","","",3); yycolumn += yyleng; return greater_than;}
"=="          { Rechercher(yytext,"Separateur","","",3); yycolumn += yyleng; return equal_equal;}
"="           { Rechercher(yytext,"Separateur","","",3); yycolumn += yyleng; return equal;}
"!="          { Rechercher(yytext,"Separateur","","",3); yycolumn += yyleng; return not_equal;}
","           { Rechercher(yytext,"Separateur","","",3); yycolumn += yyleng; return comma; }


"Setup"        { Rechercher(yytext,"Mot cle","","",2); yycolumn += yyleng; return kw_setup;}
"BeginProject" { Rechercher(yytext,"Mot cle","","",2); yycolumn += yyleng; return kw_begin_project;}
"Run"          { Rechercher(yytext,"Mot cle","","",2); yycolumn += yyleng; return kw_run;}
"EndProject"   { Rechercher(yytext,"Mot cle","","",2); yycolumn += yyleng; return kw_end_project;}
"define"       { Rechercher(yytext,"Mot cle","","",2); yycolumn += yyleng; return kw_define; }
"const"        { Rechercher(yytext,"Mot cle","","",2); yycolumn += yyleng; return kw_const;}
"if"           { Rechercher(yytext,"Mot cle","","",2); yycolumn += yyleng; return kw_if;}
"then"         { Rechercher(yytext,"Mot cle","","",2); yycolumn += yyleng; return kw_then;}
"else"         { Rechercher(yytext,"Mot cle","","",2); yycolumn += yyleng; return kw_else; }
"endIf"        { Rechercher(yytext,"Mot cle","","",2); yycolumn += yyleng; return kw_end_if; }
"loop while"   { Rechercher(yytext,"Mot cle","","",2); yycolumn += yyleng; return kw_loop_while;}
"endloop"      { Rechercher(yytext,"Mot cle","","",2); yycolumn += yyleng; return kw_end_loop;}
"for"          { Rechercher(yytext,"Mot cle","","",2); yycolumn += yyleng; return kw_for; }
"in"           { Rechercher(yytext,"Mot cle","","",2); yycolumn += yyleng; return kw_in;}
"to"           { Rechercher(yytext,"Mot cle","","",2); yycolumn += yyleng; return kw_to; }
"endfor"       { Rechercher(yytext,"Mot cle","","",2); yycolumn += yyleng; return kw_end_for;}
"OUTPUT"       { Rechercher(yytext,"Mot cle","","",2); yycolumn += yyleng; return kw_out;}
"INPUT"        { Rechercher(yytext,"Mot cle","","",2); yycolumn += yyleng; return kw_input;}
"AND"          { Rechercher(yytext,"Mot cle","","",2); yycolumn += yyleng; return kw_and; }
"OR"           { Rechercher(yytext,"Mot cle","","",2); yycolumn += yyleng; return kw_or;}
"NOT"          { Rechercher(yytext,"Mot cle","","",2); yycolumn += yyleng; return kw_not;}
"integer"      { Rechercher(yytext,"Mot cle","","",2); yycolumn += yyleng; return kw_integer;}
"float"        { Rechercher(yytext,"Mot cle","","",2); yycolumn += yyleng; return kw_float;}

{idf}          { yylval.str = strdup(yytext); 
                 if(yyleng > 14) {printf("erreur lexicale : idf trop long\n");} 
                    else {  yycolumn += yyleng;
                            Rechercher(yytext,"IDF","","",1);
                return identifier;}}
{integer} {
    char temp[50];

    if (yytext[0] == '(') {
        strncpy(temp, yytext + 1, yyleng - 2);
        temp[yyleng - 2] = '\0';
        yylval.entier = atoi(temp);
    } else {
        yylval.entier = atoi(yytext);
    }

    if (yylval.entier > 32767 || yylval.entier < -32768) {
        printf("erreur lexicale a la ligne %d, colonne %d : le chiffre n'appartient pas a [-32768 , 32767]\n",
               yylineno, yycolumn);
        exit(1);
    } else {
        yycolumn += yyleng;
        return int_literal;
    }
}
{float} {
    char temp[50];
    
    if (yytext[0] == '(' ) {
        strncpy(temp, yytext + 1, yyleng - 2);
        temp[yyleng - 2] = '\0';
        yylval.numvrg = atof(temp);
    } else {
        yylval.numvrg = atof(yytext);
    }

    yycolumn += yyleng;
    return float_literal;
}
{chaine}    {
                yycolumn += yyleng;
                yylval.str = strdup(yytext);
                return string_literal;
            }


{commentaire}   {}
{commentaireplus} {}


[ \t]+        { yycolumn += yyleng;}
\n            { yycolumn=1 ;}
.             { printf("Erreur lexicale a la ligne %d et colonne %d: '%s'", yylineno,yycolumn, yytext); }

%%
