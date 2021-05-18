#include "database.h"
#include "sql/sqlite3.h"


void database::opendb() {

    rc = sqlite3_open("test.db", &db);

    if( rc ) {
        fprintf(stderr, "can't open database: %s\n", sqlite3_errmsg(db));

    } else {
        fprintf(stderr, "opened database successfully\n");
    }
}

void database::createtabledb() {
    /* create sql statement */
    sql = "create table users("  \
          "id int primary key     not null," \
          "name           text    not null," \
          "surname        text    not null," \
          "login          text    not null," \
          "password       text    not null," \
          "age            int     not null," \
          "address        char(50)," \
          "city           char(50) );";

    /* execute sql statement */
    rc = sqlite3_exec(db, sql, callback, 0, &zerrmsg);

    if( rc != sqlite_ok ){
        fprintf(stderr, "sql error: %s\n", zerrmsg);
        sqlite3_free(zerrmsg);
    } else {
        fprintf(stdout, "records created successfully\n");
    }
}

void database::insertrowdb(string sqlstatement) {
    /* create sql statement */
    sql = sqlstatement.c_str();
    /* execute sql statement */
    rc = sqlite3_exec(db, sql, callback, 0, &zerrmsg);
    if( rc != sqlite_ok ) {
        fprintf(stderr, "sql error: %s\n", zerrmsg);
        sqlite3_free(zerrmsg);
    } else {
        fprintf(stdout, "operation done successfully\n");
    }
    sqlite3_close(db);
}

void database::selectfromdb() {

    /* create sql statement */
    sql = "select * from users";

    /* execute sql statement */
    rc = sqlite3_exec(db, sql, callback, (void*)data, &zerrmsg);
}

void database::updatedb() {

    if( rc ) {
        fprintf(stderr, "can't open database: %s\n", sqlite3_errmsg(db));
    } else {
        fprintf(stderr, "opened database successfully\n");
    }

    /* create merged sql statement */
    sql = "update company set salary = 25000000.00 where id=1; " \
          "select * from company";

    /* execute sql statement */
    rc = sqlite3_exec(db, sql, callback, (void*)data, &zerrmsg);
}

void database::successcheck() {

    if( rc != sqlite_ok ) {
        fprintf(stderr, "sql error: %s\n", zerrmsg);
        sqlite3_free(zerrmsg);
    } else {
        fprintf(stdout, "operation done successfully\n");
    }
    sqlite3_close(db);
}

void database::deletefromdb(string sqlstatement) {
    /* create merged sql statement */
    sql = sqlstatement.c_str();

//               "delete from users where id=2; " \
//               "select * from users";

    /* execute sql statement */
    rc = sqlite3_exec(db, sql, callback, (void*)data, &zerrmsg);
}

void database::closedb() {
    sqlite3_close(db);
}
