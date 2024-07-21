#include "Vertex.hpp"

Vertex::Vertex(int q, int r, char s) : _q(q), _r(r), _s(s), _hasOwner(NONE)
{
}

std::string Vertex::toString()
{
    return std::to_string(_q) + ":" + std::to_string(_r) + ":" + _s;
}

int Vertex::getHasOwner()
{
    return _hasOwner;
}

int Vertex::getQ()
{
    return _q;
}

int Vertex::getR()
{
    return _r;
}

char Vertex::getS()
{
    return _s;
}

void Vertex::setHasOwner(int hasOwner)
{
    _hasOwner = hasOwner;
}

Player *Vertex::getPlayer()
{
    return _player;
}

void Vertex::setPlayer(Player *player)
{
    _player = player;
}