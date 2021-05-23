
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
int test;

int main() {
    srand(time(NULL));
    Generator::createToken();
    Generator::addToken();
   
    // TEST
    Management rental_fv;
    rental_fv.runSystem();
   
    

    Sleep(2000);
    system("CLS");
    getchar();
    Sleep(2999);

    //Vehicle* tab[2];
    //tab[0] = new Car;
    //tab[0]->checkDB();
    //cout << endl;
    //tab[0]->createVehicleList();
    //tab[0]->loadData();
    //tab[0]->showHiddenDetailsSportCar(0);
    
    

}

