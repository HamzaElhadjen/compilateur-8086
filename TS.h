#include<string.h>
#include<stdlib.h>
#include <math.h>
//TS des constantes et variables:
typedef struct{
    int state;
    char name[20];
    char code[20];
    char type[20];
    char val[20];
}TypeTS;
TypeTS TS[200];

//TS des mots clés et Séparateurs
typedef struct{
    int state;
    char name[20];
    char code[20];
}TypeSM;
TypeSM tabS[50],tabM[50];


unsigned int hash(char* str,int size) {
    unsigned int h = 2166136261u;
    while (*str) {
        h ^= (unsigned char)(*str++);
        h *= 16777619u;
    }
    return h % (unsigned int)size;
}
void Initialization(){
    int i;
    for(i=0;i<200;i++) TS[i].state= 0;
    for(i=0;i<50;i++) {
        tabS[i].state= 0;
        tabM[i].state= 0;
    }
}
void inserer(char entite[], char code[], char type[], char val[], int i, int y) {
    switch(y) {
        case 1: // TS
            TS[i].state = 1;
            strcpy(TS[i].name, entite);
            strcpy(TS[i].code, code);
            strcpy(TS[i].type, type);
            strcpy(TS[i].val, val);
            break;

        case 2: // tabM
            tabM[i].state = 1;
            strcpy(tabM[i].name, entite);
            strcpy(tabM[i].code, code);
            break;

        case 3: // tabS
            tabS[i].state = 1;
            strcpy(tabS[i].name, entite);
            strcpy(tabS[i].code, code);
            break;
    }
}

void Rechercher(char entite[], char code[], char type[], char val[], int y) {
    unsigned int h, start;

    switch(y) {
        case 1: // TS
        h = hash(entite, 200);
        start = h;
            while(TS[h].state != 0) {
                if(strcmp(TS[h].name, entite) == 0) {
                    return;
                }
                h = (h + 1) % 200;
                if(h == start) {
                    printf(">>>> Table TS pleine ou impossible d'ajouter %s\n", entite);
                    return;
                }
            }
            inserer(entite, code, type, val, h,1);
            break;

        case 2: // tabM
        h = hash(entite, 50);
        start = h;
            while(tabM[h].state != 0) {
                if(strcmp(tabM[h].name, entite) == 0) {
                    return;
                }
                h = (h + 1) % 50;
                if(h == start) {
                    printf(">>>> Table tabM pleine ou impossible d'ajouter %s\n", entite);
                    return;
                }
            }
            inserer(entite, code, type, val, h,2);
            break;

        case 3: // tabS
        h = hash(entite, 50);
        start = h;
            while(tabS[h].state != 0) {
                if(strcmp(tabS[h].name, entite) == 0) {
                    return;
                }
                h = (h + 1) % 50;
                if(h == start) {
                    printf(">>>> Table tabS pleine ou impossible d'ajouter %s\n", entite);
                    return;
                }
            }
            inserer(entite, code, type, val, h,3);
            break;
    }
}
void afficher()
{
    int i;
    printf("/***************Table des symboles IDF***************/\n");
    printf("____________________________________________________________________________\n");
    printf("\t| Nom_Entite | Code_Entite | Type_Entite | Val_Entite |\n");
    printf("____________________________________________________________________________\n");

    for(i=0; i<200; i++)
    {
        if(TS[i].state==1)
        { 
            printf("\t|%10s |%15s | %12s | %12s |\n", TS[i].name, TS[i].code, TS[i].type, TS[i].val);
        }
    }

    printf("\n/***************Table des symboles mots cles***************/\n");
    printf("____________________________________________________\n");
    printf("\t| NomEntite | CodeEntite |\n");
    printf("____________________________________________________\n");
    for(i=0; i<50; i++)
    {
        if(tabM[i].state==1)
        { 
            printf("\t |%10s |%12s | \n", tabM[i].name, tabM[i].code); 
        }
    }

    printf("\n/***************Table des symboles separateurs***************/\n");
    printf("____________________________________________________\n");
    printf("\t| NomEntite | CodeEntite |\n");
    printf("____________________________________________________\n");
    for(i=0; i<50; i++)
    {
        if(tabS[i].state==1)
        { 
            printf("\t |%10s |%12s | \n", tabS[i].name, tabS[i].code); 
        }
    }
}

// Semantique

/// get the idf index
int rechercherIdf(char entite[]) {
    int h = hash(entite,200);
    int start = h;
    while(TS[h].state != 0) {
        if(strcmp(entite, TS[h].name) == 0)
            return h;

        h = (h+1) % 200;

        if(h == start)
            break;
    }
    return -1;
}


/// affect a type to an IDF
int updateType(char entite[], char type[]) {
    int i = rechercherIdf(entite);

    if (i != -1 && strcmp(TS[i].type, "") == 0) {
        strcpy(TS[i].type, type);
        return 1;
    }
    return -1;
}

