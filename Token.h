#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string>
#include <cstdlib>
#include <sstream>

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
    Generator() {
        _ptrToken = new Token**[_row];
        for (size_t i = 0; i < _row; i++) {
            _ptrToken[i] = new Token*[_column];
        }
        for (size_t i = 0; i < _row; i++) {
            for (size_t j = 0; j < _column; j++) {
                _ptrToken[i][j] = new Token;
            }
        }
        setNewToken();
    }

    ~Generator() {
        for (size_t i = 0; i < _row; i++) {
            for (size_t j = 0; j < _column; j++)
                delete[] _ptrToken[i][j];
            delete[] _ptrToken[i];
        }
        delete[] _ptrToken;
    }
    int getRandomToken();
    static void createToken() { _token = new Token; }
    static void addToken() { _token->setToken(); }
    static int returnToken() { 
        int _tmp = _token->getToken();
        return _tmp;
    }
};

