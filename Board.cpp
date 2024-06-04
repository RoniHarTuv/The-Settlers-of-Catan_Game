// Mail: Roniharpaz1@gmail.com
#include "Board.hpp"
#include "DevelopmentCard.hpp"

using namespace catan;
/**
This class represents the game board.
The game board consists of several components:
1. About 19 different plots of land consisting of 5 different resources and a single desert.each land have a uniqu nomber from 2 to 12.
2. About 54 junctions sitting on the vertices of the plots of land. A settlement or a town can be established on a junction.
3. About 72 ways passing between the intersections. A road can be set up on a way.
4. Pack of resource cards. Each piece of land is associated with a resource card that can be obtained by rolling out the number associated with that piece of land.
**/
// this function return *junction of speceifed index
Junction *Board::getJunctionAt(int index)
{
    return this->_junctions[index];
}
// this function return way* of speceifed index
Way *Board::getWayAt(int index)
{
    return this->_ways[index];
}
// this function return land* of speceifed index
Land *Board::getLandAt(int index)
{
    return this->_lands[index];
}
// this is board distructor
Board::~Board()
{
     // // Clean up dynamically allocated DevelopmentCard objects in the map
    for (auto &pair : _pile_developmentCards)
    {
        delete pair.first; // Delete each DevelopmentCard object
    }

    // Clean up dynamically allocated Junction objects
    for (auto junction : _junctions)
    {
        delete junction;
    }
    // Clean up dynamically allocated Land objects
    for (auto land : _lands)
    {
        delete land;
    }
     // Clean up dynamically allocated Way objects
    for (auto way : _ways)
    {
        delete way;
    }
    // Clear vectors and map
    // _junctions.clear();
    // _lands.clear();
    // _ways.clear();
    // _pile_developmentCards.clear();
}

