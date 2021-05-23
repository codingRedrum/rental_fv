//  Created by Adrian Juszczak on 03/05/2021.

#include "Management.hpp"

DynamicWelcomeScreen* Management::ptrDWS;
Generator* Management::ptrGENE;
Data* Management::ptrLoadDATA;

auto Management::abstractArrayOfCustomer(Customer* tab[]) -> void {
    tab[0] = new Premium;
    tab[1] = new VIP;
}

auto Management::chooseCustomerClass() -> void {
A:
    int _choose;
    system("CLS");
    cout << endl
        << " Hi, type in according to given information .\n\n"
        << " 1. I will rent the car for less than 10 days \n\n"
        << " 2. I will rent the car for more then 10 days \n"


        << " Choose correct number: ";

    cin >> _choose;

    switch (_choose)
    {
    case 1:
        ptrCUSTOMER[0] = new Premium;
        customer = 0;
        choosedScreen("WELCOME TO THE PREMIUM CLASS ", 2, 12);
        break;

    case 2:
        ptrCUSTOMER[1] = new VIP;
        choosedScreen("WELCOME TO THE VIP CLASS ", 2, 12);
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
    switch(customer)	{
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

void Management::setCars(){
    ptrVEHICLE = new Car;
    ptrVEHICLE->checkDB();
    ptrVEHICLE->createVehicleList();
    ptrVEHICLE->loadData();
    ptrVEHICLE->showHiddenDetailsSportCar();
    ptrVEHICLE->removeVehicle();
    ptrVEHICLE->showHiddenDetailsSportCar();

}

auto Management::addCustomer() -> void {
    system("CLS");
    ptrCUST->addCustomer();
}

auto Management::abstractPremiumCustomer(Customer* tab[], size_t size) -> void {
    for (int i = 0; i < size; i++) {
        tab[i] = new Premium;
    }
}

auto Management::vipCustomer(Customer* tab[], size_t size) -> void {
    for (int i = 0; i < size; i++) {
        tab[i] = new VIP;
    }
}

auto Management::deleteVipCustomer(Customer* tab[], size_t size) -> void {
    for (int i = 0; i < size; i++) {
        delete tab[i];
    }
}

auto Management::deletePremiumCustomer(Customer* tab[], size_t size) -> void {
    for (int i = 0; i < size; i++) {
        delete tab[i];
    }
}

auto Management::create(Customer* tab[]) -> void {
    tab[0] = new Premium;
    tab[1] = new VIP;
}

auto Management::returnCustomerType(Customer* wsk) -> void {
    
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
    ptrDWS->replaceBackgroundArray("WELCOME TO THE CAR RENTAL ", 2, 12);
    ptrDWS->replaceBackgroundArray("2021 Adrian Juszczak All Rights Reserved", 5, 5);
    ptrDWS->displayArray();
    Sleep(3000);
}

auto Management::choosedScreen(const char* txt, size_t rows, size_t columns) -> void {
    ptrDWS = new DynamicWelcomeScreen;
    system("CLS");
    ptrDWS->backgroundArray();
    ptrDWS->replaceBackgroundArray(txt, rows, columns);
    ptrDWS->replaceBackgroundArray("2021 Adrian Juszczak All Rights Reserved", 5, 5);
    ptrDWS->displayArray();
    Sleep(3000);
    delete ptrDWS;
}
////////////////////////// DYNAMIC MENU /////////////////////////////////////
auto Management::startDynamicMenu() -> int
{
    string tmpLogin;
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
        }

        if(curSel < 0){
            curSel = numItems - 1;
        }
        else if(curSel > (numItems - 1))
            curSel = 0;

        Sleep(100);
    }
    return curSel;
}

////////////////////////// LOAD DATA ////////////////////////////////////

auto Management::checkLogin() -> bool {
    string tmpLogin;
    system("CLS");
    cout << "Type your login:"; cin >> tmpLogin;
    if(ptrDATA[0]->checingSystem(tmpLogin))	{
        return true;
    }
    else	{
        cout << "Apparently you aren't our customer. You can sign up. \n";
        return false;
    }
}


////////////////////////// STOP ////////////////////////////////////////
auto summaryStop() -> void{
    cout << "Thank you for choosing rental with us. \n"
         << "We are hoping to see you soon! \n";
}