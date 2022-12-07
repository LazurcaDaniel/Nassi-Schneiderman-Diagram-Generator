#include "syntax.h"
bool cauta_var(char variabila[], int nr_variabile, char var[100][100])
{
    for(int i=0; i<nr_variabile; i++)
        if(strcmp(var[i],variabila)==0)
            return 1;
    return 0;
}
bool esteNr(char s[])
{
    int l=strlen(s);
    for(int i=0; i<l; i++)
        if(!isalnum(s[i])||isalpha(s[i]))
            return 0;
    return 1;
}
bool EsteCuvant(char s[])
{
    int l=strlen(s);
    for(int i=0; i<l; i++)
        if(!isalnum(s[i]))
            {
                cout<<"eroare NUME INCORECT PENTRU VARIABILA";
                return 0;
            }
    if(!esteNr(s))
        return 1;
    cout<<"eroare NUME INCORECT PENTRU VARIABILA";
    return 0;
}
bool checkComparison(char s[])
{
    int i=0;
    while(!strchr("=><",s[i]))
        i++;
    if(s[i]=='=')
    {
        if(s[i+1]!='=')
            return 0;
    }
    if(s[i]=='>'||s[i]=='<')
    {
        if(s[i+1]!='='&&!isalnum(s[i+1]))
            return 0;
    }
    return 1;
}
bool checkConditii(char s[], int nr_variabile, char var[100][100])
{
    queue <int> separatii;
    int l=strlen(s);
    if(s[l-1]!=')')
    {
        cout<<"eroare ')' lipsa";
        return 0;
    }
    l--;
    for(int i=0; i<l; i++)
    {
        if(s[i]=='&')
        {
            if(s[i+1]!='&')
            {
                cout<<"eroare conector gresit";
                return 0;
            }
            separatii.push(i);
            i++;
        }
        else if(s[i]=='|')
        {
            if(s[i+1]!='|')
            {
                cout<<"eroare conector gresit";
                return 0;
            }
            separatii.push(i);
            i++;
        }
    }
    separatii.push(l);
    char p[10000];
    strncpy(p,s,separatii.front());
    int i=separatii.front();
    while(!separatii.empty())
    {
        separatii.pop();
        if(!checkComparison(p))
        {
            //cout<<3;
            cout<<"eroare LIPSA COMPARATIE";
            return 0;
        }
        char s2[256];
        strcpy(s2,p);
        char *p1=strtok(s2,"=><");
        if(!cauta_var(p1,nr_variabile,var))
        {
            //cout<<4;
            cout<<"eroare NU EXISTA VARIABILA";
            return 0;
        }
        p1=strtok(NULL,"=");
        if(!cauta_var(p1,nr_variabile,var)&&!esteNr(p1))
        {
            //cout<<5;
            cout<<"eroare VALOARE INCORECTA PENTRU ATRIBUIRE";
            return 0;
        }
        if(!separatii.empty())
        {
            strncpy(p,s+i+2,separatii.front()-i-2);
            i=separatii.front();

        }
    }
    return 1;
}
bool checkElse(char s[], int nr_variabile, char var[100][100])
{
    int l=strlen(s);
    if(l==4)
        return 1;
    if(s[4]=='i')
    {
        strcpy(s,s+4);
        return checkIF(s,nr_variabile,var);
    }
    cout<<"EROARE: INSTRUCTIUNE NECUNOSCUTA DUPA ELSE";
    return 0;
}
bool checkIF(char s[], int nr_variabile, char var[100][100])
{

    if(s[2]!='(')
    {
        //cout<<1;
        cout<<"eroare LIPSESTE '(' ";
        return 0;
    }
    if(s[strlen(s)-1]!=')')
    {
        //cout<<2;
        cout<<" eroare LIPSESTE ')' ";
        return 0;
    }
    char s1[256];
    strcpy(s1,s+3);
    return checkConditii(s1,nr_variabile,var);
}
bool checkWhile(char s[], int nr_variabile, char var[100][100])
{
    if(s[5]!='(')
    {
        cout<<"Eroare: '(' lipsa";
        return 0;
    }
    if(s[strlen(s)-1]!=')')
    {
        cout<<"Eroare: ')' lipsa";
        return 0;
    }
    char s1[256];
    strcpy(s1,s+6);
    return checkConditii(s1,nr_variabile,var);
}
bool checkConditieFor(char s[], int nr_variabile, char var[100][100])
{
    int i=0;
    char var_locala[1000];

    while(s[i]!='=')
        {
            var_locala[i]=s[i];
            i++;
        }
    if(!cauta_var(var_locala,nr_variabile,var))
    {
        cout<<"Eroare: Nu exista variabila";
        return 0;
    }
    //if(!isdigit(s[i+1]))

}
bool checkFor(char s[], int nr_variabile, char var[100][100])
{
    if(s[3]!='(')
    {
        cout<<"Eroare: '(' lipsa";
        return 0;
    }
    if(s[strlen(s)-1]!=')')
    {
        cout<<"Eroare: ')' lipsa";
        return 0;
    }
    char s1[1000];
    strcpy(s1,s+4);
    return checkConditieFor(s1,nr_variabile,var);
}

