#pragma once

#include "Point.hpp"

class Line
{
public:
    Line(Point &point1, Point &point2);
    Line();

    Point &getPoint1();
    Point &getPoint2();

private:
    Point &_point1;
    Point &_point2;

    // Road hasRoad
};