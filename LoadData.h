#pragma once
//#ifndef LOADDATA_H
//#define LOADDATA_H
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <iostream>
#include "sql/sqlite3.h"  
#include <fstream>
#include <sstream>
#include <iomanip>
#include <Windows.h>
#include "Vehicle.h"

using namespace std;
class Data {
public:
    virtual void createData() = 0;
    virtual auto loadData() -> void = 0;
    virtual void getNumberOfCustomers() = 0;
    virtual void getData() = 0;
    virtual void checkLogin(string login) = 0;
    virtual bool checingSystem(string) = 0;
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
        vector<string> dataBase;
    public:
        void getNameAndSurname();
        string getLogin() const { return _login; }
        int getPass() const { return _pass; }
        void getData();
    } XXXX;

    XXXX** _ptrX;
    int _numberOfCustomers;
public:
    LoadData() { 
        getNumberOfCustomers();
        createData();
        loadData();
    }
    void getNumberOfCustomers();
    void createData();
    auto loadData() -> void;
    void getData();
    void checkLogin(string login);
    bool checingSystem(string login);

};

