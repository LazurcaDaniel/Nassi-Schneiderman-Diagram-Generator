#include <cstring>
#include <iostream>
#include <fstream>
#include "nassi.h"
using namespace std;
#define NMAX 1000
#define ULTIM 8
ifstream f("text.in");

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

void preiaInstructiuni(char instr[], int &nr_instr)
{
    while(f.getline(instr,256))
    {
        convertesteSintaxaCorect(instr);
        if (strcmp(instr, "{") == 0) ///-1
        {
            LINE[nr_instr].instruction_type = -1;
        }
        else if (strcmp(instr, "}") == 0)   ///-2
        {
            LINE[nr_instr].instruction_type = -2;
        }
        else if (strncmp(instr, "begin", 5) == 0)   ///0
        {
            LINE[nr_instr].instruction_type = 0;
            strcpy(LINE[nr_instr].loc,instr);
        }
        else if (strncmp(instr, "if", 2) == 0)   ///2
        {
            LINE[nr_instr].instruction_type = 2;
            strcpy(LINE[nr_instr].loc,instr);
        }
        else if (strncmp(instr, "else", 4) == 0)   ///3
        {

            LINE[nr_instr].instruction_type = 3;
            strcpy(LINE[nr_instr].loc,instr);
        }
        else if (strncmp(instr, "while", 5) == 0)   ///4
        {
            LINE[nr_instr].instruction_type = 4;
            strcpy(LINE[nr_instr].loc,instr);
        }
        else if (strncmp(instr, "for", 3) == 0)   ///5
        {
            LINE[nr_instr].instruction_type = 5;
            strcpy(LINE[nr_instr].loc,instr);
        }
        else if (strncmp(instr, "repeat", 6) == 0)   ///6
        {
            LINE[nr_instr].instruction_type = 6;
            strcpy(LINE[nr_instr].loc,instr);
        }
        else if (strncmp(instr, "until", 5) == 0)   ///7
        {
            LINE[nr_instr].instruction_type = 7;
            strcpy(LINE[nr_instr].loc,instr);
        }
        else if(strncmp(instr,"end",3)==0)
        {
            LINE[nr_instr].instruction_type=ULTIM;
            strcpy(LINE[nr_instr].loc,instr);
        }
        else   ///variabile - atribuiri - 1
        {
            LINE[nr_instr].instruction_type=1;
            strcpy(LINE[nr_instr].loc,instr);
        }

    }
    nr_instr++;
}
