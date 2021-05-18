#include "Customer.hpp"


bool Premium::returnTypeOfCustomer()  {
    return _classPREMIUM;
}
bool VIP::returnTypeOfCustomer() {
    return _classVIP;
}

void Premium::addCustomer() {
    cout << "\t\t WELCOME TO THE PREMIUM CLASS \n"
    << "To finish reservation process we'll ask you to fill given fields.  \n";
    cout << "Name: "; cin >> this->_name;
    cout << "Surname: "; cin >> this->_fName;
    cout << "Street: "; cin >> this->_street;
    cout << "City: "; cin >> this->_city;

}


void Premium::showGivenData() {
    cout << "\nPremium customer: \n"
         << "Name: " <<  this->_name << "\n"
         << "Surname: " << this->_fName << "\n"
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
    cout << "Name: "; cin >> this->_name;
    cout << "Surname: "; cin >> this->_fName;
    cout << "Street: "; cin >> this->_street;
    cout << "City: "; cin >> this->_city;
    cout << endl;
    // dodatkowe info priv
}

void VIP::showGivenData() {
    cout << "\nVIP customer: \n"
         << "Name: " <<  this->_name << "\n"
         << "Surname: " << this->_fName << "\n"
         << "Street: " << this->_street << "\n"
         << "City: " << this->_city << "\n"
         << endl;
}

void VIP::welcomePriorToShowedData() {
    system("CLS");
    cout << "***************** VIP *******************\n"
         << "You have provided following data: \n";
}