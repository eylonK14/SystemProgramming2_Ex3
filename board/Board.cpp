#include "Board.hpp"

Board::Board()
{
    int idx = 1;
    int secIdx = 1;

    for (int q = -2; q <= 2; q++)
    {
        for (int r = -2; r <= 2; r++)
        {
            int s = -q - r;
            if (s >= -2 && s <= 2)
            {
                if (idx == 10)
                {
                    _hexagons.insert(std::make_pair(idx, Hexagon(r, q, DESERT, true)));
                }
                else
                {
                    _hexagons.insert(std::make_pair(idx, Hexagon(r, q, randomTerrain())));
                }
                idx++;
            }
        }
    }

    randomizeHexagonNumbers();
    _hexagons.at(10).setRollNumber(7);

    std::cout << "Number of hexagons: " << _hexagons.size() << std::endl;

    for (auto hexagon : _hexagons)
    {
        std::cout << hexagon.second.toString() << std::endl;
    }

    idx = 1;

    for (auto hexagon : _hexagons)
    {
        Edge edgeNE = Edge(hexagon.second.getQ(), hexagon.second.getR(), "NE");
        Edge edgeNW = Edge(hexagon.second.getQ(), hexagon.second.getR(), "NW");
        Edge edgeW = Edge(hexagon.second.getQ(), hexagon.second.getR(), "W");

        _edgeMap.addValue(idx, edgeNE.toString(), edgeNE); // NE
        std::cout << edgeNE.toString() << std::endl;
        ++idx;
        _edgeMap.addValue(idx, edgeNW.toString(), edgeNW); // NW
        std::cout << edgeNW.toString() << std::endl;
        ++idx;
        _edgeMap.addValue(idx, edgeW.toString(), edgeW); // W
        std::cout << edgeW.toString() << std::endl;
        ++idx;

        Vertex vertexN = Vertex(hexagon.second.getQ(), hexagon.second.getR(), 'N'); // N
        Vertex vertexS = Vertex(hexagon.second.getQ(), hexagon.second.getR(), 'S'); // S

        _vertexMap.addValue(secIdx, vertexN.toString(), vertexN);
        std::cout << vertexN.toString() << std::endl;
        secIdx++;
        _vertexMap.addValue(secIdx, vertexS.toString(), vertexS);
        std::cout << vertexS.toString() << std::endl;
        secIdx++;
    }
}

bool Board::lengthLaw(int v)
{
    if (!_vertexMap.containsIndex(v))
    {
        return false;
    }

    Vertex vertex = _vertexMap.getValueByIndex(v);

    if (vertex.getS() == 'N')
    {
        bool firstC = true, secondC = true, thirdC = true;

        std::string first = std::to_string(vertex.getQ() + 1) + ":" + std::to_string(vertex.getR() - 2) + ":" + 'S';
        std::string second = std::to_string(vertex.getQ()) + ":" + std::to_string(vertex.getR() - 1) + ":" + 'S';
        std::string third = std::to_string(vertex.getQ() + 1) + ":" + std::to_string(vertex.getR() - 1) + ":" + 'S';

        if (_edgeMap.containsKey(first))
            firstC = _vertexMap.getValueByKey(first).getHasOwner() == NONE;
        if (_edgeMap.containsKey(second))
            secondC = _vertexMap.getValueByKey(second).getHasOwner() == NONE;
        if (_edgeMap.containsKey(third))
            thirdC = _vertexMap.getValueByKey(third).getHasOwner() == NONE;

        return firstC && secondC && thirdC;
    }
    else
    {
        bool firstC = true, secondC = true, thirdC = true;

        std::string first = std::to_string(vertex.getQ() - 1) + ":" + std::to_string(vertex.getR() + 1) + ":" + 'N';
        std::string second = std::to_string(vertex.getQ() - 1) + ":" + std::to_string(vertex.getR() + 2) + ":" + 'N';
        std::string third = std::to_string(vertex.getQ()) + ":" + std::to_string(vertex.getR() + 1) + ":" + 'N';

        if (_edgeMap.containsKey(first))
            firstC = _vertexMap.getValueByKey(first).getHasOwner() == NONE;
        if (_edgeMap.containsKey(second))
            secondC = _vertexMap.getValueByKey(second).getHasOwner() == NONE;
        if (_edgeMap.containsKey(third))
            thirdC = _vertexMap.getValueByKey(third).getHasOwner() == NONE;

        return firstC && secondC && thirdC;
    }
}

