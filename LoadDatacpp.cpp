#include "LoadData.h"


void LoadData::getNumberOfCustomers() {
    string line;
    int i = 0;
    ifstream file("CustomerData.txt");

    if (file.is_open()) {
        while (!file.eof()) {
            getline(file, line);
            i++;
        }
        _numberOfCustomers = i;
        cout << "Number of customers " << _numberOfCustomers << endl;      
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
    string line, buff;
    ifstream file;
    file.open("CustomerData.txt");
    int tmpValue, i = 0;

        while (!file.eof()) {
            getline(file, line);
            stringstream s_string(line);
            getline(s_string, buff, ';');
            _ptrX[i]->dataBase.push_back(buff);
            _ptrX[i]->_name = buff;
            getline(s_string, buff, ';');
            _ptrX[i]->dataBase.push_back(buff);
            _ptrX[i]->_nazwisko = buff;
            getline(s_string, buff, ';');
            _ptrX[i]->dataBase.push_back(buff);
            _ptrX[i]->_street = buff;
            getline(s_string, buff, ';');
            _ptrX[i]->dataBase.push_back(buff);
            _ptrX[i]->_city = buff;
            getline(s_string, buff, ';');
            _ptrX[i]->dataBase.push_back(buff);
            _ptrX[i]->_login = buff;
            getline(s_string, buff, ';');
            _ptrX[i]->_pass = stoi(buff);
            i++;
        }
        file.close();
}

void LoadData::AccessData::getData() {
    for (vector<string>::iterator it = dataBase.begin(); it != dataBase.end(); it++) {
        cout << setw(19) << left << *it << " ";
    }
    cout << endl;
}

void LoadData::getData() {
    cout << "\nName: \t\t Surname:\t\t Street: \t\t City: \t\t Login: " << endl
         << "------------------------------------------------------------------------------------------------" << endl;
    for (size_t i = 0; i < _numberOfCustomers; i++) {
        _ptrX[i]->getData();
    }
    cout << "------------------------------------------------------------------------------------------------" << endl;
}

void LoadData::AccessData::getNameAndSurname(){
     cout << _name << " " << _nazwisko << endl; 
}

void LoadData::checkLogin(string login) {
    size_t i = 0;
    string tmpLOG;
    int tmpPIN;
    while (i < _numberOfCustomers) {
        tmpLOG = _ptrX[i]->getLogin();
    }
}

bool LoadData::checingSystem(string login) {
    for(size_t i = 0; i < _numberOfCustomers; i++)		{
        if(login == _ptrX[i]->getLogin()) {
            cout << "Login correct! \n";
            goto PW;
        }
    }
    return false;
PW:
    int tmpPW;
    cout << "Type password: "; cin >> tmpPW;
    for(size_t i = 0; i < _numberOfCustomers; i++)		{
        if(tmpPW == _ptrX[i]->getPass())	{
            system("CLS");
            cout << " \n\n\n\t\t\t   Welcome \n\t\t\t";  _ptrX[i]->getNameAndSurname();
            Sleep(3000);
            return true;
        }
    }
    return false;
}
