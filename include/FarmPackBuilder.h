#ifndef FARMPACKBUILDER_H
#define FARMPACKBUILDER_H

class FarmPack;
// used by Farm Builder
class FarmPackBuilder
{
    public:
        FarmPackBuilder();
        virtual ~FarmPackBuilder();
        virtual void buildPack(FarmPack& pack) const = 0;
    protected:

    private:
};

#endif // FARMPACKBUILDER_H
