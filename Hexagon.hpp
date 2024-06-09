#pragma once

#include "Point.hpp"
#include "Line.hpp"

#define HEXAGON_SIZE 6

class Hexagon
{
    private:
        Point _points[HEXAGON_SIZE];
        Line _lines[HEXAGON_SIZE];

    public:
        Hexagon(Point points[HEXAGON_SIZE]);
        Point getPoint(unsigned int pointId);
        Line getLine(unsigned int lineId);
        void setPoint(unsigned int pointId, Point point);
        void setLine(unsigned int lineId, Line line);
        void print();
};