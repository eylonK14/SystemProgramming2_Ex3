// TODO: Implement TradeMaker

#pragma once

#include "Resource.hpp"

typedef struct _TradeMaker
{
    Resource _give[5];
    Resource _get[5];
} TradeMaker;

void setGive(TradeMaker &tradeMaker, Resource give[5]);

void setGet(TradeMaker &tradeMaker, Resource get[5]);
