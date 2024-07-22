// Derived class for Development Cards

#pragma once

#include "Card.hpp"

/**
 * @class DevelopmentCard
 * @brief Represents a development card in a card game.
 *
 * This class inherits from the base class Card and adds a development type to the card.
 * It provides a method to get the description of the card.
 */
class DevelopmentCard : public Card
{
private:
    std::string devType;

public:
    /**
     * @brief Constructs a DevelopmentCard object with the specified development type.
     * @param type The development type of the card.
     */
    DevelopmentCard(const std::string &type) : devType(type) {}

    /**
     * @brief Gets the description of the development card.
     * @return The description of the development card.
     */
    std::string getDescription() const override
    {
        return "Development Card: " + devType;
    }
};