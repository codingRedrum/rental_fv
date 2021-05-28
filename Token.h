/*
Dissemination of this information or reproduction of this material is strictly forbidden unless prior written permission is obtained
from Adrian Juszczak. Access to the source code contained herein is hereby forbidden.

© All Rights Reserved Created by Adrian Juszczak.
*/

#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string>
#include <cstdlib>
#include <sstream>
#include <fstream>

using namespace std;

class Token {
    int _pin;
    string _tmpToken{ "0b" };
public:
    int getToken() const { return _pin; }
    void setToken();
    friend ostream& operator<<(ostream& os, const Token* token) {
        os << "Generated token is: " << token->_pin << "\n";
        return os;
    }
};

class Generator {
    static Token* _token;
    Token*** _ptrToken;
    int _row{ 5 };
    int _column{ 5 };
    void setNewToken();

public:
    Generator();
    ~Generator();

    int getRandomToken();
    static void createToken() { _token = new Token; }
    static void addToken() { _token->setToken(); }
    static int returnToken() { 
        int _tmp = _token->getToken();
        return _tmp;
    }
};

