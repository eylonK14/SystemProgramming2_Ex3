// Derived class for Development Cards

#include "Card.hpp"

class DevelopmentCard : public Card
{
private:
    std::string devType;

public:
    DevelopmentCard(const std::string &type) : devType(type) {}

    std::string getDescription() const override
    {
        return "Development Card: " + devType;
    }
};