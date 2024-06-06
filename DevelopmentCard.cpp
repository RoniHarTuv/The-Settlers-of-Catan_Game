// Mail: Roniharpaz1@gmail.com
#include "DevelopmentCard.hpp"
#include <string>

using namespace catan;

// Constructor for DevelopmentCard.
DevelopmentCard::DevelopmentCard() {}

// Virtual destructor for DevelopmentCard.
DevelopmentCard::~DevelopmentCard() {}

// Constructor for monopolDCard.
monopolDCard::monopolDCard() {}

// Returns the quantity of monopolDCard.
int monopolDCard::getQuantity() const { return 100; }

// Clones the monopolDCard.
DevelopmentCard *monopolDCard::clone() const { return new monopolDCard(*this); }

// Returns the type of monopolDCard.
string monopolDCard::getType() const { return "monopol card"; }

// Constructor for BonusPointDCard.
BonusPointDCard::BonusPointDCard() {}

// Returns the quantity of BonusPointDCard.
int BonusPointDCard::getQuantity() const { return 4; }

// Clones the BonusPointDCard.
DevelopmentCard *BonusPointDCard::clone() const {
  return new BonusPointDCard(*this);
}

// Returns the type of BonusPointDCard.
string BonusPointDCard::getType() const { return "bonus point card"; }

// Constructor for YearOfPlentyDCard.
YearOfPlentyDCard::YearOfPlentyDCard() {}

// Returns the quantity of YearOfPlentyDCard.
int YearOfPlentyDCard::getQuantity() const { return 100; }

// Clones the YearOfPlentyDCard.
DevelopmentCard *YearOfPlentyDCard::clone() const {
  return new YearOfPlentyDCard(*this);
}

// Returns the type of YearOfPlentyDCard.
string YearOfPlentyDCard::getType() const { return "year of plenty card"; }

// Constructor for RoadDCard.
RoadDCard::RoadDCard() {}

// Returns the quantity of RoadDCard.
int RoadDCard::getQuantity() const { return 100; }

// Clones the RoadDCard.
DevelopmentCard *RoadDCard::clone() const { return new RoadDCard(*this); }

// Returns the type of RoadDCard.
string RoadDCard::getType() const { return "road card"; }

// Constructor for KnightDCard.
KnightDCard::KnightDCard() {}

// Returns the quantity of KnightDCard.
int KnightDCard::getQuantity() const { return 3; }

// Clones the KnightDCard.
DevelopmentCard *KnightDCard::clone() const { return new KnightDCard(*this); }

// Returns the type of KnightDCard.
string KnightDCard::getType() const { return "knight card"; }
