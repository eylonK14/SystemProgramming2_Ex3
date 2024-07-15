/**
 * @file Hexagon.hpp
 * @brief Defines the Hexagon class.
 */

#pragma once

#include <string>
#include <random>

#include "Terrain.hpp"

/**
 * @class Hexagon
 * @brief Represents a hexagon on a game board.
 *
 * The Hexagon class represents a hexagon on a game board. It stores the coordinates
 * of the hexagon, the terrain type, and whether it contains a robber. It also provides
 * getter and setter methods for accessing and modifying its properties.
 */
class Hexagon
{
public:
    /**
     * @brief Constructs a Hexagon object with the specified parameters.
     *
     * @param _q The q-coordinate of the Hexagon.
     * @param _r The r-coordinate of the Hexagon.
     * @param _t The terrain type of the Hexagon.
     * @param robber Indicates whether the Hexagon has a robber.
     */
    Hexagon(int _q, int _r, Terrain _t, bool robber = false);

    /**
     * @brief Converts the Hexagon object to a string representation.
     *
     * @return The string representation of the Hexagon object.
     */
    std::string toString();

    /**
     * @brief Gets the q-coordinate of the Hexagon.
     *
     * @return The q-coordinate of the Hexagon.
     */
    int getQ() const;

    /**
     * @brief Gets the r-coordinate of the Hexagon.
     *
     * @return The r-coordinate of the Hexagon.
     */
    int getR() const;

    /**
     * @brief Gets the s-coordinate of the Hexagon.
     *
     * @return The s-coordinate of the Hexagon.
     */
    int getS() const;

    /**
     * @brief Checks if the Hexagon contains a robber.
     *
     * @return True if the Hexagon contains a robber, false otherwise.
     */
    bool getContainsRobber() const;

    /**
     * @brief Sets whether the Hexagon contains a robber.
     *
     * @param containsRobber True if the Hexagon contains a robber, false otherwise.
     */
    void setContainsRobber(bool containsRobber);

    /**
     * @brief Gets the terrain type of the Hexagon.
     *
     * @return The terrain type of the Hexagon.
     */
    Terrain getTerrain() const;

    /**
     * @brief Sets the roll number of the Hexagon.
     *
     * @param rollNumber The roll number of the Hexagon.
     */
    void setRollNumber(int rollNumber);

private:
    int _q, _r, _rollNumber;
    Terrain _terrain;
    bool _containsRobber;
};