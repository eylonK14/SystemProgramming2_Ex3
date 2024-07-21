// @author: eylony1403@gmail.com

#pragma once

#define NONE 0
#define SETTELMENT 1
#define CITY 2

#include <string>

#include "Player.hpp"

/**
 * @class Vertex
 * @brief Represents a vertex in a graph.
 * @author: eylony1403@gmail.com
 *
 * The Vertex class stores information about a vertex in a graph, including its coordinates,
 * owner ID, and whether it has an owner. It also provides methods to access and modify this information.
 */
class Vertex
{
public:
    /**
     * @brief Constructs a Vertex object with the given coordinates and symbol.
     *
     * @param q The q-coordinate of the vertex.
     * @param r The r-coordinate of the vertex.
     * @param s The symbol associated with the vertex.
     */
    Vertex(int q, int r, char s);

    /**
     * @brief Gets the q-coordinate of the vertex.
     *
     * @return The q-coordinate of the vertex.
     */
    int getQ();

    /**
     * @brief Gets the r-coordinate of the vertex.
     *
     * @return The r-coordinate of the vertex.
     */
    int getR();

    /**
     * @brief Gets the symbol associated with the vertex.
     *
     * @return The symbol associated with the vertex.
     */
    char getS();

    /**
     * @brief Gets whether the vertex has an owner.
     *
     * @return 1 if the vertex has an owner, 0 otherwise.
     */
    int getHasOwner();

    /**
     * @brief Sets whether the vertex has an owner.
     *
     * @param hasOwner 1 if the vertex has an owner, 0 otherwise.
     */
    void setHasOwner(int hasOwner);

    /**
     * @brief Converts the vertex to a string representation.
     *
     * @return The string representation of the vertex.
     */
    std::string toString();

    Player *getPlayer();

    void setPlayer(Player *player);

private:
    int _q, _r, _hasOwner;
    char _s;
    Player *_player;
};