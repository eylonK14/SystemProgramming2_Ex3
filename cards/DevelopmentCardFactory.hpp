// @author: eylony1403@gmail.com

#pragma once

#include <iostream>
#include <random>

#include "KnightCard.hpp"
#include "VictoryPointCard.hpp"

/**
 * @brief Generates a random DevelopmentCard.
 *
 * This function generates a random DevelopmentCard by using a random number generator
 * and a uniform distribution. It returns a KnightCard or a VictoryPointCard based on
 * the generated random number.
 *
 * @return A randomly generated DevelopmentCard.
 */
DevelopmentCard getCard();
