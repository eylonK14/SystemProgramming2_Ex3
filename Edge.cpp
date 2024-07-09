#include "Edge.hpp"

Edge::Edge(int q, int r, std::string s) : _q(q), _r(r), _s(s), _ownerID(-1), _hasRoad(false)
{
}

std::string Edge::toString()
{
    return std::to_string(_q) + ":" + std::to_string(_r) + ":" + _s;
}

int Edge::getOwnerID()
{
    return _ownerID;
}

std::string Edge::getS()
{
    return _s;
}

void Edge::setOwnerID(int ownerID)
{
    _ownerID = ownerID;
}

void Edge::setHasRoad(bool hasRoad)
{
    _hasRoad = hasRoad;
}