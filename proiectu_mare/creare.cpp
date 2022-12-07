#include "nassi.h"

Instructiune* Incarcare()
{
    Instructiune* i1 = new Instructiune;
    i1->tip = INSTR_SIMPLA;
    strcpy(i1->text, "citeste n");

    Instructiune* i2 = new Instructiune;
    i1->urm = i2;
    i2->tip = IF;
    strcpy(i2->text, "n > 0");

    Instructiune* i8 = new Instructiune;
    i2->daca = i8;
    i8->tip = IF;
    strcpy(i8->text, "n % 2");

    Instructiune* i3 = new Instructiune;
    i8->daca = i3;
    i3->tip = INSTR_SIMPLA;
    strcpy(i3->text, "n = n + 1");


    Instructiune* i6 = new Instructiune;
    i8->urm = i6;
    i6->tip = WHILE;
    strcpy(i6->text, "n % 7 == 8");

    Instructiune* i7 = new Instructiune;
    i6->listaWhile = i7;
    i7->tip = INSTR_SIMPLA;
    strcpy(i7->text, "n++");

    Instructiune* i4 = new Instructiune;
    i2->altfel = i4;
    i4->tip = INSTR_SIMPLA;
    strcpy(i4->text, "n = n + 2");

    Instructiune* i5 = new Instructiune;
    i2->urm = i5;
    i5->tip = INSTR_SIMPLA;
    strcpy(i5->text, "afiseaza n");

    return i1;
}
