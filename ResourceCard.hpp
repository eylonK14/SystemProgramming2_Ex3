// Derived class for Resource Cards

#include "Card.hpp"

class ResourceCard : public Card {
private:
    std::string resourceType;

public:
    ResourceCard(const std::string& resource) : resourceType(resource) {}

    std::string getDescription() const override {
        return "Resource Card: " + resourceType;
    }
};