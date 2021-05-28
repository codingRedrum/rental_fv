/*
Dissemination of this information or reproduction of this material is strictly forbidden unless prior written permission is obtained
from Adrian Juszczak. Access to the source code contained herein is hereby forbidden.

© All Rights Reserved Created by Adrian Juszczak.
*/

#ifndef Management_hpp
#define Management_hpp

#include <stdio.h>
#include <iostream>
#include <iomanip>
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
extern GenericClass<string> test;
extern GenericClass<RentalStart> startRent;
extern GenericClass<RentalStop> stopRent;
extern int genericNrOfData;
class Management {

    Management* ptrMANA;
    Customer* ptrCUSTOMER[3];
    Customer* ptrCUST;
    Vehicle* ptrVEHICLE;
    size_t choosenCar;
    vector<Customer*> klient;
    string items[3] = {"Sign in", "Sign up", "EXIT"};
    static Data* ptrLoadDATA;
    static DynamicWelcomeScreen* ptrDWS;
    static Generator* ptrGENE;
    char** arrayDWS;
    int numItems {3}, choose, _choose, customer;
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
    auto checkLogin() -> void;

};

#endif /* Management_hpp */