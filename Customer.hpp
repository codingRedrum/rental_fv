#ifndef Customer_hpp
#define Customer_hpp

#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class  Customer {
protected:
    string _name;
    string _fName;
    string _street;
    string _city;
    // typ klasy
    
public:
    Customer(): _name{"def"},_fName{"def"}, _street{"def"}, _city{"def"} {};
    Customer(string name, string fName, string street, string city): _name{name},_fName{fName}, _street{street}, _city{city} {};
    virtual ~Customer() {}
    virtual bool returnTypeOfCustomer() = 0;
    virtual void addCustomer() = 0;
    virtual void showGivenData() = 0;
    virtual void welcomePriorToShowedData() = 0;
};

class Premium : public Customer {
    bool _classPREMIUM = true;
    string _classType;
public:
    Premium(): Customer(), _classPREMIUM{true}, _classType{"premium"} {};
    Premium(string name, string fName, string street, string city) : Customer( name, fName,  street, city), _classPREMIUM{true}, _classType{"premium"} {}
    ~Premium() {}
    
    bool returnTypeOfCustomer();
    virtual void addCustomer();
    virtual void showGivenData();
    virtual void welcomePriorToShowedData();
};

class VIP : public Customer {
    string _classType;
    bool _classVIP = true;
    float _discount = 1241.34;
    // dodatkowe 100 000 km + znizka

public:
    VIP() : Customer(), _classVIP{true}, _classType{"vip"}  {}
    VIP(string name, string fName, string street, string city): Customer(name, fName, street, city), _classVIP{true} , _classType{"vip"} {}
    ~VIP() {}
    
    bool returnTypeOfCustomer();
    virtual void addCustomer();
    virtual void showGivenData();
    virtual void welcomePriorToShowedData();

};


#endif /* Customer_hpp */


