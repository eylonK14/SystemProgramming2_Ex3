// @author: eylony1403@gmail.com

#include "Player.hpp"

Player::Player(int id) : _id(id), _victoryPoints(0)
{
}

int Player::getId()
{
    return _id;
}

void Player::rollDice(Board &board, Player &player1, Player &player2)
{
    int result = 0;
    std::random_device rd;  // a seed source for the random number engine
    std::mt19937 gen(rd()); // mersenne_twister_engine seeded with rd()
    std::uniform_int_distribution<> distrib(1, 6);

    result = distrib(gen);
    result += distrib(gen);

    std::vector<Hexagon> hexagons = board.yieldResources(result);

    for (auto hexagon : hexagons)
    {
        for (auto v : board.getVerticesFromHexagon(hexagon))
        {
            if (v.getOwnerID() == player1.getId())
            {
                player1._resourceCards[getIndexFromResource(getResourceFromTerrain(hexagon.getTerrain()))]++;
            }
            if (v.getOwnerID() == player2.getId())
            {
                player2._resourceCards[getIndexFromResource(getResourceFromTerrain(hexagon.getTerrain()))]++;
            }
            if (v.getOwnerID() == _id)
            {
                _resourceCards[getIndexFromResource(getResourceFromTerrain(hexagon.getTerrain()))]++;
            }
        }
    }
}

void Player::build(Board &board, bool firstRound)
{
    std::cout << "What type of building would you like to build?" << std::endl
              << "1. Road" << std::endl
              << "2. Settlement" << std::endl
              << "3. City" << std::endl;
    int choice = 0;
    int settlementLocation = 0;
    int roadLocation = 0;
    std::cin >> choice;

    switch (choice)
    {
    case 1:
        if (_resourceCards[Resource::BRICK] < 1 || _resourceCards[Resource::LUMBER] < 1)
        {
            std::cout << "Insufficient resources!" << std::endl;
            break;
        }
        std::cout << "Enter road location: ";
        std::cin >> roadLocation;

        if (board.addRoad(_id, roadLocation))
        {
            std::cout << "Road added successfully!" << std::endl;
            if (!firstRound)
            {
                _resourceCards[Resource::BRICK]--;
                _resourceCards[Resource::LUMBER]--;
            }
        }
        else
        {
            std::cout << "Invalid road location!" << std::endl;
        }
        break;
    case 2:
        if (_resourceCards[Resource::BRICK] < 3 || _resourceCards[Resource::LUMBER] < 2 || _resourceCards[Resource::WOOL] < 1 || _resourceCards[Resource::GRAIN] < 1)
        {
            std::cout << "Insufficient resources!" << std::endl;
            break;
        }
        std::cout << "Enter settlement location: ";
        std::cin >> settlementLocation;

        if (board.addSettelment(settlementLocation, _id, SETTELMENT))
        {
            std::cout << "Settlement added successfully!" << std::endl;
            if (!firstRound)
            {
                _resourceCards[Resource::BRICK]--;
                _resourceCards[Resource::LUMBER]--;
                _resourceCards[Resource::WOOL]--;
                _resourceCards[Resource::GRAIN]--;
            }
        }
        // TODO: Add settlement location to vertex
        else
        {
            std::cout << "Invalid road location!" << std::endl;
        }
        break;
    case 3:
        if (_resourceCards[Resource::ORE] < 3 || _resourceCards[Resource::GRAIN] < 2)
        {
            std::cout << "Insufficient resources!" << std::endl;
            break;
        }
        std::cout << "Enter settlement location: ";
        std::cin >> settlementLocation;

        if (board.addSettelment(settlementLocation, _id, CITY))
        {
            std::cout << "City added successfully!" << std::endl;
            if (!firstRound)
            {
                _resourceCards[Resource::ORE] -= 3;
                _resourceCards[Resource::GRAIN] -= 2;
            }
        }
        else
        {
            std::cout << "Invalid road location!" << std::endl;
        }
        break;
        break;
    default:
        std::cout << "Invalid choice!" << std::endl;
        break;
    }
}

