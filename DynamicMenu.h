#ifndef DYNAMICMENU_H
#define DYNAMICMENU_H

#include <iostream>
#include <string>
#include <time.h>
#include <Windows.h>

#include "Customer.hpp"

using namespace std;

class DynamicMenu {

public:
    int getUserChoice(string* items, int numItems)
    {
        int curSel = 0, textAttrib;
        bool selectionMade = false, needsUpdate = true; // we want to clearscreen first time through

        while (!selectionMade)
        {

            // only redraw the screen if something has changed, or we're on the first iteration of
            // our while loop.
            if (needsUpdate)
            {
                system("cls");
                needsUpdate = false;

                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
                cout << "Main Menu" << endl;
                cout << "(navigate with arrow keys, select with enter)" << endl << endl;
                for (int i = 0; i < numItems; i++)
                {
                    if (i == curSel)
                        textAttrib = 11;
                    else
                        textAttrib = 15;

                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), textAttrib);

                    if (i)
                        cout << endl;

                    cout << "\t" << "\t" << items[i];
                }
            }

            if (GetAsyncKeyState(VK_UP) != 0)
            {
                curSel--;
                needsUpdate = true;
            }

            else if (GetAsyncKeyState(VK_DOWN) != 0)
            {
                curSel++;
                needsUpdate = true;
            }

            else if (GetAsyncKeyState(VK_RETURN) != 0)
                selectionMade = true;

            if (curSel < 0)
                curSel = numItems - 1;
            else if (curSel > (numItems - 1))
                curSel = 0;
            Sleep(100);
        }
        char dummy[10];
        cin.getline(dummy, 10);   // clear the enter key from the kbd buffer
        return curSel;
    }
};

#endif // DYNAMICMENU_H
