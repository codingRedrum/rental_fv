/***********************************************************************************************************************************
** Dissemination of this information or reproduction of this material is strictly forbidden unless prior written permission is obtained
** from Adrian Juszczak. Access to the source code contained herein is hereby forbidden.

**              © All Rights Reserved Created by Adrian Juszczak.
*/

#include "Customer.hpp"

extern Generator gen;

void Premium::addCustomer() {
    system("CLS");
    cout << "\t\t WELCOME TO THE PREMIUM CLASS \n"
    << "To finish reservation process we'll ask you to fill given fields.  \n";
    cout << "Name: "; cin >> this->_imie;
    cout << "Surname: "; cin >> this->_nazwisko;
    cout << "Street: "; cin >> this->_street;
    cout << "City: "; cin >> this->_city;
    this->_password = gen.getRandomToken();
}


void Premium::showGivenData() {
    cout << "Name: " << this->_imie << "\n"
        << "Surname: " << this->_nazwisko << "\n"
        << "Street: " << this->_street << "\n"
        << "City: " << this->_city << "\n\n";
    Sleep(1000);
    int rndToken = gen.getRandomToken();
    cout << "Your random token is: " << rndToken << endl;
    Sleep(3000);
    system("CLS");

    ofstream myfile;
    myfile.open("savedData.txt", std::ios_base::app);

    if(myfile.is_open()) {
        myfile << "PREMIUM"; myfile << ";";
        myfile << this->_imie; myfile << ";";
        myfile << this->_nazwisko; myfile << ";";
        myfile << this->_street; myfile << ";";
        myfile << this->_city; myfile << ";";
        myfile << this->_imie + this->_nazwisko; myfile << ";";
        myfile << rndToken;
        myfile.close();
    }
}

void Premium::welcomePriorToShowedData() {
    system("CLS");
    cout << "***************** PREMIUM *******************\n"
         << "You have provided following data: \n";
    Sleep(1000);
}

void Premium::getDataHoritontal() {
    cout << setw(18) << left << this->_imie 
         << setw(18) << left << this->_nazwisko 
         << setw(18) << left << this->_street 
         << setw(18) << left << this->_city;
}


void VIP::addCustomer() {
    system("CLS");
    cout << "\t\t WELCOME TO THE VIP CLASS \n"
    << "To finish reservation process we'll ask you to fill given fields.  \n";
    cout << "Name: "; cin >> this->_imie;
    cout << "Surname: "; cin >> this->_nazwisko;
    cout << "Street: "; cin >> this->_street;
    cout << "City: "; cin >> this->_city;
    this->_password = gen.getRandomToken();
}

void VIP::showGivenData() {
    cout << "\nVIP customer: \n"
        << "Name: " << this->_imie << "\n"
        << "Surname: " << this->_nazwisko << "\n"
        << "Street: " << this->_street << "\n"
        << "City: " << this->_city << "\n\n";
    Sleep(1000);
    int rndToken = gen.getRandomToken();
    cout << "Your random token is: " << rndToken << endl;
    Sleep(3000);
    system("CLS");

    ofstream myfile;
    myfile.open("savedData.txt", std::ios_base::app);

    if(myfile.is_open()) {
        myfile << "\n";
        myfile << "VIP"; myfile << ";";
        myfile << this->_imie; myfile << ";";
        myfile << this->_nazwisko; myfile << ";";
        myfile << this->_street; myfile << ";";
        myfile << this->_city; myfile << ";";
        myfile << this->_imie + this->_nazwisko; myfile << ";";
        myfile << rndToken;
        myfile.close();
    }
}

void VIP::welcomePriorToShowedData() {
    system("CLS");
    cout << "***************** VIP *******************\n"
         << "You have provided following data: \n";
}
void VIP::getDataHoritontal() {
    cout << setw(18) << left << this->_imie
         << setw(18) << left << this->_nazwisko
         << setw(18) << left << this->_street
         << setw(18) << left << this->_city;
}