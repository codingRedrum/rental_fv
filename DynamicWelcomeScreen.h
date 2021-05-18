#ifndef DYNAMICWELCOMESCREEN_H
#define DYNAMICWELCOMESCREEN_H

#include <iostream>
#include <string>
//#include <time.h> // win
//#include <Windows.h>  // win
//#include <unistd.h>

using namespace std;

class DynamicWelcomeScreen {
    char** newArray;
    const char* tmpString;
    size_t rows = 8;
    size_t columns = 50;

public:
    DynamicWelcomeScreen() {
        newArray = new char* [rows];
        for (size_t i = 0; i < rows; i++) {
            newArray[i] = new char[columns];
        }
    }
    
    ~DynamicWelcomeScreen() {
        //Free each sub-array
        for (size_t i = 0; i < rows; i++) {
            delete[] newArray[i];
        }
        //Free the array of pointer
        delete[] newArray;
    }

    auto returnArray() -> char**;
    auto backgroundArray() -> char**;
    auto stringToChar(string txt);
    auto replaceBackgroundArray(const char* txtToBeReplaced, size_t row, size_t column) -> char**;
    auto displayArray() -> void;

};

#endif // DYNAMICWELCOMESCREEN_H
