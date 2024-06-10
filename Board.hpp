#include "Hexagon.hpp"

#define BOARD_SIZE 19

class Board
{
private:
    std::vector<Hexagon&> _hexagons;    

public:
    Board();
    Hexagon getHexagon(unsigned int hexagonId);
    void setHexagon(unsigned int hexagonId, Hexagon hexagon);
    void print();
};