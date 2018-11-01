#include "DescriptionMaker.h"
#include "FarmField.h"

DescriptionMaker::DescriptionMaker()
{
    //ctor
}

DescriptionMaker::~DescriptionMaker()
{
    //dtor
}

std::vector<std::string>* DescriptionMaker::makeField(FarmField* field) {
    auto result = new std::vector<std::string>();
    if(field) {
        std::string desc = field->descriptionText();
        DescriptionMaker::split(desc, '\n', *result);
        result->push_back(field->descriptionTitle());
    }
    return result;
}

void DescriptionMaker::split(const std::string& str, char c, std::vector<std::string>& dest) {
    int len = str.size();
    int i = 0, j = 0;
    for(i = 0; i < len; i++) {
        if(str[i] == c) {
            dest.push_back(str.substr(j, i - j));
            j = i + 1;
        }
    }
    if(j < i)
        dest.push_back(str.substr(j, i - j));
}
