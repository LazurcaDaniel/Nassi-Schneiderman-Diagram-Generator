#include <windef.h>

#define INSTR_SIMPLA    1
#define IF              2
#define WHILE           3
#define DO_WHILE        4
#define FOR             5
#define SWITCH          6

struct Instructiune {
    int tip;
    char text[100];
    Instructiune* urm = NULL;

    Instructiune* daca = NULL;
    Instructiune* altfel = NULL;

    Instructiune* listaWhile = NULL;
};

int Desenare(Instructiune* lista, int x, int y, int w);
Instructiune* Incarcare();
