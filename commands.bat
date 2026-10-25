@echo off
del lexical.exe 2>nul
flex lexical.l || exit /b
bison -d syntax.y || exit /b
gcc lex.yy.c syntax.tab.c -lfl -o lexical || exit /b
echo === Execution ===
lexical.exe < test5.txt