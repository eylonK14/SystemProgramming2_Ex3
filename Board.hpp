//@author: eylony1403@gmail.com

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

#define SIZE 2

class Board
{

public:
    Board();
    void print();
    void addSettelment(int, int, int);
    void addRoad(int, int);

    void moveRobber(int newId);
    // TODO GET VERTEXS WHERE ROBBER IS
private:
    int _robberLocation;
    std::map<int, Hexagon> _hexagons;
    MultiMap<Vertex> _vertexMap;
    MultiMap<Edge> _edgeMap;

    bool lengthLaw(int);
    bool oneRoadLeading(int, int);
    bool checkLegalRoad(int, int);
    void randomizeHexagonNumbers();
};