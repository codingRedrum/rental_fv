#pragma once
//#ifndef LOADNUMBERS_H
//#define LOADNUMBERS_H

#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <iostream>

#include "sql/sqlite3.h" // WINDOWS "sql/sqlite3.h"
#include "Data.h"
#include "LoadData.h"

using namespace std;

// numbers polaczy z klientami 

class LoadNumbers : public Data {
    Data* _ptrData;
    int _quantity{ 0 };
    long long int _personalNumber;
    unsigned int _PIN;

public:
    LoadNumbers(int numb = 2) : _quantity{numb} {
        _ptrData = new Data[_quantity];
    } 

    LoadNumbers(const LoadNumbers &lN) {
        _quantity = lN._quantity;
        _ptrData = new Data[_quantity];
        for (size_t i = 0; i < _quantity; i++) {
            _ptrData[i] = lN._ptrData[i];
        }
    }



    //Data(), _personalNumber(111111), _PIN(2222) {}
    LoadNumbers(long long int pNumber);
    LoadNumbers(unsigned int PIN);
    LoadNumbers(long long int pNumber, unsigned int PIN);

    LoadNumbers(const string & fName);
    LoadNumbers(const string & fName, const string & secName);
    LoadNumbers(const string & fName, const string & secName, const string & login);
    LoadNumbers(const string & fName, const string & secName, const string & login, const string & pass);

    void getData();
};


//#endif // LOADNUMBERS_H
