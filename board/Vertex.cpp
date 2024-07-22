#include "Vertex.hpp"

Vertex::Vertex(int q, int r, char s) : _q(q), _r(r), _s(s), _hasOwner(NONE), _ownerID(-1)
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

void Vertex::setOwnerID(int ownerID)
{
    _ownerID = ownerID;
}

int Vertex::getOwnerID()
{
    return _ownerID;
}