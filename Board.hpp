//@author: eylony1403@gmail.com

#pragma once

#include <iostream>
#include <random>
#include <map>
#include <vector>

#include "Vertex.hpp"
#include "Edge.hpp"
#include "Hexagon.hpp"
#include "MultiMap.hpp"

#define SIZE 2

enum Resource
{
    HILLS,
    FOREST,
    MOUNTAINS,
    DESERT,
    PASTURE,
    FIELDS
};
// typedef struct HexData
// {
//     Resource resource;
//     unsigned int rollNum;
// } HexData;

class Board
{
private:
    std::map<int, Hexagon> _hexagons;

    MultiMap<Vertex> _vertexMap;
    MultiMap<Edge> _edgeMap;

public:
    Board();
    void print();
    bool Board::lengthLaw(int i);
};