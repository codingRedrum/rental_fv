//#ifndef Customer_h
//#define Customer_h
//
//#include <stdio.h>
//#include <iostream>
//#include <vector>
//#include <string>
//
//using namespace std;
//
//class Customer {
//public:
//    enum CUSTOMER_TYPE {
//        E_Exit,
//        E_Normal,
//        E_Premium
//    };
//    
//    virtual auto returnName() -> string = 0;
//    virtual auto createCustomer() -> void = 0;
//    virtual auto showData() -> void = 0;
//    virtual enum Customer::CUSTOMER_TYPE customerType() = 0;
//    virtual void showCustomer() = 0;
//    virtual ~Customer() {};
//};
//
//class Normal : public Customer {
//protected:
//    string _normalCustomerName;
//    string _surname;
//    string _login;
//    string _password;
//    string _street;
//    string _city;
//    bool _normalCustomer {true};
//    string _description {"Normal"};
//    
//public:
//    Normal() :_normalCustomerName{"def_NORMAL"}, _surname{"def_NORMAL"}, _login{"def_NORMAL"}, _password{"def_NORMAL"}, _street{"def_NORMAL"}, _city{"def_NORMAL"}, _normalCustomer{true}, _description{"def_NORMAL"} {};
//    
////    Normal(string name, string surname, string login, string password, string street, string city, bool value, string desc):  _normalCustomerName{name}, _surname{surname}, _login{login}, _password{password}, _street{street}, _city{city}, _normalCustomer{value}, _description{desc} {};
////
////    Normal(Normal &copy) : _normalCustomer(copy._normalCustomer), _surname{copy._surname}, _login{copy._login}, _password{copy._password}, _street{copy._street}, _city{copy._street}, _description{copy._description} {};
//    
//    virtual auto returnName() -> string {
//        return _normalCustomerName;
//    }
//    
////    virtual auto createCustomer() -> void  {
////        cout << "Welcome, you'll have to type some data, type your name: "; cin >> _normalCustomerName;
////        cout << endl << "Surname: "; cin >> _surname;
////        cout << endl << "Login: "; cin >> _login;
////        cout << endl << "Password: "; cin >> _password;
////        cout << endl << "streeet: "; cin >> _street;
////        cout << endl << "city: "; cin >> _city;
////        this->_normalCustomer = true;
////    }
//    
//    virtual auto showData() -> void {
//        cout << "Name: " << _normalCustomerName << endl
//             << "Surname: " << _surname << endl
//             << "Street: " << _street << endl
//             << "City: " << _city << endl;
//    }
//    
//    virtual enum CUSTOMER_TYPE customerType() { return E_Normal; };
//    virtual void showCustomer() { cout << "Normal \n"; };
//    virtual ~Normal() {};
//};
//
//class Premium : public Customer {
//protected:
//    string _premiumCustomerName;
//    string _premiumSurname;
//    string _premiumLogin;
//    string _premiumPassword;
//    string _premiumStreet;
//    string _premiumCity;
//    bool _premiumCustomer {true};
//    string _premiumDescription {"Normal"};
//    
//public:
//    //Premium() : normalData(true), _premiumCustomerName{"def_PREMIUM"} {};
//    Premium() :_premiumCustomerName{"def_PREMIUM"}, _premiumSurname{"def_PREMIUM"}, _premiumLogin{"def_PREMIUM"}, _premiumPassword{"def_PREMIUM"}, _premiumStreet{"def_PREMIUM"}, _premiumCity{"def_PREMIUM"}, _premiumCustomer{true}, _premiumDescription{"def_PREMIUM"} {};
//    
////    Premium(string name, string surname, string login, string password, string street, string city, bool value, string desc):_premiumCustomerName{name}, _premiumSurname{surname}, _premiumLogin{login}, _premiumPassword{password}, _premiumStreet{street}, _premiumCity{city}, _premiumCustomer{true}, _premiumDescription{desc} {};
//    
//    virtual auto returnName() -> string {
//        return _premiumCustomerName;
//    }
//    
////    virtual auto createCustomer() -> void  {
////        cout << "Welcome to Premium Class - you'll have to type some data, type your name: "; cin >> _premiumCustomerName;
////        cout << endl << "Surname: "; cin >> _premiumSurname;
////        cout << endl << "Login: "; cin >> _premiumLogin;
////        cout << endl << "Password: "; cin >> _premiumPassword;
////        cout << endl << "streeet: "; cin >> _premiumStreet;
////        cout << endl << "city: "; cin >> _premiumCity;
////        this->_premiumCustomer = true;
////    }
//    virtual auto showData() -> void {
//        cout << "Name: " << _premiumCustomerName << endl
//             << "Surname: " << _premiumSurname << endl
//             << "Street: " << _premiumStreet << endl
//             << "City: " << _premiumCity << endl;
//    }
//
//    virtual enum CUSTOMER_TYPE customerType() { return E_Premium; };
//    virtual void showCustomer() { cout << "Premium \n"; };
//    virtual ~Premium() {};
//    
//};
////
////auto createAbstractArray(Customer * tab[]) {
////    tab[0] = new Normal;
////    tab[1] = new Premium;
////}
////
////auto createArray(size_t size, Customer * ptrToNormal[size], Customer * ptrToPremium[size]) -> void {
////
////    for (int i = 0; i < size; i++) {
////        ptrToNormal[i] = new Normal;
////        ptrToPremium[i] = new Premium;
////    }
////}
////
////auto showName(Customer *tab[]) -> void {
////    cout << "Normal customer - " << tab[0]->returnName() << endl;
////    cout << "Premium customer - " << tab[1]->returnName() << endl;
////}
////
////auto deleteCustomer(Customer *tab[]) -> void {
////    for (int i = 0; i < 2; i++) {
////        delete tab[i];
////    }
////}
////
////auto addAbstractObject(vector<Customer*> &abstractCustomer) -> void {
////    int _numberENUM;
////A:
////    cout << "Which customer ? \n"
////         << "1. Normal \n"
////         << "2. Premium \n"
////         << "0. Exit \n"
////         << "Choose the number: ";
////    cin >> _numberENUM;
////
////    switch ((enum Customer::CUSTOMER_TYPE)_numberENUM) {
////        case Customer::CUSTOMER_TYPE(Customer::E_Normal):
////            abstractCustomer.push_back(new Normal);
////            break;
////        case Customer::CUSTOMER_TYPE(Customer::E_Premium):
////            abstractCustomer.push_back(new Premium);
////            break;
////        case Customer::CUSTOMER_TYPE(Customer::E_Exit) :
////            cout << "You've chosen top exit the program \n";
////            break;
////        default:
////            cout << "Wrong number! Choose once again. \n";
////            goto A;
////    }
////}
//
////auto showVectorValue(vector<Customer*> vecNormal) -> void {
////    for (auto itr : vecNormal) {
////        cout << itr->returnName() << endl;
////    }
////}
//
//
//#endif /* Customer_h */
