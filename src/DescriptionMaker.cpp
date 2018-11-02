#include "DescriptionMaker.h"
#include "FarmField.h"
#include "FarmItem.h"
#include <algorithm>

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

std::vector<std::string>* DescriptionMaker::makeItem(FarmItem* item) {
    auto result = new std::vector<std::string>();
    if(item) {
        std::string desc = item->getDesc();
        DescriptionMaker::split(desc, '\n', *result);
        result->push_back(item->getName());
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

std::string DescriptionMaker::toLower(std::string str) {
    std::transform(str.begin(), str.end(), str.begin(), ::tolower);
    return str;
}

std::string DescriptionMaker::toUpper(std::string str) {
   std::transform(str.begin(), str.end(), str.begin(), ::toupper);
   return str;
}
