#include "DynamicWelcomeScreen.h"
#include <string>
#include <Windows.h>


auto DynamicWelcomeScreen::backgroundArray() -> char ** {
    for (size_t i = 0; i < rows; i++) {
        for (size_t j = 0; j < columns; j++) {
            if (i == 0 && j == j) {
                newArray[i][j] = '=';
            } else if (i == 7 && j == j) {
                newArray[i][j] = '=';
            } else if ((i > 0 && i < 7) && j == 0) {
                newArray[i][j] = '|';
            } else if ((i > 0 && i < 7) && j == 49) {
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
                //Sleep(50); use it for windows
                Sleep(10);
            } else if (i == 5) {
                //Sleep(50); use it for windows
                Sleep(10);
            } else {
                //Sleep(50); use it for windows
                Sleep(1);
            }
            cout << newArray[i][j];
            //Sleep(50); use it for windows
           // Sleep(1);
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
