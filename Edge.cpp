#include "Edge.hpp"

Edge::Edge(int q, int r, std::string s) : _q(q), _r(r), _s(s), _ownerID(-1), _hasRoad(false)
{
}

std::string Edge::toString()
{
    return std::to_string(_q) + ":" + std::to_string(_r) + ":" + _s;
}
