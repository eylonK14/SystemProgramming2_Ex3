// @author eylony1403@gmail.com

#pragma once
#include <string>

class Hexagon
{
public:
    Hexagon(int _q, int _r);
    std::string toString()
    {
        return std::to_string(_q) + "," + std::to_string(_r);
    }

    int q() const { return _q; }
    int r() const { return _r; }
    int s() const { return -_q - _r; }

private:
    int _q, _r;
};