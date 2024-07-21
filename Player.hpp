// @author eylony1403@gmail.com

#pragma once

#include <iostream>
#include <random>

#include "Resource.hpp"
#include "cards/DevelopmentCard.hpp"
#include "cards/DevelopmentCardFactory.cpp"
#include "board/Board.hpp"
#include "board/Vertex.hpp"

class Player
{
public:
    Player(int);
    ~Player();

    int getId();

    int rollDice();
    void build(Board &board);

    bool removeResourceCard(Resource);

    void Robber(Board &board);

    void purchaseDevelopmentCard();

private:
    int _id, _victoryPoints;
    int _resourceCards[5];
    std::vector<DevelopmentCard> _developmentCards;
};