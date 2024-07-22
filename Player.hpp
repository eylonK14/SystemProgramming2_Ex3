// @author eylony1403@gmail.com

#pragma once

#include <iostream>
#include <random>

#include "Resource.hpp"
#include "cards/DevelopmentCard.hpp"
#include "cards/DevelopmentCardFactory.cpp"
#include "board/Board.hpp"
#include "board/Vertex.hpp"

/**
 * @class Player
 * @brief Represents a player in the game.
 *
 * The Player class encapsulates the functionality and attributes of a player in the game.
 * It provides methods for rolling dice, building structures, removing resource cards,
 * interacting with the game board, purchasing and playing development cards, and more.
 */
class Player
{
public:
    /**
     * @brief Constructs a new Player object with the given ID.
     *
     * @param id The ID of the player.
     */
    Player(int id);

    /**
     * @brief Destroys the Player object.
     */
    ~Player();

    /**
     * @brief Gets the ID of the player.
     *
     * @return The ID of the player.
     */
    int getId();

    /**
     * @brief Rolls the dice and returns the result.
     *
     * @return The result of the dice roll.
     */
    int rollDice();

    /**
     * @brief Builds a structure on the game board.
     *
     * @param board The game board.
     * @param firstRound Flag indicating if it's the first round of the game.
     */
    void build(Board &board, bool firstRound = false);

    /**
     * @brief Removes a resource card from the player's hand.
     *
     * @param resource The resource card to remove.
     * @return True if the card was successfully removed, false otherwise.
     */
    bool removeResourceCard(Resource resource);

    /**
     * @brief Activates the Robber and performs the corresponding actions on the game board.
     *
     * @param board The game board.
     */
    void Robber(Board &board);

    /**
     * @brief Purchases a development card.
     */
    void purchaseDevelopmentCard();

    /**
     * @brief Plays a development card and performs the corresponding actions on the game board.
     *
     * @param board The game board.
     */
    void playDevelopmentCard(Board &board);

private:
    int _id;                                        // The ID of the player.
    int _victoryPoints;                             // The number of victory points the player has.
    int _knightCount;                               // The number of knight development cards the player has.
    int _resourceCards[5];                          // The number of each resource card the player has.
    std::vector<DevelopmentCard> _developmentCards; // The development cards the player has.
};