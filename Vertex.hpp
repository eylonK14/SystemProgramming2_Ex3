// @author: eylony1403@gmail.com

#pragma once

#define NONE 0
#define SETTELEMENT 1
#define CITY 2

#include <string>

class Vertex
{
public:
    Vertex(int q, int r, char s);

    int getQ();
    int getR();
    char getS();
    int getOwnerID();
    int getHasOwner();
    void setOwnerID(int ownerID);
    void setHasOwner(int hasOwner);
    std::string toString();

private:
    int _q, _r, _ownerID, _hasOwner;
    char _s;
};