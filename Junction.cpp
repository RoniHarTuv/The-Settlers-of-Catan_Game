// Mail: Roniharpaz1@gmail.com
#include "Junction.hpp"
#include "Land.hpp"

namespace catan
{
    // Default constructor for Junction
    Junction::Junction() : _num(0) {}

    // Parameterized constructor for Junction
    // @param num: Junction number
    // @param ways: Vector of Way pointers
    // @param lands: Vector of Land pointers
    Junction::Junction(int num, vector<Way *> ways, vector<Land *> lands) : _num(num), _ways(ways), _lands(lands) {}

    // Destructor for Junction
    Junction::~Junction()
    {
        // Delete the settlement pointer and the town pointers
        if (_settelment != nullptr)
        {
            delete _settelment;
        }
        if (_town != nullptr)
        {
            delete _town;
        }
    };

    // // Delete each way pointer in the vector
    // for (auto way : _ways) {
    //     delete way;
    // }

    // // Delete each land pointer in the vector
    // for (auto land : _lands) {
    //     delete land;
    // }
    // }

    // Get the number of the Junction
    int Junction::getNum()
    {
        return _num;
    }

    // Add a Way to the Junction
    void Junction::addWay(Way *w)
    {
        _ways.push_back(w);
    }

    // Add a Land to the Junction
    void Junction::addLand(Land *l)
    {
        this->_lands.push_back(l);
    }

    // Get the first Land associated with the Junction
    Land *Junction::getLand1()
    {
        return !_lands.empty() ? _lands[0] : nullptr;
    }

    // Get the second Land associated with the Junction
    Land *Junction::getLand2()
    {
        return _lands.size() > 1 ? _lands[1] : nullptr;
    }

    // Get the third Land associated with the Junction
    Land *Junction::getLand3()
    {
        return _lands.size() > 2 ? _lands[2] : nullptr;
    }

    // Get the first Way associated with the Junction
    Way *Junction::getWay1()
    {
        return this->_ways[0];
    }

    // Get the second Way associated with the Junction
    Way *Junction::getWay2()
    {
        return _ways[1] == nullptr ? nullptr : _ways[1];
    }

    // Get the third Way associated with the Junction
    Way *Junction::getWay3()
    {
        return _ways[2] == nullptr ? nullptr : _ways[2];
    }

    // Set a Settlement at the Junction
    void Junction::setSettelment(Settelment *s)
    {
        delete this->_settelment; // Delete existing Settelment
        delete this->_town;       // Delete existing Town
        this->_settelment = s;
        this->_town = nullptr; // Ensure _town is null after assigning Settelment
        this->_is_occupate = true;
    }

    // Set a Town at the Junction
    void Junction::setTown(Town *t)
    {
        delete this->_settelment;
        delete this->_town;
        this->_town = t;
        this->_settelment = nullptr;
        this->_is_occupate = true;
    }

    // Check if the Junction is occupied
    bool Junction::getis_occupate()
    {
        return this->_is_occupate;
    }

    // Set the occupied status of the Junction
    void Junction::setis_occupate(bool b)
    {
        this->_is_occupate = b;
    }

    // Get the Settlement at the Junction
    Settelment *Junction::getSettelment()
    {
        if (this->_settelment != nullptr)
        {
            return this->_settelment;
        }
        return nullptr;
    }

    // Get the Town at the Junction
    Town *Junction::getTown()
    {
        if (this->_town != nullptr)
        {
            return this->_town;
        }
        return nullptr;
    }

    // Print information about the Junction
    void Junction::printJunction()
    {
        cout << "Junction number: " << this->getNum() - 1;
        cout << " , On Lands: " << endl;
        if (this->_lands[2] != nullptr)
        {
            this->_lands[0]->printLand();
            this->_lands[1]->printLand();
            this->_lands[2]->printLand();
        }
        else if (this->_lands[1] != nullptr)
        {
            this->_lands[0]->printLand();
            this->_lands[1]->printLand();
        }
        else
        {
            this->_lands[0]->printLand();
        }
        cout << endl;
    }

    Way::Way(int n, Junction *j1, Junction *j2)
    {
        this->_num = n;
        this->_junctions.push_back(j1);
        this->_junctions.push_back(j2);
        this->is_occupate = false;
    }

    Way::~Way()
    {
        // delete _junctions[0];
        // delete _junctions[1];
        delete _road;
    }

    // Get the first Junction associated with the Way
    Junction *Way::getJunction1()
    {
        return this->_junctions[0];
    }

    // Get the second Junction associated with the Way
    Junction *Way::getJunction2()
    {
        return this->_junctions[1];
    }

    // Set a Road on the Way
    void Way::setRoad(Road *a)
    {
        this->_road = a;
        this->is_occupate = true;
    }

    // Get the Road on the Way
    Road *Way::getRoad()
    {
        return this->_road;
    }

    // Get the number of the Way
    int Way::getNum()
    {
        return this->_num;
    }

    // Print information about the Way
    void Way::printWay()
    {
        cout << "Way number: " << this->getNum() << " is occupied? " << this->getis_occupate() << endl;
    }

    // Check if the Way is occupied
    bool Way::getis_occupate()
    {
        return this->is_occupate;
    }

    // Set the occupied status of the Way
    void Way::setis_occupate(bool b)
    {
        this->is_occupate = b;
    }
}
