// Mail: Roniharpaz1@gmail.com
#ifndef PLAYER_HPP
#define PLAYER_HPP
#include "Board.hpp"
#include "DevelopmentCard.hpp"
#include <algorithm>
#include <iostream>
#include <map>
#include <random>
#include <stdexcept>
#include <string>
#include <vector>
using namespace std;

namespace catan {
/**
 * @class Player:
 * This class represents a player in the game.
 *
 * Each player has a name, a collection of cards, points, and a flag indicating
 * if it is their turn. They are also associated with a game board and can
 * perform various actions such as buying and using development cards, placing
 * roads, settlements, and towns, rolling dice, and trading with other players.
 */
class Player {
protected:
  string _name;                   ///< The player's name
  map<string, int> _cards;        ///< A map of the player's resource cards
  int _points = 0;                ///< The player's points
  bool _isMyTurn = false;         ///< Flag to check if it is the player's turn
  Player *_nextPlayer;            ///< Pointer to the next player in turn
  Board *_board;                  ///< Pointer to the game board
  vector<Player *> _otherPlayers; ///< List of other players in the game
  map<DevelopmentCard *, int>_developmentCards; ///< A map of the player's development cards

public:
  Player();                                              // Default constructor for Player.
  ~Player();                                             // Destructor for Player.
  Player(string name);                                   // Constructor for Player with a specified name.
  string getName();                                      // Get the player's name.
  int getNumOfPoints();                                  // Get the player's points.
  void BuyDevelopCard();                                 // Allow the player to buy a development card.
  void useDevelpCard(DevelopmentCard *d);                // Allow the player to use a development card.
  void implementDevelopCard(DevelopmentCard *d);         // Implement the effect of a development card.
  void addCard(Card *c);                                 // Add a resource card to the player's collection.
  void add2Card(Card *c);                                // Add two resource cards to the player's collection.
  void printDevelopCard();                               // Print the player's development cards.
  void printCard();                                      // Print the player's resource cards.
  int rollDice();                                        // Roll dice to determine the outcome of the player's turn.
  void placeRoad(int wayNumber);                         // Place a road on the game board.
  void placeSettelment(int juncNum);                     // Place a settlement on the game board.
  void placeTown(int JunctionNumber);                    // Place a town on the game board.
  void placeFirstSettelment(int JunctionNumber);         // Place the first settlement for the player.
  void placeFirstRoad(int WayNum);                       // Place the first road for the player.
  void setBoard(Board *b);                               // Set the game board for the player.
  void setNextPlayer(Player *p);                         // Set the next player in turn.
  void setOtherPlayer(Player *p);                        // Add another player to the list of other players.
  DevelopmentCard *getDevCard();                         // Get a development card.
  void trade(Player *p, string give, string get, int amountGive,int amountGet);     // Trade resources with another player.
  void setIsMyTurn(bool b);                              // Set if it is the player's turn.
  int getNumOfSpecificCard(string type);                 // Get the number of a specific type of card.
  void giveCardsAfterPlacing(int Junctionnumber);        // Give cards after placing a settlement.
  void reduceCards(map<string, int> &cards);             // Reduce the player's resource cards.
  void throwCards();                                     // Throw cards when required (e.g., after rolling a seven).
  bool getIsMyTurn();                                    // Check if it is the player's turn.

};
} 
#endif
