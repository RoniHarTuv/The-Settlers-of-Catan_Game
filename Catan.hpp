// Mail: Roniharpaz1@gmail.com
#include "Player.hpp"

namespace catan
{
    /**
     * @class Catan
     * This class represents the game operator and contains the game components - players, and the game board.
     */
    class Catan
    {
    private:
        vector<Player *> _players; ///< Vector of pointers to the players in the game
        Board* _board;              ///< The game board
        // Player _turn;              ///< The player whose turn it is

    public:
        Catan();//Default constructor for Catan.
        ~Catan();//Destructor for Catan.
        void setPlayers(Player *p1, Player *p2, Player *p3);
        Board* getBoard();//Get the game board.
        void StartTheGame();//Start the game.
        void printWinner();//Print the winner of the game.
    };
}
