#include "Data.h"
#include "Database.h"

#include "sql/sqlite3.h" // WINDOWS "sql/sqlite3.h"


Data::Data(const string & fName, const string & secName, const string & login, const int & pass){

    this->_imie = fName;
    this->_nazwisko = secName;
    this->_login = login;
    this->_password = pass;
}

void Data::setName(const string fName, string secName) {

    this->_imie = fName;
    this->_nazwisko = secName;
}

void Data::setPassword(const string pass) {
    Generator::createToken();
    Generator::addToken();
    Generator gen;

    this->_password = gen.getRandomToken();

}


