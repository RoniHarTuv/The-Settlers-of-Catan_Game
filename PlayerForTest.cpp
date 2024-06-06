// Mail: Roniharpaz1@gmail.com
#include "PlayerForTest.hpp"

int catan::PlayerForTest::rollDiceFixed9() // this function will always return 8
{
    int ans = 9;
    for (int i = 0; i < 19; i++) // go over all the land in the board(19)
    {
        if (this->_board->getLandAt(i)->getLandNum() == ans) // if the land have the ans number on it
        {
            for (int j = 0; j < 6; j++) // so go over the land's junctions(6)
            {
                if (this->_board->getLandAt(i)->getJunc()[j] != nullptr) // chack if not null
                {
                    if (this->_board->getLandAt(i)->getJunc()[j]->getis_occupate() == true) // if the junc is occupate(settelment\town)
                    {
                        if (this->_board->getLandAt(i)->getJunc()[j]->getSettelment() != nullptr) // if settelment
                        {
                            if (this->_board->getLandAt(i)->getJunc()[j]->getSettelment()->getPlayer()->getName() == this->getName()) // check if its my settelment
                            {
                                this->addCard(this->_board->getLandAt(i)->getCard()); // if yes- add a card to me
                            }
                            if (this->_board->getLandAt(i)->getJunc()[j]->getSettelment()->getPlayer()->getName() == this->_otherPlayers[0]->getName()) // same check for other players
                            {
                                this->_otherPlayers[0]->addCard(this->_board->getLandAt(i)->getCard());
                            }
                            if (this->_board->getLandAt(i)->getJunc()[j]->getSettelment()->getPlayer() == this->_otherPlayers[1])
                            {
                                this->_otherPlayers[1]->addCard(this->_board->getLandAt(i)->getCard());
                            }
                        }
                        if (this->_board->getLandAt(i)->getJunc()[j]->getTown() != nullptr) // if i have a town in this junction
                        {
                            if (this->_board->getLandAt(i)->getJunc()[j]->getTown()->getPlayer() == this) // it its belongs to me
                            {
                                this->add2Card(this->_board->getLandAt(i)->getCard()); // add 2 cards
                            }
                            if (this->_board->getLandAt(i)->getJunc()[j]->getTown()->getPlayer() == this->_otherPlayers[0]) // same check for other players
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
    return ans;
}

int catan::PlayerForTest::rollDiceFixed6()// this function will always return 6
{
    int ans = 6;
    for (int i = 0; i < 19; i++) // go over all the land in the board(19)
    {
        if (this->_board->getLandAt(i)->getLandNum() == ans) // if the land have the ans number on it
        {
            for (int j = 0; j < 6; j++) // so go over the land's junctions(6)
            {
                if (this->_board->getLandAt(i)->getJunc()[j] != nullptr) // chack if not null
                {
                    if (this->_board->getLandAt(i)->getJunc()[j]->getis_occupate() == true) // if the junc is occupate(settelment\town)
                    {
                        if (this->_board->getLandAt(i)->getJunc()[j]->getSettelment() != nullptr) // if settelment
                        {
                            if (this->_board->getLandAt(i)->getJunc()[j]->getSettelment()->getPlayer()->getName() == this->getName()) // check if its my settelment
                            {
                                this->addCard(this->_board->getLandAt(i)->getCard()); // if yes- add a card to me
                            }
                            if (this->_board->getLandAt(i)->getJunc()[j]->getSettelment()->getPlayer()->getName() == this->_otherPlayers[0]->getName()) // same check for other players
                            {
                                this->_otherPlayers[0]->addCard(this->_board->getLandAt(i)->getCard());
                            }
                            if (this->_board->getLandAt(i)->getJunc()[j]->getSettelment()->getPlayer() == this->_otherPlayers[1])
                            {
                                this->_otherPlayers[1]->addCard(this->_board->getLandAt(i)->getCard());
                            }
                        }
                        if (this->_board->getLandAt(i)->getJunc()[j]->getTown() != nullptr) // if i have a town in this junction
                        {
                            if (this->_board->getLandAt(i)->getJunc()[j]->getTown()->getPlayer() == this) // it its belongs to me
                            {
                                this->add2Card(this->_board->getLandAt(i)->getCard()); // add 2 cards
                            }
                            if (this->_board->getLandAt(i)->getJunc()[j]->getTown()->getPlayer() == this->_otherPlayers[0]) // same check for other players
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
    return ans;
}

int catan::PlayerForTest::rollDiceFixed7()// this function will always return 7
{
    int ans = 7;
    if (ans == 7) // if the result is 7
    {
        cout << "Players with more than 7 card need to get rid of half of the cards." << endl;
        throwCards(); // each player with more than 7 cards will randomly throw half of his cards.
    }
    return ans;
}

void catan::PlayerForTest::printCardAmount()
{
    for (const auto &card : this->_cards)
    {
        if (card.second != 0)
        {
            cout << card.first << " Amount: " << card.second << endl;
        }
    }
}

int catan::PlayerForTest::getNumOfCard()
{
    int ans = 0;
    for (auto &card : this->_cards)
    {
        ans += card.second;
    }
    return ans;
}

int catan::PlayerForTest::getNumOfDevCard()
{
    int amount= 0;
    for(auto devcard:this->_developmentCards){
        if(devcard.second>0){
            amount+=devcard.second;
        }
    }
    return amount;
}

void catan::PlayerForTest::giveResourceCardFree()
{
    // Iterate over each pair in the _cards map by reference, allowing modification
    for (auto &card : this->_cards)
    {
        card.second += 10; // Increase the value (resource count) of each card by 10
    }
}

void catan::PlayerForTest::buyMonopol()
{
    DevelopmentCard* c = new monopolDCard();
    this->_developmentCards[c]+=1;
    //delete c;
}

void catan::PlayerForTest::buyKnight()
{
    DevelopmentCard* c = new KnightDCard();
    this->_developmentCards[c]+=1;
}

void catan::PlayerForTest::buyYearOfPlenty()
{
    DevelopmentCard* c = new YearOfPlentyDCard();
    this->_developmentCards[c]+=1;
}

void catan::PlayerForTest::buybonusPoint()
{
    DevelopmentCard* c = new BonusPointDCard();
    this->_developmentCards[c]+=1;
}

void catan::PlayerForTest::buybuildRoaed()
{
    DevelopmentCard* c = new RoadDCard();
    this->_developmentCards[c]+=1;
}
