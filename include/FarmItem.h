#ifndef FARMITEM_H
#define FARMITEM_H
#include <string>

class FarmItem
{
    public:
        enum Type {
            SEED = 0x1,
            FRUIT = 0x10,
        };
        enum Code {
            POTATO_SEED,
            CUCUMBER_SEED,
            POTATO_FRUIT,
            CUCUMBER_FRUIT,
            END,
        };

        static const int ITEM_COUNT;

        FarmItem();
        FarmItem(Type type, Code code,  const std::string& name, const std::string& desc, int buy, int sold)
            : type(type), code(code), count(0), name(name), description(desc), buyPrice(buy), soldPrice(sold) {}
        virtual ~FarmItem();

        Type getType() const { return type; }
        Code getCode() const { return code; }
        const std::string& getName() const { return name; }
        const std::string& getDesc() const { return description; }
        int getBuyPrice() const { return buyPrice; }
        int getSoldPrice() const { return soldPrice; }
        int getCount() const { return count; }
        void incr() { count++; }
        void decr() { if(count > 0) count--; }
        void setCount(int newCount) { this->count = newCount; }

    protected:
        Type type;
        Code code;
        int count;
        std::string name;
        std::string description;
        int buyPrice;
        int soldPrice;
    private:
};

#endif // FARMITEM_H
