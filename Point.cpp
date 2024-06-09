#include "Point.hpp"

Point::Point(unsigned int pointId) : _pointId(pointId)
{
}

unsigned int Point::getPointId()
{
    return this->_pointId;
}