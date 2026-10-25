%{
    #include<stdio.h>
    #include<stdlib.h>
    #include<string.h>

    /* Declarations forward pour les fonctions de TS.h */
    char* idf_type(char entite[]);
    char* newTemp();
    void quadr(char opr[], char op1[], char op2[], char res[]);
    void updateQuad(int num_quad, int colon_quad, char val[]);

    /* Variables globales definies dans TS.h (qc) */
    extern int qc;

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
    struct { 
        char value[50];   
        char type[10];    
        char result[20];  
    } val;
    int num;              /* pour stocker qc a un instant donne */
}

%token kw_begin_project kw_end_project kw_setup kw_run
%token kw_define kw_const
%token kw_if kw_then kw_else kw_end_if
%token kw_loop_while kw_end_loop
%token kw_for kw_in kw_to kw_end_for
%token kw_out kw_input
%token kw_and kw_or kw_not
%token assign_arrow plus minus multiply divide less_equal greater_equal less_than greater_than equal_equal not_equal equal
%token semicolon colon comma pipe lbrace rbrace lbracket rbracket lparen rparen

%token <str>    identifier
%type  <idlist> LISTE_IDF
%token <str>    kw_integer kw_float
%token <str>    string_literal     
%type  <val>    VALEUR EXPR
%token <entier> int_literal
%token <numvrg> float_literal
%type <num> M_QUAD N_BR M_LOOP

%left  kw_or
%left  kw_and
%right kw_not
%left  less_than greater_than less_equal greater_equal equal_equal not_equal
%left  plus minus
%left  multiply divide


%start PROGRAMME

%%

PROGRAMME
    : kw_begin_project identifier semicolon
        { updateCode($2, "Programme"); }
      kw_setup colon PARTIE_DEC
      kw_run colon lbrace PARTIE_INSTR rbrace
      kw_end_project semicolon
      {
          printf("\n>>> Programme '%s' syntaxiquement correct.\n", $2);
          YYACCEPT;
      }
    ;

PARTIE_DEC
    : DECLARATION PARTIE_DEC 
    | 
    ;

DECLARATION
    : DEC_VAR
    | DEC_CONST
    | DEC_TAB
    ;

DEC_VAR
    : kw_define identifier colon TYPE semicolon
        {   
            if(updateType($2, current_type) == -1)
                printf("Erreur Semantique, ligne %d, colonne %d : double declaration de '%s'\n", yylineno, yycolumn, $2);
            else 
                updateCode($2, "Variable");
        }
    | kw_define LISTE_IDF colon TYPE semicolon
        {   
            int i; 
            for(i = 0; i < $2.count; i++) {
                if(updateType($2.ids[i], current_type) == -1)
                    printf("Erreur Semantique, ligne %d, colonne %d : double declaration de '%s'\n", yylineno, yycolumn, $2.ids[i]);
                else
                    updateCode($2.ids[i], "Variable");
            }
        }
    | kw_define identifier colon TYPE equal VALEUR semicolon
        {   
            if(updateType($2, current_type) == -1)
                printf("Erreur Semantique, ligne %d, colonne %d : double declaration de '%s'\n", yylineno, yycolumn, $2);
            else if(checkTypeMismatch(current_type, $6.type))
                printf("Erreur Semantique, ligne %d, colonne %d : incompatibilite de type pour '%s'\n", yylineno, yycolumn, $2);
            else {
                updateCode($2, "Variable");
                updateVal($2, $6.value);
            }
        }
    ;

DEC_CONST
    : kw_const identifier colon TYPE equal VALEUR semicolon 
        {
            if(updateType($2, current_type) == -1)
                printf("Erreur Semantique, ligne %d, colonne %d : double declaration de '%s'\n", yylineno, yycolumn, $2);
            else if(checkTypeMismatch(current_type, $6.type))
                printf("Erreur Semantique, ligne %d, colonne %d : incompatibilite de type pour '%s'\n", yylineno, yycolumn, $2);
            else { 
                updateCode($2, "Constante");
                updateVal($2, $6.value); 
            }
        }
    ;

DEC_TAB
    : kw_define identifier colon lbracket TYPE semicolon int_literal rbracket semicolon
        {
            if(updateType($2, current_type) == -1) 
                printf("Erreur Semantique, ligne %d, colonne %d : double declaration de '%s'\n", yylineno, yycolumn, $2);
            else if ($7 <= 0)
                printf("Erreur Semantique, ligne %d, colonne %d : taille du tableau '%s' doit etre > 0\n",
                       yylineno, yycolumn, $2);
            else {
                char tailleStr[20];
                sprintf(tailleStr, "%d", $7);
                updateCode($2, "Tableau");
                updateType($2, current_type);
                updateVal($2, tailleStr);
            }
        }
    ;


