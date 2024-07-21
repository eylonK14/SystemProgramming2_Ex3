// @author: eylony1403@gmail.com

#include <iostream>
#include <random>

#include "cards/KnightCard.hpp"
#include "cards/VictoryPointCard.hpp"

DevelopmentCard getCard()
{
    std::random_device rd;  // a seed source for the random number engine
    std::mt19937 gen(rd()); // mersenne_twister_engine seeded with rd()
    std::uniform_int_distribution<> distrib(1, 2);

    switch (distrib(gen))
    {
    case 1:
        return KnightCard();
    case 2:
        return VictoryPointCard();
    }
}
