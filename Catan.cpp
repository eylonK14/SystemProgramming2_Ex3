#include "Catan.hpp"

Catan::Catan()
{
    board = Board();
    player1 = Player(1);
    player2 = Player(2);
    player3 = Player(3);
    _currPlayer = 1;
}

bool Catan::checkWin()
{
    if (_currPlayer == 1)
        return player1.getVictoryPoints() >= 10;
    else if (_currPlayer == 2)
        return player2.getVictoryPoints() >= 10;
    else
        return player3.getVictoryPoints() >= 10;
}