/// important for const
void updateCode(char entite[], char code[]) {
    int i = rechercherIdf(entite);
    if (i != -1) strcpy(TS[i].code, code);
}

/// affect a value
void updateVal(char entite[], char value[]){
    int i = rechercherIdf(entite);
    if (i != -1) {
        strcpy(TS[i].val, value);
    }
}

/// get current value
float idf_value(char entite[]){
    int i = rechercherIdf(entite);
    if (i == -1 || TS[i].val == NULL) {
        return NAN;
    }
    return atof(TS[i].val) ; 
}
char* idf_type(char entite[]) {
    int i = rechercherIdf(entite);

    if (i == -1) {
        return NULL; // or "UNKNOWN"
    }

    return TS[i].type;
}

/// check type mismatch 
int checkTypeMismatch(char declared[], char valueType[]) {
    return strcmp(declared, valueType) == 0 ? 0 : 1;
}


// check underclared idfs
int checkUndeclared(char entite[]) {
    int i = rechercherIdf(entite); 
    if (i == -1) {
        return -1;
    }
    if (TS[i].type[0] == '\0') {
        return -1;
    }
    return 1;
}

/// Check if index is within bounds for table 
int checkTableIndex(char entite[], int idx) {
    int i = rechercherIdf(entite);
    
    int size = atoi(TS[i].val);
    if (idx <+ 0 || idx > size) {
        return -1;
    }

    return 1; 
}
/// check if the idf is of a constante
int isConstante(char entite[]) {
    int i = rechercherIdf(entite);
    if (i != -1 && strcmp(TS[i].code, "Constante") == 0) return 1;
    return 0;
}
/// check if the idf a table
int isTableau(char entite[]) {
    int i = rechercherIdf(entite);
    if (i != -1 && strcmp(TS[i].code, "Tableau") == 0) return 1;
    return 0;
}
// ===================== QUADRUPLETS =====================

typedef struct {
    char oper[10];
    char op1[20];
    char op2[20];
    char res[20];
} TypeQuad;

TypeQuad quad[500];
int qc = 0;          // quad counter : nombre actuel de quadruplets
int tc = 0;          // temp counter : pour générer T1, T2, T3...

// Ajouter un quadruplet
void quadr(char opr[], char op1[], char op2[], char res[]) {
    strcpy(quad[qc].oper, opr);
    strcpy(quad[qc].op1, op1);
    strcpy(quad[qc].op2, op2);
    strcpy(quad[qc].res, res);
    qc++;
}

// Mettre à jour un champ d'un quadruplet (backpatching)
// colon_quad : 1=oper, 2=op1, 3=op2, 4=res
void updateQuad(int num_quad, int colon_quad, char val[]) {
    switch(colon_quad) {
        case 1: strcpy(quad[num_quad].oper, val); break;
        case 2: strcpy(quad[num_quad].op1, val); break;
        case 3: strcpy(quad[num_quad].op2, val); break;
        case 4: strcpy(quad[num_quad].res, val); break;
    }
}

// Générer un nom de variable temporaire : T1, T2, T3...
char* newTemp() {
    char* t = (char*)malloc(10);
    sprintf(t, "T%d", tc++);
    return t;
}
// ========================== OPTIMISATION ==========================

// Verifie si une chaine est un nombre entier ou flottant
int isNumber(char* s) {
    if (s == NULL || s[0] == '\0') return 0;
    int i = 0;
    if (s[0] == '-' || s[0] == '+') i = 1;
    int hasDigit = 0;
    int hasDot = 0;
    for (; s[i] != '\0'; i++) {
        if (s[i] >= '0' && s[i] <= '9') hasDigit = 1;
        else if (s[i] == '.' && !hasDot) hasDot = 1;
        else return 0;
    }
    return hasDigit;
}

// Convertit une chaine en double pour faire le calcul
double toNumber(char* s) {
    return atof(s);
}

// === OPTI 1 : Propagation des constantes ===
// Si les deux operandes d'un calcul sont des nombres, on fait le calcul
// et on remplace le quadruplet par une simple affectation.
int propagationConstantes() {
    int modifs = 0;
    int i;
    for (i = 0; i < qc; i++) {
        char* op = quad[i].oper;
        char* o1 = quad[i].op1;
        char* o2 = quad[i].op2;
        
        // Seulement pour les 4 operateurs arithmetiques
        if (strcmp(op, "+") != 0 && strcmp(op, "-") != 0 
         && strcmp(op, "*") != 0 && strcmp(op, "/") != 0) continue;
        
        if (isNumber(o1) && isNumber(o2)) {
            double a = toNumber(o1);
            double b = toNumber(o2);
            double r = 0;
            
            if (strcmp(op, "+") == 0) r = a + b;
            else if (strcmp(op, "-") == 0) r = a - b;
            else if (strcmp(op, "*") == 0) r = a * b;
            else if (strcmp(op, "/") == 0) {
                if (b == 0) continue;  // evite division par zero
                r = a / b;
            }
            
            // Remplacer par (=, r, "", res)
            char buf[30];
            // Si c'est un entier, l'afficher comme entier
            if (r == (int)r) sprintf(buf, "%d", (int)r);
            else sprintf(buf, "%g", r);
            
            strcpy(quad[i].oper, "=");
            strcpy(quad[i].op1, buf);
            strcpy(quad[i].op2, "");
            modifs++;
        }
    }
    return modifs;
}

