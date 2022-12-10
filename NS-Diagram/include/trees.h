#include <iostream>
#include <cstring>

using namespace std;
#define NMAX 1000
#define NMAXVAR 100
#define ULTIM 8
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
    char loc[256];
};
void init_nod(code *&p, char inf[],int instr_type);
void addNode2(code *&parent, char inf[], int instr_type);
int getNrDescendants(lines line[], int &i, int nr_instr, code *curent);
void createArbore(code *&s, lines line[], int nr_instr);

