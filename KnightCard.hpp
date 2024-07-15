// Derived class for Knight Cards (a type of Development Card)

#include "DevelopmentCard.hpp"

class KnightCard : public DevelopmentCard
{
public:
    KnightCard() : DevelopmentCard("Knight") {}

    std::string getDescription() const override
    {
        return "Development Card: Knight";
    }
};