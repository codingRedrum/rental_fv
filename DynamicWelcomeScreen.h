/***********************************************************************************************************************************
** Dissemination of this information or reproduction of this material is strictly forbidden unless prior written permission is obtained
** from Adrian Juszczak. Access to the source code contained herein is hereby forbidden.

**              © All Rights Reserved Created by Adrian Juszczak.
*/

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
    size_t rows = 20;
    size_t columns = 100;

public:
    DynamicWelcomeScreen() {
        newArray = new char* [rows];
        for (size_t i = 0; i < rows; i++) {
            newArray[i] = new char[columns];
        }
    }
    
    ~DynamicWelcomeScreen() {
        ////Free each sub-array
        //for (size_t i = 0; i < rows; i++) 
        //        delete[] newArray[columns];
        ////Free the array of pointer
        //delete[] newArray;
    }

    auto returnArray() -> char**;
    auto backgroundArray() -> char**;
    auto stringToChar(string txt);
    auto replaceBackgroundArray(const char* txtToBeReplaced, size_t row, size_t column) -> char**;
    auto displayArray() -> void;

};

#endif // DYNAMICWELCOMESCREEN_H
