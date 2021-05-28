/*
Dissemination of this information or reproduction of this material is strictly forbidden unless prior written permission is obtained
from Adrian Juszczak. Access to the source code contained herein is hereby forbidden.

© All Rights Reserved Created by Adrian Juszczak.
*/

#include "Management.hpp"

DynamicWelcomeScreen* Management::ptrDWS;
Generator* Management::ptrGENE;
Data* Management::ptrLoadDATA;

void Management::whatNext() {
    switch(choose) {
        case 0:
            checkLogin();
            break;
        case 1:
            chooseCustomerClass();
            signUp();
            break;
        case 2:
            system("CLS");
            goodBye();
            Sleep(5000);
            removeStaticData();
            exit(0);
        default:
            cout << "Try once again. \n";
            break;
    }
}

auto Management::chooseCustomerClass() -> void {
A:
    int _choose;
    system("CLS");
    cout << endl;
    ptrDWS->replaceBackgroundArray("Hi, type in according to given information .", 2, 30);
    ptrDWS->replaceBackgroundArray("1. I will rent the car for less than 10 days .", 5, 30);
    ptrDWS->replaceBackgroundArray("2. I will rent the car for more then 10 days", 6, 30);
    ptrDWS->replaceBackgroundArray("Choose correct number: ", 12, 30);
    ptrDWS->displayArray();
    cin >> _choose;

    switch(_choose)     {
        case 1:
            ptrCUSTOMER[0] = new Premium;
            createContainer(_choose);
            customer = 0;
            choosedScreen("WELCOME TO THE PREMIUM CLASS ", 2, 35);
            break;

        case 2:
            ptrCUSTOMER[1] = new VIP;
            createContainer(_choose);
            choosedScreen("WELCOME TO THE VIP CLASS ", 2, 35);
            customer = 1;
            break;

        default:
            system("CLS");
            Sleep(200);
            cout << "\n\t Choose correct number \n";
            Sleep(2000);
            goto A;
    }
}

void Management::signUp() {
    switch(customer) {
        case 0:
            ptrCUSTOMER[0]->addCustomer();
            ptrCUSTOMER[0]->welcomePriorToShowedData();
            ptrCUSTOMER[0]->showGivenData();
            break;
        case 1:
            ptrCUSTOMER[1]->addCustomer();
            ptrCUSTOMER[1]->welcomePriorToShowedData();
            ptrCUSTOMER[1]->showGivenData();
        default:
            break;
    }
}

void Management::setCars() {
    ptrVEHICLE = new Car;
    ptrVEHICLE->checkDB();
    ptrVEHICLE->createVehicleList();
    ptrVEHICLE->loadData();
    ptrVEHICLE->showHiddenDetailsSportCar();
    ptrVEHICLE->removeVehicle();
    ptrVEHICLE->showHiddenDetailsSportCar();
}

void Management::summarizeRent() {
    ofstream myfile;
    myfile.open("savedData.txt", std::ios_base::app);
    system("CLS");
    cout << "\n************************************ SHORT SUMMARIZING OF YOUR RENT ******************************** \n\n";
    cout << setw(18) << left << "Name: "
         << setw(18) << left << "Surname: "
         << setw(18) << left << "Street: "
         << setw(18) << left << "City: "
         << setw(18) << left << "Rent from: "
         << "Rent to: \n";
    cout << "----------------------------------------------------------------------------------------------------- \n";
   
    ptrCUSTOMER[customer]->getDataHoritontal();
    for(size_t i = 0; i < genericNrOfData; i++) 		{
        cout << setw(18) << left << startRent[i].returnDate()  << stopRent[i].returnDate();
        if(myfile.is_open()) {
            myfile << startRent[i].returnDate(); myfile << ";";
            myfile << stopRent[i].returnDate(); myfile << ";";
            myfile << "\n";
            myfile.close();
        }
    }
    Sleep(5000);

}

void Management::goodBye() {
    choosedScreen("GOOD BYE HOPE TO SEE U AGAIN ", 2, 38);
    delete[] ptrDATA;
}

void Management::setDataToGenericClass(string start, string stop) {
    startRent.addDate(RentalStart(start));
    stopRent.addDate(RentalStop(stop));
    genericNrOfData++;
}

void Management::periodOfRental() {
    string dateFrom, dateTo;
    cout << endl << endl;
    cout << "For how long would you like to rent the car.\n"
         << "You have to provide data using dd.mm.yyy format.\n"
         << "Rental from: "; cin >> dateFrom;
    cout << "Rental to: "; cin >> dateTo;
    setDataToGenericClass(dateFrom, dateTo);
}

