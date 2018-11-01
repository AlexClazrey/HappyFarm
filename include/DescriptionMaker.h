#ifndef DESCRIPTIONMAKER_H
#define DESCRIPTIONMAKER_H
#include <vector>
#include <string>

class FarmField;
class DescriptionMaker
{
    public:
        DescriptionMaker();
        virtual ~DescriptionMaker();

        static std::vector<std::string>* makeField(FarmField* field);
        static void split(const std::string& str, char c, std::vector<std::string>& dest);
    protected:

    private:
};

#endif // DESCRIPTIONMAKER_H
