#pragma once

#include <vector>
#include "Point.hpp"
#include "Line.hpp"

#define HEXAGON_SIZE 6

enum TerrainType
{
    FOREST,
    FIELD,
    MOUNTAIN,
    HILL,
    PASTURE,
    DESERT
};

class Hexagon
{
private:
    std::vector<Point&> _points;
    std::vector<Line&> _lines;
    unsigned int _hexId;
    unsigned int _hexNum;
    TerrainType _terrainType;
    // AreaType
    // HasBandit

    public:
        Hexagon::Hexagon(std::vector<Point&> points, std::vector<Line&> lines, unsigned int hexId, unsigned int hexNum, TerrainType terrainType);
        Point getPoint(unsigned int pointId);
        Line getLine(unsigned int lineId);
        void setPoint(unsigned int pointId, Point point);
        void setLine(unsigned int lineId, Line line);
        void print();
};