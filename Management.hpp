#ifndef Management_hpp
#define Management_hpp

#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

#include "Customer.hpp"
#include "DynamicWelcomeScreen.h"
#include "Vehicle.h"
#include "LoadData.h"

extern Data* ptrDATA[2];

class Management {
    static Data* ptrLoadDATA;
    static DynamicWelcomeScreen* ptrDWS;
    static Generator* ptrGENE;
    Management* ptrMANA;
    Customer* ptrCUSTOMER[3];
    Customer* ptrCUST;
    Vehicle* ptrVEHICLE;
    char** arrayDWS;
    string items[3] = { "Sign in", "Sign up", "EXIT" };
    int numItems {3};
    int choose;
    int _choose;
    int customer;
    size_t choosenCar;
public:
    // 1. SET STATIC DATA INTO RUNNING MODE 
    /////////////////////////////// STATIC DATA //////////////////////////////////////
    static void createStaticData(){
        ptrLoadDATA = new LoadData;
        ptrDWS = new DynamicWelcomeScreen;
        ptrGENE = new Generator;
    }
    static void removeStaticData(){
        delete ptrLoadDATA;
        delete ptrDWS;
        delete ptrGENE;
    }
    ///////////////////////  RUN THE WHOLE SYSTEM ///////////////////////////////////////////
    void runSystem(){
        ptrDATA[0] = new LoadData;
        createStaticData();
        startManagemantWelcomeScreen();
        ptrLoadDATA->getNumberOfCustomers();
        ptrLoadDATA->createData();
        ptrLoadDATA->loadData();
        choose = startDynamicMenu();
        whatNext();
        setCars();
    }
 
    void whatNext(){
        switch(choose)	{
            case 0:
                checkLogin();
                break;
            case 1:
                chooseCustomerClass();
                signUp();
                break;
            case 2:
                system("CLS");
                ptrDWS->backgroundArray();
                ptrDWS->replaceBackgroundArray("GOOD BYE HOPE TO SEE U AGAIN", 2, 11);
                ptrDWS->replaceBackgroundArray("2021 Adrian Juszczak All Rights Reserved", 5, 5);
                ptrDWS->displayArray();
                Sleep(5000);
                removeStaticData();

                exit(0);
            default:
                cout << "Try once again. \n";
                break;
        }
    }

    void signUp();
    void setCars();

    // ///////////////////////////// CUSTOMER //////////////////////////////////////
    auto abstractArrayOfCustomer(Customer* tab[]) -> void;
    auto chooseCustomerClass() -> void;
    auto addCustomer() -> void; 
    auto abstractPremiumCustomer(Customer *tab[], size_t size) -> void; 
    auto vipCustomer(Customer* tab[], size_t size) -> void; 
    auto deleteVipCustomer(Customer* tab[], size_t size) -> void;
    auto deletePremiumCustomer(Customer* tab[], size_t size) -> void;
    auto create(Customer* tab[]) -> void;  
    auto returnCustomerType(Customer* wsk) -> void;
    auto wecomeClassTypePriorCustomerData() ->void;

    ////////////////////// DYNAMIC WELCOME SCREEN ///////////////////////////////////
    auto startManagemantWelcomeScreen() -> void;
    auto choosedScreen(const char* txt, size_t rows, size_t columns) -> void;

    ////////////////////////// START DYNAMIC MENU ////////////////////////////////////
    auto startDynamicMenu() -> int;
    auto deleteDynamicMEnu() -> void;

    ////////////////////////// LOAD DATA ///////////////////////////////////////////
    auto checkLogin() -> bool;

    ////////////////////////// STOP ///////////////////////////////////////////////
    auto summaryStop() -> void;
};

#endif /* Management_hpp */