LISTE_IDF
    : identifier pipe LISTE_IDF
        {
            $$ = $3;  
            $$.ids[$$.count++] = strdup($1);
        }
    | identifier
        {
            $$.count = 1;
            $$.ids[0] = strdup($1);
        }
    ;



TYPE
    : kw_integer {strcpy(current_type,"integer");}
    | kw_float   {strcpy(current_type,"float");}
    ;

VALEUR
    : int_literal {
        sprintf($$.value, "%d", $1);
        strcpy($$.type, "integer");
    }
    | float_literal {
        sprintf($$.value, "%f", $1);
        strcpy($$.type, "float");
    }
    ;



PARTIE_INSTR
    : LISTE_INSTR
    | 
    ;

LISTE_INSTR
    : LISTE_INSTR INSTRUCTION
    | INSTRUCTION
    ;

INSTRUCTION
    : INST_AFF
    | INST_COND
    | INST_LOOP_WHILE
    | INST_FOR
    | INST_INPUT
    | INST_OUT
    ;

INST_AFF
    : identifier assign_arrow EXPR semicolon
        {   
            if(checkUndeclared($1) == -1) 
                printf("Erreur Semantique, ligne %d, colonne %d : variable non declaree '%s'\n", yylineno, yycolumn, $1);
            else if (isConstante($1)) 
                printf("Erreur Semantique, ligne %d, colonne %d : modification d'une constante '%s'\n", yylineno, yycolumn, $1); 
            else if (checkTypeMismatch(idf_type($1), $3.type)) 
                printf("Erreur Semantique, ligne %d, colonne %d : incompatibilite de type dans l'affectation de '%s'\n",
                       yylineno, yycolumn, $1);
            else {
                quadr("=", $3.result, "", $1);
            }
        }
    | identifier lbracket int_literal rbracket assign_arrow EXPR semicolon 
        { 
            if(checkUndeclared($1) == -1) 
                printf("Erreur Semantique, ligne %d, colonne %d : variable non declaree '%s'\n", yylineno, yycolumn, $1);
            else if(checkTableIndex($1, $3) == -1) 
                printf("Erreur Semantique, ligne %d, colonne %d : index %d hors limites pour '%s'\n", yylineno, yycolumn, $3, $1);
            else {
                char target[40];
                sprintf(target, "%s[%d]", $1, $3);
                quadr("=", $6.result, "", target);
            }
        }
    ;

/* ===== Markers pour le backpatching ===== */

M_QUAD
    :   /* vide : capture qc AVANT la prochaine generation */
        { $$ = qc; }
    ;

N_BR
    :   /* vide : genere d'abord BR, puis capture qc APRES */
        { 
            quadr("BR", "", "", "?");
            $$ = qc;     /* $$ = position juste apres le BR = debut du else */
        }
    ;

M_LOOP
    :   /* vide : capture qc AVANT la condition */
        { $$ = qc; }
    ;
/* ===== IF / ELSE avec backpatching ===== */

INST_COND
    : kw_if lparen COND rparen kw_then colon M_QUAD
        lbrace PARTIE_INSTR rbrace
        N_BR
        kw_else lbrace PARTIE_INSTR rbrace kw_end_if semicolon
        {
            /* $7  = M_QUAD  = position juste apres BZ (debut du then)
               $11 = N_BR    = position juste apres BR (debut du else)
               qc courant    = fin du else

               BZ se trouve a la position $7 - 1. Il doit sauter au debut du else = $11.
               BR se trouve a la position $11 - 1. Il doit sauter a la fin du if = qc.
            */
            char tmp[20];
            sprintf(tmp, "%d", $11);
            updateQuad($7 - 1, 4, tmp);    
            
            sprintf(tmp, "%d", qc);
            updateQuad($11 - 1, 4, tmp);    
        }
    | kw_if lparen COND rparen kw_then colon M_QUAD
        lbrace PARTIE_INSTR rbrace kw_end_if semicolon
        {
            /* Pas de else : patcher BZ avec qc (fin du if) */
            char tmp[20];
            sprintf(tmp, "%d", qc);
            updateQuad($7 - 1, 4, tmp);
        }
    ;


