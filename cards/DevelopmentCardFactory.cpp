// @author: eylony1403@gmail.com

#include "DevelopmentCardFactory.hpp"

/**
 * @brief Generates a random DevelopmentCard.
 *
 * This function generates a random DevelopmentCard by using a random number generator
 * and a uniform distribution. It returns a KnightCard or a VictoryPointCard based on
 * the generated random number.
 *
 * @return A randomly generated DevelopmentCard.
 */
DevelopmentCard getCard()
{
    std::random_device rd;  // a seed source for the random number engine
    std::mt19937 gen(rd()); // mersenne_twister_engine seeded with rd()
    std::uniform_int_distribution<> distrib(1, 2);

    if (distrib(gen) == 1)
        return KnightCard();
    else
        return VictoryPointCard();
}
