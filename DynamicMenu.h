#ifndef DYNAMICMENU_H
#define DYNAMICMENU_H

#include <time.h>

#include "Customer.hpp"
#include "Management.hpp"
#include "LoadData.h"

using namespace std;

extern Data* ptrDATA[2];

class DynamicMenu {
    string tmpLogin;
public:
    int getUserChoice(string* items, int numItems)
    {
        int curSel = 0, textAttrib;
        bool selectionMade = false, needsUpdate = true; // we want to clearscreen first time through

        while(!selectionMade){
            // only redraw the screen if something has changed, or we're on the first iteration of
            // our while loop.
            if(needsUpdate){
                system("cls");
                needsUpdate = false;

                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
                cout << "\t\t Main Menu" << endl;
                cout << "(navigate with arrow keys, select with enter)" << endl << endl;
                for(int i = 0; i < numItems; i++){
                    if(i == curSel)
                        textAttrib = 12;
                    else
                        textAttrib = 11;

                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), textAttrib);

                    if(1)
                        cout << endl;

                    cout << "\t" << "\t" << items[i];
                }
            }

            if(GetAsyncKeyState(VK_UP) != 0){
                curSel--;
                needsUpdate = true;
            }

            else if(GetAsyncKeyState(VK_DOWN) != 0){
                curSel++;
                needsUpdate = true;
            }

            else if(GetAsyncKeyState(VK_RETURN) != 0){
                selectionMade = true;
                goto stop;
            }

            if(curSel < 0){
                curSel = numItems - 1;
            }
            else if(curSel > (numItems - 1))
                curSel = 0;

            Sleep(100);
        }

        char dummy[10];
        cin.getline(dummy, 10);   // clear the enter key from the kbd buffer
        return curSel;
stop:
        switch(curSel){
            case 0:
                ptrDATA[0]->getNumberOfCustomers();
                ptrDATA[0]->createData();
                ptrDATA[0]->loadData();
                system("CLS");
                cout << endl << "Login: "; cin >> tmpLogin;
                if(ptrDATA[0]->checingSystem(tmpLogin)){
                    return true;
                }
                else{
                    cout << "Apparently you aren't our customer. You can sign up. \n";
                    return false;
                }


            case 1:
            case 2:
                cout << "koniec ";
                break;
        }

        cout << "\nafter stop: " << endl;
        cout << "curSel: " << curSel << endl;
        Sleep(2000);
    }
   
};

#endif // DYNAMICMENU_H
