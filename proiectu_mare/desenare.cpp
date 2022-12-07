#include <graphics.h>
#include <iostream>
#include "nassi.h"

#define INALTIME_TEXT 25
//#define LUNGIME_INSTR 199
using namespace std;

int desenSimplu(Instructiune* instr, int x, int y, int w)
{
    setcolor(WHITE);
    outtextxy(x + w/2, y + INALTIME_TEXT - 5, instr->text);
    rectangle(x, y, x + w, y + INALTIME_TEXT);
    return INALTIME_TEXT;
}

int desenIf(Instructiune* instr, int x, int y, int w)
{
    setcolor(YELLOW);
    outtextxy(x + w/2, y + INALTIME_TEXT, instr->text);
    outtextxy(x + 20, y + 2*INALTIME_TEXT-5, "DA");
    outtextxy(x + w-20, y + 2*INALTIME_TEXT-5, "NU");
    line(x, y, x+w/2, y + 2*INALTIME_TEXT);
    line(x+w/2, y + 2*INALTIME_TEXT, x+w, y);
    rectangle(x, y, x + w, y + 2*INALTIME_TEXT);

    int hDaca = Desenare(instr->daca, x, y + 2*INALTIME_TEXT,  w/2);

    int hAltfel = 0;
    if (instr->altfel != NULL)
        hAltfel = Desenare(instr->altfel, x + w /2, y + 2*INALTIME_TEXT,  w/2);

    setcolor(YELLOW);
    rectangle(x, y, x + w, y + 2*INALTIME_TEXT + max(hDaca, hAltfel));
    return 2*INALTIME_TEXT + max(hDaca, hAltfel);
}

int desenWhile(Instructiune* instr, int x, int y, int w)

{
    setcolor(CYAN);
    outtextxy(x + w/2, y + INALTIME_TEXT-5, instr->text);
    line(x, y, x+w, y);
    line(x + w, y, x + w, y + INALTIME_TEXT);
    line(x + 20, y + INALTIME_TEXT, x + w, y + INALTIME_TEXT);

    int lenghtWhile = Desenare(instr->listaWhile, x + 20, y + INALTIME_TEXT /* *instr->nr_children*/, w - 20);
    setcolor(CYAN);
    line(x, y, x, y + lenghtWhile);
    line(x + 20, y + INALTIME_TEXT, x + 20, y + lenghtWhile);
    line(x, y + INALTIME_TEXT + lenghtWhile, x + 20, y + INALTIME_TEXT + lenghtWhile);

    // itereaza lista de copii afisandu-i si calculeaza inaltimea totala
    return INALTIME_TEXT + lenghtWhile; // + inaltimea copiilor
}

int Desenare(Instructiune* lista, int x, int y, int w)
{
    int h = 0;
    settextjustify(CENTER_TEXT, CENTER_TEXT);
    while (lista != NULL)
    {
        cout << lista->tip << " " << lista->text << endl;
        switch (lista->tip)
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
        }
        lista = lista->urm;
    }
    return h;
}
