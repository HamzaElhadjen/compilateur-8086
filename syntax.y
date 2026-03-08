%{
    #include<stdio.h>
    #include<stdlib.h>
    int yylex();
    extern int yylineno; 
    extern int col;
    void yyerror(char* s);
    char current_type[20] = "";


    
%}

%union{
    int entier;
    float numvrg;
    char* str;
}

%token mc_BeginProject mc_EndProject mc_Setup mc_Run
%token mc_define mc_const
%token mc_if mc_then mc_else mc_endIf
%token mc_loopwhile mc_endloop
%token mc_for mc_in mc_to mc_endfor
%token mc_out
%token mc_AND mc_OR mc_NON
%token PVG DPT PIPE ACCO ACCF CROV CRMF PARO PARF
%token AFF PLUS MINS MULT DIV LEQ GEQ LT GT EQ NEQ EGAL

%token <str>    IDF
%token <str>    mc_integer mc_float
%token <entier> CST_INT
%token <numvrg> CST_FLOAT
%token <str>    CHAINE

%type <str> TYPE EXPR COND

%left mc_OR
%left mc_AND
%right mc_NON
%left LT GT LEQ GEQ EQ NEQ
%left PLUS MINS
%left MULT DIV
%right UMINUS

%start PROGRAMME

%%


PROGRAMME
    : mc_BeginProject IDF PVG
      mc_Setup DPT PARTIE_DEC
      mc_Run DPT ACCO PARTIE_INSTR ACCF
      mc_EndProject PVG
      {
          printf("\n>>> Programme '%s' syntaxiquement correct.\n", $2);
          afficher();
          YYACCEPT;
      }
    ;


PARTIE_DEC: LISTE_DEC | ;

LISTE_DEC
    : LISTE_DEC DECLARATION
    | DECLARATION
    ;

DECLARATION
    : DEC_VAR
    | DEC_TAB
    | DEC_CONST
    ;

DEC_VAR
    : mc_define LISTE_IDF DPT TYPE PVG
    | mc_define LISTE_IDF DPT TYPE EGAL VALEUR PVG
    ;

LISTE_IDF
    : LISTE_IDF PIPE IDF_DECL
    | IDF_DECL
    ;

IDF_DECL
    : IDF
      {
          if(checkNoDuplicate($1)==-1) printf("Erreur_Semantique, ligne %d, colonne %d, entite '%s' "
                "(variable deja declaree)\n", yylineno, col, $1);
          updateCode($1, "Var");
          updateType($1, current_type);
      }
    ;

TYPE
    : mc_integer { strcpy(current_type, "integer"); $$ = "integer"; }
    | mc_float   { strcpy(current_type, "float");   $$ = "float";   }
    ;

VALEUR
    : CST_INT
    | CST_FLOAT
    | PARO PLUS CST_INT   PARF
    | PARO MINS CST_INT   PARF
    | PARO PLUS CST_FLOAT PARF
    | PARO MINS CST_FLOAT PARF
    ;

DEC_TAB
    : mc_define IDF DPT CROV TYPE PVG CST_INT CRMF PVG
      {
          if(checkNoDuplicate($2)==-1) printf("Erreur_Semantique, ligne %d, colonne %d, entite '%s' "
                "(variable deja declaree)\n", yylineno, col, $2);
          updateCode($2, "Tableau");
          updateType($2, current_type);
          if ($7 <= 0)
              printf("Erreur_Semantique, ligne %d, taille du tableau '%s' doit etre > 0\n",
                     yylineno, $2);
      }
    ;


DEC_CONST
    : mc_const IDF DPT TYPE EGAL VALEUR PVG
      {
          if(checkNoDuplicate($2)==-1) printf("Erreur_Semantique, ligne %d, colonne %d, entite '%s' "
                "(variable deja declaree)\n", yylineno, col, $2);
          updateCode($2, "Const");
          updateType($2, current_type);
      }
    ;

PARTIE_INSTR: LISTE_INSTR|;

LISTE_INSTR
    : LISTE_INSTR INSTRUCTION
    | INSTRUCTION
    ;

