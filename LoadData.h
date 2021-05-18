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

class LoadData  {
    friend class Car;
public:
    auto loadData() -> void;
};

//#endif // LOADDATA_H


// uzyc techniki delegowania konstruktorow













//string  loadStrings(string imie, string nazwisko, string login, string password) {

////    string createdSQL = "'" + imie +  "', '" += nazwisko + "', '" + login + "', '" + password + "'";

////    return createdSQL;
//}