auto Management::addCustomer() -> void {
    system("CLS");
    ptrCUST->addCustomer();
}

auto Management::wecomeClassTypePriorCustomerData() ->void {

    ptrCUST = new Premium;
    Sleep(1000);
    ptrCUST->welcomePriorToShowedData();
    Sleep(2000);
    ptrCUST->showGivenData();
    Sleep(3000);

    ptrCUST = new VIP;
    Sleep(1000);
    ptrCUST->welcomePriorToShowedData();
    Sleep(2000);
    ptrCUST->showGivenData();
    Sleep(3000);

    delete ptrCUST;
}
////////////////////////// START ////////////////////////////////////
auto Management::startManagemantWelcomeScreen() -> void {
    system("CLS");
    ptrDWS->backgroundArray();
    ptrDWS->replaceBackgroundArray("WELCOME TO THE CAR RENTAL ", 2, 38);
    ptrDWS->replaceBackgroundArray("2021 Adrian Juszczak All Rights Reserved", 18, 30);
    ptrDWS->displayArray();
    Sleep(3000);
}

auto Management::choosedScreen(const char* txt, size_t rows, size_t columns) -> void {
    ptrDWS = new DynamicWelcomeScreen;
    system("CLS");
    ptrDWS->backgroundArray();
    ptrDWS->replaceBackgroundArray(txt, rows, columns);
    ptrDWS->replaceBackgroundArray("2021 Adrian Juszczak All Rights Reserved", 18, 30);
    ptrDWS->displayArray();
    Sleep(3000);
    
}
////////////////////////// DYNAMIC MENU /////////////////////////////////////
auto Management::startDynamicMenu() -> int {
    string tmpLogin;
    int curSel = 0, textAttrib;
    bool selectionMade = false, needsUpdate = true; 
    while(!selectionMade) {
        if(needsUpdate) {
            system("cls");
            needsUpdate = false;

            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
            cout << endl << endl << endl;
            cout << setw(20) << left << "\t\t\t\t Main Menu" << endl;
            cout << setw(20) << left << "\t\t(navigate with arrow keys, select with enter)" << endl << endl;
            for(int i = 0; i < numItems; i++) {
                if(i == curSel)
                    textAttrib = 12;
                else
                    textAttrib = 11;

                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), textAttrib);

                if(1)
                    cout << endl;

                cout << setw(20) << left  << "\t" << "\t" << items[i];
            }
        }

        if(GetAsyncKeyState(VK_UP) != 0) {
            curSel--;
            needsUpdate = true;
        }

        else if(GetAsyncKeyState(VK_DOWN) != 0) {
            curSel++;
            needsUpdate = true;
        }

        else if(GetAsyncKeyState(VK_RETURN) != 0) {
            selectionMade = true;
        }

        if(curSel < 0) {
            curSel = numItems - 1;
        }
        else if(curSel > (numItems - 1))
            curSel = 0;

        Sleep(100);
    }
    return curSel;
}

////////////////////////// LOAD DATA ////////////////////////////////////
auto Management::checkLogin() -> void {
    string tmpLogin;
    string txt[3] {"Something wen't wrong. \n", "Apparently you aren't our customer. Try once again. \n", "You will be forwarded to main menu where you can Sign Up! \n"};
    system("CLS");
    for(size_t i = 0; i < 3; i++) {
        cout << "Type your login:"; cin >> tmpLogin;
        if(ptrDATA[0]->checingSystem(tmpLogin)) {
            setCars();
            periodOfRental();
            ptrDATA[0]->getPointerXXXX(LoadData::_numberOnList);
            goodBye();
            Sleep(5000);
            exit(0);
        }
        else {
            system("CLS");
            cout << txt[i];
            Sleep(3000);
            system("CLS");
        }
    }
}

////////////////////////////// RUN SYSTEM ///////////////////////////////////
void Management::runSystem() {
    ptrDATA[0] = new LoadData;
    createStaticData();
    startManagemantWelcomeScreen();
    ptrLoadDATA->getNumberOfCustomers();
    ptrLoadDATA->createData();
    ptrLoadDATA->loadData();
    choose = startDynamicMenu();
    whatNext();
    setCars();
    periodOfRental();
    summarizeRent();
    goodBye();
}