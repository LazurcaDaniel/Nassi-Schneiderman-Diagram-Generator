/*#include "nassi.h"

code* Incarcare()
{
    code* i1 = new code;
    i1->type = INSTR_SIMPLA;
    strcpy(i1->code_instruction, "citeste n");

    code* i2 = new code;
    i1->urm = i2;
    i2->type = IF;
    strcpy(i2->code_instruction, "n > 0");

    code* i8 = new code;
    i2->daca = i8;
    i8->type = IF;
    strcpy(i8->code_instruction, "n % 2");

    code* i9 = new code;
    i2->altfel = i9;
    i9->type = WHILE;
    strcpy(i9->code_instruction, "n<50");

    code* i3 = new code;
    i8->daca = i3;
    i3->type = INSTR_SIMPLA;
    strcpy(i3->code_instruction, "n = n + 1");

    code* i6 = new code;
    i8->urm = i6;
    i6->type = WHILE;
    strcpy(i6->code_instruction, "n % 7 == 8");

    code* i7 = new code;
    i6->listaWhile = i7;
    i7->type = INSTR_SIMPLA;
    strcpy(i7->code_instruction, "n++");

    code* i4 = new code;
    i9->listaWhile = i4;
    i4->type = INSTR_SIMPLA;
    strcpy(i4->code_instruction, "n = n + 2");

    code* i5 = new code;
    i2->urm = i5;
    i5->type = INSTR_SIMPLA;
    strcpy(i5->code_instruction, "afiseaza n");

    return i1;

    code* i6 = new code;
    i6->type = REPEAT;
    strcpy(i6->code_instruction, "n % 7 == 8");

    code* i7 = new code;
    i6-> = i7;
    i7->type = INSTR_SIMPLA;
    strcpy(i7->code_instruction, "n++");
    return i6;
}*/
