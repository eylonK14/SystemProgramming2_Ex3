// @author: eylony1403@gmail.com

#pragma once

#include <string>
#include <random>

enum Terrain
{
    PASTURE,
    FOREST,
    HILLS,
    MOUNTAINS,
    FIELDS,
    DESERT
};

Terrain randomTerrain();
std::string terrainToString(Terrain terrain);