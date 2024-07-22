#include "Catan.hpp"

Catan::Catan() : board(Board()), player1(Player(1)), player2(Player(2)), player3(Player(3)), _currPlayer(1)
{
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

void Catan::playTurn()
{
    std::cout << "Player " << _currPlayer << "'s turn" << std::endl;

    if (_currPlayer == 1)
    {
        player1.rollDice(board, player2, player3);
        player1.build(board);
        player1.trade(player2, player3);
        player1.purchaseDevelopmentCard();
        player1.playDevelopmentCard(board);
        _currPlayer = 2;
    }
    else if (_currPlayer == 2)
    {
        player2.rollDice(board, player1, player3);
        player2.build(board);
        player2.trade(player1, player3);
        player2.purchaseDevelopmentCard();
        player2.playDevelopmentCard(board);
        _currPlayer = 3;
    }
    else
    {
        player3.rollDice(board, player2, player1);
        player3.build(board);
        player3.trade(player2, player1);
        player3.purchaseDevelopmentCard();
        player3.playDevelopmentCard(board);
        _currPlayer = 1;
    }
}