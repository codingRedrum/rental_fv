/***********************************************************************************************************************************
** Dissemination of this information or reproduction of this material is strictly forbidden unless prior written permission is obtained
** from Adrian Juszczak. Access to the source code contained herein is hereby forbidden.

**              © All Rights Reserved Created by Adrian Juszczak.
*/

#include "Token.h"

Token* Generator::_token;

Generator::Generator() {
    _ptrToken = new Token * *[_row];
    for(size_t i = 0; i < _row; i++) {
        _ptrToken[i] = new Token * [_column];
    }
    for(size_t i = 0; i < _row; i++) {
        for(size_t j = 0; j < _column; j++) {
            _ptrToken[i][j] = new Token;
        }
    }
    setNewToken();
}

Generator::~Generator() {
    for(size_t i = 0; i < _row; i++) {
        for(size_t j = 0; j < _column; j++)
            delete[] _ptrToken[i][j];
        delete[] _ptrToken[i];
    }
    delete[] _ptrToken;
}

void Generator::setNewToken() {

    for (size_t i = 0; i < 5; i++) {
        for (size_t j = 0; j < 5; j++) {
            _ptrToken[i][j]->setToken();
        }
    }
}

void Token::setToken() {
    int _tmpValue;
    string _tmpToken, _tmpString;

    for (size_t i = 0; i < 2; i++) {
        for (size_t j = 0; j < 6; j++) {
            _tmpValue = rand() % 2;
            _tmpString = to_string(_tmpValue);
            _tmpToken.append(_tmpString);
        }
    }
    _pin = stoi(_tmpToken, 0, 2);
}

int Generator::getRandomToken() {
        size_t _row = rand() % 5, _column = rand() % 5;

        return _ptrToken[_row][_column]->getToken(); 
}