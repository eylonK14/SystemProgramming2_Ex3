//@author: eylony1403@gmail.com

/**
 * @file Board.hpp
 * @brief Defines the Board class which represents the game board.
 */

#pragma once

#include <iostream>
#include <random>
#include <map>
#include <vector>
#include <chrono>
#include <algorithm>

#include "Vertex.hpp"
#include "Edge.hpp"
#include "Hexagon.hpp"
#include "MultiMap.hpp"
#include "Terrain.hpp"
#include "../Player.hpp"

#define SIZE 2

/**
 * @class Board
 * @brief Represents the game board.
 */
class Board
{

public:
    /**
     * @brief Constructs a new Board object.
     */
    Board();

    /**
     * @brief Prints the board.
     */
    void print();

    /**
     * @brief Adds a settlement to the board.
     * @param x The x-coordinate of the settlement.
     * @param y The y-coordinate of the settlement.
     * @param playerId The ID of the player who owns the settlement.
     */
    bool addSettelment(int x, int y, int playerId, Player *player);

    /**
     * @brief Adds a road to the board.
     * @param x The x-coordinate of the road.
     * @param y The y-coordinate of the road.
     */
    bool addRoad(int x, int y);

    /**
     * @brief Moves the robber to a new location on the board.
     * @param newId The ID of the new location for the robber.
     */
    void moveRobber(int newId);

    /**
     * Performs a robbery on the terrain.
     *
     * @return The result of the robbery.
     */
    Terrain preformRobbery();

private:
    int _robberLocation;              /**< The current location of the robber on the board. */
    std::map<int, Hexagon> _hexagons; /**< The hexagons on the board. */
    MultiMap<Vertex> _vertexMap;      /**< The vertices on the board. */
    MultiMap<Edge> _edgeMap;          /**< The edges on the board. */

    /**
     * @brief Checks if the length of a road is legal.
     * @param length The length of the road.
     * @return True if the length is legal, false otherwise.
     */
    bool lengthLaw(int length);

    /**
     * @brief Checks if there is only one road leading to a vertex.
     * @param x The x-coordinate of the vertex.
     * @param y The y-coordinate of the vertex.
     * @return True if there is only one road leading to the vertex, false otherwise.
     */
    bool oneRoadLeading(int x, int y);

    /**
     * @brief Checks if a road is legal.
     * @param x The x-coordinate of the road.
     * @param y The y-coordinate of the road.
     * @return True if the road is legal, false otherwise.
     */
    bool checkLegalRoad(int x, int y);

    /**
     * @brief Randomizes the numbers on the hexagons.
     */
    void randomizeHexagonNumbers();
};