#include "Customer.hpp"

extern Generator gen;

void Premium::addCustomer() {
    cout << "\t\t WELCOME TO THE PREMIUM CLASS \n"
    << "To finish reservation process we'll ask you to fill given fields.  \n";
    cout << "Name: "; cin >> this->_imie;
    cout << "Surname: "; cin >> this->_nazwisko;
    cout << "Street: "; cin >> this->_street;
    cout << "City: "; cin >> this->_city;
    this->_password = gen.getRandomToken();
}


void Premium::showGivenData() {
    cout << "\nPremium customer: \n"
        << "Name: " << this->_imie << "\n"
        << "Surname: " << this->_nazwisko << "\n"
        << "Street: " << this->_street << "\n"
        << "City: " << this->_city << "\n"
        << endl;
}

void Premium::welcomePriorToShowedData() {
    system("CLS");
    cout << "***************** PREMIUM *******************\n"
         << "You have provided following data: \n";
}


void VIP::addCustomer() {
    cout << "\t\t WELCOME TO THE VIP CLASS \n"
    << "To finish reservation process we'll ask you to fill given fields.  \n";
    cout << "Name: "; cin >> this->_imie;
    cout << "Surname: "; cin >> this->_nazwisko;
    cout << "Street: "; cin >> this->_street;
    cout << "City: "; cin >> this->_city;
    this->_password = gen.getRandomToken();
    // dodatkowe info priv
}

void VIP::showGivenData() {
    cout << "\nVIP customer: \n"
         << "Name: " <<  this->_imie << "\n"
         << "Surname: " << this->_nazwisko << "\n"
         << "Street: " << this->_street << "\n"
         << "City: " << this->_city << "\n"
         << endl;
}

void VIP::welcomePriorToShowedData() {
    system("CLS");
    cout << "***************** VIP *******************\n"
         << "You have provided following data: \n";
}