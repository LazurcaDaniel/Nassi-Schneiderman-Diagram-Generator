#include <iostream>
#include <graphics.h>
#include <fstream>
#include "nassi.h"

#define F_LATIME  1000
#define F_LUNGIME 800

using namespace std;

char menu_entry[4][30] = {"Incarcare cod", "Setari", "Instructiuni", "Quit"};
#define COL_ACTIVE      WHITE
#define COL_INACTIVE    YELLOW
#define COL_DELETE      BLACK
#define KEY_UP          72 * 256
#define KEY_DOWN        80 * 256

void ClearScreen()
{
    setcolor(BLACK);
    setfillstyle(SOLID_FILL, BLACK);
    bar(0, 0, F_LATIME, F_LUNGIME);
}

void drawMenuItem(int item, int x, int y, bool active)
{
    setcolor(active ? COL_ACTIVE : COL_INACTIVE);
    outtextxy(x, y, menu_entry[item]);

    setcolor(active ? COL_ACTIVE : COL_DELETE);
    rectangle(F_LATIME/2-100, y-10, F_LATIME/2+ 100, y + 30);
}

void moveActive(int src, int dst)
{
    //cout << "inac:" << src << " activ:" << dst << endl;
    drawMenuItem(src, F_LATIME/2, 200 + 50 * src, false);
    drawMenuItem(dst, F_LATIME/2, 200 + 50 * dst, true);
}

void drawMenu(int active)
{
    settextstyle(SANS_SERIF_FONT, HORIZ_DIR, 3);
    settextjustify(CENTER_TEXT, TOP_TEXT);
    for (int i = 0; i < 4; i++)
    {
        drawMenuItem(i, F_LATIME/2, 200 + 50 * i, i == active);
    }
}

//driver program

void WriteFromFile()
{
    ClearScreen();
    settextjustify(LEFT_TEXT, TOP_TEXT);
    setcolor(WHITE);
    ifstream fin("INSTRUCTIUNI_RO.txt");
    char linie_cod[250];
    int k = 1;
    while(fin.getline(linie_cod, 250))
    {
         outtextxy(100, k*INALTIME_TEXT, linie_cod);
         k++;
    }
    fin.close();

    getch();

    ClearScreen();


}
int main()
{
    initwindow(F_LATIME,F_LUNGIME,"Diagrame Nassi-Schneiderman",150,50);

    char s[256];
    instruction=new code;
    //preiaInstructiuni(s, nr_instr);
    //createArbore(instruction, LINE, nr_instr);

   /* int active = 0;
    drawMenu(active);

    do
    {
        int ch = getch();
        if (ch == 0)
        {
            ch = getch() * 256;
        }
        switch (ch)
        {
            case KEY_UP:
                if (active > 0)
                {
                    moveActive(active, active-1);
                    active--;
                }
                break;
            case KEY_DOWN:
                if (active < 3)
                {
                    moveActive(active, active + 1);
                    active++;
                }
                break;
            case 'q':
            case VK_ESCAPE:
                active = -1;
                closegraph();
                return 0;
            case VK_RETURN:
                switch (active)
                {
                    case 0:
                    {
                        ClearScreen();

                        Desenare(instruction, 100, 100, 500);
                        getch();


                        drawMenu(active);
                        break;
                    }

                    case 1:
                        //OpenSettings();
                        break;
                    case 2:

                WriteFromFile();
                        drawMenu(active);
                        //OpenInstructions();
                        break;

                    case 3:
                    {
                        closegraph();
                        return 0;
                    }
                } //switch (active)
                break;
        } // switch(key)
        //cout << ch << endl;
    }
    while (active >= 0);

    closegraph();*/
}
