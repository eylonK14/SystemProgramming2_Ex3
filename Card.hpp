#include <iostream>
#include <string>
#include <vector>

// Base class for all cards
class Card {
public:
    virtual std::string getDescription() const = 0; // Pure virtual function
    virtual ~Card() = default; // Virtual destructor
};