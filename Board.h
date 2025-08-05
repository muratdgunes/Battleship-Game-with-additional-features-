/* Murat Doruk Güneş – 2453272, Turab Erkin Akdeniz – 2452936
We read and accept the submission rules and the extra rules specified
in each question. This is our own work that is done by us only */

#ifndef ASSIGNMENT3_BOARD_H
#define ASSIGNMENT3_BOARD_H

#include<iostream>
using namespace std;


class Board {
private:
    int width;
    int length;

    char **board;

public:
    Board(int,int);
    void initializeBoard();
    void printBoard();
    void hitBoard(int,int);
    int getCharVal(char);
    void placeShip(char,int,char,int,char,int,char,int,char,int);
    void placeShip(char,int,char,int,char,int,char,int);
    void placeShip(char,int,char,int,char,int);
    void placeShip(char,int);
    int getLen();
    int hit_or_miss(int,int);
    void setBoardWithIndex(int,int,char);
};

#endif //ASSIGNMENT3_BOARD_H
