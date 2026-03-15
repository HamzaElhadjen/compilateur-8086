#include<string.h>

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

//fonction de hachage 
unsigned int hash(char* str,int size) {
    unsigned int h = 0;
    while (*str)
        h = h * 31 + *str++;
    return h % size;
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
int idf_value(char entite[]){
    int i = rechercherIdf(entite);
    if ( i != -1) return atoi(TS[i].val);
    return -99999999; 
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
