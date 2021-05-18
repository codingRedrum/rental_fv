#include "Token.h"

Token* Generator::_token;

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