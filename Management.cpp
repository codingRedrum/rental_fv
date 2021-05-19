//  Created by Adrian Juszczak on 03/05/2021.

#include "Management.hpp"


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
        << " 1. I've already rented a car more then 10 times \n"
        << " 2. I've rented car less than 10 times \n\n"
        << " Choose correct number: ";

    cin >> _choose;

    switch (_choose)
    {
    case 1:
        ptrCUST = new Premium;
        ptrMANA = new Management;
        ptrMANA->choosedScreen("WELCOME TO THE PREMIUM CLASS ", 2, 12);
        delete ptrMANA;
        break;
    case 2:
        ptrCUST = new VIP;
        ptrMANA = new Management;
        ptrMANA->choosedScreen("WELCOME TO THE VIP CLASS ", 2, 12);
        delete ptrMANA;
        break;
    default:
        system("CLS");
        Sleep(200);
        cout << "\n\t Choose correct number \n";
        Sleep(2000);
        goto A;
    }
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
    ptrDWS = new DynamicWelcomeScreen;
    system("CLS");
    ptrDWS->backgroundArray();
    ptrDWS->replaceBackgroundArray("WELCOME TO THE CAR RENTAL ", 2, 12);
    ptrDWS->replaceBackgroundArray("2021 Adrian Juszczak All Rights Reserved", 5, 5);
    ptrDWS->displayArray();
    Sleep(3000);
    delete ptrDWS;
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

auto Management::startDynamicMenu() -> void {
    ptrDM = new DynamicMenu;
    ptrDM->getUserChoice(menuTab, 3);
}

auto Management::deleteDynamicMEnu() -> void {
    delete ptrDM;
}