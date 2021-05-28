/*
Dissemination of this information or reproduction of this material is strictly forbidden unless prior written permission is obtained
from Adrian Juszczak. Access to the source code contained herein is hereby forbidden.

© All Rights Reserved Created by Adrian Juszczak.
*/

#include "DynamicWelcomeScreen.h"
#include <string>
#include <Windows.h>


auto DynamicWelcomeScreen::backgroundArray() -> char ** {
    for (size_t i = 0; i < rows; i++) {
        for (size_t j = 0; j < columns; j++) {
            if (i == 0 && j == j) {
                newArray[i][j] = '=';
            } else if (i == 19 && j == j) {
                newArray[i][j] = '=';
            } else if ((i > 0 && i < 19) && j == 0) {
                newArray[i][j] = '|';
            } else if ((i > 0 && i < 19) && j == 99) {
                newArray[i][j] = '|';
            } else {
                newArray[i][j] = ' ';
            }
        }
    }
    return newArray;
}

auto DynamicWelcomeScreen::replaceBackgroundArray(const char* txtToBeReplaced, size_t row, size_t column) -> char** {
    int lenght = strlen(txtToBeReplaced);

    for (size_t i = 0; i < lenght; i++) {
        newArray[row][column++] = *(txtToBeReplaced++);
    }
    return newArray;
}

auto DynamicWelcomeScreen::displayArray() -> void  {
    for (size_t i = 0; i < rows; i++) {
        for (size_t j = 0; j < columns; j++) {
            if (i == 2) {
                Sleep(0);
            } else if (i == 5) {
                Sleep(0);
            } else {
                Sleep(0);
            }
            cout << newArray[i][j];
        }
        cout << endl;
    }
}

auto DynamicWelcomeScreen::stringToChar(string txt) {
    tmpString = txt.c_str();
}

auto DynamicWelcomeScreen::returnArray() -> char **  {
    return newArray;
}
