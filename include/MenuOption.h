#ifndef MENUOPTION_H
#define MENUOPTION_H
#include <string>
#include <functional>

class MenuOption
{
    public:
        typedef std::function<int()> CallbackFunc;  // return 0 exit menu, return 1 return to upper page, return 2 stay here
        typedef CallbackFunc CBF;

        MenuOption();
        MenuOption(const std::string& name, const std::string& desc, const CBF& func) : name(name), desc(desc), cbf(func) {}
        virtual ~MenuOption();

        const std::string& getName() { return name; }
        const std::string& getDesc() { return desc; }
        CallbackFunc getCBF() { return cbf; }

        void setName(const std::string& val) { name = val; }
        void setDesc(const std::string& val) { desc = val; }
        void setCBF(CallbackFunc val) { cbf = val; }

    protected:
        std::string name;
        std::string desc;
        CallbackFunc cbf;

    private:

};

#endif // MENUOPTION_H
