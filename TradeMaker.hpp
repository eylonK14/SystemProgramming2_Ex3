// TODO: Implement TradeMaker

#pragma once

#include "Resource.hpp"

typedef struct _TradeMaker
{
    int _give[5];
    int _get[5];
} TradeMaker;

void addToGive(TradeMaker &tradeMaker, std::string str, int amt)
{
    tradeMaker._give[resource_from_string(str)] = amt;
}

void addToGet(TradeMaker &tradeMaker, std::string str, int amt)
{
    tradeMaker._get[resource_from_string(str)] = amt;
}
