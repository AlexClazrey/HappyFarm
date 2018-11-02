#ifndef FARMFIELD_H
#define FARMFIELD_H
#include <string>

class PlantLive;
class FarmField
{
    public:
        FarmField();
        virtual ~FarmField();
        virtual std::string toString() const;
        virtual std::string descriptionText() const;
        virtual std::string descriptionTitle() const;
        void setId(int id) {this->id = id;}
        int getId() {return this->id;}
        int getIdPlusOne() { return getId() + 1; }
        int getWater() {return waterAmount; }
        void setWater(int water) { this->waterAmount = water; }
        bool empty() const;
        void removePlant();
        PlantLive* getPlant() { return this->plant; }
        void addPlant(PlantLive* pl) { plant = pl; }
        void deadPlant();
        void harvest();
        void update();
    protected:

    private:
        int id;
        int waterAmount;
        PlantLive* plant;
};

#endif // FARMFIELD_H
