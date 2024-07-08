#include "Vertex.hpp"

Vertex::Vertex(int q, int r, char s) : _q(q), _r(r), _s(s), _ownerID(-1), _hasOwner(NONE)
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