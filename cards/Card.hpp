#include <iostream>
#include <string>
#include <vector>

// Base class for all cards
/**
 * @class Card
 * @brief Represents a generic card.
 *
 * The Card class is an abstract base class that provides a common interface for all types of cards.
 * It defines a pure virtual function `getDescription()` that must be implemented by derived classes.
 * The class also has a virtual destructor to ensure proper cleanup when deleting objects through a base class pointer.
 */
class Card
{
public:
    /**
     * @brief Gets the description of the card.
     * @return A string representing the description of the card.
     */
    virtual std::string getDescription() const = 0; // Pure virtual function

    /**
     * @brief Virtual destructor.
     *
     * The virtual destructor ensures that the destructor of the derived class is called when deleting objects
     * through a base class pointer.
     */
    virtual ~Card() = default;
};