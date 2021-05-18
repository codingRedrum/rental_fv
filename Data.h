//#ifndef DATA_H
//#define DATA_H

#pragma once

#include "Token.h"
#include "sql/sqlite3.h"

using namespace std;

class Data {

    string _imie;
    string _nazwisko;
    string _login;
    int _password;

public:
    Data() : _imie{"none"}, _nazwisko{"none"}, _login{"none"}, _password{1234} {};
    // copy constructor
    Data(const Data & cp ) : _imie{cp._imie}, _nazwisko{cp._nazwisko}, _login{cp._login}, _password{cp._password} {};
    // move constructor 
    Data(Data && mv) noexcept(true) : _imie{ mv._imie }, _nazwisko{ mv._nazwisko }, _login{ mv._login }, _password{ mv._password } {};
    Data(const string & fName, const string & secName, const string & login, const int & pass);

    Data& operator=(const Data& cp) {
        if (this != &cp) {
            _imie = cp._imie;
            _nazwisko = cp._nazwisko;
            _login = cp._login;
            _password = cp._password;
        }
    }
    Data&& operator=(const Data&& mv) {
        if (this != &mv) {
            _imie = mv._imie;
            _nazwisko = mv._nazwisko;
            _login = mv._login;
            _password = mv._password;
        }
    }

    void setName(const string fName, string secName);
    void setPassword(const string pass);
    void getData ()  {

        cout << _imie << endl
             << _nazwisko << endl
             << _login << endl
             << _password << endl;
    }
};




template<class Datownik> Data* create()
{
    return new Datownik;
}

