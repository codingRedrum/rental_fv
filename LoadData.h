/*
Dissemination of this information or reproduction of this material is strictly forbidden unless prior written permission is obtained
from Adrian Juszczak. Access to the source code contained herein is hereby forbidden.

© All Rights Reserved Created by Adrian Juszczak.
*/

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
#include "RentalHistory.h"

using namespace std;
extern GenericClass<string> test;
extern GenericClass<RentalStart> startRent;
extern GenericClass<RentalStop> stopRent;
extern int genericNrOfData;
class Data {
public:
    virtual void createData() = 0;
    virtual auto loadData() -> void = 0;
    virtual void getNumberOfCustomers() = 0;
    virtual void getData() = 0;
    virtual void checkLogin(string login) = 0;
    virtual bool checingSystem(string) = 0;
    virtual void getPointerXXXX(int nmb) = 0;
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
        void summarizeLoadData();
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
    void getPointerXXXX(int nmb);
    void checkLogin(string login);
    bool checingSystem(string login);
    static int _numberOnList;
};

