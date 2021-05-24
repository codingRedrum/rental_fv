#pragma once
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class RentalStart {
	string startDate;
public:
	RentalStart( string start = "start") {
		this->startDate = start;
	}
	~RentalStart() {};
	string returnDate() { return this->startDate; }
};

class RentalStop {
	string finishDate;
public:
	RentalStop(string stop = "stop" ) {
		this->finishDate = stop;
	}
	~RentalStop() {};
	string returnDate() { return this->finishDate; }
};

template<typename T>
class GenericClass {
	unsigned _howManyS;
	T** startArr;
public:
	GenericClass();
	~GenericClass();
	auto create() -> void;
	auto addDate(const T& obj) -> void;
	T& operator[](const int index);
};

template<typename T>
GenericClass<T>::GenericClass() {
	this->_howManyS = 0;
	create();
}

template<typename T>
GenericClass<T>::~GenericClass() {
	for(size_t i = 0; i < _howManyS; i++) 		{
		delete[] startArr[i];
	}
	delete[] startArr;
}

template<typename T>
auto GenericClass<T>::create() -> void {
	startArr = new T * [_howManyS];
	
	for(size_t i = 0; i < this->_howManyS; i++) {
		startArr[i] = new T;
	}
}

template<typename T>
auto GenericClass<T>::addDate(const T& obj) -> void {
	size_t new_size = _howManyS + 1;
	T** tmp = new T * [new_size];

	for(size_t i = 0; i < _howManyS; i++) 		{
		tmp[i] = this->startArr[i];
	}
	tmp[this->_howManyS] = new T(obj);

	delete[] this->startArr;
	this->startArr = tmp;
	this->_howManyS++;
}

template<typename T>
T& GenericClass<T>::operator[](const int index) {
	if(index < 0 || index >= this->_howManyS) {
		throw "Wrong index number!\n";
	}
	return *this->startArr[index];
}


