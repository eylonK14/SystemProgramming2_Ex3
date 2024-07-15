// @author eylony1403@gmail.com

#pragma once

#include "Resource.hpp"

class Player
{
public:
    Player();
    ~Player();

private:
    int _id, _victoryPoints;
    Resource _resourceCards[5];
    // TODO: Add more fields as needed
};