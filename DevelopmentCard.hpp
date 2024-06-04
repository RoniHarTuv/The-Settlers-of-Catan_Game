// // Mail: Roniharpaz1@gmail.com
// #ifndef DEVELOPMENT_CARD_HPP
// #define DEVELOPMENT_CARD_HPP
// #include <string>
// #include <iostream>
// using namespace std;
// namespace catan
// {
//     /**This class represents a development card. A development card is a virtual class since it is not necessary to create an object from it, but only from the classes inheriting from it.
//     Development cards are another object that a player can own and purchase during the game.
//     Details about the meaning of each card will be defined above its class.
//     **/
//     class DevelopmentCard
//     {
//     public:
//         DevelopmentCard() {}
//         virtual ~DevelopmentCard() {}
//         virtual int getQuantity() const = 0;
//         virtual DevelopmentCard *clone() const = 0;
//         virtual string getType() const = 0;
//     };
// //Monopol- When a player uses the monopol card, he decides on a random resource that he would like to receive from all the other participants
// //all the other participants are obliged to transfer this resource card to that player.
//     class monopolDCard : public DevelopmentCard
//     {
//     public:
//         monopolDCard() {}
//         int getQuantity() const override { return 100; }
//         DevelopmentCard *clone() const override { return new monopolDCard(*this); }
//         string getType() const override { return "monopol card"; }
//     };
// //This card grants a victory point to the player who received it
//     class BonusPointDCard : public DevelopmentCard
//     {
//     public:
//         BonusPointDCard() {}
//         int getQuantity() const override { return 4; }
//         DevelopmentCard *clone() const override { return new BonusPointDCard(*this); }
//         string getType() const override { return "bonus point card"; }
//     };
// //A player using the "Year of Plenty" card may choose 2 resource cards at will.
//     class YearOfPlentyDCard : public DevelopmentCard
//     {
//     public:
//         YearOfPlentyDCard() {}
//         int getQuantity() const override { return 100; }
//         DevelopmentCard *clone() const override { return new YearOfPlentyDCard(*this); }
//         std::string getType() const override { return "year of plenty card"; }
//     };
// //A road construction card user may place 2 road sections without paying for them.
//     class RoadDCard : public DevelopmentCard
//     {
//     public:
//         RoadDCard() {}
//         int getQuantity() const override { return 100; }
//         DevelopmentCard *clone() const override { return new RoadDCard(*this); }
//         string getType() const override { return "road card"; }
//     };
// //A player who holds 3 knight cards gets 2 victory points
//     class KnightDCard : public DevelopmentCard
//     {
//     public:
//         KnightDCard() {}
//         int getQuantity() const override { return 3; }
//         DevelopmentCard *clone() const override { return new KnightDCard(*this); }
//         string getType() const override { return "knight card"; }
//     };
// }

// #endif // DEVELOPMENT_CARD_HPP




























// Mail: Roniharpaz1@gmail.com
#ifndef DEVELOPMENT_CARD_HPP
#define DEVELOPMENT_CARD_HPP
#include <string>
using namespace std;

namespace catan
{
    /**
     * This class represents a development card. A development card is a virtual class 
     * since it is not necessary to create an object from it, but only from the classes 
     * inheriting from it.
     * Development cards are another object that a player can own and purchase during the game.
     * Details about the meaning of each card will be defined above its class.
     **/
    class DevelopmentCard
    {
    public:
        DevelopmentCard();
        virtual ~DevelopmentCard();
        virtual int getQuantity() const = 0;
        virtual DevelopmentCard *clone() const = 0;
        virtual string getType() const = 0;
    };

    /**
     * MonopolDCard - When a player uses the monopol card, he decides on a random resource 
     * that he would like to receive from all the other participants
     * all the other participants are obliged to transfer this resource card to that player.
     */
    class monopolDCard : public DevelopmentCard
    {
    public:
        monopolDCard();
        int getQuantity() const override;
        DevelopmentCard *clone() const override;
        string getType() const override;
    };

    /**
     * BonusPointDCard - This card grants a victory point to the player who received it.
     */
    class BonusPointDCard : public DevelopmentCard
    {
    public:
        BonusPointDCard();
        int getQuantity() const override;
        DevelopmentCard *clone() const override;
        string getType() const override;
    };

    /**
     * YearOfPlentyDCard - A player using the "Year of Plenty" card may choose 2 resource cards at will.
     */
    class YearOfPlentyDCard : public DevelopmentCard
    {
    public:
        YearOfPlentyDCard();
        int getQuantity() const override;
        DevelopmentCard *clone() const override;
        string getType() const override;
    };

    /**
     * RoadDCard - A road construction card user may place 2 road sections without paying for them.
     */
    class RoadDCard : public DevelopmentCard
    {
    public:
        RoadDCard();
        int getQuantity() const override;
        DevelopmentCard *clone() const override;
        string getType() const override;
    };

    /**
     * KnightDCard - A player who holds 3 knight cards gets 2 victory points.
     */
    class KnightDCard : public DevelopmentCard
    {
    public:
        KnightDCard();
        int getQuantity() const override;
        DevelopmentCard *clone() const override;
        string getType() const override;
    };
}

#endif // DEVELOPMENT_CARD_HPP
