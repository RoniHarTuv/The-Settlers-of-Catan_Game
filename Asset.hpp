// Mail: Roniharpaz1@gmail.com
#ifndef ASSET_HPP
#define ASSET_HPP
#include <string>
#include <vector>
using namespace std;

namespace catan {
class Player;

/**
 * class Asset:
 * This class stands for "game tool". From this class, three classes inherit:
 * Road, Settelment, and Town. This class is virtual, meaning that no object is
 * created from it, but only from the classes that inherit from it. Each class
 * has a "Player" field that refers to the owner of that object.
 */
class Asset {
public:
  Player *_player; ///< Pointer to the player who owns the asset //$$$null
  string _type;    ///< Type of the asset $$$
  virtual string getType() = 0;    // Pure virtual function to get the type of the asset.
  Asset();          // Constructor for Asset.
  virtual ~Asset(); // Virtual destructor for Asset.
};

/**
 * @class Road
 */
class Road : public Asset {
public:
  Road();              // Default constructor for Road.
  ~Road();             // Destructor for Road.
  Road(Player *p);     // Constructor for Road that sets the owner player.
  Player *getPlayer(); // Get the player who owns the road.
  string getType();    // Get the type of the asset.
};

/**
 * @class Town
 */
class Town : public Asset {
public:
  Town(Player *p);     // Constructor for Town that sets the owner player.
  Town();              // Default constructor for Town.
  ~Town();             // Destructor for Town.
  string getType();    // Get the type of the asset.
  Player *getPlayer(); // Get the player who owns the town.
};

/**
 * @class Settelment
 */
class Settelment : public Asset {
public:
  Settelment(
      Player *p);      // Constructor for Settelment that sets the owner player.
  Settelment();        // Default constructor for Settelment.
  ~Settelment();       // Destructor for Settelment.
  string getType();    // Get the type of the asset.
  Player *getPlayer(); // Get the player who owns the settlement.
};
} 

#endif 
