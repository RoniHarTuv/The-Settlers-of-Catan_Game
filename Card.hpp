// Mail: Roniharpaz1@gmail.com
#ifndef CARD_HPP
#define CARD_HPP
#include <iostream>
#include <string>
using namespace std;

namespace catan {
/**
 * This class represents the "resource card" object.
 * This class is virtual and an object (only "card") cannot be created from it.
 * 5 classes of different resource cards are inherited from this class:
 * tree, iron, oats, wool, and bricks.
 * Each resource is associated with a plot of land:
 * tree is associated with the forest, wool is associated with sheep pasture,
 * oats are associated with the field, iron is associated with mountains,
 * bricks are associated with hills.
 * When dice are thrown, and a random number between 2 and 12 comes out,
 * every player who has a settlement or town on a piece of land with this number
 * receives the corresponding resource card.
 * With these cards, players can buy settlement, road, town, or development
 * cards. When the dice show the number 7, each player with more than 7 cards
 * will need to throw away half of their cards.
 */
class Card {
protected:
  string _type; // Protected so derived classes can access it

public:
  // Default constructor
  Card();

  // Copy constructor
  Card(const Card &c);

  // Virtual destructor
  virtual ~Card();

  // Virtual function to get the type of the card
  virtual string getType() const;
};
/**
 * @class TreeCard
 */
class TreeCard : public Card {
public:
  // Constructor
  TreeCard();
  // Override getType method
  string getType() const override;
};
/**
 * @class OatsCard
 */
class OatsCard : public Card {
public:
  // Constructor
  OatsCard();
  // Override getType method
  string getType() const override;
};
/**
 * @class WoolCard
 */
class WoolCard : public Card {
public:
  // Constructor
  WoolCard();
  // Override getType method
  string getType() const override;
};
/**
 * @class IronCard
 */
class IronCard : public Card {
public:
  // Constructor
  IronCard();
  // Override getType method
  string getType() const override;
};
/**
 * @class BrickCard
 */
class BrickCard : public Card {
public:
  // Constructor
  BrickCard();
  // Override getType method
  string getType() const override;
};
} 
#endif
