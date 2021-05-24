#ifndef Management_hpp
#define Management_hpp

#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <limits>

#include "Customer.hpp"
#include "DynamicWelcomeScreen.h"
#include "Vehicle.h"
#include "LoadData.h"
#include "RentalHistory.h"

extern Data* ptrDATA[2];

class Management {
    GenericClass<string> test;
    GenericClass<RentalStart> startRent;
    GenericClass<RentalStop> stopRent;
    static Data* ptrLoadDATA;
    static DynamicWelcomeScreen* ptrDWS;
    static Generator* ptrGENE;
    Management* ptrMANA;
    Customer* ptrCUSTOMER[3];
    Customer* ptrCUST;
    Vehicle* ptrVEHICLE;
    char** arrayDWS;
    string items[3] = {"Sign in", "Sign up", "EXIT"};
    int numItems {3}, choose, _choose, customer, genericNrOfData;
    size_t choosenCar;
    vector<Customer*> klient;
public:
    Management() {
        runSystem();
    }
    ~Management() {
        removeStaticData();
    }
    // 1. SET STATIC DATA INTO RUNNING MODE 
    /////////////////////////////// STATIC DATA //////////////////////////////////////
    static void createStaticData() {
        ptrLoadDATA = new LoadData;
        ptrDWS = new DynamicWelcomeScreen;
        ptrGENE = new Generator;
    }
    static void removeStaticData() {
        delete ptrLoadDATA;
        delete ptrDWS;
        delete ptrGENE;
    }
    ///////////////////////  RUN THE WHOLE SYSTEM ///////////////////////////////////////////
    void runSystem();
    void whatNext();
    void signUp();
    void setCars();
    void periodOfRental();
    void setDataToGenericClass(string start, string stop);
    void summarizeRent();
    void goodBye();

    //////////////////////////////// VECTOR ///////////////////////////////////////
    void createContainer(int wybor) {
        switch(wybor) 	{
            case 0:
                klient.push_back(new Premium);
                break;
            case 1:
                klient.push_back(new VIP);
                break;
            default:
                break;
        }   
    }

    // ///////////////////////////// CUSTOMER //////////////////////////////////////
    auto chooseCustomerClass() -> void;
    auto addCustomer() -> void;
    auto wecomeClassTypePriorCustomerData() ->void;

    ////////////////////// DYNAMIC WELCOME SCREEN ///////////////////////////////////
    auto startManagemantWelcomeScreen() -> void;
    auto choosedScreen(const char* txt, size_t rows, size_t columns) -> void;

    ////////////////////////// START DYNAMIC MENU ////////////////////////////////////
    auto startDynamicMenu() -> int;
    auto deleteDynamicMEnu() -> void;

    ////////////////////////// LOAD DATA ///////////////////////////////////////////
    auto checkLogin() -> bool;

};

#endif /* Management_hpp */