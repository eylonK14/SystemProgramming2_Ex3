
#include "DevelopmentCard.hpp"
class ProgressCard : public DevelopmentCard
{
private:
    std::string progressType;

public:
    ProgressCard(const std::string &type) : DevelopmentCard("Progress"), progressType(type) {}

    std::string getDescription() const override
    {
        return "Development Card: Progress - " + progressType;
    }
};