// === OPTI 2 : Simplifications algebriques ===
// x + 0 = x, x - 0 = x, x * 1 = x, x / 1 = x, x * 0 = 0, 0 * x = 0
int simplificationsAlgebriques() {
    int modifs = 0;
    int i;
    for (i = 0; i < qc; i++) {
        char* op = quad[i].oper;
        char* o1 = quad[i].op1;
        char* o2 = quad[i].op2;
        
        // x + 0  ou  0 + x  ou  x - 0
        if ((strcmp(op, "+") == 0 && strcmp(o2, "0") == 0) ||
            (strcmp(op, "-") == 0 && strcmp(o2, "0") == 0)) {
            strcpy(quad[i].oper, "=");
            strcpy(quad[i].op2, "");
            modifs++;
        }
        else if (strcmp(op, "+") == 0 && strcmp(o1, "0") == 0) {
            strcpy(quad[i].oper, "=");
            strcpy(quad[i].op1, o2);
            strcpy(quad[i].op2, "");
            modifs++;
        }
        // x * 1  ou  1 * x  ou  x / 1
        else if ((strcmp(op, "*") == 0 && strcmp(o2, "1") == 0) ||
                 (strcmp(op, "/") == 0 && strcmp(o2, "1") == 0)) {
            strcpy(quad[i].oper, "=");
            strcpy(quad[i].op2, "");
            modifs++;
        }
        else if (strcmp(op, "*") == 0 && strcmp(o1, "1") == 0) {
            strcpy(quad[i].oper, "=");
            strcpy(quad[i].op1, o2);
            strcpy(quad[i].op2, "");
            modifs++;
        }
        // x * 0  ou  0 * x   => resultat = 0
        else if (strcmp(op, "*") == 0 && 
                 (strcmp(o1, "0") == 0 || strcmp(o2, "0") == 0)) {
            strcpy(quad[i].oper, "=");
            strcpy(quad[i].op1, "0");
            strcpy(quad[i].op2, "");
            modifs++;
        }
    }
    return modifs;
}

// === OPTI 3 : Elimination du code mort ===
// Si un temporaire Ti est calcule mais jamais utilise plus tard, supprimer le quadruplet
// ATTENTION : ne pas supprimer les quadruplets qui ecrivent dans des vraies variables
int eliminationCodeMort() {
    int modifs = 0;
    int i, j;
    
    for (i = 0; i < qc; i++) {
        char* res = quad[i].res;
        
        // On ne s'attaque qu'aux temporaires (commencent par T)
        if (res[0] != 'T') continue;
        
        // On ne touche pas aux BZ, BR (leur "res" est une cible de saut)
        if (strcmp(quad[i].oper, "BZ") == 0 || 
            strcmp(quad[i].oper, "BR") == 0) continue;
        
        // Chercher si ce Ti est utilise dans un quadruplet SUIVANT
        int estUtilise = 0;
        for (j = i + 1; j < qc; j++) {
            if (strcmp(quad[j].op1, res) == 0 || 
                strcmp(quad[j].op2, res) == 0) {
                estUtilise = 1;
                break;
            }
        }
        
        if (!estUtilise) {
            // Marquer comme NOP (no operation) - a supprimer
            strcpy(quad[i].oper, "NOP");
            strcpy(quad[i].op1, "");
            strcpy(quad[i].op2, "");
            strcpy(quad[i].res, "");
            modifs++;
        }
    }
    return modifs;
}

// Fonction principale d'optimisation
void optimiser() {
    printf("\n/******************** Optimisation ********************/\n");
    int total = 0, round = 0;
    int m;
    
    // On fait plusieurs passes car une optimisation peut en rendre une autre possible
    do {
        round++;
        m = 0;
        m += propagationConstantes();
        m += simplificationsAlgebriques();
        m += eliminationCodeMort();
        total += m;
        printf("Passe %d : %d optimisation(s)\n", round, m);
    } while (m > 0 && round < 10);   // securite : max 10 passes
    
    printf("Total : %d optimisation(s) appliquee(s)\n", total);
}

// Afficher la table des quadruplets
void afficher_qdr() {
    int i;
    printf("\n/******************** Les Quadruplets ********************/\n");
    printf("_____________________________________________________________\n");
    printf("   N  |   Oper   |   Op1   |   Op2   |   Res   \n");
    printf("_____________________________________________________________\n");
    for(i = 0; i < qc; i++) {
        printf("  %3d | %8s | %7s | %7s | %7s\n",
               i, quad[i].oper, quad[i].op1, quad[i].op2, quad[i].res);
    }
    printf("_____________________________________________________________\n");
}
