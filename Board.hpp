// Mail: Roniharpaz1@gmail.com
#include <map>
#include <vector>
#include "Land.hpp"
#include "DevelopmentCard.hpp"
using namespace std;

namespace catan
{
    /**
     * class Board
     * The game board consists of several components:
     * 1. About 19 different plots of land consisting of 5 different resources and a single desert. Each land has a unique number from 2 to 12.
     * 2. About 54 junctions sitting on the vertices of the plots of land. A settlement or a town can be established on a junction.
     * 3. About 72 ways passing between the intersections. A road can be set up on a way.
     * 4. A pack of development cards. Players can buy development cards.
     */
    class Board
    {
    private:
        vector<Junction *> _junctions; ///< Vector of pointers to the junctions on the board
        vector<Way *> _ways; ///< Vector of pointers to the ways on the board
        vector<Land *> _lands; ///< Vector of pointers to the lands on the board
        map<DevelopmentCard *, int> _pile_developmentCards; ///< Map of development cards and their quantities

    public:
        Board();
        ~Board();
        Junction *getJunctionAt(int index);//Get the junction at the specified index.
        Way *getWayAt(int index);//Get the way at the specified index.
        Land *getLandAt(int index);//Get the land at the specified index.
        DevelopmentCard *generateRandomDevCard();//Generate a random development card from the pile
    };
}
