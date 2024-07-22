// Derived class for Resource Cards

#pragma once

#include "board/Terrain.hpp"
#include <iostream>
#include <stdexcept>

enum Resource
{
    BRICK,  // Represents brick resource
    LUMBER, // Represents lumber resource
    WOOL,   // Represents wool resource
    GRAIN,  // Represents grain resource
    ORE     // Represents ore resource
};

// Converts a string to a Resource enum value
Resource resource_from_string(const std::string &str);

// Converts a Resource enum value to a string
std::string resource_to_string(Resource resource);

// Retrieves the resource associated with a given terrain type
Resource getResourceFromTerrain(Terrain terrain);

// Retrieves the index of a resource in a collection
size_t getIndexFromResource(Resource resource);