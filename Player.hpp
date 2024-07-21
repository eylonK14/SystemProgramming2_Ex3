// @author eylony1403@gmail.com

#pragma once

#include "Resource.hpp"
#include "DevelopmentCard.hpp"

class Player
{
public:
    Player();
    ~Player();

    int rollDice();


private:
    int _id, _victoryPoints;
    Resource _resourceCards[5];
    std::vector<DevelopmentCard> _developmentCards;
};