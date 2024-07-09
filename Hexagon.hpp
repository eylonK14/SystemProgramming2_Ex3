// @author eylony1403@gmail.com

#pragma once
#include <string>

enum Terrain
{
    DESERT,
    PASTURE,
    FOREST,
    HILLS,
    MOUNTAINS,
    FIELDS
};

class Hexagon
{
public:
    Hexagon(int _q, int _r);
    std::string toString()
    {
        return std::to_string(_q) + "," + std::to_string(_r);
    }

    int getQ() const { return _q; }
    int getR() const { return _r; }
    int getS() const { return -_q - _r; }

private:
    int _q, _r;
};