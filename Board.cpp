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
                _hexagons.insert(std::make_pair(idx, Hexagon(r, q)));
                idx++;
            }
        }
    }

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
            firstC = _vertexMap.getValueByKey(first).getOwnerID() == id;
        if (_vertexMap.containsKey(second))
            secondC = _vertexMap.getValueByKey(first).getOwnerID() == id;

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
            firstC = _vertexMap.getValueByKey(first).getOwnerID() == id;
        if (_vertexMap.containsKey(second))
            secondC = _vertexMap.getValueByKey(first).getOwnerID() == id;

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
            firstC = _vertexMap.getValueByKey(first).getOwnerID() == id;
        if (_vertexMap.containsKey(second))
            secondC = _vertexMap.getValueByKey(first).getOwnerID() == id;

        thirdC = oneRoadLeading(_vertexMap.getIndexByKey(first), id);
        fourthC = oneRoadLeading(_vertexMap.getIndexByKey(second), id);

        return firstC || secondC || thirdC || fourthC;
    }
}

void Board::addSettelment(int v, int id, int settementType)
{
    if (lengthLaw(v) && oneRoadLeading(v, id))
    {
        _vertexMap.getValueByIndex(v).setOwnerID(id);
        _vertexMap.getValueByIndex(v).setHasOwner(settementType);
    }
}

void Board::addRoad(int e, int id)
{
    if (checkLegalRoad(e, id))
    {
        _edgeMap.getValueByIndex(e).setOwnerID(id);
        _edgeMap.getValueByIndex(e).setHasRoad(true);
    }
}
