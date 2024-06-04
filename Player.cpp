// Mail: Roniharpaz1@gmail.com
#include "Player.hpp"
using namespace std;
using namespace catan;
// Default constructor for Player class
Player::Player() {}
Player::~Player()
{
  for (auto &pair : _developmentCards)
    {
        delete pair.first;
    }
}
// Parameterized constructor for Player class
Player::Player(string name) : _name(name),
                              _cards({{"TreeCard", 0},
                                      {"OatsCard", 0},
                                      {"WoolCard", 0},
                                      {"IronCard", 0},
                                      {"BrickCard", 0}})
{
  // Initialize the development cards with their respective quantities set to 0
  _developmentCards[new monopolDCard()] = 0;
  _developmentCards[new BonusPointDCard()] = 0;
  _developmentCards[new YearOfPlentyDCard()] = 0;
  _developmentCards[new RoadDCard()] = 0;
  _developmentCards[new KnightDCard()] = 0;
}
// return the name of the player
string Player::getName()
{
  return this->_name;
}
// Function to get the number of points of the player
int catan::Player::getNumOfPoints()
{
  return this->_points;
}
// Function to check if it's the player's turn
bool catan::Player::getIsMyTurn()
{
  return this->_isMyTurn;
}
// Function to set whether it's the player's turn
void Player::setIsMyTurn(bool b)
{
  this->_isMyTurn = b;
}
// Function for the player to buy a development card
void catan::Player::BuyDevelopCard()
{
  if (this->getNumOfSpecificCard("OatsCard") < 1 || getNumOfSpecificCard("IronCard") < 1 || getNumOfSpecificCard("WoolCard") < 1)
  {
    __throw_logic_error("Error: cannot buy Development card because don't have the resource");
    return;
  }
  DevelopmentCard *c = this->_board->generateRandomDevCard();
  this->_developmentCards[c]++;
  cout << this->getName() << " Buy a Development Card. The card is: " << c->getType() << endl;
}
// Function for the player to use a development card
void catan::Player::useDevelpCard(DevelopmentCard *d)
{
  if (d == nullptr)
  {
    cout << "Error: No Development card to use"<< endl;
    return;
  }
  if (this->_developmentCards[d] == 0)
  {
    __throw_invalid_argument("Error: cannot implements development card because the player dont have the card.");
    return;
  }
  this->implementDevelopCard(d);
}
// An helper Function to implement the effects of a development card
void catan::Player::implementDevelopCard(DevelopmentCard *d)
{
  //monopol card- i will iterate on _cards, and i will choose the card with the smaller amount. this source card will be 
  //the choose of the player and all the other players will give to this playr this card.
  if (d->getType() == "monopol card")
  {
    if (this->_cards.empty()) {
        // Handle empty map case- throwing an exception or returning a specific value
        throw std::runtime_error("_cards is empty");
    }
    int minValue = numeric_limits<int>::max();
    string s;
    for (const auto& pair : _cards) {//go over all the card in oder to find the less amount.
        if (pair.second < minValue) {
            minValue = pair.second;
            s = pair.first;
        }
    }
    for(Player* p: this->_otherPlayers){//go over the other players
      int amountToGive = p->_cards[s];//find the amount of this card
      p->_cards[s]-=amountToGive;//take this cards from another player
      this->_cards[s]+=amountToGive;//add this card to this player.
    }
    cout << this->getName() << " implements monopol card and got: "<<s<<" from all the players!" << endl;/////////////
    this->_developmentCards[d]--;
    return;
  }
  //this is bonus 1 point to this palyer
  if (d->getType() == "bonus point card")
  {
    this->_points++;
    cout << this->getName() << " Implements bonus point development card and got 1 point!" << endl;
    this->_developmentCards[d]--;
    return;
  }
  if (d->getType() == "year of plenty card")
  {
    int minValue1 = numeric_limits<int>::max();
    int minValue2 = numeric_limits<int>::max();
    string s1="";
    string s2="";

    for (const auto& pair : _cards) {
        if (pair.second < minValue1) {
            minValue2 = minValue1;
            s2 = s1;
            minValue1 = pair.second;
            s1 = pair.first;
        } else if (pair.second < minValue2) {
            minValue2 = pair.second;
            s2 = pair.first;
        }
    }
    _cards[s1]++;
    _cards[s2]++;

    cout << this->getName() << " Implements year of plenty development card and got: "<<s1<< " and "<< s2<<" new cards!" << endl;
    this->_developmentCards[d]--;
  }
  //road card will give to this player 2 tree card and 2 brick card(that is the 2 road resources)
  if (d->getType() == "road card")
  {
    TreeCard* t = new TreeCard();
    BrickCard* b = new BrickCard();
    this->add2Card(t );
    this->add2Card(b);
    cout << this->getName() << " Implements road development card ,and got 4 new resource card for this!" << endl;
    this->_developmentCards[d]--;
    delete t;
    delete b;
    return;
  }
  //only if one player got 3 knight- he got 2 point
  if (d->getType() == " knight card")
  {
    if (this->_developmentCards[d] == 3)
    { // have 3 knight card
      cout << this->getName() << " Implements the 3'rd knight development card and got 2 points!" << endl;
      this->_points += 2;
    }
    else
    {
      cout << this->getName() << " Implements knight development card ! more 1/2 to get 2 points..." << endl;
    }
    return;
  }
}
// Function to add a card to the player's hand
void catan::Player::addCard(Card *c)
{
  for (auto &card : this->_cards) //  get a reference to each pair
  {
    if (card.first == c->getType())
    {
      card.second++;
      cout << "Player: " << this->getName() << " , got 1 card of: " << c->getType() << endl;
      return;
    }
  }
}
// Function to add 2 cards to the player's hand
void catan::Player::add2Card(Card *c)
{
  for (auto &card : this->_cards)
  {
    if (card.first == c->getType())
    {
      card.second += 2;
      cout << "Player: " << this->getName() << " got 2 cards of: " << c->getType() << endl;
      return;
    }
  }
}
// Function to print the player's development cards
void catan::Player::printDevelopCard()
{
  cout <<"Player " << this->getName() << ". Development Cards: " ;

  for (const auto &pair : _developmentCards)
  {
    DevelopmentCard *card = pair.first;
    int quantity = pair.second;
    if (quantity != 0)
    {
      cout << card->getType() << ", Amount: " << quantity << endl;
    }
  }
}
// Function for the player to place their first settlement
void Player::placeFirstSettelment(int JunctionNumber)
{
  if (this->_board->getJunctionAt(JunctionNumber)->getis_occupate() == false)
  {
    cout << this->getName() << " Placed First Settelment at junction number: " << this->_board->getJunctionAt(JunctionNumber)->getNum() << endl;
    this->_board->getJunctionAt(JunctionNumber)->setis_occupate(true);
    Settelment *s = new Settelment(this);
    this->_board->getJunctionAt(JunctionNumber)->setSettelment(s); // set the settelment to player
     //$$$$$$$$
    cout << "add settelment to land number : " << this->_board->getJunctionAt(JunctionNumber)->getLand1()->getNum() << endl;
    if (this->_board->getJunctionAt(JunctionNumber)->getLand2() != nullptr)
    {
      cout << "add settelment to land number: " << this->_board->getJunctionAt(JunctionNumber)->getLand2()->getNum() << endl;
    }
    if (this->_board->getJunctionAt(JunctionNumber)->getLand3() != nullptr)
    {
      cout << "add settelment to land number: " << this->_board->getJunctionAt(JunctionNumber)->getLand3()->getNum() << endl;
    }
    this->giveCardsAfterPlacing(JunctionNumber);
    this->_points++;
   //// delete s;
  }
  else
  {
    __throw_logic_error("Error: this Junction is already occupate");
  }
}
// Function for the player to place their first road
void catan::Player::placeFirstRoad(int wayNumber)
{
  if (this->_board->getWayAt(wayNumber)->getis_occupate() == false)
  {
    this->_board->getWayAt(wayNumber)->setis_occupate(true);
    Road *r = new Road(this);
    this->_board->getWayAt(wayNumber)->setRoad(r);
    cout << this->getName() << " Place Road at way number: " << this->_board->getWayAt(wayNumber)->getNum() << endl;
    //delete r;
  }
  else
  {
    __throw_logic_error("Error: this Way is already occupate");
  }
}
// Function to set the game board for the player
void Player::setBoard(Board *b)
{
  this->_board = b;
}
// Function to set the next player in the game sequence
void catan::Player::setNextPlayer(Player *p)
{
  this->_nextPlayer = p;
}
// Function to set another player in the game
void catan::Player::setOtherPlayer(Player *p)
{
  if (p != nullptr)
  {
    this->_otherPlayers.push_back(p);
  }
}
// Function to print the player's cards
void catan::Player::printCard()
{
  cout << "Player: " << this->getName();
  for (const auto &card : this->_cards)
  {
    if (card.second != 0)
    {
      cout << ". Cards: " << card.first << " Amount: " << card.second;
    }
  }
  cout << "" << endl;
}
// Function for the player to roll the dice
int Player::rollDice()
{
  if (this->getIsMyTurn())
  {
    // Initialize random number generator
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dis(1, 6);

    // Roll two dice
    int dice1 = dis(gen);
    int dice2 = dis(gen);
    int ans = (dice1 + dice2);
    cout << this->getName() << " Roll the dice. the result: " << ans << endl;

    if (ans == 7)
    {
      cout << "Players with more than 7 card need to get rid of half of the cards." << endl;
      throwCards(); // each player with more than 7 cards will randomly throw half of his cards.
    }
    for (int i = 0; i < 19; i++)
    {
      if (this->_board->getLandAt(i)->getLandNum() == ans)
      {
        for (int j = 0; j < 6; j++)
        {
          if (this->_board->getLandAt(i)->getJunc()[j] != nullptr)
          {
            if (this->_board->getLandAt(i)->getJunc()[j]->getis_occupate() == true)
            {
              if (this->_board->getLandAt(i)->getJunc()[j]->getSettelment() != nullptr)
              {
                if (this->_board->getLandAt(i)->getJunc()[j]->getSettelment()->getPlayer()->getName() == this->getName())
                {
                  this->addCard(this->_board->getLandAt(i)->getCard());
                }
                if (this->_board->getLandAt(i)->getJunc()[j]->getSettelment()->getPlayer()->getName() == this->_otherPlayers[0]->getName())
                {
                  this->_otherPlayers[0]->addCard(this->_board->getLandAt(i)->getCard());
                }
                if (this->_board->getLandAt(i)->getJunc()[j]->getSettelment()->getPlayer() == this->_otherPlayers[1])
                {
                  this->_otherPlayers[1]->addCard(this->_board->getLandAt(i)->getCard());
                }
              }
              if (this->_board->getLandAt(i)->getJunc()[j]->getTown() != nullptr)
              {
                if (this->_board->getLandAt(i)->getJunc()[j]->getTown()->getPlayer() == this)
                {
                  this->add2Card(this->_board->getLandAt(i)->getCard());
                }
                if (this->_board->getLandAt(i)->getJunc()[j]->getTown()->getPlayer() == this->_otherPlayers[0])
                {
                  this->_otherPlayers[0]->add2Card(this->_board->getLandAt(i)->getCard());
                }
                if (this->_board->getLandAt(i)->getJunc()[j]->getTown()->getPlayer() == this->_otherPlayers[1])
                {
                  this->_otherPlayers[1]->add2Card(this->_board->getLandAt(i)->getCard());
                }
              }
            }
          }
        }
      }
    }
    this->_isMyTurn = false;
    this->_nextPlayer->setIsMyTurn(true);
  }
  else
  {
    throw logic_error("Error: Not your turn");
    return 0;
  }
  return 0;
}
// Function for the player to place a road
void catan::Player::placeRoad(int wayNumber)
{
  // if this Way isnt occupate- i cannot sat a road.
  if (this->_board->getWayAt(wayNumber)->getis_occupate())
  {
    __throw_logic_error("Error: This Way is Already occupate");
  }
  else // if the way is clear:make sure you have the card source for road
  {
    if (this->getNumOfSpecificCard("TreeCard") < 1 || getNumOfSpecificCard("BrickCard") < 1)
    {
      __throw_logic_error("Error: cannot place Road because dont have the resource");
      return;
    }
    this->_cards["TreeCard"]--;
    this->_cards["BrickCard"]--;
    Junction *j1 = this->_board->getWayAt(wayNumber)->getJunction1();
    Junction *j2 = this->_board->getWayAt(wayNumber)->getJunction2();
    // if j1 is my junction- i can set a road on this way.
    if (j2->getis_occupate())
    {

      if (j2->getSettelment()->getPlayer()->getName() == this->getName() || j2->getTown()->getPlayer()->getName() == this->getName())
      {
        _board->getWayAt(wayNumber)->setis_occupate(true);
        Road *r = new Road(this);
        _board->getWayAt(wayNumber)->setRoad(r);
        cout << this->getName() << " Place Road at way number: " << this->_board->getWayAt(wayNumber)->getNum() << endl;
        //delete r;
        return;
      }
    }
    // if j1 is my junction- i can set a road on this way.
    else if (j1->getis_occupate())
    {
      if (j1->getSettelment()->getPlayer()->getName() == this->getName() || j1->getTown()->getPlayer()->getName() == this->getName())
      {
        _board->getWayAt(wayNumber)->setis_occupate(true);
        Road *r = new Road(this);
        _board->getWayAt(wayNumber)->setRoad(r);
        cout << this->getName() << " Place Road at way number: " << this->_board->getWayAt(wayNumber)->getNum() << endl;
        //delete r;
        return;
      }
    }
    // check all the neighbrood ways and roads;if they belong to me- i can set a road on this way.
    else if (j1->getWay1() != nullptr)
    {
      if (j1->getWay1()->getis_occupate())
      {
        if (j1->getWay1()->getRoad()->getPlayer() == this)
        {
          Road *r = new Road(this);
          _board->getWayAt(wayNumber)->setRoad(r);
          cout << this->getName() << " Place Road at way number: " << this->_board->getWayAt(wayNumber)->getNum() << endl;
          //delete r;
          return;
        }
      }
    }
    else if (j1->getWay2() != nullptr)
    {
      if (j1->getWay2()->getis_occupate())
      {
        if (j1->getWay2()->getRoad()->getPlayer() == this)
        {
          Road *r = new Road(this);
          _board->getWayAt(wayNumber)->setRoad(r);
          cout << this->getName() << " Place Road at way number: " << this->_board->getWayAt(wayNumber)->getNum() << endl;
          //delete r;
          return;
        }
      }
    }
    else if (j1->getWay3() != nullptr)
    {
      if (j1->getWay3()->getis_occupate())
      {
        if (j1->getWay3()->getRoad()->getPlayer() == this)
        {
          Road *r = new Road(this);
          _board->getWayAt(wayNumber)->setRoad(r);
          cout << this->getName() << " Place Road at way number: " << this->_board->getWayAt(wayNumber)->getNum() << endl;
          return;
        }
      }
    }
    else if (j2->getWay1() != nullptr)
    {
      if (j2->getWay1()->getis_occupate())
      {
        if (j2->getWay1()->getRoad()->getPlayer() == this)
        {
          Road *r = new Road(this);
          _board->getWayAt(wayNumber)->setRoad(r);
          cout << this->getName() << " Place Road at way number: " << this->_board->getWayAt(wayNumber)->getNum() << endl;
          return;
        }
      }
    }
    else if (j2->getWay2() != nullptr)
    {
      if (j2->getWay2()->getis_occupate())
      {
        if (j2->getWay2()->getRoad()->getPlayer() == this)
        {
          Road *r = new Road(this);
          _board->getWayAt(wayNumber)->setRoad(r);
          cout << this->getName() << " Place Road at way number: " << this->_board->getWayAt(wayNumber)->getNum() << endl;
          return;
        }
      }
    }
    else if (j2->getWay3() != nullptr)
    {
      if (j2->getWay3()->getis_occupate())
      {
        if (j2->getWay3()->getRoad()->getPlayer() == this)
        {
          Road *r = new Road(this);
          _board->getWayAt(wayNumber)->setRoad(r);
          cout << this->getName() << " Place Road at way number: " << this->_board->getWayAt(wayNumber)->getNum() << endl;
          return;
        }
      }
    }
    else
    {
      __throw_logic_error("Error: canot replace road  in this way");
    }
  }
}
// Function for the player to place a settlement
void catan::Player::placeSettelment(int juncNumber)
{
  // Check if the junction is already occupied
  if (this->_board->getJunctionAt(juncNumber)->getis_occupate())
  {
    __throw_invalid_argument("Error: this Junction is already occupied");
  }

  // Check if the player has the required resources
  if ((this->getNumOfSpecificCard("TreeCard") < 1) ||
      (this->getNumOfSpecificCard("BrickCard") < 1) ||
      (this->getNumOfSpecificCard("OatsCard") < 1) ||
      (this->getNumOfSpecificCard("WoolCard") < 1))
  {
    __throw_logic_error("Error: cannot place Settlement because don't have the resource cards");
  }
  // Deduct the resources
  this->_cards["TreeCard"]--;
  this->_cards["BrickCard"]--;
  this->_cards["OatsCard"]--;
  this->_cards["WoolCard"]--;
  // Get the junction object
  Junction *j = this->_board->getJunctionAt(juncNumber);
  // check if there is a way that belong to this player next to this junction:(2/3 options to ways from junction)
  if (j->getWay1() != nullptr && j->getWay1()->getis_occupate())
  { // check if the road belong to this player:
    if (j->getWay1()->getRoad()->getPlayer() == this)
    { // if at the end of the road there is no junction with settelment\town- the plyer can place settelment.
      if ((j->getWay1()->getJunction2() != j && j->getWay1()->getJunction2()->getis_occupate() == false) ||
          (j->getWay1()->getJunction1() != j && j->getWay1()->getJunction1()->getis_occupate() == false))
      {
        j->setSettelment(new Settelment(this));
        cout << this->getName() << " Placed Settelment at junction number: " << this->_board->getJunctionAt(juncNumber)->getNum() << endl;
        this->_points++;
        return;
      }
    }
  }
  if (j->getWay2() != nullptr && j->getWay2()->getis_occupate())
  {
    if (j->getWay2()->getRoad()->getPlayer() == this)
    {
      if ((j->getWay2()->getJunction2() != j && j->getWay2()->getJunction2()->getis_occupate() == false) ||
          (j->getWay2()->getJunction1() != j && j->getWay2()->getJunction1()->getis_occupate() == false))
      {
        j->setSettelment(new Settelment(this));
        cout << this->getName() << " Placed Settelment at junction number: " << this->_board->getJunctionAt(juncNumber)->getNum() << endl;
        this->_points++;
        return;
      }
    }
  }
  if (j->getWay3() != nullptr && j->getWay3()->getis_occupate())
  {
    if (j->getWay3()->getRoad()->getPlayer() == this)
    {
      if ((j->getWay3()->getJunction2() != j && j->getWay3()->getJunction2()->getis_occupate() == false) ||
          (j->getWay3()->getJunction1() != j && j->getWay3()->getJunction1()->getis_occupate() == false))
      {
        j->setSettelment(new Settelment(this));
        cout << this->getName() << " Placed Settelment at junction number: " << this->_board->getJunctionAt(juncNumber)->getNum() << endl;
        this->_points++;
        return;
      }
    }
  }
  else
  { // there is no way that next to this junction- cannot place here settelment
    __throw_logic_error("Error: cannot place Settlement because don't have a road to this junction");
  }
}
// Function for the player to place a town
void catan::Player::placeTown(int JunctionNumber)
{
  // if this junction has a town on it already / this junction dont have a settelment on it- cannot replace town:
  if (this->_board->getJunctionAt(JunctionNumber)->getTown() != nullptr )
  {
    __throw_invalid_argument("Error: this town already occupate");
    return;
  }
  if ( this->_board->getJunctionAt(JunctionNumber)->getSettelment() == nullptr)
  {
    __throw_invalid_argument("Error:there is not settelment on this junction");
    return;
  }

  if (this->_board->getJunctionAt(JunctionNumber)->getSettelment()->getPlayer() == this)
  {
    if (
        this->getNumOfSpecificCard("OatsCard") < 2 ||
        this->getNumOfSpecificCard("IronCard") < 3)
    {
      __throw_logic_error("Error: cannot place Town because don't have the resource");
      return;
    }
    // Deduct the resources
    this->_cards["IronCard"] -= 3;
    this->_cards["OatsCard"] -= 2;
    Town *t = new Town(this);
    this->_board->getJunctionAt(JunctionNumber)->setTown(t);
    this->_points++;
    cout << this->getName() << " Placed Town at junction number: " << this->_board->getJunctionAt(JunctionNumber)->getNum() << endl;
   }
  else
  {
    __throw_logic_error("Error: this Junction already had a settelment of another player");
  }
}
// Function for the player to discard cards when the dice is rolled and a 7 is thrown,chosen randomly
void Player::throwCards()
{
  // Reduce cards for the player if needed
  if (this->_cards.size() > 7)
  {
    reduceCards(this->_cards);
    cout << this->_name << "get rid of cards" << endl;
  }

  // Reduce cards for the other players if needed
  for (auto *player : this->_otherPlayers)
  {
    if (player->_cards.size() > 7)
    {
      cout << player->_name << "get rid of cards" << endl;
      reduceCards(player->_cards);
    }
  }
}
// Function to reduce cards for the player if needed
void Player::reduceCards(map<string, int> &cards)
{
    int totalCards = 0;
    for (const auto &card : cards)
    {
        totalCards += card.second;
    }

    // If the total number of cards is greater than 7
    if (totalCards > 7)
    {
        // Calculate the number of cards to remove
        int targetTotal = totalCards / 2;
        vector<string> cardTypes;
        for (const auto &card : cards)
        {
            if (card.second > 0)
            {
                cardTypes.push_back(card.first);
            }
        }
        
        // Randomly discard cards until the target total is reached
        random_device rd;
        mt19937 gen(rd());
        uniform_int_distribution<> dis(0, cardTypes.size() - 1);
        
        while (totalCards > targetTotal)
        {
            int index = dis(gen);
            string cardType = cardTypes[index];
            if (cards[cardType] > 0)
            {
                cards[cardType]--;
                totalCards--;
                if (cards[cardType] == 0)
                {
                    cardTypes.erase(cardTypes.begin() + index);
                    if (cardTypes.empty())
                    {
                        break;
                    }
                }
            }
        }
    }
}

