// @author eylony1403@gmail.com

#include "Hexagon.hpp"

Hexagon::Hexagon(int _q, int _r, Terrain _t, bool robber) : _q(_q), _r(_r), _terrain(_t), _containsRobber(robber)
{
}

std::string Hexagon::toString()
{
    return std::to_string(_q) + "," + std::to_string(_r) + "," + terrainToString(_terrain) + "," + std::to_string(_containsRobber) + "," + std::to_string(_rollNumber);
}

int Hexagon::getQ() const
{
    return _q;
}
int Hexagon::getR() const
{
    return _r;
}
int Hexagon::getS() const
{
    return -_q - _r;
}

bool Hexagon::getContainsRobber() const
{
    return _containsRobber;
}
void Hexagon::setContainsRobber(bool containsRobber)
{
    _containsRobber = containsRobber;
}

Terrain Hexagon::getTerrain() const
{
    return _terrain;
}

void Hexagon::setRollNumber(int rollNumber)
{
    _rollNumber = rollNumber;
}