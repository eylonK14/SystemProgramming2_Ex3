// TODO: implement Catan.hpp
// check win
// make turn

// shalom al israel


#pragma once

#include "board/Board.hpp"
#include "Player.hpp"

class Catan
{
private:
    Board board;
    Player player1;
    Player player2;
    Player player3;
    int _currPlayer;

    public:
        Catan();
        void playTurn();
        bool checkWin();
};