bool Player::removeResourceCard(Resource resource)
{
    if (_resourceCards[resource] > 0)
    {
        _resourceCards[resource]--;
        return true;
    }
    return false;
}

void Player::Robber(Board &board)
{
    int newLocation = 0;
    std::cout << "Enter new robber location: ";
    std::cin >> newLocation;

    board.moveRobber(newLocation);
}

void Player::purchaseDevelopmentCard()
{
    if (_resourceCards[Resource::ORE] < 1 || _resourceCards[Resource::WOOL] < 1 || _resourceCards[Resource::GRAIN] < 1)
    {
        std::cout << "Insufficient resources!" << std::endl;
        return;
    }

    _resourceCards[Resource::ORE]--;
    _resourceCards[Resource::WOOL]--;
    _resourceCards[Resource::GRAIN]--;

    _developmentCards.push_back(getCard());
}

void Player::playDevelopmentCard(Board &board)
{
    if (_developmentCards.size() == 0)
    {
        std::cout << "No development cards to play!" << std::endl;
        return;
    }

    DevelopmentCard card = _developmentCards.front();
    _developmentCards.erase(_developmentCards.begin());

    if (card.getDescription() == "Victory Point Card")
    {
        this->_victoryPoints++;
    }
    else
    {
        int choice = 0;
        std::cout << "Knight card played!" << std::endl;
        std::cout << "Where do you want to place the robber? ";
        std::cin >> choice;

        if (choice == 10)
        {
            std::cout << "Invalid choice!" << std::endl;
        }
        else
        {
            board.moveRobber(choice);
            this->_knightCount++;

            if (this->_knightCount == 3)
                _victoryPoints += 2;
        }
    }
}

void Player::trade(Player &player1, Player &player2)
{
    TradeMaker t;
    int choice = 0;
    std::cout << "Which player do you want to trade with?" << std::endl
              << "1. Player 1" << std::endl
              << "2. Player 2" << std::endl;
    std::cin >> choice;

    std::string giveR;
    std::string wantR;

    int give = 0;
    int want = 0;
    std::cout << "What resource do you want to give (Resource Amount - (-1 to stop))? ";
    while (giveR != "-1")
    {
        std::cin >> giveR;
        if (giveR == "-1")
            break;
        std::cin >> give;

        addToGive(t, giveR, give);
    }

    std::cin >> giveR >> give;
    std::cout << "What resource do you want to get (Resource Amount - (-1 to stop))? ";
    while (wantR != "-1")
    {
        std::cin >> wantR;
        if (wantR == "-1")
            break;
        std::cin >> want;

        addToGive(t, wantR, want);
    }

    if (choice == 1)
    {
        for (int i = 0; i < 5; i++)
        {
            if (t._give[i] > player1._resourceCards[i])
            {
                std::cout << "Invalid trade!" << std::endl;
                return;
            }
        }

        for (int i = 0; i < 5; i++)
        {
            _resourceCards[i] -= t._give[i];
            _resourceCards[i] += t._get[i];
            player1._resourceCards[i] += t._give[i];
            player1._resourceCards[i] -= t._get[i];
        }
    }
    else if (choice == 2)
    {
        for (int i = 0; i < 5; i++)
        {
            if (t._give[i] > player2._resourceCards[i])
            {
                std::cout << "Invalid trade!" << std::endl;
                return;
            }
        }

        for (int i = 0; i < 5; i++)
        {
            _resourceCards[i] -= t._give[i];
            _resourceCards[i] += t._get[i];
            player2._resourceCards[i] += t._give[i];
            player2._resourceCards[i] -= t._get[i];
        }
    }
    else
    {
        std::cout << "Invalid choice!" << std::endl;
    }
}

int Player::getVictoryPoints()
{
    return _victoryPoints;
}
