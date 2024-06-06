// Mail: Roniharpaz1@gmail.com
#include "Card.hpp"

using namespace catan;

// Default constructor sets a default type
Card::Card() : _type("Unknown") {}

// Copy constructor
Card::Card(const Card &c) : _type(c._type) {}

// Virtual destructor
Card::~Card() {}

// Virtual function with a default implementation to get the type of the card
string Card::getType() const { return this->_type; }

// TreeCard constructor sets the type to "TreeCard"
TreeCard::TreeCard() { this->_type = "TreeCard"; }//emojicpp::emojize(":smile:",true)

// Override getType method for TreeCard
string TreeCard::getType() const { return this->_type; }

// OatsCard constructor sets the type to "OatsCard"
OatsCard::OatsCard() { this->_type = "OatsCard"; }

// Override getType method for OatsCard
string OatsCard::getType() const { return this->_type; }

// WoolCard constructor sets the type to "WoolCard"
WoolCard::WoolCard() { this->_type = "WoolCard"; }

// Override getType method for WoolCard
string WoolCard::getType() const { return this->_type; }

// IronCard constructor sets the type to "IronCard"
IronCard::IronCard() { this->_type = "IronCard"; }

// Override getType method for IronCard
string IronCard::getType() const { return this->_type; }

// BrickCard constructor sets the type to "BrickCard"
BrickCard::BrickCard() { this->_type = "BrickCard"; }

// Override getType method for BrickCard
string BrickCard::getType() const { return this->_type; }
