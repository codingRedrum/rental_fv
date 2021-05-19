#include "LoadData.h"

int LoadData::_numberOfCustomers;

void LoadData::getNumberOfCustomers() {
    string line;
    int i = 0;

    ifstream file("SportCar.txt");

    if (file.is_open()) {
        while (!file.eof()) {
            getline(file, line);
            i++;
        }
        _numberOfCustomers = i;
        // file.close();
    }
}
void LoadData::createData() {
    XXXX** tmp = new XXXX*[_numberOfCustomers];
    for (size_t i = 0; i < _numberOfCustomers; i++) {
        tmp[i] = new XXXX;
    }
    _ptrX = tmp;
}

auto LoadData::loadData() -> void {
    string _string[10];
    string line, buff;

    int i = 0;
    ifstream file("CustomerData.txt");

    if (file.is_open()) {
        while (!file.eof()) {
            getline(file, line);
            stringstream s_string(line);

            getline(s_string, buff, ';');
            _ptrX[i]->_name = buff;
            getline(s_string, buff, ';');
            _ptrX[i]->_nazwisko = buff;
            getline(s_string, buff, ';');
            _ptrX[i]->_street = buff;
            getline(s_string, buff, ';');
            _ptrX[i]->_city = buff;
            getline(s_string, buff, ';');
            _ptrX[i]->_login = buff;
            getline(s_string, buff, ';');
            _ptrX[i]->_pass = stoi(buff);
            i++;
        }
        file.close();
    }
}

void LoadData::AccessData::getData() {
    cout << _name << "\t\t " << _nazwisko << "\t\t" << _street << "\t\t" 
         << _city << "\t\t" << _login << "\t\t" << endl;
}

void LoadData::getData() {
    cout << "Name: \t\t Surname:\t\t Street: \t\t City: \t\t Login: " << endl
         << "------------------------------------------------------------------" << endl;
    for (size_t i = 0; i < _numberOfCustomers; i++) {
        _ptrX[i]->getData();
    }
}

void LoadData::checkLogin(string login) {
    size_t i = 0;
    string tmpLOG;
    int tmpPIN;
    while (i < _numberOfCustomers) {
        tmpLOG = _ptrX[i]->getLogin();
    }
}
void LoadData::checkPass(int pw) {

}