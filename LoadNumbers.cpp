#include "LoadNumbers.h"
#include "Data.h"

LoadNumbers::LoadNumbers(long long int pNumber)
    : Data(), _personalNumber(pNumber) {}

LoadNumbers::LoadNumbers(unsigned int PIN)
    : Data (), _PIN(PIN) {}

LoadNumbers::LoadNumbers(long long int pNumber, unsigned int PIN)
    : Data(), _personalNumber(pNumber), _PIN(PIN)  {}




void LoadNumbers::getData() {

    cout << endl
         << _personalNumber << endl
         << _PIN << endl;
}