INSTRUCTION
    : INST_AFF
    | INST_COND
    | INST_LOOP_WHILE
    | INST_FOR
    | INST_IN
    | INST_OUT
    ;

INST_AFF
    : IDF AFF EXPR PVG
      { if(checkDeclared($1)==-1) printf("Erreur_Semantique, ligne %d, colonne %d, entite '%s' "
                "(variable non declaree)\n", yylineno, col, $1);}
    | IDF CROV EXPR CRMF AFF EXPR PVG
      { if(checkDeclared($1)==-1) printf("Erreur_Semantique, ligne %d, colonne %d, entite '%s' "
                "(variable non declaree)\n", yylineno, col, $1); }
    ;

INST_COND
    : mc_if PARO COND PARF mc_then DPT
      ACCO PARTIE_INSTR ACCF
      mc_else ACCO PARTIE_INSTR ACCF
      mc_endIf PVG
    | mc_if PARO COND PARF mc_then DPT
      ACCO PARTIE_INSTR ACCF
      mc_endIf PVG
    ;


INST_LOOP_WHILE
    : mc_loopwhile PARO COND PARF
      ACCO PARTIE_INSTR ACCF
      mc_endloop PVG
    ;

INST_FOR
    : mc_for IDF mc_in VALEUR mc_to VALEUR
      ACCO PARTIE_INSTR ACCF
      mc_endfor PVG
      { if(checkDeclared($2)==-1) printf("Erreur_Semantique, ligne %d, colonne %d, entite '%s' "
                "(variable non declaree)\n", yylineno, col, $2); }
    ;

INST_IN
    : mc_in PARO IDF PARF PVG
      { if(checkDeclared($3)==-1) printf("Erreur_Semantique, ligne %d, colonne %d, entite '%s' "
                "(variable non declaree)\n", yylineno, col, $3); }
    ;

INST_OUT
    : mc_out PARO LISTE_OUT PARF PVG
    ;

LISTE_OUT
    : LISTE_OUT PIPE OUT_ARG
    | OUT_ARG
    ;

OUT_ARG
    : CHAINE
    | EXPR
    ;

EXPR
    : EXPR PLUS EXPR   { $$ = "expr"; }
    | EXPR MINS EXPR   { $$ = "expr"; }
    | EXPR MULT EXPR   { $$ = "expr"; }
    | EXPR DIV  EXPR   { $$ = "expr"; }
    | MINS EXPR %prec UMINUS { $$ = "expr"; }
    | PARO EXPR PARF   { $$ = $2; }
    | IDF
      {
          if(checkDeclared($1)==-1) printf("Erreur_Semantique, ligne %d, colonne %d, entite '%s' "
                "(variable non declaree)\n", yylineno, col, $1);
          $$ = $1;
      }
    | IDF CROV EXPR CRMF
      {
          if(checkDeclared($1)==-1) printf("Erreur_Semantique, ligne %d, colonne %d, entite '%s' "
                "(variable non declaree)\n", yylineno, col, $1);
          $$ = $1;
      }
    | CST_INT          { $$ = "integer"; }
    | CST_FLOAT        { $$ = "float";   }
    | PARO PLUS CST_INT   PARF { $$ = "integer"; }
    | PARO MINS CST_INT   PARF { $$ = "integer"; }
    | PARO PLUS CST_FLOAT PARF { $$ = "float"; }
    | PARO MINS CST_FLOAT PARF { $$ = "float"; }
    ;

COND
    : EXPR LT  EXPR  { $$ = "cond"; }
    | EXPR GT  EXPR  { $$ = "cond"; }
    | EXPR LEQ EXPR  { $$ = "cond"; }
    | EXPR GEQ EXPR  { $$ = "cond"; }
    | EXPR EQ  EXPR  { $$ = "cond"; }
    | EXPR NEQ EXPR  { $$ = "cond"; }
    | PARO COND mc_AND COND PARF { $$ = "cond"; }
    | PARO COND mc_OR  COND PARF { $$ = "cond"; }
    | mc_NON PARO COND PARF      { $$ = "cond"; }
    | PARO COND PARF             { $$ = $2;     }
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