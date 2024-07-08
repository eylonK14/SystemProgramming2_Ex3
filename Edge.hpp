// @author: eylony1403@gmail.com

#pragma once

#include <string>

class Edge
{
public:
    Edge(int q, int r, std::string s);
    std::string toString();

private:
    int _q, _r, _ownerID;
    std::string _s;
    bool _hasRoad;
};