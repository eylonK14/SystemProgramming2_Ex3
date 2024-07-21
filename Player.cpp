// @author: eylony1403@gmail.com

#include "Player.hpp"

Player::Player(int id) : _id(id), _victoryPoints(0)
{
}

int Player::rollDice()
{
    int result = 0;
    std::random_device rd;  // a seed source for the random number engine
    std::mt19937 gen(rd()); // mersenne_twister_engine seeded with rd()
    std::uniform_int_distribution<> distrib(1, 6);

    result = distrib(gen);
    result += distrib(gen);

    return result;
}

void Player::build(Board &board)
{
    std::cout << "What type of building would you like to build?" << std::endl
              << "1. Road" << std::endl
              << "2. Settlement" << std::endl
              << "3. City" << std::endl;
    int choice = 0;
    std::cin >> choice;

    switch (choice)
    {
    case 1:
        int roadLocation = 0;
        std::cout << "Enter road location: ";
        std::cin >> roadLocation;

        if (board.addRoad(_id, roadLocation))
        {
            std::cout << "Road added successfully!" << std::endl;
            _resourceCards[Resource::BRICK]--;
            _resourceCards[Resource::LUMBER]--;
        }
        else
        {
            std::cout << "Invalid road location!" << std::endl;
        }
        break;
    case 2:
        int settlementLocation = 0;
        std::cout << "Enter settlement location: ";
        std::cin >> settlementLocation;

        if (board.addSettelment(settlementLocation, _id, SETTELMENT))
        {
            std::cout << "Road added successfully!" << std::endl;
            _resourceCards[Resource::BRICK]--;
            _resourceCards[Resource::LUMBER]--;
            _resourceCards[Resource::WOOL]--;
            _resourceCards[Resource::GRAIN]--;
        }
        else
        {
            std::cout << "Invalid road location!" << std::endl;
        }
        break;
    case 3:
        int settlementLocation = 0;
        std::cout << "Enter settlement location: ";
        std::cin >> settlementLocation;

        if (board.addSettelment(settlementLocation, _id, CITY))
        {
            std::cout << "Road added successfully!" << std::endl;
            _resourceCards[Resource::ORE] -= 3;
            _resourceCards[Resource::GRAIN] -= 2;
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