bool Board::oneRoadLeading(int v, int id)
{
    if (!_vertexMap.containsIndex(v))
    {
        return false;
    }

    Vertex vertex = _vertexMap.getValueByIndex(v);

    if (vertex.getS() == 'N')
    {
        bool firstC = false, secondC = false, thirdC = false;

        std::string first = std::to_string(vertex.getQ()) + ":" + std::to_string(vertex.getR()) + ":" + "NE";
        std::string second = std::to_string(vertex.getQ() + 1) + ":" + std::to_string(vertex.getR() - 1) + ":" + "W";
        std::string third = std::to_string(vertex.getQ()) + ":" + std::to_string(vertex.getR()) + ":" + "NW";

        if (_edgeMap.containsKey(first))
            firstC = _edgeMap.getValueByKey(first).getOwnerID() == id;
        if (_edgeMap.containsKey(second))
            secondC = _edgeMap.getValueByKey(first).getOwnerID() == id;
        if (_edgeMap.containsKey(third))
            thirdC = _edgeMap.getValueByKey(first).getOwnerID() == id;

        return firstC || secondC || thirdC;
    }
    else
    {
        bool firstC = false, secondC = false, thirdC = false;

        std::string first = std::to_string(vertex.getQ()) + ":" + std::to_string(vertex.getR() + 1) + ":" + "NW";
        std::string second = std::to_string(vertex.getQ() - 1) + ":" + std::to_string(vertex.getR() + 1) + ":" + "NE";
        std::string third = std::to_string(vertex.getQ()) + ":" + std::to_string(vertex.getR() + 1) + ":" + "W";

        if (_edgeMap.containsKey(first))
            firstC = _edgeMap.getValueByKey(first).getOwnerID() == id;
        if (_edgeMap.containsKey(second))
            secondC = _edgeMap.getValueByKey(first).getOwnerID() == id;
        if (_edgeMap.containsKey(third))
            thirdC = _edgeMap.getValueByKey(first).getOwnerID() == id;

        return firstC || secondC || thirdC;
    }
}

bool Board::checkLegalRoad(int edge, int id)
{
    if (!_edgeMap.containsIndex(edge))
    {
        return false;
    }

    Edge e = _edgeMap.getValueByIndex(edge);

    if (e.getS() == "NE")
    {
        bool firstC = false, secondC = false, thirdC = false, fourthC = false;

        std::string first = std::to_string(e.getQ() + 1) + ":" + std::to_string(e.getR() - 1) + ":" + 'S';
        std::string second = std::to_string(e.getQ()) + ":" + std::to_string(e.getR()) + ":" + 'N';

        if (_vertexMap.containsKey(first))
            firstC = _vertexMap.getValueByKey(first).getPlayer()->getId() == id;
        if (_vertexMap.containsKey(second))
            secondC = _vertexMap.getValueByKey(first).getPlayer()->getId() == id;

        thirdC = oneRoadLeading(_vertexMap.getIndexByKey(first), id);
        fourthC = oneRoadLeading(_vertexMap.getIndexByKey(second), id);

        return firstC || secondC || thirdC || fourthC;
    }

    if (e.getS() == "NW")
    {
        bool firstC = false, secondC = false, thirdC = false, fourthC = false;

        std::string first = std::to_string(e.getQ()) + ":" + std::to_string(e.getR() - 1) + ":" + 'S';
        std::string second = std::to_string(e.getQ()) + ":" + std::to_string(e.getR()) + ":" + 'N';

        if (_vertexMap.containsKey(first))
            firstC = _vertexMap.getValueByKey(first).getPlayer()->getId() == id;
        if (_vertexMap.containsKey(second))
            secondC = _vertexMap.getValueByKey(first).getPlayer()->getId() == id;

        thirdC = oneRoadLeading(_vertexMap.getIndexByKey(first), id);
        fourthC = oneRoadLeading(_vertexMap.getIndexByKey(second), id);

        return firstC || secondC || thirdC || fourthC;
    }

    else
    {
        bool firstC = false, secondC = false, thirdC = false, fourthC = false;

        std::string first = std::to_string(e.getQ()) + ":" + std::to_string(e.getR() - 1) + ":" + 'S';
        std::string second = std::to_string(e.getQ() - 1) + ":" + std::to_string(e.getR() + 1) + ":" + 'N';

        if (_vertexMap.containsKey(first))
            firstC = _vertexMap.getValueByKey(first).getPlayer()->getId() == id;
        if (_vertexMap.containsKey(second))
            secondC = _vertexMap.getValueByKey(first).getPlayer()->getId() == id;

        thirdC = oneRoadLeading(_vertexMap.getIndexByKey(first), id);
        fourthC = oneRoadLeading(_vertexMap.getIndexByKey(second), id);

        return firstC || secondC || thirdC || fourthC;
    }
}