INST_LOOP_WHILE
    : kw_loop_while M_LOOP lparen COND rparen M_QUAD
      lbrace PARTIE_INSTR rbrace
      kw_end_loop semicolon
        {
            
            char tmp[20];
            
            /* Generer le BR de retour au debut de la boucle */
            sprintf(tmp, "%d", $2);
            quadr("BR", "", "", tmp);
            
            /* Patcher le BZ pour sortir de la boucle */
            sprintf(tmp, "%d", qc);
            updateQuad($6 - 1, 4, tmp);
        }
    ;

INST_FOR
    : kw_for identifier kw_in int_literal 
        {
            /* ACTION 1 : verifier idf + generer i <- val_init */
            if (checkUndeclared($2) == -1) {
                printf("Erreur Semantique, ligne %d, colonne %d : variable de boucle non declaree '%s'\n",
                       yylineno, yycolumn, $2);
                updateType($2, "integer");   /* evite cascade d'erreurs */
            }
            
            char valStr[20];
            sprintf(valStr, "%d", $4);
            quadr("=", valStr, "", $2);
        }
      kw_to int_literal
        {
            /* ACTION 2 : verifier bornes */
            if ($4 > $7)
                printf("Erreur Semantique, ligne %d, colonne %d : borne initiale (%d) superieure a la borne finale (%d) dans le for '%s'\n",
                       yylineno, yycolumn, $4, $7, $2);
        }
      M_LOOP
        {
            /* ACTION 3 : generer le test i <= val_limit et le BZ */
            char limStr[20];
            char* t = newTemp();
            sprintf(limStr, "%d", $7);
            quadr("<=", $2, limStr, t);
            quadr("BZ", t, "", "?");
        }
      lbrace PARTIE_INSTR rbrace kw_end_for semicolon
        {
            /* ACTION FINALE : generer l'increment i <- i + 1, BR de retour, et patcher le BZ */
            char tmp[20];
            char* t2 = newTemp();
            
            /* i <- i + 1 */
            quadr("+", $2, "1", t2);
            quadr("=", t2, "", $2);
            
            /* BR retour a M_LOOP ($9) */
            sprintf(tmp, "%d", $9);
            quadr("BR", "", "", tmp);
            
            /* Patcher BZ (situe juste apres le test = qc au moment de l'action 3)
               Le BZ est a la position ($9 + 2) - 1 = $9 + 1 
               Car l'action 3 genere 2 quadruplets apres $9 : le test et le BZ
            */
            sprintf(tmp, "%d", qc);
            updateQuad($9 + 1, 4, tmp);
        }
    ;

INST_INPUT
    : kw_input lparen identifier rparen semicolon 
        { 
            if (checkUndeclared($3) == -1)
                printf("Erreur Semantique, ligne %d, colonne %d : variable non declaree '%s'\n", yylineno, yycolumn, $3);
            else if (isConstante($3))
                printf("Erreur Semantique, ligne %d, colonne %d : saisie dans une constante '%s'\n",
                       yylineno, yycolumn, $3);
            else {
                quadr("READ", "", "", $3);
            }
        }
    ;

INST_OUT
    : kw_out lparen LISTE_OUT rparen semicolon
    ;

LISTE_OUT
    : ELEM_OUT
    | LISTE_OUT comma ELEM_OUT
    ;

ELEM_OUT
    : string_literal
        {
            quadr("WRITE", $1, "", "");
        }
    | identifier
        {
            if (checkUndeclared($1) == -1)
                printf("Erreur Semantique, ligne %d, colonne %d : variable non declaree '%s'\n", yylineno, yycolumn, $1);
            else
                quadr("WRITE", $1, "", "");
        }
    ;


