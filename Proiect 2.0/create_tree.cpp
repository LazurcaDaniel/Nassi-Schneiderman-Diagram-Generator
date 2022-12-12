#include "nassi.h"
/*struct code
{
    int info;
    int nr_children;
    arbore *children[100];
};*/
void init_nod(code *&p, char inf[],int instr_type)
{
    p=new code;
    strcpy(p->code_instruction,inf);
    p->nr_children=0;
    p->type=instr_type;
    for(int i=0; i<100; i++)
        p->children[i]=NULL;
}
void addNode2(code *&parent, char inf[], int instr_type)
{
    code *p;
    init_nod(p,inf,instr_type);
    parent->children[parent->nr_children]=p;
    parent->nr_children++;
}
int getNrDescendants(lines LINE[], int &i, int nr_instr, code *curent)
{
    int nr_desc=0;
    int nr_desc_irelevant=0;
    i+=2;
    while(i<=nr_instr)
    {
        if(LINE[i].instruction_type==-1)
        {
            i--;
            int aux=getNrDescendants(LINE,i,nr_instr,curent->children[curent->nr_children-1]);
            nr_desc_irelevant+=aux;
        }
        else if(LINE[i].instruction_type==-2)
        {
            i++;
            break;
        }
        else
        {
            addNode2(curent,LINE[i].loc,LINE[i].instruction_type);
            nr_desc++;
            i++;
        }

    }
    return nr_desc-nr_desc_irelevant;
}

void createArbore(code *&s, lines LINE[], int nr_instr)
{
    code *p=s;
    int i=0;
    while(i<=nr_instr)
    {
        switch(LINE[i].instruction_type)
        {
        case 0:
        {

            addNode2(s,LINE[i].loc,LINE[i].instruction_type);
            s=s->children[0];
            i++;
            break;
        }
        case 1:
        {

            addNode2(s,LINE[i].loc,LINE[i].instruction_type);
            s=s->children[0];
            i++;
            break;
        }
        case -1:
        {
            i++;
            break;
        }
        case -2:
        {
            i++;
            break;
        }
        case 7:
        {
            addNode2(s,LINE[i].loc,LINE[i].instruction_type);
            s=s->children[0];
            i++;
        }
        case ULTIM:
        {
            addNode2(s,LINE[i].loc,LINE[i].instruction_type);
            i++;
            break;
        }
        default:
        {
            addNode2(s,LINE[i].loc,LINE[i].instruction_type);
            s=s->children[s->nr_children-1];
            int i1=getNrDescendants(LINE,i,nr_instr,s);
            i--;
            break;
        }
        }
    }
    s=p;
}
/*void parcurgere(arbore *p, int nivel)
{
    if(p!=NULL)
    {
        cout<<p->nr_children<<" "<<p->info<<" "<<nivel<<'\n';
        //for(int i=0; i<p->nr_children; i++)
          //  cout<<p->children[i]->info<<" ";
        //if(p->nr_children==1)
        //cout<<"unu "<<p->info<<'\n';
        //else
        cout<<endl;
        //cout<<'\n'<<"Sunt la instructiunea "<<p->info<<'\n';
        for(int i=0; i<p->nr_children; i++)
            {
                parcurgere(p->children[i],nivel+1);}
    }
}*/

