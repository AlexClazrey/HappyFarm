#ifndef FARMCOMMAND_H
#define FARMCOMMAND_H
#include "PlantSpecies.h"

class FarmField;
class FarmPack;
class FarmYard;

class FarmCommand
{
    public:
        FarmCommand();
        virtual ~FarmCommand();
        // return 0 for success
        virtual int toYard(FarmYard* yard) = 0;
        virtual int toField() = 0;
        virtual int toPack(FarmPack* pack) = 0;
        virtual int toMoney(int* money) = 0;
    protected:
    private:
};

class FarmCommandPlant : public FarmCommand {
public:
    FarmCommandPlant(FarmField* ff, PlantSpecies::Code pc, FarmItem::Code fc)
        : ff(ff), plantCode(pc), seedCode(fc) {}
    virtual ~FarmCommandPlant() {}
    int toYard(FarmYard*) { return 0; }
    int toField();
    int toPack(FarmPack* pack);
    int toMoney(int*) { return 0; }
private:
    FarmField* ff;
    PlantSpecies::Code plantCode;
    FarmItem::Code seedCode;
};

class FarmCommandHarvest : public FarmCommand {
public:
    FarmCommandHarvest(FarmField* ff) : ff(ff) {};
    virtual ~FarmCommandHarvest() {}
    int toYard(FarmYard*) { return 0; }
    int toField();
    int toPack(FarmPack* pack);
    int toMoney(int*) { return 0; }
private:
    FarmField *ff;
};

#endif // FARMCOMMAND_H
