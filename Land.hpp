// Mail: Roniharpaz1@gmail.com
#include "Card.hpp"
#include "Junction.hpp"
#include <vector>
using namespace std;

namespace catan {

/**
 * @class Land
 *This class represents a plot of land in the game.
 * Each land has a resource type, a unique number, and a land number from 2
 *to 12. It can also hold roads, junctions, and a card representing a resource.
 */
class Land {
private:
  string _resource;     ///< The type of resource the land produces//$$$
  int _num;             ///< Unique identifier for the land (e.g., l1, l2, ..., l19)
  int _landNum;         ///< Number associated with the land (e.g., 2, 3, ..., 12)
  vector<Road> _roads;  ///< Roads associated with the land
  Card *_card;          ///< Pointer to a Card representing the resource
  vector<Junction *> _junctions = {3, nullptr}; ///< Junctions located on the vertices of the land
      
public:
  Land(string resource, int num, vector<Town> towns, vector<Road> roads,vector<Settelment> settelments); // Constructor for Land.
  Land();                               // Default constructor for Land.
  ~Land();                              // Destructor for Land.
  string getResourceNameOfLand();       // Get the name of the resource produced by the land.
  Road *getRoadd(size_t index);        // Get a pointer to a road at the specified index.
  void setRoads(Road r);               // Set the roads associated with the land.
  void printLand();                    // Print information about the land.
  void setJunction(vector<Junction *>junction); // Set the junctions associated with the land.
  vector<Junction *> getJunc();        // Get the junctions associated with the land
  int getNum();                        // Get the unique identifier of the land.
  Card *getCard();                     // Get the card representing the resource on the land.
  void setCard(Card *c);               // Set the card representing the resource on the land.
  int getLandNum();                    // Get the number associated with the land.
  void setLandNum(int n);              // Set the number associated with the land.
};
} 
