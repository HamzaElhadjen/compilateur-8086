%{
    #include<stdio.h>
    #include<stdlib.h>
    int yylex();
    extern int yylineno; 
    extern int yycolumn;
    void yyerror(char* s);
    char current_type[20];
%}


%union {
    int entier;
    float numvrg;
    char* str;
    struct { char* ids[50]; int count; } idlist;
    struct { char value[50]; char type[10]; } val;
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
%type <idlist> LISTE_IDF
%token <str>    mc_integer mc_float
%token <str>    CHAINE

%type <val> VALEUR
%token <entier> CST_INT
%token <numvrg> CST_FLOAT


%left mc_OR
%left mc_AND
%right mc_NON
%left LT GT LEQ GEQ EQ NEQ
%left PLUS MINS
%left MULT DIV


%start PROGRAMME

%%


PROGRAMME
    : mc_BeginProject IDF PVG
      mc_Setup DPT PARTIE_DEC
      mc_Run DPT ACCO PARTIE_INSTR ACCF
      mc_EndProject PVG
      {
          printf("\n>>> Programme '%s' syntaxiquement correct.\n", $2);
          YYACCEPT;
      }
    ;

PARTIE_DEC: DECLARATION PARTIE_DEC 
            | ;


DECLARATION
    : DEC_VAR
    | DEC_CONST
    | DEC_TAB
    ;

DEC_VAR
    : mc_define IDF DPT TYPE PVG
        {   
            // check de double declaration
            if(updateType($2, current_type) == -1)
                printf("Erreur semantique ligne %d : double declaration de %s\n", yylineno, $2);  
        }
    | mc_define LISTE_IDF DPT TYPE PVG
        {   
            // check de double declaration
            int i;
            for(i = 0; i < $2 .count; i++) {
                if(updateType($2 .ids[i], current_type) == -1)
                    printf("Erreur semantique ligne %d : double declaration de %s\n", yylineno, $2 .ids[i]);
            }
        }
    | mc_define IDF DPT TYPE EGAL VALEUR PVG
        {   
            // check de double declaration
            if(updateType($2, current_type) == -1)
                printf("Erreur semantique ligne %d : double declaration de %s\n", yylineno, $2);
            // check de type mismatch
            else if(checkTypeMismatch(current_type, $6 .type)){
                printf("Erreur semantique ligne %d : incompatibilite de type pour %s\n",
                    yylineno, $2);
            }else updateVal($2, $6 .value);

            
        }
    ;

DEC_CONST
    : mc_const IDF DPT TYPE EGAL VALEUR PVG {
        // check double declaration
        if(updateType($2, current_type) == -1)
            printf("Erreur semantique ligne %d : double declaration de %s\n", yylineno, $2);
        // check de type mismatch
        else if(checkTypeMismatch(current_type, $6 .type)){
                printf("Erreur semantique ligne %d : incompatibilite de type pour %s\n",
                    yylineno, $2);
            }else updateVal($2, $6 .value); 
    }
;

DEC_TAB
    : mc_define IDF DPT CROV TYPE PVG CST_INT CRMF PVG
      {
          if(updateType($2, current_type) == -1) printf("Erreur semantique ligne %d : double declaration de %s\n", yylineno, $2);
            else if ($7 <= 0)
              printf("Erreur_Semantique, ligne %d, taille du tableau '%s' doit etre > 0\n",
                     yylineno, $2);
            else{
                char tailleStr[20];
                sprintf(tailleStr, "%d", $7);
                updateCode($2, "Tableau");
                updateType($2, current_type);
                updateVal($2, tailleStr);
            }
      }
    ;


LISTE_IDF
    : IDF PIPE LISTE_IDF
        {
            $$ = $3;  
            $$ .ids[$$ .count++] = strdup($1);
        }
    | IDF
        {
            $$ .count = 1;
            $$ .ids[0] = strdup($1);
        }
    ;



TYPE
    : mc_integer {strcpy(current_type,"integer");}
    | mc_float  {strcpy(current_type,"float");}
    ;

VALEUR
  : CST_INT {
        sprintf($$.value, "%d", $1);
        strcpy($$.type, "integer");
    }
  | CST_FLOAT {
        sprintf($$.value, "%f", $1);
        strcpy($$.type, "float");
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
    { if( checkUndeclared($1)==-1 ) printf("Erreur semantique ligne %d : variable non declaree %s\n", yylineno, $1);}
    | IDF CROV CST_INT CRMF AFF EXPR PVG { if( checkUndeclared($1)==-1 ) printf("Erreur semantique ligne %d : variable non declaree %s\n", yylineno, $1);
                                            else{ if(checkTableIndex($1,$3) == -1) printf("Erreur semantique ligne %d: index %d hors limites pour le tableau '%s'.\n",yylineno, $3, $1);}}
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
    : mc_for IDF mc_in CST_INT mc_to CST_INT ACCO PARTIE_INSTR ACCF mc_endfor PVG { if( checkUndeclared($2)==-1 ) printf("Erreur semantique ligne %d : variable non declaree %s\n", yylineno, $2);}
    ;

INST_IN
    : mc_in PARO IDF PARF PVG { if( checkUndeclared($3)==-1 ) printf("Erreur semantique ligne %d : variable non declaree %s\n", yylineno, $3);}
    ;

INST_OUT
    : mc_out PARO LISTE_OUT PARF PVG
    ;

LISTE_OUT
    : CHAINE IDF
    | CHAINE
    | IDF
    ;


EXPR
    : EXPR PLUS EXPR
    | EXPR MINS EXPR
    | EXPR MULT EXPR
    | EXPR DIV EXPR
    | MINS EXPR
    | PARO EXPR PARF
    | IDF { if( checkUndeclared($1)==-1 ) printf("Erreur semantique ligne %d : variable non declaree %s\n", yylineno, $1);}
    | IDF CROV CST_INT CRMF { if( checkUndeclared($1)==-1 ) printf("Erreur semantique ligne %d : variable non declaree %s\n", yylineno, $1);
                                else{ if(checkTableIndex($1,$3) == -1) printf("Erreur semantique ligne %d: index %s hors limites pour le tableau '%s'.\n",yylineno, $3, $1);}}
    | CST_INT
    | CST_FLOAT


COND
    : EXPR LT  EXPR  
    | EXPR GT  EXPR  
    | EXPR LEQ EXPR  
    | EXPR GEQ EXPR  
    | EXPR EQ  EXPR  
    | EXPR NEQ EXPR  
    | PARO COND mc_AND COND PARF 
    | PARO COND mc_OR  COND PARF 
    | mc_NON PARO COND PARF      
    | PARO COND PARF             
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