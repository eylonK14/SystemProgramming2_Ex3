// Derived class for Resource Cards

#include "Terrain.hpp"
#include <iostream>
#include <stdexcept>

enum Resource
{
    BRICK,
    LUMBER,
    WOOL,
    GRAIN,
    ORE
};

Resource resource_from_string(const std::string &str)
{
    if (str == "Brick")
        return BRICK;
    else if (str == "Lumber")
        return LUMBER;
    else if (str == "Wool")
        return WOOL;
    else if (str == "Grain")
        return GRAIN;
    else if (str == "Ore")
        return ORE;
    else
        throw std::invalid_argument("Invalid resource string: " + str);
}

std::string resource_to_string(Resource resource)
{
    switch (resource)
    {
    case BRICK:
        return "Brick";
    case LUMBER:
        return "Lumber";
    case WOOL:
        return "Wool";
    case GRAIN:
        return "Grain";
    case ORE:
        return "Ore";
    default:
        return "Unknown";
    }
}

Resource getResourceFromTerrain(Terrain terrain)
{
    switch (terrain)
    {
    case DESERT:
        throw std::invalid_argument("Desert does not produce resources");
    case FOREST:
        return LUMBER;
    case HILLS:
        return BRICK;
    case MOUNTAINS:
        return ORE;
    case PASTURE:
        return WOOL;
    case FIELDS:
        return GRAIN;
    default:
        throw std::invalid_argument("Invalid terrain type");
    }
}

size_t getIndexFromResource(Resource resource)
{
    switch (resource)
    {
    case BRICK:
        return 0;
    case LUMBER:
        return 1;
    case WOOL:
        return 2;
    case GRAIN:
        return 3;
    case ORE:
        return 4;
    default:
        throw std::invalid_argument("Invalid resource type");
    }
}