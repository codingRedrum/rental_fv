#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string>

// additional headers
// #include "sql/sqlite3.h"// WINDOWS "sql/sqlite3.h"
#include "Database.h"
#include "LoadData.h"
#include "Data.h"
#include "LoadNumbers.h"
#include "DynamicWelcomeScreen.h"
#include "DynamicMenu.h"
#include "Customer.hpp"
#include "Management.hpp"

/////////////////////////////////////////////////////////////////////// CUSTOMER //////////////////////////////////////////////////////////////////
void create(Customer *tab[]) {
    tab[0] = new Premium;
    tab[1] = new VIP;
}

void fun(Customer *tab[]) {
    tab[0]->returnTypeOfCustomer();
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

using namespace std;

int main () {

    Database a;
    a.openDB();
    a.deleteFromDB("SELECT * from USERS");

////////////////////////////////////////////////////////////////
////////////// DATA, LOAD DATA, LOAD NUMBERS FINISHED //////////
    LoadData * lD = new LoadData;
    LoadNumbers * lN = new LoadNumbers;

    Data * ptr = lN;
    ptr->getData();

    

    DynamicWelcomeScreen DWS;
    DWS.backgroundArray();
    DWS.replaceBackgroundArray("WELCOME TO CAR RENTAL ", 2, 14);
    DWS.replaceBackgroundArray("2021 Adrian Juszczak All Rights Reserved", 5, 5);
    DWS.displayArray();

    string Menu[] = { "Log in", "Exit" };
    
    char * wsk = nullptr;

    if(wsk) {
        cout << "true" << endl;
    } else
        cout << "false" << endl;

    ////////////////////////////// DYNAMIC MENU FOR WINDOWS ////////////////////////////////////
//    DynamicMenu dM;
//    int selection;
//    selection = dM.getUserChoice(Menu, sizeof(Menu) / sizeof(Menu[0]));
//    cout << "You chose: " << Menu[selection] << endl;


    
////////////////////////////////    CUSTOMER ///////////////////////////////////
    Customer * ptrCustomer[2];

    Management m_A;
    m_A.abstractPremiumCustomer(ptrCustomer, 2);
    ptrCustomer[0]->addCustomer();
    ptrCustomer[0]->showGivenData();
    
////////////////////////////////////////////////////////////////

    /*"INSERT INTO USERS (ID,NAME,SURNAME,LOGIN,PASSWORD,AGE,ADDRESS,CITY) "  \
  "VALUES (1, 'ADRIAN','JUSZCZAK','KURCZAK','KURCZAK',30,'SZCZECIN','SZCZECIN' );";*/
    

   

}
