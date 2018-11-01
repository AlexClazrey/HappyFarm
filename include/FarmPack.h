#ifndef FARMPACK_H
#define FARMPACK_H
#include "FarmItem.h"
#include <vector>
#include <functional>

class FarmPack
{
    public:
        FarmPack();
        virtual ~FarmPack();
        const FarmPack& getProtoPack() const { return this->protoPack; }
        void addItem(FarmItem::Code code) { items[code]->incr(); }
        void addItem(FarmItem::Code code, int count) {
            items[code]->setCount(items[code]->getCount() + count);
        }
        void removeItem(FarmItem::Code code) { items[code]->decr(); }
        void removeItem(FarmItem::Code code, int count) {
            items[code]->setCount(items[code]->getCount() <= count ? 0 : (items[code]->getCount() - count));
        }
        bool hasItem(FarmItem::Code code)  const { return items[code] && items[code]->getCount() > 0; }
        int getCount(FarmItem::Code code)  const { return items[code] ? items[code]->getCount() : 0; }
        int getSize() const { return FarmItem::Code::END; }
        std::vector<FarmItem*> scanPack();
        std::vector<FarmItem*> scanPack(const std::function<bool(const FarmItem*)>& judge);
        FarmItem* getItem(FarmItem::Code code) { if(code < getSize()) return items[code]; return nullptr; }
    protected:

    private:
        static void initProto();
        static bool inited;
        static FarmPack protoPack;
        FarmItem* items[FarmItem::Code::END];
};

#endif // FARMPACK_H
