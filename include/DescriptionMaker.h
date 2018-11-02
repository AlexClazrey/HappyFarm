#ifndef DESCRIPTIONMAKER_H
#define DESCRIPTIONMAKER_H
#include <vector>
#include <string>

class FarmField;
class FarmItem;
class DescriptionMaker
{
    public:
        DescriptionMaker();
        virtual ~DescriptionMaker();

        static std::vector<std::string>* makeField(FarmField* field);
        static std::vector<std::string>* makeItem(FarmItem* item);
        static void split(const std::string& str, char c, std::vector<std::string>& dest);
        static std::string toLower(std::string str);
        static std::string toUpper(std::string str);

    protected:

    private:
};

#endif // DESCRIPTIONMAKER_H
