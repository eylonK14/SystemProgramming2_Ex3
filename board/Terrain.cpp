// @author: eylony1403@gmail.com

#include "Terrain.hpp"

Terrain randomTerrain()
{
    static std::random_device rd;
    static std::mt19937 gen(rd());

    static std::vector<Terrain> allTerrains = {PASTURE, FOREST, HILLS, MOUNTAINS, FIELDS};
    std::uniform_int_distribution<size_t> dis(0, allTerrains.size() - 1);

    Terrain randomTerrain = allTerrains[dis(gen)];
    return randomTerrain;
}

std::string terrainToString(Terrain terrain)
{
    switch (terrain)
    {
    case PASTURE:
        return "Pasture";
    case FOREST:
        return "Forest";
    case HILLS:
        return "Hills";
    case MOUNTAINS:
        return "Mountains";
    case FIELDS:
        return "Fields";
    case DESERT:
        return "Desert";
    default:
        return "Unknown";
    }
}