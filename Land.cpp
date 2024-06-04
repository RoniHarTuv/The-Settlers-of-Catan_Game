//Mail: Roniharpaz1@gmail.com
#include "Land.hpp"
using namespace std;
using namespace catan;

Land::Land(string r, int num, vector<Town> towns, vector<Road> roads, vector<Settelment> settelments)
    : _resource(r), _num(num), _card(nullptr)
{
    // Free previous card memory if exists
    delete this->_card;
    if (r == "forest") {
        this->_card = new TreeCard();
    } else if (r == "sheeps") {
        this->_card = new WoolCard();
    } else if (r == "hills") {
        this->_card = new BrickCard();
    } else if (r == "mountains") {
        this->_card = new IronCard();
    } else if (r == "agricultural") {
        this->_card = new OatsCard();
    } else { // desert
        this->_card = nullptr;
    }
}

catan::Land::Land()
{
}

// Destructor to clean up dynamically allocated card
Land::~Land() {
    delete this->_card;
    // for (auto junction : _junctions)
    // {
    //     delete junction;
    // }

}


// Method to get the resource name
string Land::getResourceNameOfLand() {
    return this->_resource;
}

// Method to get a road
Road* Land::getRoadd(size_t index) {
    if (index < this->_roads.size()) {
        return &this->_roads[index];
    }
    return nullptr;
}

// Method to set a road
void Land::setRoads(Road r) {
    this->_roads.push_back(r);
}

// Method to print land information
void Land::printLand() {
    cout << "Land number: " << this->_num << ", Land resource: " << this->_resource << endl;
}

// Method to set junctions
void catan::Land::setJunction(vector<Junction *> junction) {
    this->_junctions = junction;
}

// Method to get junctions
vector<Junction *> catan::Land::getJunc() {
    return this->_junctions;
}

// Method to get land number
int catan::Land::getNum() {
    return this->_num;
}

// Method to get a card, creating it if necessary
Card* catan::Land::getCard() {
    if (this->_card != nullptr) {
        //cout << "the card ot this land is "<< this->_card->getType()<< endl;
        return this->_card; // Return the existing card if it has been created
    }

    string resource = this->getResourceNameOfLand();
    
    if (resource == "forest") {
        this->_card = new TreeCard();
    } else if (resource == "sheeps") {
        this->_card = new WoolCard();
    } else if (resource == "hills") {
        this->_card = new BrickCard();
    } else if (resource == "mountains") {
        this->_card = new IronCard();
    } else if (resource == "agricultural") {
        this->_card = new OatsCard();
    } else { // dessert or any other resource
        this->_card = nullptr;
    }

    return this->_card;
}

// Method to set a card
void catan::Land::setCard(Card* c) {
    this->_card = c;
}

// Method to get land number
int catan::Land::getLandNum() {
    return this->_landNum;
}

// Method to set land number
void catan::Land::setLandNum(int n) {
    this->_landNum = n;
}