// Function for the player to give cards after placing the first settlement
void Player::giveCardsAfterPlacing(int Junctionnumber)
{
  Land *land1 = this->_board->getJunctionAt(Junctionnumber)->getLand1();
  if (land1)
  {
    Card *card1 = land1->getCard();
    if (card1)
    {
      Card *newCard1 = new Card(*card1);
      this->addCard(newCard1);
      delete newCard1; // $$$$$$
    }
    else
    {
      cerr << "Error: card1 is null" << endl;
    }
  }

  Land *land2 = this->_board->getJunctionAt(Junctionnumber)->getLand2();
  if (land2)
  {
    Card *card2 = land2->getCard();
    if (card2)
    {
      Card *newCard2 = new Card(*card2);
      this->addCard(newCard2);
      delete newCard2;// $$$$$$
    }
    else
    {
      cerr << "Error: card2 is null" << endl;
    }
  }
  Land *land3 = this->_board->getJunctionAt(Junctionnumber)->getLand3();
  if (land3)
  {
    Card *card3 = land3->getCard();
    if (card3)
    {
      Card *newCard3 = new Card(*card3);
      this->addCard(newCard3);
      delete newCard3;// $$$$$$
    }
    else
    {
      cerr << "Error: card3 is null" << endl;
    }
  }
  

}
// Function to get the number of a specific card in the player's hand
int catan::Player::getNumOfSpecificCard(string type)
{
  return this->_cards[type];
}
// Function for the player to trade resources with another player
void catan::Player::trade(Player *p, string give, string get, int amountGive, int amountGet)
{
  if(p==this){
    __throw_invalid_argument("Error: cannot trade with myself...");
  }
  if (this->getNumOfSpecificCard(give) >= amountGive && p->getNumOfSpecificCard(get) >= amountGet)
  {
    this->_cards[give] -= amountGive;
    this->_cards[get] += amountGet;
    p->_cards[get] -= amountGet;
    p->_cards[give] += amountGive;
    cout << this->getName() << " Trades: give " << amountGive << " " << give << " To " << p->getName() << ", and get " << amountGet << " " << get << endl;
  }
  else
  {
    __throw_invalid_argument("Error: this trade couldn't be completed");
  }
}

DevelopmentCard *catan::Player::getDevCard()
{
  // Iterate through the development cards map
  for (auto &pair : _developmentCards)
  {
    // If the quantity of the card at position i is greater than 0, return that card
    if (pair.second > 0)
    {
      return pair.first;
    }
  }
  // If no card with quantity > 0 is found, return nullptr or handle the case accordingly
  return nullptr;
}