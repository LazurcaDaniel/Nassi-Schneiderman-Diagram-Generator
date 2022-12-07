#include <bits/stdc++.h>
#include <queue>
using namespace std;
bool cauta_var(char variabila[] ,int nr_variabile, char var[100][100]); ///cauta variabila in multimea de variabile
bool esteNr(char s[]); ///verifica daca s este un nr
bool checkIF(char s[],int nr_variabile, char var[100][100]); /// verifica sintaxa pentru IF
bool EsteCuvant(char s[]); ///verifica daca s este un nume valid pentru o variabila
bool checkElse(char s[], int nr_variabile, char var[100][100]); ///verifica sintaxa pentru ELSE
bool checkComparison(char s[]); /// verifica semnele pentru comparatii din conditii
bool checkWhile(char s[], int nr_variabile, char var[100][100]); ///verifica sintaxa WHILE
bool checkFor(char s[], int nr_variabile, char var[100][100]); ///verifica sintaxa FOR
bool checkConditieFor(char s[], int nr_variabile, char var[100][100]); ///verifica conditiile de la FOR
