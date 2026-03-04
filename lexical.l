%{
#include <stdio.h>
%}

%option yylineno

idf                   [a-z]([a-z0-9]|_[a-z0-9]){0,13}
integer               \(([+-][0-9]+)\)|[0-9]+
float                  \(([+-][0-9]+\.[0-9]+)\)|[0-9]+\.[0-9]+
commentaireOneLine    %%.* 
commentaireMultiLine  "//*"(.|\n)*"*//"

%%


";"           { printf("; "); }
":"           { printf(": "); }
"|"           { printf("| "); }
"{"           { printf("{ "); }
"}"           { printf("} "); }
"["           { printf("[ "); }
"]"           { printf("] "); }
"("           { printf("( "); }
")"           { printf(") "); }


"<-"          { printf("<- "); }
"+"           { printf("+ "); }
"-"           { printf("- "); }
"*"           { printf("* "); }
"/"           { printf("/ "); }
"<="          { printf("<= "); }
">="          { printf(">= "); }
"<"           { printf("< "); }
">"           { printf("> "); }
"=="          { printf("== "); }
"="           { printf("= "); }
"!="          { printf("!= "); }
"AND"         { printf("AND "); }
"OR"          { printf("OR "); }


"Setup"        { printf("Setup "); }
"BeginProject" { printf("BeginProject "); }
"Run"          { printf("Run "); }
"EndProject"   { printf("EndProject "); }
"define"       { printf("define "); }
"const"        { printf("const "); }
"if"           { printf("if "); }
"then"         { printf("then "); }
"else"         { printf("else "); }
"endIf"        { printf("endIf "); }
"loop while"   { printf("loop while "); }
"endloop"      { printf("endloop "); }
"for"          { printf("for "); }
"in"           { printf("in "); }
"to"           { printf("to "); }
"endfor"       { printf("endfor "); }
"out"          { printf("out "); }
"integer"      { printf("integer "); }
"float"         { printf("float "); }

{idf}          { printf("%s ", yytext); }
{integer}      { printf("%s ", yytext); }
{float}         { printf("%s ", yytext); }


{commentaireOneLine}   {}
{commentaireMultiLine} {}


[ \t]+        {}
\n            { printf("\n"); }
.             { printf("Erreur lexicale a la ligne %d: '%s'", yylineno, yytext); }

%%

int main(){
    yylex();
    return 0;
}