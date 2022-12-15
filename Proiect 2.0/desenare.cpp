#include <graphics.h>
#include <iostream>
#include "nassi.h"
#include <queue>
//#define LUNGIME_INSTR 199
using namespace std;

int desenSimplu(code* instr, int x, int y, int w)
{
    setcolor(WHITE);
    outtextxy(x + w/2, y + INALTIME_TEXT- 5, instr->code_instruction);
    rectangle(x, y, x + w, y + INALTIME_TEXT);
    return INALTIME_TEXT;
}

int desenIf(code* instr, int x, int y, int w)
{
    setcolor(YELLOW);
    outtextxy(x + w/2, y + INALTIME_TEXT, instr->code_instruction);
    outtextxy(x + 20, y + 2*INALTIME_TEXT-5, "DA");
    outtextxy(x + w-20, y + 2*INALTIME_TEXT-5, "NU");
    line(x, y, x+w/2, y + 2*INALTIME_TEXT);
    line(x + w/2, y + 2*INALTIME_TEXT, x+w, y);
    rectangle(x, y, x + w, y + 2*INALTIME_TEXT);

    int hDaca = Desenare(instr, x, y + 2*INALTIME_TEXT,  w/2);

    int hAltfel = 0;
    if (instr->children[instr->nr_children - 1]->type == ELSE)
        hAltfel = Desenare(instr->children[instr->nr_children - 1], x + w /2, y + 2*INALTIME_TEXT,  w/2);

    setcolor(YELLOW);
    rectangle(x, y, x + w, y + 2*INALTIME_TEXT + max(hDaca, hAltfel));
    return 2*INALTIME_TEXT + max(hDaca, hAltfel);
}

int desenWhile(code* instr, int x, int y, int w)

{
    setcolor(CYAN);
    outtextxy(x + w/2, y + INALTIME_TEXT-5, instr->code_instruction);
    line(x, y, x+w, y);
    line(x + w, y, x + w, y + INALTIME_TEXT);
    line(x + 20, y + INALTIME_TEXT, x + w, y + INALTIME_TEXT);

    int lenghtWhile = Desenare(instr, x + 20, y + INALTIME_TEXT, w - 20);
    setcolor(CYAN);
    line(x, y, x, y + INALTIME_TEXT + lenghtWhile);
    line(x + 20, y + INALTIME_TEXT, x + 20, y + lenghtWhile);
    line(x, y + INALTIME_TEXT + lenghtWhile, x + 20, y + INALTIME_TEXT + lenghtWhile);

    // itereaza lista de copii afisandu-i si calculeaza inaltimea totala
    return INALTIME_TEXT + lenghtWhile; // + inaltimea copiilor
}
int desenR(code* instr, int x, int y, int w)

{
    int lenghtR = Desenare(instr, x+20, y, w-20);
    setcolor(BLUE);
    outtextxy(x + w/2, y + lenghtR + INALTIME_TEXT-5, instr->code_instruction);
    line(x, y + INALTIME_TEXT + lenghtR, x+w, y+ INALTIME_TEXT + lenghtR);
    line(x + w, y + lenghtR, x + w, y + lenghtR + INALTIME_TEXT);
    line(x + 20, y + lenghtR, x + w, y + lenghtR);
    line(x, y, x, y + INALTIME_TEXT + lenghtR);
    //line(x + 20, y, x + 20, y + lenghtR);
    line(x, y, x + 20, y);
    setcolor(BLUE);
    return INALTIME_TEXT + lenghtR;
}

int desenFor(code* instr, int x, int y, int w)

{

    setcolor(RED);
    outtextxy(x + w/2, y + INALTIME_TEXT-5, instr->code_instruction);
    line(x, y, x+w, y);
    line(x + w, y, x + w, y + INALTIME_TEXT);
    line(x + 20, y + INALTIME_TEXT, x + w, y + INALTIME_TEXT);

    int lenghtFor = Desenare(instr, x + 20, y + INALTIME_TEXT, w - 20);
    cout<< lenghtFor;
    setcolor(RED);
    line(x, y, x, y + INALTIME_TEXT + lenghtFor);
    line(x + 20, y + INALTIME_TEXT, x + 20, y + lenghtFor);
    line(x, y + INALTIME_TEXT + lenghtFor, x + 20, y + INALTIME_TEXT + lenghtFor);

    return INALTIME_TEXT + lenghtFor;
}

int Desenare(code* lista, int x, int y, int w)
{

    queue <code*> urm;
    for(int i = 0; i < lista->nr_children; i++)
    {
        if(lista->children[i]->type != 0)
        {
            if(lista->children[i]->type != ELSE)
                urm.push(lista->children[i]);
        }
    }
    int h = 0;
    settextjustify(CENTER_TEXT, CENTER_TEXT);
    while (!urm.empty())
    {
        cout << lista->type << " " << lista->code_instruction << endl;
        switch (lista->type)
        {
        case INSTR_SIMPLA:
            h += desenSimplu(lista, x, y + h, w);
            break;
        case IF:
            h += desenIf(lista, x, y + h, w);
            break;
        case WHILE:
            h += desenWhile(lista, x, y + h, w);
            break;
        case REPEAT:
            h += desenR(lista, x, y + h, w);
        case FOR:
            h += desenFor(lista, x, y + h, w);
        }
        lista = urm.front();
        urm.pop();
    }
    return h;
}
