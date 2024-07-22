// Derived class for Knight Cards (a type of Development Card)

#include "DevelopmentCard.hpp"

/**
 * @class KnightCard
 * @brief Represents a Knight development card.
 * 
 * The KnightCard class is a subclass of DevelopmentCard and represents a development card with the ability to activate the knight action.
 * It provides a getDescription() method that returns a description of the card.
 */
class KnightCard : public DevelopmentCard
{
public:
    /**
     * @brief Default constructor for KnightCard.
     * 
     * Initializes a KnightCard object with the name "Knight".
     */
    KnightCard() : DevelopmentCard("Knight") {}

    /**
     * @brief Get the description of the KnightCard.
     * 
     * @return A string representing the description of the KnightCard.
     */
    std::string getDescription() const override
    {
        return "Development Card: Knight";
    }
};