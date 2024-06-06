// Mail: Roniharpaz1@gmail.com
#ifndef PLAYERFORTEST_HPP
#define PLAYERFORTEST_HPP
#include "Player.hpp"

using namespace std;
namespace catan{
    /**
     * @class Player For Test
     * This class was created in order to perform tests on the game,
     *  without harming the "player" class. Added functions that we don't want to give the client access to.
    */
class PlayerForTest: public Player{
    public:
    PlayerForTest(string name) : Player(name) {}
    int rollDiceFixed9();
    int rollDiceFixed6();
    int rollDiceFixed7();
    void printCardAmount();
    int getNumOfCard();
    int getNumOfDevCard();
    void giveResourceCardFree();
    void buyMonopol();
    void buyKnight();
    void buyYearOfPlenty();
    void buybonusPoint();
    void buybuildRoaed();
    
};
}
#endif