#ifndef FARMYARD_H
#define FARMYARD_H
#include <vector>
#include <string>
#include "FarmField.h"

class FarmYard
{
    public:
        static const int FARMYARD_COUNT;
        FarmYard();
        virtual ~FarmYard();

        FarmField* getField(int index) { return (index >= 0 && index < FARMYARD_COUNT) ? &this->farmFields[index] : nullptr; }
        void makeSummary(std::vector<std::string> &dest);
        void update();
    protected:

    private:
        std::vector<FarmField> farmFields;
};

#endif // FARMYARD_H
