// Derived class for Victory Point Cards (a type of Development Card)

#include "DevelopmentCard.hpp"

/**
 * @class VictoryPointCard
 * @brief Represents a victory point card, which is a type of development card.
 * 
 * This class inherits from the DevelopmentCard class and provides a specific implementation
 * for the victory point card. It overrides the getDescription() method to return a description
 * specific to the victory point card.
 */
class VictoryPointCard : public DevelopmentCard
{
public:
    /**
     * @brief Default constructor for the VictoryPointCard class.
     * 
     * Initializes the VictoryPointCard object with the name "Victory Point".
     */
    VictoryPointCard() : DevelopmentCard("Victory Point") {}

    /**
     * @brief Get the description of the victory point card.
     * 
     * @return A string representing the description of the victory point card.
     */
    std::string getDescription() const override
    {
        return "Development Card: Victory Point";
    }
};