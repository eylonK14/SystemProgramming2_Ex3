#include "TradeMaker.hpp"

void addToGive(TradeMaker &tradeMaker, std::string str, int amt)
{
    tradeMaker._give[resource_from_string(str)] = amt;
}

void addToGet(TradeMaker &tradeMaker, std::string str, int amt)
{
    tradeMaker._get[resource_from_string(str)] = amt;
}
