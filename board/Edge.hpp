/**
 * @file Edge.hpp
 * @brief This file contains the declaration of the Edge class.
 * @author: eylony1403@gmail.com
 *
 * The Edge class represents an edge in a graph. It stores information such as the owner ID,
 * whether it has a road, and the coordinates of the edge.
 */

#pragma once

#include <string>

class Edge
{
public:
    /**
     * @brief Constructs an Edge object with the given coordinates and string.
     *
     * @param q The q-coordinate of the edge.
     * @param r The r-coordinate of the edge.
     * @param s The string associated with the edge.
     */
    Edge(int q, int r, std::string s);

    /**
     * @brief Returns a string representation of the Edge object.
     *
     * @return A string representation of the Edge object.
     */
    std::string toString();

    /**
     * @brief Returns the owner ID of the Edge object.
     *
     * @return The owner ID of the Edge object.
     */
    int getOwnerID();

    /**
     * @brief Sets the owner ID of the Edge object.
     *
     * @param ownerID The owner ID to set.
     */
    void setOwnerID(int ownerID);

    /**
     * @brief Returns whether the Edge object has a road.
     *
     * @return True if the Edge object has a road, false otherwise.
     */
    bool getHasRoad();

    /**
     * @brief Sets whether the Edge object has a road.
     *
     * @param hasRoad Whether the Edge object has a road.
     */
    void setHasRoad(bool hasRoad);

    /**
     * @brief Returns the q-coordinate of the Edge object.
     *
     * @return The q-coordinate of the Edge object.
     */
    int getQ();

    /**
     * @brief Returns the r-coordinate of the Edge object.
     *
     * @return The r-coordinate of the Edge object.
     */
    int getR();

    /**
     * @brief Returns the string associated with the Edge object.
     *
     * @return The string associated with the Edge object.
     */
    std::string getS();

private:
    int _q, _r, _ownerID;
    std::string _s;
    bool _hasRoad;
};