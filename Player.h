/* Murat Doruk Güneş – 2453272, Turab Erkin Akdeniz – 2452936
We read and accept the submission rules and the extra rules specified
in each question. This is our own work that is done by us only */

#ifndef ASSIGNMENT3_PLAYER_H
#define ASSIGNMENT3_PLAYER_H
#include <cstring>
#include "Battle_Ship.h"
#include "Board.h"


class Player{
private:
    char* name;
    Battle_Ship **battleships;
    int shipNum;
    Board board1;
    Board board2;

public:
    //Player();
    Player(char*,int,int);
    ~Player();
    Board getBoard1();
    Board getBoard2();
    char* getName();
    int getshipNum();
    int highestShooter();
    Battle_Ship& getBattleships(int);
    void printShips();
    void lostPrint(int);
    void anotherlostPrint(int);
    int rollDice();
    int countShipType(int);
    int loseCondition();
};

#endif //ASSIGNMENT3_PLAYER_H
