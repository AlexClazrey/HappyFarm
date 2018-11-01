#include "FarmYard.h"

const int FarmYard::FARMYARD_COUNT = 8;
FarmYard::FarmYard()
{
    farmFields.resize(FARMYARD_COUNT);
    for(int i = 0; i < FARMYARD_COUNT; i++) {
        farmFields[i].setId(i);
    }
}

FarmYard::~FarmYard()
{
}

void FarmYard::makeSummary(std::vector<std::string> &dest) {
    for(int i = 0; i < FARMYARD_COUNT; i++) {
        dest.push_back(this->farmFields[i].toString());
    }
}

void FarmYard::update() {
    for(int i = 0; i < FARMYARD_COUNT; i++) {
        farmFields[i].update();
    }
}
