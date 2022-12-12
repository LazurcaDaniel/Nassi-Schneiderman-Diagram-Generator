#include <windef.h>
#include <cstring>
#include <iostream>
#define ULTIM           8
#define NMAX         1000
#define INSTR_SIMPLA    1
#define IF              2
#define ELSE            3
#define WHILE           4
#define FOR             5
#define REPEAT          6

//#define SWITCH

#define INALTIME_TEXT 25


struct code
{
    char code_instruction[256];
    int type;
    int nr_children;
    code *children[NMAX];
};

struct lines
{
    int instruction_type;
    char loc[256]; //code_instruction
};
int Desenare(code* lista, int x, int y, int w);
//code* Incarcare();


int nr_variabile;
int nr_instr;
code *instruction;
lines LINE[NMAX];


/*struct code {
    int type;
    char code_instruction[100];
    code* urm = NULL;

    code* daca = NULL;
    code* altfel = NULL;

    code* listaI = NULL;
};

int Desenare(code* lista, int x, int y, int w);
code* Incarcare();*/

void init_nod(code *&p, char inf[],int instr_type);
void addNode2(code *&parent, char inf[], int instr_type);
int getNrDescendants(lines LINE[], int &i, int nr_instr, code *curent);
void createArbore(code *&s, lines LINE[], int nr_instr);

void convertesteSintaxaCorect(char s[]);
void preiaInstructiuni(char instr[], int &nr_instr);
