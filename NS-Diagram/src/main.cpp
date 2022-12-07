#include <cstring>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <fstream>
#include "syntax.h"
using namespace std;
#define NMAX 1000
#define NMAXVAR 100
#define ULTIM 7
ifstream f("text.in");
struct code
{
    char code_instruction[256];
    int level;
    int intr_type;
    int nr_children;
    code *children[NMAX];
} *instructions;

struct lines
{
    int instruction_type;
    char loc[256];
} line[NMAX];

char var[256][NMAXVAR];
int nr_variabile;
int nr_instr;
void convertesteSintaxaCorect(char s[])
{

    int l=strlen(s);
    for(int i=0; i<l; i++)
    {
        if(s[i]==' ')
        {
            strcpy(s+i,s+i+1);
            i--;
        }
        else s[i]=tolower(s[i]);
    }
}
void addNode(code *parent, char c[], int lvl, int type)
{
    code *p= new code;
    strcpy(p->code_instruction,c);
    p->level=lvl;
    p->intr_type=type;
    p->nr_children=0;
    parent->children[parent->nr_children]=p;
    parent->nr_children++;
}
void preiaInstructiuni(char instr[], int &nr_instr)
{
    while(f.getline(instr,256))
    {
        int i=0;
        while(instr[i]==' ')
            i++;
        strcpy(instr,instr+i); /// scap de indentari
        if (strcmp(instr, "{") == 0) ///-1
        {
            convertesteSintaxaCorect(instr);
            if(instr[1]==NULL) ///verific daca este doar acolada si nimic altceva
                line[nr_instr].instruction_type = -1;
            else
            {
                cout<<"EROARE";
                break;
            }
        }
        else if (strcmp(instr, "}") == 0)   ///-2
        {
            convertesteSintaxaCorect(instr);
            if(instr[1]==NULL) ///verific daca este doar acolada si nimic altceva
                line[nr_instr] = -2;
            else
            {
                cout<<"EROARE";
                break;
            }
        }
        else if (strncmp(instr, "begin", 5) == 0)   ///0
        {
            convertesteSintaxaCorect(instr);
            if(instr[5]==NULL) ///verific daca este doar BEGIN si nimic altceva
                line[nr_instr].instruction_type = 0;
            else
            {
                cout<<"EROARE";
                break;
            }
        }
        else if (strncmp(instr, "if", 2) == 0)   ///2
        {
            convertesteSintaxaCorect(instr);
            if(checkIF(instr,nr_variabile,var))
            {
                line[nr_instr].instruction_type = 2;
                strcpy(line[nr_instr].loc,instr);
            }
            else break;
        }
        else if (strncmp(instr, "else", 4) == 0)   ///3
        {
            convertesteSintaxaCorect(instr);
            if(checkElse(instr,nr_variabile,var))
            {
                line[nr_instr].instruction_type = 3;
                strcpy(line[nr_instr].loc,instr);
            }
            else break;
        }
        else if (strncmp(instr, "while", 5) == 0)   ///4
        {
            convertesteSintaxaCorect(instr);
            if(checkWhile(instr,nr_variabile,var))
            {
                line[nr_instr].instruction_type = 4;
                strcpy(line[nr_instr].loc,instr);
            }
            else break;
        }
        else if (strncmp(instr, "for", 3) == 0)   ///5
        {

            line[nr_instr].instruction_type = 5;
            strcpy(line[nr_instr].loc,instr);
        }
        else if (strncmp(instr, "do", 2) == 0)   ///6
        {
            convertesteSintaxaCorect(instr);
            if(instr[2]==NULL)
            {
                line[nr_instr].instruction_type = 6;
                strcpy(line[nr_instr].loc,instr);
            }
            else
            {
                cout<<"eroare SINTAXA 'DO' GRESITA";
                break;
            }
        }
        else if(strncmp(instr,"end",3)==0)
        {
            convertesteSintaxaCorect(instr);
            line[nr_instr].instruction_type=ULTIM;
            strcpy(line[nr_instr].loc,instr);
        }
        else   ///variabile - atribuiri - 1
        {
            convertesteSintaxaCorect(instr);
            ///check variabile
            if(!strstr(instr,"="))
            {
                ///EROARE: VARIABILA FARA ATRIBUIRE
                break;
            }
            else
            {
                strcpy(line[nr_instr].loc,instr);
                char *p=strtok(instr,"="); ///iau cuvantul pana la egal
                if(EsteCuvant(p))   ///verific daca este un nume corect pt o variabila
                {
                    if(!cauta_var(p,nr_variabile,var)) ///verific daca exista variabila,daca nu, o adaug
                    {
                        strcpy(var[nr_variabile],p);
                        nr_variabile++;
                    }
                    char *p=strtok(NULL,"="); ///iau ce este dupa egal
                    if(!esteNr(p)&&!cauta_var(p,nr_variabile,var)) ///verific daca este numar sau alta variabila
                    {
                        ///print eroare
                        break;
                    }
                    line[nr_instr].instruction_type = 1;
                }
                else
                {
                    ///print eroare
                    break;
                }
            }

        }
        nr_instr++;
    }
}
int getNrDescendants(int start)
{
    int nr_desc=0;
    int parantheses=1;
    while(parantheses&&start<=nr_instr)
    {
        start++;
        if(line[start].instruction_type==-1)
            parantheses++;
        else if(line[start].instruction_type==-2)
            parantheses--;
        else nr_desc++;
    }
    return nr_desc;
}
void addIF(code *current_node, int i)
{
    current_node->nr_children=getNrDescendants(i+1);
    int nr=current_node->nr_children;
    i+=2;
    while(nr)
    {
        switch(line[i].instruction_type)
        {
        case 1:
            {
                addATR();///inca nu face nimic :(
                break;
            }
        }
    }
}
void createTREE()
{
    instructions->intr_type=0;
    instructions->level=0;
    instructions->nr_children=1;
    code *current_node=instructions;
    int i=0;
    while(i<=nr_instr)
    {
        switch(line[i].instruction_type)
        {
        case 1:
            {
                addNode(current_node,line[i].loc,i,line[i].instruction_type)l
                i++;
                current_node=current_node->children[1];
                break;
            }
        case 2:
            {
                int i1=getNrDescendants(start+1);
                code *IFcurrent = current_node;
                i++;
                while(i1)
                {
                    i++;
                    addNode()
                }
            }
        }
    }
}
int main()
{
    nr_variabile=0;
    nr_instr=0;
    char s[256];
    instructions->nr_children=1;
    instructions->level=0;
    instructions->intr_type=0;
    preiaInstructiuni(s,nr_instr);
    //for(int i=0; i<nr_instr; i++)
    //  cout<<instructiuni[i]<<'\n';
    return 0;
}