// this function return a development card randomly
DevelopmentCard *Board::generateRandomDevCard()
{
    if (_pile_developmentCards.empty())
    {
        return nullptr; // No cards available
    }
    // Create a vector to hold the non-zero quantity cards
    vector<DevelopmentCard *> availableCards;
    for (const auto &pair : _pile_developmentCards)
    {
        if (pair.second > 0)
        {
            availableCards.push_back(pair.first);
        }
    }
    if (availableCards.empty())
    {
        return nullptr; // No available cards with non-zero quantity
    }
    // Randomly select a card from the available cards
    int randomIndex = rand() % availableCards.size();
    DevelopmentCard *selectedCard = availableCards[randomIndex];
    // Decrease the quantity of the selected card
    _pile_developmentCards[selectedCard]--;
    // Return a clone of the selected card
    return selectedCard->clone();
}
// this constructor creates the board pueces.
Board::Board()
{

    // create resource
    string forest("forest");
    string sheeps("sheeps");
    string hills("hills");
    string mountains("mountains");
    string agricultural("agricultural");
    string dessert("dessert");
    
    // create all the junctions on the board
    Junction *j1 = new Junction(1, vector<Way *>(), vector<Land *>());
    Junction *j2 = new Junction(2, vector<Way *>(), vector<Land *>());
    Junction *j3 = new Junction(3, vector<Way *>(), vector<Land *>());
    Junction *j4 = new Junction(4, vector<Way *>(), vector<Land *>());
    Junction *j5 = new Junction(5, vector<Way *>(), vector<Land *>());
    Junction *j6 = new Junction(6, vector<Way *>(), vector<Land *>());
    Junction *j7 = new Junction(7, vector<Way *>(), vector<Land *>());
    Junction *j8 = new Junction(8, vector<Way *>(), vector<Land *>());
    Junction *j9 = new Junction(9, vector<Way *>(), vector<Land *>());
    Junction *j10 = new Junction(10, vector<Way *>(), vector<Land *>());
    Junction *j11 = new Junction(11, vector<Way *>(), vector<Land *>());
    Junction *j12 = new Junction(12, vector<Way *>(), vector<Land *>());
    Junction *j13 = new Junction(13, vector<Way *>(), vector<Land *>());
    Junction *j14 = new Junction(14, vector<Way *>(), vector<Land *>());
    Junction *j15 = new Junction(15, vector<Way *>(), vector<Land *>());
    Junction *j16 = new Junction(16, vector<Way *>(), vector<Land *>());
    Junction *j17 = new Junction(17, vector<Way *>(), vector<Land *>());
    Junction *j18 = new Junction(18, vector<Way *>(), vector<Land *>());
    Junction *j19 = new Junction(19, vector<Way *>(), vector<Land *>());
    Junction *j20 = new Junction(20, vector<Way *>(), vector<Land *>());
    Junction *j21 = new Junction(21, vector<Way *>(), vector<Land *>());
    Junction *j22 = new Junction(22, vector<Way *>(), vector<Land *>());
    Junction *j23 = new Junction(23, vector<Way *>(), vector<Land *>());
    Junction *j24 = new Junction(24, vector<Way *>(), vector<Land *>());
    Junction *j25 = new Junction(25, vector<Way *>(), vector<Land *>());
    Junction *j26 = new Junction(26, vector<Way *>(), vector<Land *>());
    Junction *j27 = new Junction(27, vector<Way *>(), vector<Land *>());
    Junction *j28 = new Junction(28, vector<Way *>(), vector<Land *>());
    Junction *j29 = new Junction(29, vector<Way *>(), vector<Land *>());
    Junction *j30 = new Junction(30, vector<Way *>(), vector<Land *>());
    Junction *j31 = new Junction(31, vector<Way *>(), vector<Land *>());
    Junction *j32 = new Junction(32, vector<Way *>(), vector<Land *>());
    Junction *j33 = new Junction(33, vector<Way *>(), vector<Land *>());
    Junction *j34 = new Junction(34, vector<Way *>(), vector<Land *>());
    Junction *j35 = new Junction(35, vector<Way *>(), vector<Land *>());
    Junction *j36 = new Junction(36, vector<Way *>(), vector<Land *>());
    Junction *j37 = new Junction(37, vector<Way *>(), vector<Land *>());
    Junction *j38 = new Junction(38, vector<Way *>(), vector<Land *>());
    Junction *j39 = new Junction(39, vector<Way *>(), vector<Land *>());
    Junction *j40 = new Junction(40, vector<Way *>(), vector<Land *>());
    Junction *j41 = new Junction(41, vector<Way *>(), vector<Land *>());
    Junction *j42 = new Junction(42, vector<Way *>(), vector<Land *>());
    Junction *j43 = new Junction(43, vector<Way *>(), vector<Land *>());
    Junction *j44 = new Junction(44, vector<Way *>(), vector<Land *>());
    Junction *j45 = new Junction(45, vector<Way *>(), vector<Land *>());
    Junction *j46 = new Junction(46, vector<Way *>(), vector<Land *>());
    Junction *j47 = new Junction(47, vector<Way *>(), vector<Land *>());
    Junction *j48 = new Junction(48, vector<Way *>(), vector<Land *>());
    Junction *j49 = new Junction(49, vector<Way *>(), vector<Land *>());
    Junction *j50 = new Junction(50, vector<Way *>(), vector<Land *>());
    Junction *j51 = new Junction(51, vector<Way *>(), vector<Land *>());
    Junction *j52 = new Junction(52, vector<Way *>(), vector<Land *>());
    Junction *j53 = new Junction(53, vector<Way *>(), vector<Land *>());
    Junction *j54 = new Junction(54, vector<Way *>(), vector<Land *>());
    // create all the ways on the board
    Way *w1 = new Way(1, j1, j14);
    Way *w2 = new Way(2, j1, j2);
    Way *w3 = new Way(3, j2, j3);
    Way *w4 = new Way(4, j3, j4);
    Way *w5 = new Way(5, j4, j5);
    Way *w6 = new Way(6, j5, j6);
    Way *w7 = new Way(7, j6, j7);
    Way *w8 = new Way(8, j7, j8);
    Way *w9 = new Way(9, j8, j9);
    Way *w10 = new Way(10, j9, j10);
    Way *w11 = new Way(11, j10, j5);
    Way *w12 = new Way(12, j10, j11);
    Way *w13 = new Way(13, j11, j12);
    Way *w14 = new Way(14, j12, j3);
    Way *w15 = new Way(15, j12, j13);
    Way *w16 = new Way(16, j13, j14);
    Way *w17 = new Way(17, j14, j15);
    Way *w18 = new Way(18, j16, j16);
    Way *w19 = new Way(19, j16, j17);
    Way *w20 = new Way(20, j17, j18);
    Way *w21 = new Way(21, j18, j13);
    Way *w22 = new Way(22, j18, j19);
    Way *w23 = new Way(23, j19, j20);
    Way *w24 = new Way(24, j20, j11);
    Way *w25 = new Way(25, j20, j21);
    Way *w26 = new Way(26, j21, j22);
    Way *w27 = new Way(27, j22, j9);
    Way *w28 = new Way(28, j22, j23);
    Way *w29 = new Way(29, j23, j25);
    Way *w30 = new Way(30, j25, j24);
    Way *w31 = new Way(31, j24, j8);
    Way *w32 = new Way(32, j25, j26);
    Way *w33 = new Way(33, j26, j27);
    Way *w34 = new Way(34, j27, j28);
    Way *w35 = new Way(35, j28, j29);
    Way *w36 = new Way(36, j29, j23);
    Way *w37 = new Way(37, j29, j30);
    Way *w38 = new Way(38, j30, j31);
    Way *w39 = new Way(39, j31, j32);
    Way *w40 = new Way(40, j31, j32);
    Way *w41 = new Way(41, j32, j33);
    Way *w42 = new Way(42, j33, j19);
    Way *w43 = new Way(43, j33, j34);
    Way *w44 = new Way(44, j34, j35);
    Way *w45 = new Way(45, j35, j17);
    Way *w46 = new Way(46, j35, j36);
    Way *w47 = new Way(47, j36, j38);
    Way *w48 = new Way(48, j38, j37);
    Way *w49 = new Way(49, j37, j16);
    Way *w50 = new Way(50, j36, j39);
    Way *w51 = new Way(51, j39, j40);
    Way *w52 = new Way(52, j40, j41);
    Way *w53 = new Way(53, j41, j34);
    Way *w54 = new Way(54, j41, j42);
    Way *w55 = new Way(55, j42, j43);
    Way *w56 = new Way(56, j43, j32);
    Way *w57 = new Way(57, j43, j44);
    Way *w58 = new Way(58, j44, j45);
    Way *w59 = new Way(59, j45, j30);
    Way *w60 = new Way(60, j45, j46);
    Way *w61 = new Way(61, j46, j47);
    Way *w62 = new Way(62, j47, j28);
    Way *w63 = new Way(63, j46, j48);
    Way *w64 = new Way(64, j48, j49);
    Way *w65 = new Way(65, j49, j50);
    Way *w66 = new Way(66, j50, j44);
    Way *w67 = new Way(67, j50, j51);
    Way *w68 = new Way(68, j51, j52);
    Way *w69 = new Way(69, j52, j42);
    Way *w70 = new Way(70, j52, j53);
    Way *w71 = new Way(71, j53, j54);
    Way *w72 = new Way(72, j54, j40);

    // create all the land on the board:
    // Land l1(forest, 1, vector<Town>(), vector<Road>(), vector<Settelment>());
    Land *pl1 = new Land(forest, 1, vector<Town>(), vector<Road>(), vector<Settelment>());
    Land l2(sheeps, 2, vector<Town>(), vector<Road>(), vector<Settelment>());
    Land *pl2 = new Land(sheeps, 2, vector<Town>(), vector<Road>(), vector<Settelment>());
    Land l3(agricultural, 3, vector<Town>(), vector<Road>(), vector<Settelment>());
    Land *pl3 = new Land(agricultural, 3, vector<Town>(), vector<Road>(), vector<Settelment>());
    Land l4(hills, 4, vector<Town>(), vector<Road>(), vector<Settelment>());
    Land *pl4 = new Land(hills, 4, vector<Town>(), vector<Road>(), vector<Settelment>());
    Land l5(mountains, 5, vector<Town>(), vector<Road>(), vector<Settelment>());
    Land *pl5 = new Land(mountains, 5, vector<Town>(), vector<Road>(), vector<Settelment>());
    Land l6(hills, 6, vector<Town>(), vector<Road>(), vector<Settelment>());
    Land *pl6 = new Land(hills, 6, vector<Town>(), vector<Road>(), vector<Settelment>());
    Land l7(sheeps, 7, vector<Town>(), vector<Road>(), vector<Settelment>());
    Land *pl7 = new Land(sheeps, 7, vector<Town>(), vector<Road>(), vector<Settelment>());
    Land l8(dessert, 8, vector<Town>(), vector<Road>(), vector<Settelment>());
    Land *pl8 = new Land(dessert, 8, vector<Town>(), vector<Road>(), vector<Settelment>());
    Land l9(forest, 9, vector<Town>(), vector<Road>(), vector<Settelment>());
    Land *pl9 = new Land(forest, 9, vector<Town>(), vector<Road>(), vector<Settelment>());
    Land l10(agricultural, 10, vector<Town>(), vector<Road>(), vector<Settelment>());
    Land *pl10 = new Land(agricultural, 10, vector<Town>(), vector<Road>(), vector<Settelment>());
    Land l11(forest, 11, vector<Town>(), vector<Road>(), vector<Settelment>());
    Land *pl11 = new Land(forest, 11, vector<Town>(), vector<Road>(), vector<Settelment>());
    Land l12(agricultural, 12, vector<Town>(), vector<Road>(), vector<Settelment>());
    Land *pl12 = new Land(agricultural, 12, vector<Town>(), vector<Road>(), vector<Settelment>());
    Land l13(hills, 13, vector<Town>(), vector<Road>(), vector<Settelment>());
    Land *pl13 = new Land(hills, 13, vector<Town>(), vector<Road>(), vector<Settelment>());
    Land l14(sheeps, 14, vector<Town>(), vector<Road>(), vector<Settelment>());
    Land *pl14 = new Land(sheeps, 14, vector<Town>(), vector<Road>(), vector<Settelment>());
    Land l15(sheeps, 15, vector<Town>(), vector<Road>(), vector<Settelment>());
    Land *pl15 = new Land(sheeps, 15, vector<Town>(), vector<Road>(), vector<Settelment>());
    Land l16(mountains, 16, vector<Town>(), vector<Road>(), vector<Settelment>());
    Land *pl16 = new Land(mountains, 16, vector<Town>(), vector<Road>(), vector<Settelment>());
    Land l17(mountains, 17, vector<Town>(), vector<Road>(), vector<Settelment>());
    Land *pl17 = new Land(mountains, 17, vector<Town>(), vector<Road>(), vector<Settelment>());
    Land l18(agricultural, 18, vector<Town>(), vector<Road>(), vector<Settelment>());
    Land *pl18 = new Land(agricultural, 18, vector<Town>(), vector<Road>(), vector<Settelment>());
    Land l19(forest, 19, vector<Town>(), vector<Road>(), vector<Settelment>());
    Land *pl19 = new Land(forest, 19, vector<Town>(), vector<Road>(), vector<Settelment>());

    pl1->setLandNum(11);
    pl2->setLandNum(12);
    pl3->setLandNum(9);
    pl4->setLandNum(4);
    pl5->setLandNum(6);
    pl6->setLandNum(5);
    pl7->setLandNum(10);
    pl8->setLandNum(0);
    pl9->setLandNum(3);
    pl10->setLandNum(11);
    pl11->setLandNum(4);
    pl12->setLandNum(8);
    pl13->setLandNum(8);
    pl14->setLandNum(10);
    pl15->setLandNum(9);
    pl16->setLandNum(3);
    pl17->setLandNum(5);
    pl18->setLandNum(2);
    pl19->setLandNum(6);

    // place all the ways and the kands into junctions
    j1->addWay(w1);
    j1->addWay(w2);
    j1->addLand(pl1);

    j2->addWay(w2);
    j2->addWay(w3);
    j2->addLand(pl1);

    j3->addWay(w3);
    j3->addWay(w4);
    j3->addLand(pl1);
    j3->addLand(pl2);

    j4->addWay(w4);
    j4->addWay(w5);
    j4->addLand(pl2);

    j5->addWay(w5);
    j5->addWay(w6);
    j5->addLand(pl2);
    j5->addLand(pl3);

    j6->addWay(w6);
    j6->addWay(w7);
    j6->addLand(pl3);

    j7->addWay(w7);
    j7->addWay(w8);
    j7->addLand(pl3);

    j8->addWay(w8);
    j8->addWay(w9);
    j8->addWay(w31);
    j8->addLand(pl3);
    j8->addLand(pl7);

    j9->addWay(w9);
    j9->addWay(w10);
    j9->addWay(w27);
    j9->addLand(pl3);
    j9->addLand(pl7);
    j9->addLand(pl6);

    j10->addWay(w11);
    j10->addWay(w10);
    j10->addWay(w12);
    j10->addLand(pl2);
    j10->addLand(pl3);
    j10->addLand(pl6);

    j11->addWay(w12);
    j11->addWay(w13);
    j11->addWay(w24);
    j11->addLand(pl2);
    j11->addLand(pl5);
    j11->addLand(pl6);

    j12->addWay(w13);
    j12->addWay(w14);
    j12->addWay(w15);
    j12->addLand(pl1);
    j12->addLand(pl2);
    j12->addLand(pl5);

    j13->addWay(w15);
    j13->addWay(w16);
    j13->addWay(w21);
    j13->addLand(pl1);
    j13->addLand(pl4);
    j13->addLand(pl5);

    j14->addWay(w1);
    j14->addWay(w16);
    j14->addWay(w17);
    j14->addLand(pl1);
    j14->addLand(pl4);

    j15->addWay(w17);
    j15->addWay(w18);
    j15->addLand(pl4);

    j16->addWay(w18);
    j16->addWay(w19);
    j16->addWay(w49);
    j16->addLand(pl4);
    j16->addLand(pl8);

    j17->addWay(w20);
    j17->addWay(w19);
    j17->addWay(w45);
    j17->addLand(pl4);
    j17->addLand(pl8);
    j17->addLand(pl9);

    j18->addWay(w20);
    j18->addWay(w21);
    j18->addWay(w22);
    j18->addLand(pl4);
    j18->addLand(pl5);
    j18->addLand(pl9);

    j19->addWay(w22);
    j19->addWay(w23);
    j19->addWay(w42);
    j19->addLand(pl5);
    j19->addLand(pl10);
    j19->addLand(pl9);

    j20->addWay(w24);
    j20->addWay(w23);
    j20->addWay(w25);
    j20->addLand(pl5);
    j20->addLand(pl6);
    j20->addLand(pl10);

    j21->addWay(w25);
    j21->addWay(w26);
    j21->addWay(w39);
    j21->addLand(pl6);
    j21->addLand(pl10);
    j21->addLand(pl11);

    j22->addWay(w27);
    j22->addWay(w28);
    j22->addWay(w26);
    j22->addLand(pl6);
    j22->addLand(pl7);
    j22->addLand(pl11);

    j23->addWay(w28);
    j23->addWay(w29);
    j23->addWay(w36);
    j23->addLand(pl7);
    j23->addLand(pl11);
    j23->addLand(pl12);

    j24->addWay(w31);
    j24->addWay(w30);
    j24->addLand(pl7);

    j25->addWay(w29);
    j25->addWay(w30);
    j25->addWay(w32);
    j25->addLand(pl7);
    j25->addLand(pl12);

    j26->addWay(w33);
    j26->addWay(w32);
    j26->addLand(pl12);

    j27->addWay(w33);
    j27->addWay(w34);
    j27->addLand(pl12);

    j28->addWay(w34);
    j28->addWay(w35);
    j28->addWay(w62);
    j28->addLand(pl6);
    j28->addLand(pl12);

    j29->addWay(w35);
    j29->addWay(w36);
    j29->addWay(w37);
    j29->addLand(pl1);
    j29->addLand(pl12);
    j29->addLand(pl16);

    j30->addWay(w37);
    j30->addWay(w38);
    j30->addWay(w59);
    j30->addLand(pl11);
    j30->addLand(pl15);
    j30->addLand(pl16);

    j31->addWay(w40);
    j31->addWay(w38);
    j31->addWay(w39);
    j31->addLand(pl10);
    j31->addLand(pl15);
    j31->addLand(pl11);

    j32->addWay(w40);
    j32->addWay(w41);
    j32->addWay(w56);
    j32->addLand(pl10);
    j32->addLand(pl15);
    j32->addLand(pl14);

    j33->addWay(w41);
    j33->addWay(w42);
    j33->addWay(w43);
    j33->addLand(pl10);
    j33->addLand(pl9);
    j33->addLand(pl14);

    j34->addWay(w43);
    j34->addWay(w44);
    j34->addWay(w53);
    j34->addLand(pl9);
    j34->addLand(pl13);
    j34->addLand(pl14);

    j35->addWay(w44);
    j35->addWay(w45);
    j35->addWay(w46);
    j35->addLand(pl8);
    j35->addLand(pl9);
    j35->addLand(pl13);

    j36->addWay(w46);
    j36->addWay(w47);
    j36->addWay(w50);
    j36->addLand(pl8);
    j36->addLand(pl13);

    j37->addWay(w49);
    j37->addWay(w48);
    j37->addLand(pl8);

    j38->addWay(w47);
    j38->addWay(w48);
    j38->addLand(pl8);

    j39->addWay(w50);
    j39->addWay(w51);
    j39->addLand(pl13);

    j40->addWay(w51);
    j40->addWay(w52);
    j40->addWay(w72);
    j40->addLand(pl13);
    j40->addLand(pl17);

    j41->addWay(w52);
    j41->addWay(w53);
    j41->addWay(w54);
    j41->addLand(pl13);
    j41->addLand(pl14);
    j41->addLand(pl17);

    j42->addWay(w54);
    j42->addWay(w55);
    j42->addWay(w69);
    j42->addLand(pl18);
    j42->addLand(pl14);
    j42->addLand(pl17);

    j43->addWay(w55);
    j43->addWay(w56);
    j43->addWay(w57);
    j43->addLand(pl18);
    j43->addLand(pl14);
    j43->addLand(pl15);

    j44->addWay(w57);
    j44->addWay(w58);
    j44->addWay(w66);
    j44->addLand(pl18);
    j44->addLand(pl19);
    j44->addLand(pl15);

    j45->addWay(w58);
    j45->addWay(w59);
    j45->addWay(w60);
    j45->addLand(pl16);
    j45->addLand(pl19);
    j45->addLand(pl15);

    j46->addWay(w60);
    j46->addWay(w61);
    j46->addWay(w63);
    j46->addLand(pl16);
    j46->addLand(pl19);

    j47->addWay(w62);
    j47->addWay(w61);
    j47->addLand(pl16);

    j48->addWay(w64);
    j48->addWay(w63);
    j48->addLand(pl19);

    j49->addWay(w64);
    j49->addWay(w65);
    j49->addLand(pl19);

    j50->addWay(w65);
    j50->addWay(w66);
    j50->addWay(w67);
    j50->addLand(pl19);
    j50->addLand(pl18);

    j51->addWay(w67);
    j51->addWay(w68);
    j51->addLand(pl18);

    j52->addWay(w68);
    j52->addWay(w69);
    j52->addWay(w70);
    j52->addLand(pl17);
    j52->addLand(pl18);

    j53->addWay(w70);
    j53->addWay(w71);
    j53->addLand(pl17);

    j54->addWay(w72);
    j54->addWay(w71);
    j54->addLand(pl17);

    vector<Junction *> juncLand1 = {j1, j2, j3, j12, j13, j14};
    vector<Junction *> juncLand2 = {j3, j4, j5, j12, j11, j10};
    vector<Junction *> juncLand3 = {j5, j6, j7, j8, j9, j10};
    vector<Junction *> juncLand4 = {j13, j14, j15, j16, j17, j18};
    vector<Junction *> juncLand5 = {j11, j12, j13, j18, j19, j20};
    vector<Junction *> juncLand6 = {j9, j10, j11, j20, j21, j22};
    vector<Junction *> juncLand7 = {j8, j9, j3, j22, j23, j25};
    vector<Junction *> juncLand8 = {j16, j17, j35, j36, j38, j37};
    vector<Junction *> juncLand9 = {j17, j18, j19, j33, j34, j35};
    vector<Junction *> juncLand10 = {j19, j20, j21, j31, j32, j33};
    vector<Junction *> juncLand11 = {j21, j22, j23, j29, j30, j31};
    vector<Junction *> juncLand12 = {j23, j25, j26, j27, j28, j29};
    vector<Junction *> juncLand13 = {j34, j35, j36, j39, j40, j41};
    vector<Junction *> juncLand14 = {j32, j33, j34, j41, j42, j43};
    vector<Junction *> juncLand15 = {j30, j31, j32, j43, j44, j45};
    vector<Junction *> juncLand16 = {j28, j29, j30, j45, j46, j47};
    vector<Junction *> juncLand17 = {j40, j41, j42, j52, j53, j54};
    vector<Junction *> juncLand18 = {j42, j43, j44, j50, j51, j52};
    vector<Junction *> juncLand19 = {j44, j45, j46, j48, j49, j50};

    pl1->setJunction(juncLand1);
    pl2->setJunction(juncLand2);
    pl3->setJunction(juncLand3);
    pl4->setJunction(juncLand4);
    pl5->setJunction(juncLand5);
    pl6->setJunction(juncLand6);
    pl7->setJunction(juncLand7);
    pl8->setJunction(juncLand8);
    pl9->setJunction(juncLand9);
    pl10->setJunction(juncLand10);
    pl11->setJunction(juncLand11);
    pl12->setJunction(juncLand12);
    pl13->setJunction(juncLand13);
    pl14->setJunction(juncLand14);
    pl15->setJunction(juncLand15);
    pl16->setJunction(juncLand16);
    pl17->setJunction(juncLand17);
    pl18->setJunction(juncLand18);
    pl19->setJunction(juncLand19);

    this->_junctions.push_back(j1);
    this->_junctions.push_back(j2);
    this->_junctions.push_back(j3);
    this->_junctions.push_back(j4);
    this->_junctions.push_back(j5);
    this->_junctions.push_back(j6);
    this->_junctions.push_back(j7);
    this->_junctions.push_back(j8);
    this->_junctions.push_back(j9);
    this->_junctions.push_back(j10);
    this->_junctions.push_back(j11);
    this->_junctions.push_back(j12);
    this->_junctions.push_back(j13);
    this->_junctions.push_back(j14);
    this->_junctions.push_back(j15);
    this->_junctions.push_back(j16);
    this->_junctions.push_back(j17);
    this->_junctions.push_back(j18);
    this->_junctions.push_back(j19);
    this->_junctions.push_back(j20);
    this->_junctions.push_back(j21);
    this->_junctions.push_back(j22);
    this->_junctions.push_back(j23);
    this->_junctions.push_back(j24);
    this->_junctions.push_back(j25);
    this->_junctions.push_back(j26);
    this->_junctions.push_back(j27);
    this->_junctions.push_back(j28);
    this->_junctions.push_back(j29);
    this->_junctions.push_back(j30);
    this->_junctions.push_back(j31);
    this->_junctions.push_back(j32);
    this->_junctions.push_back(j33);
    this->_junctions.push_back(j34);
    this->_junctions.push_back(j35);
    this->_junctions.push_back(j36);
    this->_junctions.push_back(j37);
    this->_junctions.push_back(j38);
    this->_junctions.push_back(j39);
    this->_junctions.push_back(j40);
    this->_junctions.push_back(j41);
    this->_junctions.push_back(j42);
    this->_junctions.push_back(j43);
    this->_junctions.push_back(j44);
    this->_junctions.push_back(j45);
    this->_junctions.push_back(j46);
    this->_junctions.push_back(j47);
    this->_junctions.push_back(j48);
    this->_junctions.push_back(j49);
    this->_junctions.push_back(j50);
    this->_junctions.push_back(j51);
    this->_junctions.push_back(j52);
    this->_junctions.push_back(j53);
    this->_junctions.push_back(j54);

    this->_ways.push_back(w1);
    this->_ways.push_back(w2);
    this->_ways.push_back(w3);
    this->_ways.push_back(w4);
    this->_ways.push_back(w5);
    this->_ways.push_back(w6);
    this->_ways.push_back(w7);
    this->_ways.push_back(w8);
    this->_ways.push_back(w9);
    this->_ways.push_back(w10);
    this->_ways.push_back(w11);
    this->_ways.push_back(w12);
    this->_ways.push_back(w13);
    this->_ways.push_back(w14);
    this->_ways.push_back(w15);
    this->_ways.push_back(w16);
    this->_ways.push_back(w17);
    this->_ways.push_back(w18);
    this->_ways.push_back(w19);
    this->_ways.push_back(w20);
    this->_ways.push_back(w21);
    this->_ways.push_back(w22);
    this->_ways.push_back(w23);
    this->_ways.push_back(w24);
    this->_ways.push_back(w25);
    this->_ways.push_back(w26);
    this->_ways.push_back(w27);
    this->_ways.push_back(w28);
    this->_ways.push_back(w29);
    this->_ways.push_back(w30);
    this->_ways.push_back(w31);
    this->_ways.push_back(w32);
    this->_ways.push_back(w33);
    this->_ways.push_back(w34);
    this->_ways.push_back(w35);
    this->_ways.push_back(w36);
    this->_ways.push_back(w37);
    this->_ways.push_back(w38);
    this->_ways.push_back(w39);
    this->_ways.push_back(w40);
    this->_ways.push_back(w41);
    this->_ways.push_back(w42);
    this->_ways.push_back(w43);
    this->_ways.push_back(w44);
    this->_ways.push_back(w45);
    this->_ways.push_back(w46);
    this->_ways.push_back(w47);
    this->_ways.push_back(w48);
    this->_ways.push_back(w49);
    this->_ways.push_back(w50);
    this->_ways.push_back(w51);
    this->_ways.push_back(w52);
    this->_ways.push_back(w53);
    this->_ways.push_back(w54);
    this->_ways.push_back(w55);
    this->_ways.push_back(w56);
    this->_ways.push_back(w57);
    this->_ways.push_back(w58);
    this->_ways.push_back(w59);
    this->_ways.push_back(w60);
    this->_ways.push_back(w61);
    this->_ways.push_back(w62);
    this->_ways.push_back(w63);
    this->_ways.push_back(w64);
    this->_ways.push_back(w65);
    this->_ways.push_back(w66);
    this->_ways.push_back(w67);
    this->_ways.push_back(w68);
    this->_ways.push_back(w69);
    this->_ways.push_back(w70);
    this->_ways.push_back(w71);
    this->_ways.push_back(w72);

    this->_lands.push_back(pl1);
    this->_lands.push_back(pl2);
    this->_lands.push_back(pl3);
    this->_lands.push_back(pl4);
    this->_lands.push_back(pl5);
    this->_lands.push_back(pl6);
    this->_lands.push_back(pl7);
    this->_lands.push_back(pl8);
    this->_lands.push_back(pl9);
    this->_lands.push_back(pl10);
    this->_lands.push_back(pl11);
    this->_lands.push_back(pl12);
    this->_lands.push_back(pl13);
    this->_lands.push_back(pl14);
    this->_lands.push_back(pl15);
    this->_lands.push_back(pl16);
    this->_lands.push_back(pl17);
    this->_lands.push_back(pl18);
    this->_lands.push_back(pl19);

    monopolDCard *monopol = new monopolDCard();
    BonusPointDCard *bonusPoint = new BonusPointDCard();
    YearOfPlentyDCard *yearOfPlenty = new YearOfPlentyDCard();
    RoadDCard *road = new RoadDCard();
    KnightDCard *knight = new KnightDCard();

    // Populate the map with card instances and their quantities
    _pile_developmentCards[monopol] = monopol->getQuantity();
    _pile_developmentCards[bonusPoint] = bonusPoint->getQuantity();
    _pile_developmentCards[yearOfPlenty] = yearOfPlenty->getQuantity();
    _pile_developmentCards[road] = road->getQuantity();
    _pile_developmentCards[knight] = knight->getQuantity();
}
