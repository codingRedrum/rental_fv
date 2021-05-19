#pragma once
//#ifndef LOADDATA_H
//#define LOADDATA_H
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <iostream>
#include "sql/sqlite3.h"  // WINDOWS "sql/sqlite3.h"
#include <fstream>
#include <sstream>
#include "Vehicle.h"

using namespace std;

// zrobic abstracta dziedziczyc load cars, load customers
class Data {
public:
    virtual void createData() = 0;
    virtual auto loadData() -> void = 0;
    virtual void getNumberOfCustomers() = 0;
    virtual void getData() = 0;
    virtual void checkLogin(string login) = 0;
    virtual void checkPass(int pw) = 0;
};

class LoadData : public Data {
    typedef class AccessData {
        friend class LoadData;
        string _name;
        string _nazwisko;
        string _street;
        string _city;
        string _login;
        int _pass;
    public:
        string getLogin() const { return _login; }
        int getPass() const { return _pass; }
        void getData();
    } XXXX;

    XXXX** _ptrX;
    static int _numberOfCustomers;
public:
    LoadData() {
        getNumberOfCustomers();

    }
    void createData();
    auto loadData() -> void;
    void getNumberOfCustomers();
    void getData();
    void checkLogin(string login);
    void checkPass(int pw);
    
};

//#endif // LOADDATA_H


// uzyc techniki delegowania konstruktorow













//string  loadStrings(string imie, string nazwisko, string login, string password) {

////    string createdSQL = "'" + imie +  "', '" += nazwisko + "', '" + login + "', '" + password + "'";

////    return createdSQL;
//}
