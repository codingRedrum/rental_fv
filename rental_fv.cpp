/***********************************************************************************************************************************
** Dissemination of this information or reproduction of this material is strictly forbidden unless prior written permission is obtained
** from Adrian Juszczak. Access to the source code contained herein is hereby forbidden.

**              © All Rights Reserved Created by Adrian Juszczak.
*/

#include <iostream>
#include "Customer.hpp"
#include "Database.h"
#include "Vehicle.h"
#include "Token.h"
#include "Management.hpp"
#include "LoadData.h"

using namespace std;
Data* ptrDATA[2];
Generator gen;
GenericClass<string> test;
GenericClass<RentalStart> startRent;
GenericClass<RentalStop> stopRent;
int genericNrOfData;

int main() {
    srand(time(NULL));
    Generator::createToken();
    Generator::addToken();
    
    Management rental_fv;

    cout << "\n\n\t\t  THE END :) \n";
    Sleep(5000);
    
    
   

 
    
    

}

