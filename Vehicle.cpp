/***********************************************************************************************************************************
** Dissemination of this information or reproduction of this material is strictly forbidden unless prior written permission is obtained
** from Adrian Juszczak. Access to the source code contained herein is hereby forbidden.

**              © All Rights Reserved Created by Adrian Juszczak.
*/
#include <stdio.h>
#include <iostream>
#include "Vehicle.h"

using namespace std;

array<string, 3> _hiddenDataArray;
array<float, 3> _hiddenFloatArray;

auto Car::createVehicleList() -> void {
    _sportCar = new SportCar*[_howMany];
    
    for (int i = 0; i < _howMany; i++) {
        _sportCar[i] = new SportCar;
    }
    _numberOfCars = _howMany;
}

auto Car::addVehicle() -> void  {
    size_t new_size = _howMany + 1;
    SportCar** _tmp = new SportCar*[new_size];   
    // rewrite the value of pointer
    for (int i = 0; i < new_size-1; i++) {
        _tmp[i] = _sportCar[i];
    }
  
    _tmp[new_size-1] = new SportCar;
    delete[] _sportCar;
    _sportCar = _tmp;
    _howMany++;
    _numberOfCars++;
}

auto Car::removeVehicle() -> void {
    size_t new_size = _howMany - 1;
    int _choose, _pom{1};
    
    cout << "\n" << "Which car you would like to rent, choose numer:  "; cin >> _choose;
    
    SportCar** tmp = new SportCar*[new_size];
    
    for (int i = 0; i < new_size; i++) {
        if (i < (_choose-1)) {
            tmp[i] = _sportCar[i];
            _pom++;
        }
        tmp[i] = _sportCar[_pom++];
    }
    
    delete [] _sportCar;
    _sportCar = tmp;
    _numberOfCars--;
    cout << "Thank you for your choose! \n";
    Sleep(1000);
}

auto Car::describeHiddenSportCar()->void {
    
    cout << "What " << _hiddenData[0] << " is your car? ";          cin >> ::_hiddenDataArray[0];
    cout << "What " << _hiddenData[1] << " is your car? ";          cin >> ::_hiddenDataArray[1];
    cout << "What kind of " << _hiddenData[2] << " has the car? ";  cin >> ::_hiddenDataArray[2];
    cout << "How many " << _hiddenData[3] << " has the car?";       cin >> ::_hiddenFloatArray[0];
    cout << endl;
}

auto Car::setHiddenDetailsSportCar(size_t numb) -> void {
    
        _sportCar[numb]->_mark = reinterpret_cast<char*>(&_hiddenDataArray[0]);
        _sportCar[numb]->_model = reinterpret_cast<char*>(&_hiddenDataArray[1]);
        _sportCar[numb]->_insuranceType = reinterpret_cast<char*>(&_hiddenDataArray[2]);
        _sportCar[numb]->_horsePower = _hiddenFloatArray[0];
}

auto Car::showHiddenDetailsSportCar() -> void  {
    system("CLS");

    cout << endl <<  "ID \t" << "Mark \t\t" << "Model \t" << "  Insurance Type: " << "   Horse Power: \t\n";
    for (size_t i = 0; i < 64; i++) {
        cout << "-";
    }
    cout << endl;
    for (size_t i = 0; i < _numberOfCars; i++) {
        cout << i+1 << "\t";
        cout << _sportCar[i]->getMark() << "\t\t";
        cout << _sportCar[i]->getModel() << "\t\t";
        cout << _sportCar[i]->getInsuranceDetails() << "\t\t";
        cout << _sportCar[i]->getHorsePower() << "\t";
        cout << endl;
    }
    Sleep(1000);
}

auto Car::checkDB() -> void {
    string line;
    int i = 0;
    ifstream file("SportCar.txt");

    if (file.is_open()) {
        while (!file.eof()) {
            getline(file, line);
            i++;
        }
        _howMany = i;
       // file.close();
    }
}

auto Car::loadData()-> void {
    string _string[10];
    string line, buff;

    int i = 0;
    ifstream file("SportCar.txt");

    if (file.is_open()) {
        while (!file.eof()) {
            getline(file, line);
            stringstream s_string(line);

            getline(s_string, buff, ';');
            _sportCar[i]->_mark = buff;
            getline(s_string, buff, ';');
            _sportCar[i]->_model = buff;
            getline(s_string, buff, ';');
            _sportCar[i]->_insuranceType = buff;
            getline(s_string, buff, ';');
            _sportCar[i]->_horsePower = stof(buff);
            i++;
        }
        file.close();
    } 
}

auto Car::showTypeOfCar() -> void {
    vehicleType->vehicleType();
}

 auto Car::SportCar::setMark(string mark) -> void {
     this->_mark = mark;
}
 auto Car::SportCar::setModel(string model) -> void {
     this->_model = model;
}

 auto Car::SportCar::setInsurance(string insurance) -> void {
     this->_insuranceType = insurance; 
}
 auto Car::SportCar::setHorsePower(float hp) -> void {
     this->_horsePower = hp;
}

auto Car::showVehicle() -> void {

}

auto Car::showHiddenData() -> void {
    
}

Car::SportCar::SportCar() {
    
}
