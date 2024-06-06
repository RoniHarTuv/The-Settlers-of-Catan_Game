// Mail: Roniharpaz1@gmail.com
#include "doctest.h"
#include "Catan.hpp"
#include "PlayerForTest.hpp"
#include <iostream>

using namespace catan;
/**
 * @class Test:
 *  tests all the functions in this game, using "player for test class" that was created specially for this.
 */

TEST_CASE("Test set players in Catan")
{
    Player *p1 = new Player("Amit");
    Player *p2 = new Player("Yossi");
    Player *p3 = new Player("Dana");
    Catan *catan = new Catan();
    catan->setPlayers(p1, p2, p3);
    CHECK(catan->getPlayers()[0] == p1);
    CHECK(catan->getPlayers()[1] == p2);
    CHECK(catan->getPlayers()[2] == p3);
    delete p1;
    delete p2;
    delete p3;
    delete catan;
};
TEST_CASE("Test place first settelment function")
{
    Player *p1 = new Player("Amit");
    Board *board = new Board;
    p1->setBoard(board);
    CHECK(!board->getJunctionAt(10)->getis_occupate()); // before placing no occupat
    CHECK(p1->getNumOfPoints() == 0);                   // before placing 0 points
    p1->placeFirstSettelment(10);
    CHECK(board->getJunctionAt(10)->getis_occupate()); // after placing is occupate
    CHECK(p1->getNumOfPoints() == 1);                  // after placing 1 points
    CHECK_THROWS(p1->placeFirstSettelment(10));        // check if the player tried to place in the same place again
    delete p1;
    delete board;
};
TEST_CASE("Test place first Road function")
{
    Player *p1 = new Player("Amit");
    Board *board = new Board;
    p1->setBoard(board);
    CHECK(!board->getWayAt(10)->getis_occupate()); // before placing
    CHECK(p1->getNumOfPoints() == 0);              // before placing 0 points
    p1->placeFirstRoad(10);
    CHECK(board->getWayAt(10)->getis_occupate()); // after placing
    CHECK(p1->getNumOfPoints() == 0);             // after placing, same score
    CHECK_THROWS(p1->placeFirstRoad(10));         // check if the player tried to place in the same place again
    delete p1;
    delete board;
};
TEST_CASE("Test Roll Dice function")
{
    // settings:
    PlayerForTest *p1 = new PlayerForTest("Amit");
    PlayerForTest *p2 = new PlayerForTest("Roni");
    PlayerForTest *p3 = new PlayerForTest("Omer");
    Catan *catan = new Catan();
    catan->setPlayers(p1, p2, p3);
    Board *board = new Board;
    p1->setBoard(board);
    p2->setBoard(board);
    p3->setBoard(board);
    catan->StartTheGame();

    SUBCASE("Test the result is 2--12")
    {
        CHECK(2 <= p1->rollDice());   // p1 roll
        CHECK_THROWS(p1->rollDice()); // p1 tries to roll dice but is not his turn
        CHECK(p2->rollDice() <= 12);  // p2 roll
    }

    SUBCASE("Test got resources according to result")
    {
        CHECK(p3->getNumOfCard() == 0); // before throw, and without asset on the board
        p3->setIsMyTurn(true);
        p3->rollDice();
        CHECK(p3->getNumOfCard() == 0); // still without asset
        p3->placeFirstSettelment(10);   // junction 10 is on lands: sheeps(12),hills(5),mountains(6)
        p2->placeFirstSettelment(31);   // junction 33 is on lands: sheeps(9+10),hills(5),agricultural(11)
        p1->placeFirstSettelment(44);   // junction 44 is on lands: sheeps(9),forest(6),mountains(3)
        CHECK(p3->getNumOfPoints() == 1);
        CHECK(p3->getNumOfCard() == 3); // before roll the dice
        CHECK(p2->getNumOfCard() == 3); // before roll the dice
        CHECK(p1->getNumOfCard() == 3); // before roll the dice
        p1->rollDiceFixed6();
        p2->rollDiceFixed9();
        CHECK(p3->getNumOfCard() == 4); // after roll the dice
        CHECK(p2->getNumOfCard() == 4); // after roll the dice
        CHECK(p1->getNumOfCard() == 5); // after roll the dice
    }
    SUBCASE("Test result 7")
    {
        p3->giveResourceCardFree(); // give playrs 50 resource in order to check
        p2->giveResourceCardFree();
        p1->giveResourceCardFree();
        CHECK(p3->getNumOfCard() == 50); // before roll the dice
        CHECK(p2->getNumOfCard() == 50); // before roll the dice
        CHECK(p1->getNumOfCard() == 50); // before roll the dice
        p1->rollDiceFixed7();            // roll the dice for 7- each player have to get rid of 25 cards
        CHECK(p3->getNumOfCard() == 25); // after roll the dice
        CHECK(p2->getNumOfCard() == 25); // after roll the dice
        CHECK(p1->getNumOfCard() == 25); // after roll the dice
    }

    delete p1;
    delete p2;
    delete p3;
    delete board;
    delete catan;
};
TEST_CASE("Test place road")
{
    // settings:
    PlayerForTest *p1 = new PlayerForTest("Amit");
    PlayerForTest *p2 = new PlayerForTest("Roni");
    PlayerForTest *p3 = new PlayerForTest("Omer");
    Catan *catan = new Catan();
    catan->setPlayers(p1, p2, p3);
    Board *board = new Board;
    p1->setBoard(board);
    p2->setBoard(board);
    p3->setBoard(board);
    catan->StartTheGame();
    p3->placeFirstSettelment(10); // junction 10 is on lands: sheeps(12),hills(5),mountains(6)
    p2->placeFirstSettelment(31); // junction 33 is on lands: sheeps(9+10),hills(5),agricultural(11)
    p1->placeFirstSettelment(44); // junction 44 is on lands: sheeps(9),forest(6),mountains(3)

    SUBCASE("Test place road without resource cards")
    {
        CHECK_THROWS(p1->placeRoad(11));
    }
    SUBCASE("Test place road in occupate way-")
    {
        p1->giveResourceCardFree();
        p2->placeFirstRoad(57);
        CHECK_THROWS(p1->placeRoad(57));
    }
    SUBCASE("Test place road in NOT occupate way,lleagel way")
    {
        p1->giveResourceCardFree();
        CHECK_NOTHROW(p1->placeRoad(57));
        CHECK_NOTHROW(p1->placeRoad(56)); // next to 57 way
    }
    delete p1;
    delete p2;
    delete p3;
    delete board;
    delete catan;
};
TEST_CASE("Test place settelment and town")
{
    // settings:
    PlayerForTest *p1 = new PlayerForTest("Amit");
    PlayerForTest *p2 = new PlayerForTest("Roni");
    PlayerForTest *p3 = new PlayerForTest("Omer");
    Catan *catan = new Catan();
    catan->setPlayers(p1, p2, p3);
    Board *board = new Board;
    p1->setBoard(board);
    p2->setBoard(board);
    p3->setBoard(board);
    catan->StartTheGame();
    p3->placeFirstSettelment(10); // junction 10 is on lands: sheeps(12),hills(5),mountains(6)
    p2->placeFirstSettelment(31); // junction 33 is on lands: sheeps(9+10),hills(5),agricultural(11)
    p1->placeFirstSettelment(44); // junction 44 is on lands: sheeps(9),forest(6),mountains(3)

    SUBCASE("Test place settelment without resource cards")
    {
        CHECK_THROWS(p1->placeSettelment(11));
    }
    SUBCASE("Test place Town without resource cards")
    {
        CHECK_THROWS(p1->placeTown(11));
    }
    SUBCASE("Test place settelment in occupate junction-")
    {
        p1->giveResourceCardFree();
        CHECK_THROWS(p1->placeSettelment(10));
        CHECK_THROWS(p1->placeSettelment(31));
    }
    SUBCASE("Test place town on other player settelmant-")
    {
        p1->giveResourceCardFree();
        CHECK_THROWS(p1->placeTown(31));
    }
    SUBCASE("Test place settelment on NOT occupate way,lleagel way")
    {
        p1->giveResourceCardFree();
        p1->placeFirstRoad(57);
        p1->placeFirstRoad(65);
        CHECK_NOTHROW(p1->placeSettelment(49));
    }
    SUBCASE("Test place settelment not next to roads")
    {
        p1->giveResourceCardFree();
        p1->placeFirstRoad(57);
        p1->placeFirstRoad(65);
        CHECK_THROWS(p1->placeSettelment(51));
    }
    SUBCASE("Test place Town on NOT occupate way,lleagel way")
    {
        p1->giveResourceCardFree();
        CHECK_NOTHROW(p1->placeTown(44));
    }
    SUBCASE("Test place Town not on occupate junction")
    {
        p1->giveResourceCardFree();
        CHECK_THROWS(p1->placeTown(40));
    }
    delete p1;
    delete p2;
    delete p3;
    delete board;
    delete catan;
};
TEST_CASE("Test buy developemnt card ")
{
    // settings:
    PlayerForTest *p1 = new PlayerForTest("Amit");
    PlayerForTest *p2 = new PlayerForTest("Roni");
    PlayerForTest *p3 = new PlayerForTest("Omer");
    Catan *catan = new Catan();
    catan->setPlayers(p1, p2, p3);
    Board *board = new Board;
    p1->setBoard(board);
    p2->setBoard(board);
    p3->setBoard(board);
    catan->StartTheGame();
    SUBCASE("Test buy develop card without resource cards")
    {
        CHECK_THROWS(p1->BuyDevelopCard());
    }
    SUBCASE("Test that after buy develop card the amount grows")
    {
        p1->giveResourceCardFree();
        CHECK(p1->getNumOfDevCard() == 0);
        p1->BuyDevelopCard();
        CHECK(p1->getNumOfDevCard() == 1);
    }

    delete p1;
    delete p2;
    delete p3;
    delete board;
    delete catan;
};
TEST_CASE("Test use developemnt card ")
{
    // settings:
    PlayerForTest *p1 = new PlayerForTest("Amit");
    PlayerForTest *p2 = new PlayerForTest("Roni");
    PlayerForTest *p3 = new PlayerForTest("Omer");
    Catan *catan = new Catan();
    catan->setPlayers(p1, p2, p3);
    Board *board = new Board;
    p1->setBoard(board);
    p2->setBoard(board);
    p3->setBoard(board);
    catan->StartTheGame();
    p1->giveResourceCardFree();
    p2->giveResourceCardFree();
    p3->giveResourceCardFree();

    SUBCASE("Test use monopol card")
    {
        CHECK_NOTHROW(p1->buyMonopol());
        CHECK(p1->getNumOfCard() == 50);
        p1->useDevelpCard(p1->getDevCard());
        CHECK(p1->getNumOfCard() == 70); // each player give him 10 cards
    }
    SUBCASE("Test knight card")
    {
        CHECK_NOTHROW(p1->buyKnight());
        CHECK(p1->getNumOfPoints() == 0);
        p1->buyKnight();
        p1->useDevelpCard(p1->getDevCard());
        CHECK(p1->getNumOfPoints() == 0);
    }
    SUBCASE("Test year of plenty card")
    {
        CHECK(p1->getNumOfCard() == 50);
        CHECK_NOTHROW(p1->buyYearOfPlenty());
        p1->useDevelpCard(p1->getDevCard());
        CHECK(p1->getNumOfCard() == 52);
    }
    SUBCASE("Test bonus point card")
    {
        CHECK(p1->getNumOfPoints() == 0);
        CHECK_NOTHROW(p1->buybonusPoint());
        p1->useDevelpCard(p1->getDevCard());
        CHECK(p1->getNumOfPoints() == 1);
    }
    SUBCASE("Test build road card")
    {
        CHECK(p1->getNumOfCard() == 50);
        CHECK_NOTHROW(p1->buybuildRoaed());
        p1->useDevelpCard(p1->getDevCard());
        CHECK(p1->getNumOfCard() == 54);
    }
    delete p1;
    delete p2;
    delete p3;
    delete board;
    delete catan;
};
TEST_CASE("Test trade function ")
{
    // settings:
    PlayerForTest *p1 = new PlayerForTest("Amit");
    PlayerForTest *p2 = new PlayerForTest("Roni");
    PlayerForTest *p3 = new PlayerForTest("Omer");
    Catan *catan = new Catan();
    catan->setPlayers(p1, p2, p3);
    Board *board = new Board;
    p1->setBoard(board);
    p2->setBoard(board);
    p3->setBoard(board);
    catan->StartTheGame();
    CHECK_THROWS(p1->trade(p2,"treeCard","oatsCard",1,1));//players p1 +p2 dont have cards to give
    p1->giveResourceCardFree();
    CHECK_THROWS(p1->trade(p2,"treeCard","oatsCard",1,1));//player p2 dont have cards to give
    p2->giveResourceCardFree();
    CHECK_NOTHROW(p1->trade(p2,"treeCard","oatsCard",1,1));//player p2=p2  have cards to give
    CHECK_THROWS(p1->trade(p2,"oatsCard","treeCard",1001,2));//Trade too much cards
    CHECK_THROWS(p1->trade(p2,"oatsCard","treeCard",1,52));//Trade too much cards
    CHECK_THROWS(p1->trade(p2,"kjnweCard","treeCard",1,2));//cards not exsist
    delete p1;
    delete p2;
    delete p3;
    delete board;
    delete catan;
};
