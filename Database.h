/***********************************************************************************************************************************
** Dissemination of this information or reproduction of this material is strictly forbidden unless prior written permission is obtained
** from Adrian Juszczak. Access to the source code contained herein is hereby forbidden.

**              © All Rights Reserved Created by Adrian Juszczak.
*/


//#ifndef DATABASE_H
//#define DATABASE_H
#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string>
#include "sql/sqlite3.h"

using namespace std;

static int callback(void *NotUsed, int argc, char **argv, char **azColName) {
    int i;
    for(i = 0; i < argc; i++) {
        printf("%s = %s\n", azColName[i], argv[i] ? argv[i] : "NULL");
    }
    printf("\n");
    return 0;
}

class Database {

    sqlite3 *db;
    char *zErrMsg = 0;
    int rc;
    const char *sql;
    const char* data = "Callback function called";

public:
    void openDB();
    void createTableDB();
    void insertRowDB(string sqlStatement);
    void selectFromDB();
    void updateDB();
    void successCheck();
    void deleteFromDB(string sqlStatement);
    void closeDB();
};


//#endif // DATABASE_H
