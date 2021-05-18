//
//#include <iostream>
//#include <string>
//#include <vector>
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
//    virtual auto assignName(string name) -> void = 0;
//    virtual auto showName() -> string = 0;
//    virtual enum Customer::CUSTOMER_TYPE customerType() = 0;
//    virtual void showCustomer() = 0;
//    virtual ~Customer() {};
//    
//};
//
//class Normal : public Customer {
//protected:
//    string _normalCustomerName;
//    bool _normalCustomer {true};
//    string _description {"Normal"};
//    
//public:
//    Normal() : _normalCustomer{true}, _normalCustomerName{"def_NORMAL"} {};
//    Normal(bool value) : _normalCustomer{value} {};
//    Normal(Normal &copy) : _normalCustomer(copy._normalCustomer) {};
//    
//    auto assignName(string name) -> void {
//        this->_normalCustomerName = name;
//    }
//    virtual auto showName() -> string {
//        return _normalCustomerName;
//    }
//    
//    auto setStatus(bool value) -> void { this->_normalCustomer = value; };
//    virtual enum CUSTOMER_TYPE customerType() { return E_Normal; };
//    virtual void showCustomer() { cout << "Normal \n"; };
//    virtual ~Normal() {};
//};
//
//class Premium : public Customer {
//protected:
//    string _premiumCustomerName;
//    bool _premiumCustomer {true};
//    string _description {"Premium"};
//    Normal normalData;
//public:
//    Premium() : normalData(true), _premiumCustomerName{"def_PREMIUM"} {};
//    Premium(bool value) : _premiumCustomer(true) {};
//    
//    auto assignName(string name) -> void {
//        this->_premiumCustomerName = name;
//    }
//    
//    virtual auto showName() -> string {
//        return _premiumCustomerName;
//    }
//    
//    virtual enum CUSTOMER_TYPE customerType() { return E_Premium; };
//    virtual void showCustomer() { cout << "Premium \n"; };
//    virtual ~Premium() {};
//    
//};
//
//auto createAbstractArray(Customer * tab[]) {
//    tab[0] = new Normal;
//    tab[1] = new Premium;
//}
//
//auto createArray(size_t size, Customer * ptrToNormal[size], Customer * ptrToPremium[size]) -> void {
//    
//    for (int i = 0; i < size; i++) {
//        ptrToNormal[i] = new Normal;
//        ptrToPremium[i] = new Premium;
//    }
//}
//
//auto assignName(Customer *tab[], string normalCustomerName, string premiumCustomerName) {
//    tab[0]->assignName(normalCustomerName);
//    tab[1]->assignName(premiumCustomerName);
//}
//
//auto showName(Customer *tab[]) -> void {
//    cout << "Normal customer - " << tab[0]->showName() << endl;
//    cout << "Premium customer - " << tab[1]->showName() << endl;
//}
//
//auto deleteCustomer(Customer *tab[]) -> void {
//    for (int i = 0; i < 2; i++) {
//        delete tab[i];
//    }
//}
//
//auto addAbstractObject(vector<Customer*> &abstractCustomer) -> void {
//    int _numberENUM;
//A:
//    cout << "Which customer ? \n"
//         << "1. Normal \n"
//         << "2. Premium \n"
//         << "0. Exit \n"
//         << "Choose the number: ";
//    cin >> _numberENUM;
//    
//    switch ((enum Customer::CUSTOMER_TYPE)_numberENUM) {
//        case Customer::CUSTOMER_TYPE(Customer::E_Normal):
//            abstractCustomer.push_back(new Normal);
//            break;
//        case Customer::CUSTOMER_TYPE(Customer::E_Premium):
//            abstractCustomer.push_back(new Premium);
//            break;
//        case Customer::CUSTOMER_TYPE(Customer::E_Exit) :
//            cout << "You've chosen top exit the program \n";
//            break;
//        default:
//            cout << "Wrong number! Choose once again. \n";
//            goto A;
//    }
//}
//
//auto showVectorValue(vector<Customer*> vecNormal) -> void {
//    for (auto itr : vecNormal) {
//        cout << itr->showName() << endl;
//    }
//}
//
//int main(int argc, const char * argv[]) {
//    
//    std::cout << "Hello, World!\n";
//    
//    Customer *tab[2];
//    createAbstractArray(tab);
//    assignName(tab, "Normalny", "Premium");
//    showName(tab);
//    
//    vector<Customer*> normalCustomer;
//    addAbstractObject(normalCustomer);
//    showVectorValue(normalCustomer);
//    
//    
//    
//    return 0;
//}
//
///*
// Right, The reason I wanted to do this is that I want to pass these vectors to other functions. If I do not make my classes polymorphic then I have to write a function for each of the derived classes even if I'm doing manipulations that just involve the base class functions. By using polymorphism I can write one function that takes an ABC.
//
// The reason I wanted to create vectors of objects and not pointers is not very strong: When I am looping over a vector of objects, I get an iterator vector<ABC>::iterator itr= vec1->begin() and then to access a member function I just do itr->memberfuncion(). But if its a vector of pointers then to use the iterator I have to do (*itr)->memberfunction() which I didn't think was as nice. Maybe its worth switching to pointers in my vectors.
// */