bool Board::addSettelment(int v, int id, int settlementType, Player *player)
{
    if (settlementType == SETTELMENT)
    {
        if (lengthLaw(v) && oneRoadLeading(v, id))
        {
            _vertexMap.getValueByIndex(v).setPlayer(player);
            _vertexMap.getValueByIndex(v).setHasOwner(SETTELMENT);

            return true;
        }
    }
    if (settlementType == CITY)
    {
        if (_vertexMap.getValueByIndex(v).getPlayer()->getId() == id && _vertexMap.getValueByIndex(v).getHasOwner() == SETTELMENT)
        {
            _vertexMap.getValueByIndex(v).setHasOwner(CITY);

            return true;
        }
    }

    return false;
}

bool Board::addRoad(int e, int id)
{
    if (checkLegalRoad(e, id))
    {
        _edgeMap.getValueByIndex(e).setOwnerID(id);
        _edgeMap.getValueByIndex(e).setHasRoad(true);

        return true;
    }

    return false;
}

void Board::moveRobber(int newId)
{
    if (newId < 0 || newId > 19)
    {
        throw std::invalid_argument("Invalid argument");
    }
    _hexagons.at(_robberLocation).setContainsRobber(false);
    _hexagons.at(newId).setContainsRobber(true);
    _robberLocation = newId;
}

void Board::print()
{
    for (auto i = _hexagons.begin(); i != _hexagons.end(); i++)
    {
        std::cout << i->first << ": " << i->second.toString() << std::endl;
    }
}

void Board::randomizeHexagonNumbers()
{
    std::vector<int> numbers = {2, 3, 3, 4, 4, 5, 5, 6, 6, 8, 8, 9, 9, 10, 10, 11, 11, 12};

    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    std::shuffle(numbers.begin(), numbers.end(), std::default_random_engine(seed));

    size_t numberIndex = 0;
    for (auto &hexagonPair : _hexagons)
    {
        if (!(hexagonPair.second.getTerrain() == DESERT))
        {
            if (numberIndex < numbers.size())
            {
                hexagonPair.second.setRollNumber(numbers[numberIndex++]);
            }
        }
    }
}

Terrain Board::preformRobbery()
{
    Hexagon robberHex = _hexagons.at(_robberLocation);

    std::string first = std::to_string(robberHex.getQ()) + ":" + std::to_string(robberHex.getR()) + ":" + 'N';
    std::string second = std::to_string(robberHex.getQ() + 1) + ":" + std::to_string(robberHex.getR() - 1) + ":" + 'S';
    std::string third = std::to_string(robberHex.getQ()) + ":" + std::to_string(robberHex.getR() - 1) + ":" + 'S';
    std::string fourth = std::to_string(robberHex.getQ() - 1) + ":" + std::to_string(robberHex.getR() + 1) + ":" + 'N';
    std::string fifth = std::to_string(robberHex.getQ()) + ":" + std::to_string(robberHex.getR() + 1) + ":" + 'N';
    std::string sixth = std::to_string(robberHex.getQ()) + ":" + std::to_string(robberHex.getR()) + ":" + 'S';

    std::vector<std::string> vertices = {first, second, third, fourth, fifth, sixth};

    for (auto i = vertices.begin(); i != vertices.end(); i++)
    {
        if (_vertexMap.containsKey(*i))
        {
            if (_vertexMap.getValueByKey(*i).getHasOwner() == CITY || _vertexMap.getValueByKey(*i).getHasOwner() == SETTELMENT)
            {
                if (_vertexMap.getValueByKey(*i).getPlayer()->removeResourceCard(getResourceFromTerrain(robberHex.getTerrain())))
                    return robberHex.getTerrain();
            }
        }
    }
}