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
                _hexagons.insert(std::make_pair(idx, Hexagon(q, r)));
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
        ++idx;
        _edgeMap.addValue(idx, edgeNW.toString(), edgeNW); // NW
        ++idx;
        _edgeMap.addValue(idx, edgeW.toString(), edgeW); // W
        ++idx;

        Vertex vertexN = Vertex(hexagon.second.getQ(), hexagon.second.getR(), 'N'); // N
        Vertex vertexS = Vertex(hexagon.second.getQ(), hexagon.second.getR(), 'S'); // S

        _vertexMap.addValue(secIdx, vertexN.toString(), vertexN);
        secIdx++;
        _vertexMap.addValue(secIdx, vertexS.toString(), vertexS);
        secIdx++;
    }
}

bool Board::lengthLaw(int v)
{
    Vertex vertex = _vertexMap.getValueByIndex(v);
    if (vertex.getS() == 'N')
    {
        std::string first = std::to_string(vertex.getQ() + 1) + ":" + std::to_string(vertex.getR() - 2) + ":" + 'S';
        std::string second = std::to_string(vertex.getQ()) + ":" + std::to_string(vertex.getR() - 1) + ":" + 'S';
        std::string third = std::to_string(vertex.getQ() + 1) + ":" + std::to_string(vertex.getR() - 1) + ":" + 'S';

        return _vertexMap.getValueByKey(first).getHasOwner() == NONE &&
               _vertexMap.getValueByKey(second).getHasOwner() == NONE && _vertexMap.getValueByKey(third).getHasOwner() == NONE;
    }
    else if (vertex.getS() == 'S')
    {
        std::string first = std::to_string(vertex.getQ() - 1) + ":" + std::to_string(vertex.getR() + 1) + ":" + 'N';
        std::string second = std::to_string(vertex.getQ() - 1) + ":" + std::to_string(vertex.getR() + 2) + ":" + 'N';
        std::string third = std::to_string(vertex.getQ()) + ":" + std::to_string(vertex.getR() + 1) + ":" + 'N';

        return _vertexMap.getValueByKey(first).getHasOwner() == NONE &&
               _vertexMap.getValueByKey(second).getHasOwner() == NONE && _vertexMap.getValueByKey(third).getHasOwner() == NONE;
    }
}
