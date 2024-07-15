// Derived class for Victory Point Cards (a type of Development Card)

#include "DevelopmentCard.hpp"

class VictoryPointCard : public DevelopmentCard
{
public:
    VictoryPointCard() : DevelopmentCard("Victory Point") {}

    std::string getDescription() const override
    {
        return "Development Card: Victory Point";
    }
};