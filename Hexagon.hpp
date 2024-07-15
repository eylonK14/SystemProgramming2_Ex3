// @author eylony1403@gmail.com

#pragma once

#include <string>
#include <random>

#include "Terrain.hpp"

class Hexagon
{
public:
    Hexagon(int _q, int _r, Terrain _t, bool robber = false);
    std::string toString();

    int getQ() const;
    int getR() const;
    int getS() const;

    bool getContainsRobber() const;
    void setContainsRobber(bool containsRobber);

    Terrain getTerrain() const;

    void setRollNumber(int rollNumber);

private:
    int _q, _r, _rollNumber;
    Terrain _terrain;
    bool _containsRobber;
};