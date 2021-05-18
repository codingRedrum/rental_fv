#ifndef Vehicle_h
#define Vehicle_h

#include <iostream>
#include <cstring>
#include <vector>
#include <string>
#include <array>
#include <fstream>
#include <sstream>
#include "LoadData.h"

using namespace std;

static int _numberOfCars{ 0 };

class Vehicle {
public:
	
	virtual auto createVehicleList() -> void = 0;
    virtual auto addVehicle() -> void = 0;
	virtual auto removeVehicle() -> void = 0;
	virtual auto showVehicle() -> void = 0;
	virtual auto showHiddenData() -> void = 0;
    virtual auto describeHiddenSportCar()->void = 0;
    virtual auto setHiddenDetailsSportCar(size_t numb) -> void = 0;
    virtual auto showHiddenDetailsSportCar(size_t numb) -> void = 0;
	virtual auto loadData()-> void = 0;
	virtual auto checkDB() -> void = 0;
	Vehicle() = default;
    
private:
	int _ID;
};

class Car : public Vehicle {
	friend class LoadData;
public:
	Car() : Vehicle(), _ID{ 0 }, _howMany{ 0 }, _sportCar{nullptr} {};
	~Car();

	virtual auto createVehicleList() -> void;
    virtual auto addVehicle() -> void;
	virtual auto removeVehicle() -> void;
	virtual auto showVehicle() -> void; 
	virtual auto showHiddenData() -> void;
    virtual auto describeHiddenSportCar()->void;
    virtual auto setHiddenDetailsSportCar(size_t numb) -> void;
    virtual auto showHiddenDetailsSportCar(size_t numb) -> void;
	virtual auto loadData()-> void;
	virtual auto checkDB() -> void;

	//Car& operator=(const Car& v) {
	//	if (this != &v) {
	//		delete[] _ptrSC;
	//		_howMany = v._howMany;

	//		_ptrSC = new SportCar * [_howMany];
	//		for (size_t i = 0; i < v._howMany; i++) {
	//			_ptrSC[i] = v._ptrSC[i];
	//		}
	//		return *this;
	//	}
	//}

private:
	class SportCar {
		friend class Car;
	public:
		SportCar ();
		~SportCar ();
		auto getMark() -> const string { return this->_mark; }
		auto getModel() -> const string { return _model; }
		auto getHorsePower() -> const float { return _horsePower; }
		auto getInsuranceDetails() -> const string { return _insuranceType; }
		auto setHiddenDetailsSportCar(string mark, string model, string insurance, float horsePower) -> void;
		auto setHiddenDetailsSportCar(SportCar** ptrSportCar, vector<string> &hiddenString, vector<float> hiddenFloat, size_t number) -> void;
        auto describeHiddenSportCar() -> void;
		auto setMark(string mark) -> void;
		auto setModel(string model) -> void;
		auto setInsurance(string insurance) -> void;
		auto setHorsePower(float hp) -> void;
	private:
		float _horsePower;
		string _insuranceType;
		string _mark;
		string _model;
	};

    SportCar** _sportCar;
	int _howMany;
    int _ID;
    vector<string> _hiddenData {"mark", "model", "insurance type", "horse power"};
};

// konstruktor kopiujacy, przenoszay
// operator przenoszacy []////


#endif //VEHICLE_H