EXPR
    : EXPR plus EXPR
        {
            char* t = newTemp();
            if (strcmp($1.type,"float")==0 || strcmp($3.type,"float")==0)
                strcpy($$.type, "float");
            else
                strcpy($$.type, "integer");
            strcpy($$.result, t);
            strcpy($$.value, "?");
            quadr("+", $1.result, $3.result, t);
        }
    | EXPR minus EXPR
        {
            char* t = newTemp();
            if (strcmp($1.type,"float")==0 || strcmp($3.type,"float")==0)
                strcpy($$.type, "float");
            else
                strcpy($$.type, "integer");
            strcpy($$.result, t);
            strcpy($$.value, "?");
            quadr("-", $1.result, $3.result, t);
        }
    | EXPR multiply EXPR
        {
            char* t = newTemp();
            if (strcmp($1.type,"float")==0 || strcmp($3.type,"float")==0)
                strcpy($$.type, "float");
            else
                strcpy($$.type, "integer");
            strcpy($$.result, t);
            strcpy($$.value, "?");
            quadr("*", $1.result, $3.result, t);
        }
    | EXPR divide EXPR
        {
            char* t = newTemp();
            if (strcmp($3.value, "0") == 0 || strcmp($3.value, "0.000000") == 0)
                printf("Erreur Semantique, ligne %d, colonne %d : division par zero\n",
                       yylineno, yycolumn);
            if (strcmp($1.type,"float")==0 || strcmp($3.type,"float")==0)
                strcpy($$.type, "float");
            else
                strcpy($$.type, "integer");
            strcpy($$.result, t);
            strcpy($$.value, "?");
            quadr("/", $1.result, $3.result, t);
        }
    | minus EXPR
        {
            char* t = newTemp();
            strcpy($$.type, $2.type);
            strcpy($$.value, "?");
            strcpy($$.result, t);
            quadr("NEG", $2.result, "", t);
        }
    | lparen EXPR rparen
        {
            $$ = $2;
        }
    | identifier 
        {   
            if(checkUndeclared($1) == -1) {
                printf("Erreur Semantique, ligne %d, colonne %d : variable non declaree '%s'\n", yylineno, yycolumn, $1);
                updateType($1, "integer");
                strcpy($$.type, "integer");
            } else {
                strcpy($$.type, idf_type($1));
            }
            strcpy($$.value, "?");
            strcpy($$.result, $1);
        }
    | identifier lbracket int_literal rbracket 
        {   
            char* t;
            char accessStr[40];
            if(checkUndeclared($1) == -1) {
                printf("Erreur Semantique, ligne %d, colonne %d : variable non declaree '%s'\n", yylineno, yycolumn, $1);
                strcpy($$.type, "integer");
            }
            else if(checkTableIndex($1, $3) == -1) {
                printf("Erreur Semantique, ligne %d, colonne %d : index %d hors limites pour '%s'\n", yylineno, yycolumn, $3, $1);
                strcpy($$.type, idf_type($1));
            }
            else {
                strcpy($$.type, idf_type($1));
            }
            strcpy($$.value, "?");
            sprintf(accessStr, "%s[%d]", $1, $3);
            t = newTemp();
            strcpy($$.result, t);
            quadr("=", accessStr, "", t);
        }
    | int_literal
        {
            sprintf($$.value, "%d", $1);
            strcpy($$.type, "integer");
            sprintf($$.result, "%d", $1);
        }
    | float_literal
        {
            sprintf($$.value, "%f", $1);
            strcpy($$.type, "float");
            sprintf($$.result, "%f", $1);
        }
    ;


COND
    : EXPR less_than EXPR      
        { 
            char* t = newTemp();
            quadr("<", $1.result, $3.result, t);
            quadr("BZ", t, "", "?");
        }
    | EXPR greater_than EXPR   
        { 
            char* t = newTemp();
            quadr(">", $1.result, $3.result, t);
            quadr("BZ", t, "", "?");
        }
    | EXPR less_equal EXPR     
        { 
            char* t = newTemp();
            quadr("<=", $1.result, $3.result, t);
            quadr("BZ", t, "", "?");
        }
    | EXPR greater_equal EXPR  
        { 
            char* t = newTemp();
            quadr(">=", $1.result, $3.result, t);
            quadr("BZ", t, "", "?");
        }
    | EXPR equal_equal EXPR    
        { 
            char* t = newTemp();
            quadr("==", $1.result, $3.result, t);
            quadr("BZ", t, "", "?");
        }
    | EXPR not_equal EXPR      
        { 
            char* t = newTemp();
            quadr("!=", $1.result, $3.result, t);
            quadr("BZ", t, "", "?");
        }
    | lparen COND kw_and COND rparen
    | lparen COND kw_or  COND rparen
    | kw_not lparen COND rparen
    | lparen COND rparen
    ;

%%


int main(){
    Initialization();
    yyparse();
    afficher();
    
    printf("\n=== CODE AVANT OPTIMISATION ===");
    afficher_qdr(); 
    
    optimiser();
    
    printf("\n=== CODE APRES OPTIMISATION ===");
    afficher_qdr(); 
    
    return 0;
}

void yyerror(char* msg){
    printf("Erreur Syntaxique a la ligne : %d\n", yylineno);
}