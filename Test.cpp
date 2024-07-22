#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include "doctest.h"
#include "board/Vertex.hpp"
#include "Player.hpp"
#include "board/Terrain.hpp"
#include "board/MultiMap.hpp"
#include "board/Edge.hpp"
#include "board/Board.hpp"
#include "board/Hexagon.hpp"

TEST_CASE("Vertex Construction")
{
    Vertex v(1, 2, 'A');
    CHECK(v.getQ() == 1);
    CHECK(v.getR() == 2);
    CHECK(v.getS() == 'A');
    CHECK(v.getHasOwner() == 0);
    CHECK(v.getPlayer() == nullptr);
}

TEST_CASE("Vertex Owner")
{
    Vertex v(1, 2, 'A');
    Player p(1);
    v.setHasOwner(1);
    v.setPlayer(&p);
    CHECK(v.getHasOwner() == 0);
    CHECK(v.getPlayer() == &p);
}

TEST_CASE("Vertex String Representation")
{
    Vertex v(1, 2, 'A');
    std::string expected = "Vertex (1, 2): A";
    CHECK(v.toString() == expected);
}

TEST_CASE("terrainToString")
{
    SUBCASE("PASTURE")
    {
        Terrain terrain = PASTURE;
        std::string expected = "PASTURE";
        CHECK(terrainToString(terrain) == expected);
    }

    SUBCASE("FOREST")
    {
        Terrain terrain = FOREST;
        std::string expected = "FOREST";
        CHECK(terrainToString(terrain) == expected);
    }

    SUBCASE("HILLS")
    {
        Terrain terrain = HILLS;
        std::string expected = "HILLS";
        CHECK(terrainToString(terrain) == expected);
    }

    SUBCASE("MOUNTAINS")
    {
        Terrain terrain = MOUNTAINS;
        std::string expected = "MOUNTAINS";
        CHECK(terrainToString(terrain) == expected);
    }

    SUBCASE("FIELDS")
    {
        Terrain terrain = FIELDS;
        std::string expected = "FIELDS";
        CHECK(terrainToString(terrain) == expected);
    }

    SUBCASE("DESERT")
    {
        Terrain terrain = DESERT;
        std::string expected = "DESERT";
        CHECK(terrainToString(terrain) == expected);
    }
}

TEST_CASE("MultiMap Test")
{
    MultiMap<int> multiMap;

    // Add values to the MultiMap
    multiMap.addValue(0, "zero", 0);
    multiMap.addValue(1, "one", 1);
    multiMap.addValue(2, "two", 2);

    // Check if the MultiMap contains the keys
    CHECK(multiMap.containsKey("zero"));
    CHECK(multiMap.containsKey("one"));
    CHECK(multiMap.containsKey("two"));

    // Check if the MultiMap contains the indices
    CHECK(multiMap.containsIndex(0));
    CHECK(multiMap.containsIndex(1));
    CHECK(multiMap.containsIndex(2));

    // Get values by index
    CHECK(multiMap.getValueByIndex(0) == 0);
    CHECK(multiMap.getValueByIndex(1) == 1);
    CHECK(multiMap.getValueByIndex(2) == 2);

    // Get values by key
    CHECK(multiMap.getValueByKey("zero") == 0);
    CHECK(multiMap.getValueByKey("one") == 1);
    CHECK(multiMap.getValueByKey("two") == 2);

    // Get index by key
    CHECK(multiMap.getIndexByKey("zero") == 0);
    CHECK(multiMap.getIndexByKey("one") == 1);
    CHECK(multiMap.getIndexByKey("two") == 2);

    // Get key by index
    CHECK(multiMap.getKeyByIndex(0) == "zero");
    CHECK(multiMap.getKeyByIndex(1) == "one");
    CHECK(multiMap.getKeyByIndex(2) == "two");
}

TEST_CASE("Hexagon toString")
{
    Hexagon hex(1, 2, Terrain::FOREST, true);
    hex.setRollNumber(6);
    std::string expected = "1,2,Forest,1,6";
    CHECK_EQ(hex.toString(), expected);
}

TEST_CASE("Hexagon getters and setters")
{
    Hexagon hex(3, 4, Terrain::HILLS, false);
    CHECK_EQ(hex.getQ(), 3);
    CHECK_EQ(hex.getR(), 4);
    CHECK_EQ(hex.getS(), -7);
    CHECK_EQ(hex.getContainsRobber(), false);
    hex.setContainsRobber(true);
    CHECK_EQ(hex.getContainsRobber(), true);
    hex.setRollNumber(3);
    CHECK_EQ(hex.getRollNumber(), 3);
    CHECK_EQ(hex.getTerrain(), Terrain::HILLS);
}

TEST_CASE("Edge toString")
{
    SUBCASE("Positive q and r values")
    {
        Edge edge(1, 2, "A");
        std::string expected = "1:2:A";
        CHECK_EQ(edge.toString(), expected);
    }

    SUBCASE("Negative q and r values")
    {
        Edge edge(-3, -4, "B");
        std::string expected = "-3:-4:B";
        CHECK_EQ(edge.toString(), expected);
    }

    SUBCASE("Zero q and r values")
    {
        Edge edge(0, 0, "C");
        std::string expected = "0:0:C";
        CHECK_EQ(edge.toString(), expected);
    }
}

TEST_CASE("Test Board::addSettelment")
{
    Board board;
    Player player(1);
    Player player2(2);
    Player player3(3);

    // Test adding a settlement at (0, 0) for player 1
    CHECK(board.addSettelment(0, 0, 1, &player) == true);

    // Test adding a settlement at (1, 1) for player 2
    CHECK(board.addSettelment(1, 1, 2, &player3) == true);

    // Test adding a settlement at (0, 0) for player 3 (should fail because there is already a settlement)
    CHECK(board.addSettelment(0, 0, 3, &player3) == false);
}

TEST_CASE("Test Board::addRoad")
{
    Board board;

    // Test adding a road at (0, 0)
    CHECK(board.addRoad(0, 0) == true);

    // Test adding a road at (1, 1)
    CHECK(board.addRoad(1, 1) == true);

    // Test adding a road at (0, 0) again (should fail because there is already a road)
    CHECK(board.addRoad(0, 0) == false);
}

TEST_CASE("Test Board::preformRobbery")
{
    Board board;

    // Test performing a robbery
    Terrain result = board.preformRobbery();
    CHECK(result == Terrain::FOREST || result == Terrain::HILLS || result == Terrain::FIELDS ||
          result == Terrain::MOUNTAINS || result == Terrain::PASTURE || result == Terrain::DESERT);
}