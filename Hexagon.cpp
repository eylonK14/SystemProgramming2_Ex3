#include "Hexagon.hpp"

Hexagon::Hexagon(std::vector<Point&> points, std::vector<Line&> lines, unsigned int hexId, unsigned int hexNum, TerrainType terrainType)
    : _points(points), _lines(lines), _hexId(hexId), _hexNum(hexNum), _terrainType(terrainType)
{
}
