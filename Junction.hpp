// Mail: Roniharpaz1@gmail.com
#ifndef JUNCTION_HPP
#define JUNCTION_HPP
#include "Asset.hpp"
#include <iostream>
#include <vector>
using namespace std;

namespace catan {

class Way;
class Land;
/**
 * @class Junction:
 * This class Represents a junction in the board game
 * **/
class Junction {
private:
  int _num;                           // Number of the junction
  Town *_town;                        // Pointer to a Town
  Settelment *_settelment;            // Pointer to a Settlement
  bool _is_occupate ;                 // Occupied status of the junction
  vector<Way *> _ways = {3, nullptr}; // Vector of Way pointers 
  vector<Land *> _lands = {3, nullptr}; // Vector of Land pointers (initialized

public:
  Junction();            // Default constructor
  Junction(int num, vector<Way *> ways,vector<Land *> lands); // Parameterized constructor
  ~Junction();           // Destructor
  int getNum();          // Get the junction number
  void addWay(Way *w);   // Add a Way to the junction
  void printJunction();  // Print information about the junction
  void addLand(Land *l); // Add a Land to the junction
  Land *getLand1();      // Get the first Land associated with the junction
  Land *getLand2();      // Get the second Land associated with the junction
  Land *getLand3();      // Get the third Land associated with the junction
  Way *getWay1();        // Get the first Way associated with the junction
  Way *getWay2();        // Get the second Way associated with the junction
  Way *getWay3();        // Get the third Way associated with the junction
  void setSettelment(Settelment *s); // Set a Settlement at the junction
  void setTown(Town *t);             // Set a Town at the junction
  bool getis_occupate();             // Check if the junction is occupied
  void setis_occupate(bool b);       // Set the occupied status of the junction
  Settelment *getSettelment();       // Get the Settlement at the junction
  Town *getTown();                   // Get the Town at the junction
};

/**
 * @class Junction:
 * This class Represents a way in the board game
 * **/

class Way {
private:
  int _num;                      // Number of the way
  vector<Junction *> _junctions; // Vector of Junction pointers
  Road *_road ;                  // Pointer to a Road
  bool is_occupate;              // Occupied status of the way

public:
  Way();                                  // Default constructor
  Way(int n, Junction *j1, Junction *j2); // Parameterized constructor
  ~Way();                                 // Destructor

  Junction *getJunction1(); // Get the first Junction associated with the way
  Junction *getJunction2(); // Get the second Junction associated with the way
  void setRoad(Road *a);    // Set a Road on the way
  Road *getRoad();          // Get the Road on the way
  int getNum();             // Get the number of the way
  void printWay();          // Print information about the way
  bool getis_occupate();    // Check if the way is occupied
  void setis_occupate(bool b); // Set the occupied status of the way
};
}

#endif 
