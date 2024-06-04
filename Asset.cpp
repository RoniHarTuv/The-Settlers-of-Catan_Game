#include "Asset.hpp"
#include <stdexcept> // For throwing exceptions

using namespace catan;

// Constructor for Asset.
Asset::Asset(): _player(nullptr){}

// Virtual destructor for Asset.
Asset::~Asset() {}

// Default constructor for Road.
Road::Road() {}

// Destructor for Road.
Road::~Road() {}

// Constructor for Road that sets the owner player.
Road::Road(Player *p)
{
    this->_player = p;
}

// Get the player who owns the road.
Player *Road::getPlayer()
{
    return this->_player;
}

// Get the type of the asset.
string Road::getType()
{
    return "Road";
}

// Constructor for Town that sets the owner player.
Town::Town(Player *p)
{
    this->_player = p;
}

// Default constructor for Town.
Town::Town() {}

// Destructor for Town.
Town::~Town() {}

// Get the type of the asset.
string Town::getType()
{
    return "Town";
}

// Get the player who owns the town.
Player *Town::getPlayer()
{
    return this->_player;
}

// Constructor for Settelment that sets the owner player.
Settelment::Settelment(Player *p)
{
    this->_player = p;
}

// Default constructor for Settelment.
Settelment::Settelment() {}

// Destructor for Settelment.
Settelment::~Settelment()
{
    // if (this->_player != nullptr)
    // {
    //     delete this->_player;
    // }
}

// Get the type of the asset.
string Settelment::getType()
{
    return "Settelment";
}

// Get the player who owns the settlement.
Player *Settelment::getPlayer()
{
    if (this->_player != nullptr)
    {
        return this->_player;
    }
    throw logic_error("Error: tried to go to settelment without owner");
}
