#ifndef Management_hpp
#define Management_hpp

#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

#include "Customer.hpp"
#include "DynamicWelcomeScreen.h"
#include "DynamicMenu.h"
#include "Vehicle.h"

class Management {
    Management* ptrMANA;
    Customer* ptrCUST;
    DynamicMenu* ptrDM;
    DynamicWelcomeScreen* ptrDWS;
    char** arrayDWS;
    string menuTab[3] = { "Sign in", "Sign up", "EXIT" };
    int _choose;

public:

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

    ////////////////////// DYNAMIC WELCOME SCREEN /////////////////////////////
    



    ////////////////////////// START ////////////////////////////////////
    auto startManagemantWelcomeScreen() -> void;
    auto choosedScreen(const char* txt, size_t rows, size_t columns) -> void;
    auto startDynamicMenu() -> void;
    auto deleteDynamicMEnu() -> void;
};

#endif /* Management_hpp */
