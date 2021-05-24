#ifndef Customer_hpp
#define Customer_hpp

#include <stdio.h>
#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include "Token.h"
#include <Windows.h>

using namespace std;

class Customer {
protected:
    string _imie;
    string _nazwisko;
    string _city;
    string _street;
    string _login;
    int _password;

public:
    Customer() {}
    virtual void addCustomer() = 0;
    virtual void welcomePriorToShowedData() = 0;
    virtual void showGivenData() = 0;
    virtual void getDataHoritontal() = 0;
};

class NormalCustomer : public Customer {
public:
    NormalCustomer() {
        this->_imie = "def";
        this->_nazwisko = "def";
        this->_login = "def"; 
        this->_city = "def";
        this->_street = "def";
    };
    // copy constructor
    NormalCustomer(const NormalCustomer& cp) {
        this->_imie = cp._imie;
        this->_nazwisko = cp._nazwisko;
        this->_login = cp._login;
        this->_city = cp._city;
        this->_street = cp._street;
    };
    // move constructor 
    NormalCustomer(NormalCustomer&& mv) noexcept(true) {
        this->_imie = mv._imie;
        this->_nazwisko = mv._nazwisko;
        this->_login = mv._login;
        this->_city = mv._city;
        this->_street =mv._street;
    };

    NormalCustomer& operator=(const NormalCustomer& cp) {
        if (this != &cp) {
            _imie = cp._imie;
            _nazwisko = cp._nazwisko;
            _login = cp._login;
            _password = cp._password;
            _city = cp._city;
            _street = cp._street;
        }
    }
    NormalCustomer&& operator=(const NormalCustomer&& mv) {
        if (this != &mv) {
            _imie = mv._imie;
            _nazwisko = mv._nazwisko;
            _login = mv._login;
            _password = mv._password;
            _city = mv._city;
            _street = mv._street;
        }
    }

     void addCustomer();
     void showGivenData();
     void welcomePriorToShowedData();
     void getDataHoritontal();
private:
    float _discount{ 24.33 };
};

class Premium : public Customer {
public:
    Premium() {
        this->_imie = "def";
        this->_nazwisko = "def";
        this->_login = "def";
        this->_city = "def";
        this->_street = "def";
    };
    // copy constructor
    Premium(const Premium& cp) {
        this->_imie = cp._imie;
        this->_nazwisko = cp._nazwisko;
        this->_login = cp._login;
        this->_city = cp._city;
        this->_street = cp._street;
    };
    // move constructor 
    Premium(Premium&& mv) noexcept(true) {
        this->_imie = mv._imie;
        this->_nazwisko = mv._nazwisko;
        this->_login = mv._login;
        this->_city = mv._city;
        this->_street = mv._street;
    };

    Premium& operator=(const Premium& cp) {
        if (this != &cp) {
            _imie = cp._imie;
            _nazwisko = cp._nazwisko;
            _login = cp._login;
            _password = cp._password;
            _city = cp._city;
            _street = cp._street;
        }
    }
    Premium&& operator=(const Premium&& mv) {
        if (this != &mv) {
            _imie = mv._imie;
            _nazwisko = mv._nazwisko;
            _login = mv._login;
            _password = mv._password;
            _city = mv._city;
            _street = mv._street;
        }
    }

    void addCustomer();
    void showGivenData();
    void welcomePriorToShowedData();
    void getDataHoritontal();
private:
    float _discount{ 29.33 };
};

class VIP : public Customer {
public:
    VIP() {
        this->_imie = "def";
        this->_nazwisko = "def";
        this->_login = "def";
    };
    // copy constructor
    VIP(const VIP& cp) {
        this->_imie = cp._imie;
        this->_nazwisko = cp._nazwisko;
        this->_login = cp._login;
    };
    // move constructor 
    VIP(VIP&& mv) noexcept(true) {
        this->_imie = mv._imie;
        this->_nazwisko = mv._nazwisko;
        this->_login = mv._login;
    };

    VIP& operator=(const VIP& cp) {
        if (this != &cp) {
            _imie = cp._imie;
            _nazwisko = cp._nazwisko;
            _login = cp._login;
            _password = cp._password;
        }
    }
    VIP&& operator=(const VIP&& mv)  {
        if (this != &mv) {
            _imie = mv._imie;
            _nazwisko = mv._nazwisko;
            _login = mv._login;
            _password = mv._password;
        }
    }
    void addCustomer();
    void showGivenData();
    void welcomePriorToShowedData();
    void getDataHoritontal();
private:
    float _discount {49.33};
};

#endif /* Customer_hpp */


