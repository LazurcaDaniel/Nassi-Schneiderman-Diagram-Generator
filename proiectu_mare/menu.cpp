#include <iostream>
#include <graphics.h>

#include "nassi.h"

using namespace std;

char menu_entry[4][30] = {"Incarcare cod", "Setari", "Pseudocod", "Quit"};
#define COL_ACTIVE      WHITE
#define COL_INACTIVE    YELLOW
#define COL_DELETE      BLACK
#define KEY_UP          72 * 256
#define KEY_DOWN        80 * 256


void drawMenuItem(int item, int x, int y, bool active)
{
    setcolor(active ? COL_ACTIVE : COL_INACTIVE);
    outtextxy(x, y, menu_entry[item]);

    setcolor(active ? COL_ACTIVE : COL_DELETE);
    rectangle(x-10, y-10, x + 200, y + 30);
}

void moveActive(int src, int dst)
{
    cout << "inac:" << src << " activ:" << dst << endl;
    drawMenuItem(src, 240, 200 + 50 * src, false);
    drawMenuItem(dst, 240, 200 + 50 * dst, true);
}

void drawMenu(int active)
{
    settextstyle(SANS_SERIF_FONT, HORIZ_DIR, 3);
    settextjustify(LEFT_TEXT, TOP_TEXT);
    for (int i = 0; i < 4; i++)
    {
        drawMenuItem(i, 240, 200 + 50 * i, i == active);
    }
}

//driver program
int main()
{
    initwindow(700,600,"Diagrame Nassi-Schneiderman",150,50);

    int active = 0;
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
                        setcolor(BLACK);
                        setfillstyle(SOLID_FILL, BLACK);
                        bar(0, 0, 700, 600);

                        Desenare(Incarcare(), 100, 100, 500);
                        getch();

                        setcolor(BLACK);
                        setfillstyle(SOLID_FILL, BLACK);
                        bar(0, 0, 700, 600);

                        drawMenu(active);
                        break;
                    }

                    case 1:
                        //OpenSettings();
                        break;
                    case 2:
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
        cout << ch << endl;
    }
    while (active >= 0);

    closegraph();
}
