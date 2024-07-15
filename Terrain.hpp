// @author: eylony1403@gmail.com
/**
 * @file Terrain.hpp
 * @brief Defines the Terrain enum and related functions.
 *
 * This file contains the declaration of the Terrain enum and two functions:
 * - randomTerrain: Generates a random Terrain value.
 * - terrainToString: Converts a Terrain object to a string representation.
 */

#pragma once

#include <string>
#include <random>

/**
 * @enum Terrain
 * @brief Represents different types of terrains.
 *
 * The Terrain enum represents different types of terrains, including:
 * - PASTURE
 * - FOREST
 * - HILLS
 * - MOUNTAINS
 * - FIELDS
 * - DESERT
 */
enum Terrain
{
    PASTURE,
    FOREST,
    HILLS,
    MOUNTAINS,
    FIELDS,
    DESERT
};

/**
 * @brief Generates a random Terrain value.
 *
 * This function generates a random Terrain value using a random number generator.
 *
 * @return A randomly generated Terrain value.
 */
Terrain randomTerrain();

/**
 * @brief Converts a Terrain object to a string representation.
 *
 * This function takes a Terrain object and converts it to a string representation.
 *
 * @param terrain The Terrain object to convert.
 * @return A string representation of the Terrain object.
 */
std::string terrainToString(Terrain terrain);