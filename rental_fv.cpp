
#include <iostream>

#include "Customer.hpp"
#include "Database.h"
#include "Vehicle.h"
#include "Token.h"
#include "Management.hpp"

using namespace std;
Generator gen;

int main() {

    Generator::createToken();
    Generator::addToken();


    srand(time(NULL));

    LoadData lD;
    Vehicle* tab[2];
    tab[0] = new Car;


    Management rentalManagement;
    rentalManagement.startManagemantWelcomeScreen();
    rentalManagement.startDynamicMenu();
    system("CLS");
    rentalManagement.chooseCustomerClass();
    rentalManagement.addCustomer();
    rentalManagement.wecomeClassTypePriorCustomerData();

    tab[0]->checkDB();
    cout << endl;
    tab[0]->createVehicleList();
    tab[0]->loadData();
    tab[0]->showHiddenDetailsSportCar(0);
    
    

}

