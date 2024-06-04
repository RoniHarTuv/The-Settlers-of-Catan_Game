// Mail: Roniharpaz1@gmail.com
#include "Catan.hpp"
#include <iostream>

using namespace catan;
/**
 * This class represents a simulation of the game "Settlers of Catan".
 * There are 3 participants in this game, where each player is allowed to roll a dice and make moves as he wishes.
  After every 2 rounds, statistics will be printed to the screen
  in which the number of points of each player, and the resource cards in his hand will be updated.
  this game is very randomly each round will be different.
*/
int main()
{ // set the players of catan:
    Player *p1 = new Player("Amit");
    Player *p2 = new Player("Yossi");
    Player *p3 = new Player("Dana");
    Catan* catan= new Catan();
    catan->setPlayers(p1,p2,p3);
    // set the geme Board:
    Board *board = new Board();
    p1->setBoard(board);
    p2->setBoard(board);
    p3->setBoard(board);
    //start the game by each player places 2 settelment and two roads:
    catan->StartTheGame();
    board->getJunctionAt(12)->printJunction();
    p1->placeFirstSettelment(9);
    p1->placeFirstRoad(10);
    p2->placeFirstSettelment(29);
    p2->placeFirstRoad(37);
    p3->placeFirstSettelment(33);
    p3->placeFirstRoad(42);
    p3->placeFirstSettelment(41);
    p3->placeFirstRoad(53);
    p2->placeFirstSettelment(20);
    p2->placeFirstRoad(25);
    p1->placeFirstSettelment(11);
    p1->placeFirstRoad(14);
    //print number of card for each player:
    p1->printCard();
    p2->printCard();
    p3->printCard();

    cout << endl;
    cout << "              ******** ROUND # 1 !! ********" << endl;
    p1->rollDice();
    p1->placeRoad(15); // p1 place road
    try
    { // p3 tried to roll dice but it is not his turn
        p3->rollDice();
    }
    catch (const std::exception &e)
    {
        cerr << e.what() << '\n';
    }
    p2->rollDice();
    p2->placeRoad(27); // p2 place road
    p3->rollDice();
    try
    {
        p3->placeRoad(1); // p3 tries to place road in illeagel place(not next to his settelment/road)
    }
    catch (const std::exception &e)
    {
        cerr << e.what() << '\n';
    }
    p1->rollDice();
    p2->rollDice();
    p3->rollDice();

    cout << "              ********ROUND # 1 DATA: ********" << endl;
    p1->printCard();
    p2->printCard();
    p3->printCard();
    cout << p1->getName() << " Number of points: " << p1->getNumOfPoints() << endl;
    cout << p2->getName() << " Number of points: " << p2->getNumOfPoints() << endl;
    cout << p3->getName() << " Number of points: " << p3->getNumOfPoints() << endl;
    cout << endl;
    cout << "              ******** ROUND # 2 !! ********" << endl;
    p1->rollDice();
    p2->rollDice();
    p3->rollDice();
    try
    {
        p1->placeSettelment(13); // p1 tries to place a settelment- not sure he got inugh resource cards
    }
    catch (const std::exception &e)
    {
        cerr << e.what() << '\n';
     }
    try
    {
        p2->placeSettelment(22); // p2 tries to place a settelment- not sure he got inugh resource cards
    }
    catch (const std::exception &e)
    {
        cerr << e.what() << '\n';
    }
    try
    {
        p3->placeSettelment(18); // p3 tries to place a settelment- not sure he got inugh resource cards
    }
    catch (const std::exception &e)
    {
        cerr << e.what() << '\n';
    }
    cout << "              ********ROUND # 2 DATA: ********" << endl;
    p1->printCard();
    p2->printCard();
    p3->printCard();
    cout << p1->getName() << " Number of points: " << p1->getNumOfPoints() << endl;
    cout << p2->getName() << " Number of points: " << p2->getNumOfPoints() << endl;
    cout << p3->getName() << " Number of points: " << p3->getNumOfPoints() << endl;
    cout << endl;
    cout << "              ******** ROUND # 3 !! ********" << endl;
    p1->rollDice();
    try
    {
        p1->placeSettelment(13); // p1 tries to place a settelment- not sure he got inugh resource cards
    }
    catch (const std::exception &e)
    {
        cerr << e.what() << '\n';
    }
    p2->rollDice();
    try
    {
        p2->placeSettelment(22); // p2 tries to place a settelment- not sure he got inugh resource cards
    }
    catch (const std::exception &e)
    {
        cerr << e.what() << '\n';
    }
    p3->rollDice();
    try
    {
        p3->placeSettelment(18); // p3 tries to place a settelment- not sure he got inugh resource cards
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }
    p1->rollDice();
    p2->rollDice();
    p3->rollDice();
    cout << "              ********ROUND # 3 DATA: ********" << endl;
    p1->printCard();
    p2->printCard();
    p3->printCard();
    cout << p1->getName() << " Number of points: " << p1->getNumOfPoints() << endl;
    cout << p2->getName() << " Number of points: " << p2->getNumOfPoints() << endl;
    cout << p3->getName() << " Number of points: " << p3->getNumOfPoints() << endl;

    cout << endl;
    cout << "              ******** ROUND # 4 !! ********" << endl; // buy development card
    p1->rollDice();
    p2->rollDice();
    p3->rollDice();
    p1->rollDice();
    try
    {
        p1->BuyDevelopCard(); // p1 tries to buy a development card- not sure he got inugh resource cards
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }
    try
    {
        p1->placeRoad(5); // p1 tries to place a road- not sure he got inugh resource cards
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }
    p2->rollDice();
    try
    {
        p2->BuyDevelopCard(); // p2 tries to buy a development card- not sure he got inugh resource cards
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }
    try
    {
        p2->placeRoad(39); // p2 tries to place a settelment- not sure he got inugh resource cards
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }
    p3->rollDice();
    try
    {
        p3->BuyDevelopCard(); // p3 tries to buy a development card- not sure he got inugh resource cards
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }
    try
    {
        p3->placeRoad(51); // p3 tries to place a settelment- not sure he got inugh resource cards
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }

    cout << "              ********ROUND # 4 DATA: ********" << endl;
    p1->printCard();
    p2->printCard();
    p3->printCard();

    cout << p1->getName() << " Number of points: " << p1->getNumOfPoints() << endl;
    cout << p2->getName() << " Number of points: " << p2->getNumOfPoints() << endl;
    cout << p3->getName() << " Number of points: " << p3->getNumOfPoints() << endl;
    cout << endl;
    cout << "              ******** ROUND # 5 !! ********" << endl; // place towns
    p1->rollDice();
    p2->rollDice();
    p3->rollDice();
    p1->rollDice();
    try
    {
        p1->placeTown(11); // p1 tries to place a town- not sure he got inugh resource cards
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }
    p2->rollDice();
    try
    {
        p2->placeTown(29); // p2 tries to place a town- not sure he got inugh resource cards
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }
    p3->rollDice();
    try
    {
        p3->placeTown(41); // p3 tries to place a town- not sure he got inugh resource cards
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }
    cout << "              ********ROUND # 5 DATA: ********" << endl;
    p1->printCard();
    p2->printCard();
    p3->printCard();
    cout << p1->getName() << " Number of points: " << p1->getNumOfPoints() << endl;
    cout << p2->getName() << " Number of points: " << p2->getNumOfPoints() << endl;
    cout << p3->getName() << " Number of points: " << p3->getNumOfPoints() << endl;

    cout << endl;
    cout << "              ******** ROUND # 6 !! ********" << endl;
    p1->rollDice();
    p2->rollDice();
    p3->rollDice();
    p1->rollDice();
    try
    {
        p1->placeTown(9);
    }
    catch (const exception &e)
    {
        std::cerr << e.what() << '\n';
    }
    try
    {
        p1->placeRoad(5);
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }
    p2->rollDice();
    try
    {
        p2->placeSettelment(31);
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }
    try
    {
        p2->placeTown(20);
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }
    p3->rollDice();
    try
    {
        p3->placeTown(41);
        p3->placeTown(33);
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }

    cout << "              ********ROUND # 6 DATA: ********" << endl;
    p1->printCard();
    p2->printCard();
    p3->printCard();

    cout << p1->getName() << " Number of points: " << p1->getNumOfPoints() << endl;
    cout << p2->getName() << " Number of points: " << p2->getNumOfPoints() << endl;
    cout << p3->getName() << " Number of points: " << p3->getNumOfPoints() << endl;

    cout << "              ******** ROUND # 7 !! ********" << endl; /// place towns(same as round 6)
    p1->rollDice();
    p2->rollDice();
    p3->rollDice();
    p1->rollDice();
    try
    {
        p1->placeTown(9);
    }
    catch (const exception &e)
    {
        std::cerr << e.what() << '\n';
    }
    try
    {
        p1->placeRoad(5);
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }
    p2->rollDice();
    try
    {
        p2->placeSettelment(31);
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }
    try
    {
        p2->placeTown(20);
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }
    p3->rollDice();
    try
    {
        p3->placeTown(33);
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }

    cout << "              ********ROUND # 7 DATA: ********" << endl;
    p1->printCard();
    p2->printCard();
    p3->printCard();

    cout << p1->getName() << " Number of points: " << p1->getNumOfPoints() << endl;
    cout << p2->getName() << " Number of points: " << p2->getNumOfPoints() << endl;
    cout << p3->getName() << " Number of points: " << p3->getNumOfPoints() << endl;
    cout << "              ******** ROUND # 8 !! ********" << endl; /// trades +develop card////
    p1->rollDice();
    p2->rollDice();
    p3->rollDice();
    p1->rollDice();
    try
    {
        p1->trade(p2, "TreeCard", "OatsCard", 1, 1);//p1 try to trade with p2
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }
    try
    {
        p1->trade(p2, "BrickCard", "IronCard", 1, 1);//p1 try to trade with p2
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }
    try
    {
        p1->BuyDevelopCard(); // p1 tries to buy a development card
    }
    catch (const exception &e)
    {
        cerr << e.what() << '\n';
    }
    p2->rollDice();
    try
    {
        p2->trade(p3, "TreeCard", "IronCard", 1, 2);//p2 try to trade with p3
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }
    try
    {
        p2->trade(p3, "BrickCard", "WoolCard", 1, 2);//p2 try to trade with p3
    }
    catch (const exception &e)
    {
        std::cerr << e.what() << '\n';
    }
    try
    {
        p2->BuyDevelopCard(); // p2 tries to buy a development card
    }
    catch (const exception &e)
    {
        cerr << e.what() << '\n';
    }
    p3->rollDice();
    try
    {
        p3->trade(p3, "TreeCard", "IronCard", 1, 2); // p3 try to trade with p3- error
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }
    try
    {
        p3->trade(p1, "BrickCard", "WoolCard", 1, 1);//p3 try to trade with p1
    }
    catch (const exception &e)
    {
        std::cerr << e.what() << '\n';
    }
    try
    {
        p2->BuyDevelopCard(); // p3 tries to buy a development card
    }
    catch (const exception &e)
    {
        cerr << e.what() << '\n';
    }

    cout << "              ********ROUND # 8 DATA: ********" << endl;
    p1->printCard();
    p2->printCard();
    p3->printCard();
    p1->printDevelopCard();
    p2->printDevelopCard();
    p3->printDevelopCard();
    cout << p1->getName() << " Number of points: " << p1->getNumOfPoints() << endl;
    cout << p2->getName() << " Number of points: " << p2->getNumOfPoints() << endl;
    cout << p3->getName() << " Number of points: " << p3->getNumOfPoints() << endl;

    cout << "              ******** ROUND # 9 !! ********" << endl;// implements development cards
    p1->rollDice();
    p1->useDevelpCard(p1->getDevCard()); //p1 using its developmant card
    try{p1->BuyDevelopCard();}
    catch (const exception &e)
    {
        cerr << e.what() << '\n';
    }
    p1->useDevelpCard(p1->getDevCard());
    p2->rollDice();
    p2->useDevelpCard(p2->getDevCard());
    p3->rollDice();
    p3->printCard();
    p3->useDevelpCard(p3->getDevCard());

    cout << "              ********ROUND # 9 DATA: ********" << endl;
    p1->printCard();
    p2->printCard();
    p3->printCard();
    p1->printDevelopCard();
    p2->printDevelopCard();
    p3->printDevelopCard();
    cout << p1->getName() << " Number of points: " << p1->getNumOfPoints() << endl;
    cout << p2->getName() << " Number of points: " << p2->getNumOfPoints() << endl;
    cout << p3->getName() << " Number of points: " << p3->getNumOfPoints() << endl;
    cout << endl;
    cout << "              ******** ROUND # 10 !! ********" << endl;
    p1->rollDice();
    p2->rollDice();
    p3->rollDice();

    cout << "              ********ROUND # 10 DATA: ********" << endl;
    p1->printCard();
    p2->printCard();
    p3->printCard();

    cout << p1->getName() << " Number of points: " << p1->getNumOfPoints() << endl;
    cout << p2->getName() << " Number of points: " << p2->getNumOfPoints() << endl;
    cout << p3->getName() << " Number of points: " << p3->getNumOfPoints() << endl;

    catan->printWinner();// check if the game is over or not.

    delete p1;
    delete p2;
    delete p3;
    delete catan;
    delete board;

    return 0;
}
