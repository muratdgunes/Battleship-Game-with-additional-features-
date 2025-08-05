/* Murat Doruk Güneş – 2453272, Turab Erkin Akdeniz – 2452936
We read and accept the submission rules and the extra rules specified
in each question. This is our own work that is done by us only */

/* In this assignment we contributed equally. We coded together by using "code with me" feature.
 * And also when we did not use this feature we coded together in one computer. And we think we contributed equally.*/

#include <cstring>
#include <iostream>
using namespace std;
#include <ctime>
#include "Battle_Ship.h"
#include "Player.h"
#include "Board.h"

int main() {
    srand(time(nullptr));
    char player1name[25];
    char player2name[25];
    int op;
    cout<<"Welcome to the GALACTIC NCC STAR WARS BATTLE"<<endl;
    cout<<"Game modes are;"<<endl<<"1- The Swiftstrike (5x8)"<<endl;
    cout<<"2- The Starlight Clash (8x10)"<<endl<<"3- Wrath of Titans (10x12)"<<endl;
    cout<<"Which game mode you would like to play?";
    cin>>op;

    cout<<"Enter the name of Player 1 ->";
    cin>>player1name;
    cout<<"Enter the name of Player 2 ->";
    cin>>player2name;
    Player *p1;
    Player *p2;

    if(op == 1){
        p1 = new Player(player1name,5,8);
        p2 = new Player(player2name,5,8);

        p1->getBoard1().initializeBoard();
        p1->getBoard2().initializeBoard();

        p2->getBoard1().initializeBoard();
        p2->getBoard2().initializeBoard();
    }

    else if(op == 2){
        p1 = new Player(player1name,8,10);
        p2 = new Player(player2name,8,10);

        p1->getBoard1().initializeBoard();
        p1->getBoard2().initializeBoard();

        p2->getBoard1().initializeBoard();
        p2->getBoard2().initializeBoard();
    }

    else{
        p1 = new Player(player1name,10,12);
        p2 = new Player(player2name,12,10);

        p1->getBoard1().initializeBoard();
        p1->getBoard2().initializeBoard();

        p2->getBoard1().initializeBoard();
        p2->getBoard2().initializeBoard();
    }

    // Board initialisation is completed here.

    int flag;
    flag = rand()%2;
    //flag =1;

    if (flag == 0) {
        char a,b,c,d,e;
        int a1,b1,c1,d1,e1;
        int shipNumber = p1->getshipNum();
        cout << p1->getName() << " will start placing ships first!" << endl;
        cout<<"Place your ships"<<endl;
        for(int x = 0;x<shipNumber;x++){
            p1->getBattleships(x).printShip();
            p1->getBoard1().printBoard();
            cout<<"Please enter in format (a1 b1 c1 ...)"<<endl;
            if(p1->getBattleships(x).getSize() == 5){
                cin>> a>>a1>> b>>b1>> c>>c1>> d>>d1>> e>>e1;
                p1->getBoard1().placeShip(a,a1,b,b1,c,c1,d,d1,e,e1);
            }

            else if(p1->getBattleships(x).getSize() == 4){
                cin>> a>>a1>> b>>b1>> c>>c1>> d>>d1;
                p1->getBoard1().placeShip(a,a1,b,b1,c,c1,d,d1);
            }

            else if(p1->getBattleships(x).getSize() == 3){
                cin>> a>>a1>> b>>b1>> c>>c1;
                p1->getBoard1().placeShip(a,a1,b,b1,c,c1);
            }

            else{
                cin>> a>>a1;
                p1->getBoard1().placeShip(a,a1);
            }
        }
        p1->getBoard1().printBoard();

        cout<<p1->getName()<<", you successfully distributed your ships. Enter any button to hide your ships";
        cin>>a;
        cout<<". . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . ."<<endl;
        cout<<". . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . ."<<endl;
        cout<<". . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . ."<<endl;
        cout<<". . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . ."<<endl;
        cout<<". . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . ."<<endl;
        cout<<". . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . ."<<endl;
        cout<<". . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . ."<<endl;
        cout<<". . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . ."<<endl;
        cout<<". . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . ."<<endl;
        cout << p2->getName() << " will start placing ships now!" << endl;
        cout<<"Place your ships"<<endl;
        for(int x = 0;x<shipNumber;x++){
            p2->getBattleships(x).printShip();
            p2->getBoard1().printBoard();
            cout<<"Please enter in format (a1 b1 c1 ...)"<<endl;
            if(p2->getBattleships(x).getSize() == 5){
                cin>> a>>a1>> b>>b1>> c>>c1>> d>>d1>> e>>e1;
                p2->getBoard1().placeShip(a,a1,b,b1,c,c1,d,d1,e,e1);
            }

            else if(p2->getBattleships(x).getSize() == 4){
                cin>> a>>a1>> b>>b1>> c>>c1>> d>>d1;
                p2->getBoard1().placeShip(a,a1,b,b1,c,c1,d,d1);
            }

            else if(p2->getBattleships(x).getSize() == 3){
                cin>> a>>a1>> b>>b1>> c>>c1;
                p2->getBoard1().placeShip(a,a1,b,b1,c,c1);
            }

            else{
                cin>> a>>a1;
                p2->getBoard1().placeShip(a,a1);
            }
            p2->getBoard1().printBoard();
        }
        cout<<p2->getName()<<", you successfully distributed your ships. Enter any button to hide your ships";
        cin>>a;
    }  // end of if statement.

    else{
        char a,b,c,d,e;
        int a1,b1,c1,d1,e1;
        int shipNumber = p2->getshipNum();
        cout << p2->getName() << " will start placing ships first!" << endl;
        cout<<"Place your ships"<<endl;
        for(int x = 0;x<shipNumber;x++){
            p2->getBattleships(x).printShip();
            p2->getBoard1().printBoard();
            cout<<"Please enter in format (a1 b1 c1 ...)"<<endl;

            if(p2->getBattleships(x).getSize() == 5){
                cin>> a>>a1>> b>>b1>> c>>c1>> d>>d1>> e>>e1;
                p2->getBoard1().placeShip(a,a1,b,b1,c,c1,d,d1,e,e1);
            }

            else if(p2->getBattleships(x).getSize() == 4){
                cin>> a>>a1>> b>>b1>> c>>c1>> d>>d1;
                p2->getBoard1().placeShip(a,a1,b,b1,c,c1,d,d1);
            }

            else if(p2->getBattleships(x).getSize() == 3){
                cin>> a>>a1>> b>>b1>> c>>c1;
                p2->getBoard1().placeShip(a,a1,b,b1,c,c1);
            }

            else{
                cin>> a>>a1;
                p2->getBoard1().placeShip(a,a1);
            }
        }
        p2->getBoard1().printBoard();

        cout<<p2->getName()<<", you successfully distributed your ships. Enter any button to hide your ships";
        cin>>a;
        cout<<". . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . ."<<endl;
        cout<<". . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . ."<<endl;
        cout<<". . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . ."<<endl;
        cout<<". . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . ."<<endl;
        cout<<". . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . ."<<endl;
        cout<<". . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . ."<<endl;
        cout<<". . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . ."<<endl;
        cout<<". . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . ."<<endl;
        cout<<". . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . ."<<endl;
        cout << p1->getName() << " will start placing ships now!" << endl;
        cout<<"Place your ships"<<endl;
        for(int x = 0;x<p1->getshipNum();x++){
            p1->getBattleships(x).printShip();
            p1->getBoard1().printBoard();
            cout<<"Please enter in format (a1 b1 c1 ...)"<<endl;
            if(p1->getBattleships(x).getSize() == 5){
                cin>> a>>a1>> b>>b1>> c>>c1>> d>>d1>> e>>e1;
                p1->getBoard1().placeShip(a,a1,b,b1,c,c1,d,d1,e,e1);
            }

            else if(p1->getBattleships(x).getSize() == 4){
                cin>> a>>a1>> b>>b1>> c>>c1>> d>>d1;
                p1->getBoard1().placeShip(a,a1,b,b1,c,c1,d,d1);
            }

            else if(p1->getBattleships(x).getSize() == 3){
                cin>> a>>a1>> b>>b1>> c>>c1;
                p1->getBoard1().placeShip(a,a1,b,b1,c,c1);
            }

            else{
                cin>> a>>a1;
                p1->getBoard1().placeShip(a,a1);
            }
            p1->getBoard1().printBoard();
        }
        cout<<p1->getName()<<", you successfully distributed your ships. Enter any button to hide your ships";
        cin>>a;
    } // end of else statement.

    cout<<". . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . ."<<endl;
    cout<<". . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . ."<<endl;
    cout<<". . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . ."<<endl;
    cout<<". . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . ."<<endl;
    cout<<". . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . ."<<endl;
    cout<<". . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . ."<<endl;
    cout<<". . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . ."<<endl;
    cout<<". . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . ."<<endl;
    cout<<". . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . ."<<endl;
    cout<<". . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . ."<<endl;
    cout<<". . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . ."<<endl;
    cout<<". . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . ."<<endl;
    cout<<". . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . ."<<endl;
    cout<<". . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . ."<<endl;
    cout<<". . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . ."<<endl;
    cout<<". . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . ."<<endl;
    cout<<". . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . ."<<endl;
    cout<<"Game will start now"<<endl<<endl;
    int first_turn=0;
    char temp;
    int player1_ones=0,player1_threes=0,player1_fours=0,player1_fives=0;
    int player2_ones=0,player2_threes=0,player2_fours=0,player2_fives=0;
    int p1_lost_TIE=0,p1_lost_XWING=0,p1_lost_MonCal=0,p1_lost_Star=0;
    int p2_lost_TIE=0,p2_lost_XWING=0,p2_lost_MonCal=0,p2_lost_Star=0;
    int hit_p1=0,hit_p2=0,miss_p1=0,miss_p2=0;
    int lost=0,anotherLost=0;
    int p1hitRound=0,p2hitRound=0;
    int restrictionP2=0,restrictionP1=0;
    int antiFlag = 0;
    while(1) {
        char a;
        int b;
        /// PLAYER 1 SHOOTS HERE
        if (flag == 0) {    // if-else conditions to make it turn based.;
            if (first_turn==0){
                cout<<"Player 1: "<<p1->getName()<<" will start first, press any button to start!";
                cin>>temp;
                first_turn=1;// set first turn as 1 so that it will not be called again.
            }
            else {
                cout << "Are you ready ? Player 1:" << p1->getName() << " Enter any button to start";
                cin>>temp;
            }
            for(int i=p1->highestShooter();i>0;i--) {

                if(restrictionP1 == 1){ // if player 1 won gifts that restrict shooting, then come here.
                    i = 1;                 // this will cause player 2 to shoot just once.
                    restrictionP1 = 0;
                }

                if(restrictionP1==99){  // this will cause player 2 to shoot one less.
                    i--;
                    restrictionP1 = 0;
                }

                cout << endl << "You can shoot " << i << " times. Chose wisely" << endl;
                cout << "Your Board" << endl;
                p1->getBoard1().printBoard();

                cout << "Enemy Board" << endl;
                p1->getBoard2().printBoard();
                cout << "Please enter in format (a1 b1 c1 ...)" << endl;
                cin >> a >> b;
                temp = p1->getBoard1().getCharVal(a); // just to convert character to integer value. (Ex: a1 -> 0 1)
                char result = p2->getBoard1().hit_or_miss(b - 1, temp); // this will return hit value, if missed->0, if hit-> size value of the ship;
                if (result != 0) { // if hit
                    p1->getBoard2().setBoardWithIndex(b - 1, temp, result); // set player 1, board 2 with hit info.
                    p2->getBoard1().setBoardWithIndex(b - 1, temp, '*');  // set player 2, board 1 with '*'. Means that opponent shot that tile.
                    hit_p1++;
                    p1hitRound++;
                }
                else {
                    p1->getBoard2().setBoardWithIndex(b - 1, temp, '0'); // set player 1, board 2 with miss info.
                    p2->getBoard1().setBoardWithIndex(b - 1, temp, '*'); // set player 2, board 1 with '*' symbol, means that opponent shot that tile.
                    miss_p1++;
                }


                if (op==1) {
                    if (result-'0' == 1){   // char result will be integer value after I subtract '0'
                        player2_ones++;
                        if(player2_ones==1) {
                            p2->getBattleships(3).decrementHP(); // first size 1 ship is sunk now
                            if(p2->getBattleships(3).getStatus()==true) {

                                p2_lost_TIE++;
                                lost = 1;
                            }
                        }
                        else if(player2_ones==2) {
                            p2->getBattleships(4).decrementHP(); // second size 1 ship is sunk now
                            if(p2->getBattleships(4).getStatus()==true) {

                                p2_lost_TIE++;
                                anotherLost = 1;
                            }
                        }   // until this part, default ship number (no gifts) is processed. If they are sunk edit status.
                        else{   // if gifted ship is TIE ship, I will manage information here. I think assumption of 5 gifted TIE is fair.
                            if(player2_ones==3 || player2_ones==4|| player2_ones==5 || player2_ones==6 || player2_ones==7){

                                p2_lost_TIE++;
                                anotherLost = 1;
                            }
                        }
                    }   // lost TIE fighter logic on game mode 1.


                    else if (result-'0' == 3){  // char result will be integer value after I subtract '0'
                        player2_threes++;
                        if(player2_threes == 1 || player2_threes == 2) {
                            p2->getBattleships(2).decrementHP();  // if hit 2 times, then ship is sunk. edited inside decrementHP
                            if (p2->getBattleships(2).getStatus() == true) {

                                p2_lost_XWING++;
                                lost = 3;
                            }
                        }   // until this part, default ship number (no gifts) is processed. If they are sunk edit status.
                        else{   // if gifted ship is XWING, I will manage information here. Assumption of 4 gifted XWINGs is relatively fair.
                            if(player2_threes == 4 || player2_threes == 6 || player2_threes == 8 || player2_threes == 10){

                                p2_lost_XWING++;
                                anotherLost = 3;
                            }
                        }
                    }   // lost XWING logic on game mode 1.

                    else if (result-'0' == 4){  // char result will be integer value after I subtract '0'
                        player2_fours++;
                        if(player2_fours == 1 || player2_fours == 2 || player2_fours == 3) {
                            p2->getBattleships(1).decrementHP();  // if hit 3 times, then ship is sunk. edited inside decrementHP
                            if (p2->getBattleships(1).getStatus() == true) {

                                p2_lost_MonCal++;
                                lost = 4;
                            }
                        }// until this part, default ship number (no gifts) is processed. If they are sunk edit status.
                        else{// if gifted ship is Mon calmari, I will manage information here. Assumption of 4 gifted mon calmaris is relatively fair.
                            if(player2_fours == 6 || player2_fours == 9 || player2_fours == 12 || player2_fours == 15){

                                p2_lost_MonCal++;
                                anotherLost = 4;
                            }
                        }
                    }

                    else if (result-'0' == 5){  // char result will be integer value after I subtract '0'
                        player2_fives++;
                        if(player2_fives==1 || player2_fives==2 || player2_fives==3 || player2_fives==4) {
                            p2->getBattleships(0).decrementHP(); // if hit 4 times, then ship is sunk. edited inside decrementHP
                            if (p2->getBattleships(0).getStatus() == true) {

                                p2_lost_Star++;
                                lost = 5;
                            }
                        }// until this part, default ship number (no gifts) is processed. If they are sunk edit status.
                        else{// if gifted ship is Star destroyer, I will manage information here. Assumption of 3 gifted star destroyers is relatively fair.
                            if(player2_fives == 8 || player2_fives == 12 || player2_fives == 16){

                                p2_lost_Star++;
                                anotherLost = 5;
                            }
                        }
                    }

                    else
                        cout << endl;
                }                       // end of sinking ships for battle mode 1.
                else if(op ==2){
                    if (result-'0' == 1){   // char result will be integer value after I subtract '0'
                        player2_ones++;
                        if(player2_ones==1) {
                            p2->getBattleships(6).decrementHP(); // first size 1 ship is sunk now
                            if(p2->getBattleships(6).getStatus()==true) {

                                p2_lost_TIE++;
                                lost = 1;
                            }
                        }
                        else if(player2_ones==2) {
                            p2->getBattleships(7).decrementHP(); // second size 1 ship is sunk now
                            if(p2->getBattleships(7).getStatus()==true) {

                                p2_lost_TIE++;
                                anotherLost = 1;
                            }
                        }
                        else if(player2_ones==3) {
                            p2->getBattleships(8).decrementHP(); // second size 1 ship is sunk now
                            if(p2->getBattleships(8).getStatus()==true) {

                                p2_lost_TIE++;
                                anotherLost = 1;
                            }
                        }
                        else if(player2_ones==4) {
                            p2->getBattleships(9).decrementHP(); // second size 1 ship is sunk now
                            if(p2->getBattleships(9).getStatus()==true) {

                                p2_lost_TIE++;
                                anotherLost = 1;
                            }
                        }// until this part default number of TIE fighters are managed. Game mode = 2.
                        else {  // this part is for gift management. If gifted ship is TIE fighter and this ship is shot, we will come here.

                            p2_lost_TIE++;
                            anotherLost = 1;
                        }

                    }   // lost TIE part

                    else if (result-'0' == 3){  // char result will be integer value after I subtract '0'
                        player2_threes++;
                        if(player2_threes==1 || player2_threes==2){
                            p2->getBattleships(4).decrementHP();  // if hit 2 times, then ship is sunk. edited inside decrementHP
                            if(p2->getBattleships(4).getStatus()==true) {

                                p2_lost_XWING++;
                                lost = 3;
                            }
                        }
                        else if(player2_threes==3 || player2_threes==4){
                            p2->getBattleships(5).decrementHP();  // if hit 2 times, then ship is sunk. edited inside decrementHP
                            if(p2->getBattleships(5).getStatus()==true) {

                                p2_lost_XWING++;
                                anotherLost = 3;
                            }
                        }// until this part default number of XWINGS are managed. No gifts. Game mode = 2.
                        else{ // this part is for gift management. If gifted ship is XWING and this ship is shot, we will come here.
                            if(player2_threes==6 || player2_threes==8 || player2_threes==10){

                                p2_lost_XWING++;
                                anotherLost = 3;
                            }
                        }
                    }   // lost xwing part.

                    else if (result-'0' == 4){  // char result will be integer value after I subtract '0'
                        player2_fours++;
                        if(player2_fours==1 || player2_fours==2 || player2_fours==3){
                            p2->getBattleships(2).decrementHP();  // if hit 3 times, then ship is sunk. edited inside decrementHP
                            if(p2->getBattleships(2).getStatus()==true) {

                                p2_lost_MonCal++;
                                lost = 4;
                            }
                        }
                        else if(player2_fours==4 || player2_fours==5 || player2_fours==6 ){
                            p2->getBattleships(3).decrementHP();  // if hit 3 times, then ship is sunk. edited inside decrementHP
                            if(p2->getBattleships(3).getStatus()==true) {

                                p2_lost_MonCal++;
                                anotherLost = 4;
                            }
                        }// until this part default number of mon calmaris are managed. No gifts. Game mode = 2.
                        else{// this part is for gift management. If gifted ship is mon calmari and this ship is shot, we will come here.
                            if(player2_fours==9 || player2_fours==12 || player2_fours==15){

                                p2_lost_MonCal++;
                                anotherLost = 4;
                            }
                        }
                    }   // lost mon calmari part.

                    else if (result-'0' == 5){  // char result will be integer value after I subtract '0'
                        player2_fives++;
                        if(player2_fives==1 || player2_fives==2 || player2_fives==3 || player2_fives==4){
                            p2->getBattleships(0).decrementHP();  // if hit 2 times, then ship is sunk. edited inside decrementHP
                            if(p2->getBattleships(0).getStatus()==true) {

                                p2_lost_Star++;
                                lost = 5;
                            }
                        }
                        else if(player2_fives==5 || player2_fives==6 || player2_fives==7 || player2_fives==8){
                            p2->getBattleships(1).decrementHP();  // if hit 2 times, then ship is sunk. edited inside decrementHP
                            if(p2->getBattleships(1).getStatus()==true) {

                                p2_lost_Star++;
                                anotherLost = 5;
                            }
                        }// until this part default number of Star destroyers are managed. No gifts. Game mode = 2.
                        else{   // this part is for gift management. If gifted ship is star destoyer and this ship is shot, we will come here.
                            if(player2_fives==12 || player2_fives==16 || player2_fives==20){

                                p2_lost_Star++;
                                anotherLost = 5;
                            }
                        }
                    } // lost Star destroyer part.
                }

                else { // op == 3.
                    if (result - '0' == 1) {   // char result will be integer value after I subtract '0'
                        player2_ones++;
                        if (player2_ones == 1) {
                            p2->getBattleships(9).decrementHP(); // first size 1 ship is sunk now
                            if (p2->getBattleships(9).getStatus() == true) {

                                p2_lost_TIE++;
                                lost = 1;
                            }
                        } else if (player2_ones == 2) {
                            p2->getBattleships(10).decrementHP(); // second size 1 ship is sunk now
                            if (p2->getBattleships(10).getStatus() == true) {

                                p2_lost_TIE++;
                                anotherLost = 1;
                            }
                        } else if (player2_ones == 3) {
                            p2->getBattleships(11).decrementHP(); // second size 1 ship is sunk now
                            if (p2->getBattleships(11).getStatus() == true) {

                                p2_lost_TIE++;
                                anotherLost = 1;
                            }
                        } else if (player2_ones == 4) {
                            p2->getBattleships(12).decrementHP(); // second size 1 ship is sunk now
                            if (p2->getBattleships(12).getStatus() == true) {

                                p2_lost_TIE++;
                                anotherLost = 1;
                            }
                        }// until this part default number of TIE fighters are managed. Game mode = 3.
                        else {  // this part is for gift management. If gifted ship is TIE fighter and this ship is shot, we will come here.

                            p2_lost_TIE++;
                            anotherLost = 1;
                        }
                    }// end of game mode = 3, Lost TIE Fighter logic

                    else if (result-'0' == 3){  // char result will be integer value after I subtract '0'
                        player2_threes++;
                        if(player2_threes==1 || player2_threes==2){
                            p2->getBattleships(7).decrementHP();  // if hit 2 times, then ship is sunk. edited inside decrementHP
                            if(p2->getBattleships(7).getStatus()==true) {

                                p2_lost_XWING++;
                                lost = 3;
                            }
                        }
                        else if(player2_threes==3 || player2_threes==4){
                            p2->getBattleships(8).decrementHP();  // if hit 2 times, then ship is sunk. edited inside decrementHP
                            if(p2->getBattleships(8).getStatus()==true) {

                                p2_lost_XWING++;
                                anotherLost = 3;
                            }
                        }// until this part default number of XWINGS are managed. No gifts. Game mode = 3.
                        else{ // this part is for gift management. If gifted ship is XWING and this ship is shot, we will come here.
                            if(player2_threes==6 || player2_threes==8 || player2_threes==10){

                                p2_lost_XWING++;
                                anotherLost = 3;
                            }
                        }
                    }  // end of lost XWING Squadron logic, game mode = 3.

                    else if (result-'0' == 4){  // char result will be integer value after I subtract '0'
                        player2_fours++;
                        if(player2_fours==1 || player2_fours==2 || player2_fours==3){
                            p2->getBattleships(4).decrementHP();  // if hit 3 times, then ship is sunk. edited inside decrementHP
                            if(p2->getBattleships(4).getStatus()==true) {

                                p2_lost_MonCal++;
                                lost = 4;
                            }
                        }
                        else if(player2_fours==4 || player2_fours==5 || player2_fours==6 ){
                            p2->getBattleships(5).decrementHP();  // if hit 3 times, then ship is sunk. edited inside decrementHP
                            if(p2->getBattleships(5).getStatus()==true) {

                                p2_lost_MonCal++;
                                anotherLost = 4;
                            }
                        }// until this part default number of mon calmaris are managed. No gifts. Game mode = 3.
                        else if(player2_fours==7 || player2_fours==8 || player2_fours==9 ){
                            p2->getBattleships(6).decrementHP();  // if hit 3 times, then ship is sunk. edited inside decrementHP
                            if(p2->getBattleships(6).getStatus()==true) {

                                p2_lost_MonCal++;
                                anotherLost = 4;
                            }
                        }// until this part default number of mon calmaris are managed. No gifts. Game mode = 3.
                        else{// this part is for gift management. If gifted ship is mon calmari and this ship is shot, we will come here.
                            if(player2_fours==12 || player2_fours==15 || player2_fours==18){

                                p2_lost_MonCal++;
                                anotherLost = 4;
                            }
                        }
                    }   // lost mon calmari part.

                    else if (result-'0' == 5){  // char result will be integer value after I subtract '0'
                        player2_fives++;
                        if(player2_fives==1 || player2_fives==2 || player2_fives==3 || player2_fives==4){
                            p2->getBattleships(0).decrementHP();  // if hit 2 times, then ship is sunk. edited inside decrementHP
                            if(p2->getBattleships(0).getStatus()==true) {

                                p2_lost_Star++;
                                lost = 5;
                            }
                        }
                        else if(player2_fives==5 || player2_fives==6 || player2_fives==7 || player2_fives==8){
                            p2->getBattleships(1).decrementHP();  // if hit 2 times, then ship is sunk. edited inside decrementHP
                            if(p2->getBattleships(1).getStatus()==true) {

                                p2_lost_Star++;
                                anotherLost = 5;
                            }
                        }
                        else if(player2_fives==9 || player2_fives==10 || player2_fives==11 || player2_fives==12){
                            p2->getBattleships(2).decrementHP();  // if hit 2 times, then ship is sunk. edited inside decrementHP
                            if(p2->getBattleships(2).getStatus()==true) {

                                p2_lost_Star++;
                                anotherLost = 5;
                            }
                        }
                        else if(player2_fives==13 || player2_fives==14 || player2_fives==15 || player2_fives==16){
                            p2->getBattleships(3).decrementHP();  // if hit 2 times, then ship is sunk. edited inside decrementHP
                            if(p2->getBattleships(3).getStatus()==true) {

                                p2_lost_Star++;
                                anotherLost = 5;
                            }
                        }// until this part default number of Star destroyers are managed. No gifts. Game mode = 3.
                        else{   // this part is for gift management. If gifted ship is star destoyer and this ship is shot, we will come here.
                            if(player2_fives==20 || player2_fives==24 || player2_fives==28){

                                p2_lost_Star++;
                                anotherLost = 5;
                            }
                        }
                    } // lost Star destroyer part.
                } /// END OF LOST SHIPS LOGIC
/////////////////////////////////////////////////////////////////////


                cout << "Your Board" << endl;
                p1->getBoard1().printBoard();

                cout << "Enemy Board" << endl;
                p1->getBoard2().printBoard();

                if(lost != 0) {
                    p1->lostPrint(lost);    // just for printing lost ship
                    lost = 0;
                }
                if(anotherLost != 0){
                    p1->anotherlostPrint(anotherLost);  // for printing lost ship. p1 , p2 does not matter.
                    anotherLost = 0;
                }
            }

            /// GIFT DISTRIBUTION SYSTEM
            if(p1hitRound>1) {  // if hit more than one times
                cout << "Player 1: " << p1->getName() << ", " << p1hitRound
                     << " of your shots were successful. Rolling the dice for your gift gift!!!"<<endl;
                int gift = p1->rollDice();  // roll a die

                if(gift == 11){ // gifted TIE fighter
                    char x;
                    int x1;
                    cout<<"Your Board: "<<endl;
                    p1->getBoard1().printBoard();
                    cout<<"Place your new TIE Fighter!"<<endl<<endl;
                    cout<<"Enter in format (a1...)"<<endl;
                    cin>>x>>x1;
                    p1->getBoard1().placeShip(x,x1);
                    cout<<"Your new board is:"<<endl;
                    p1->getBoard1().printBoard();
                }

                else if(gift == 13){    // gifted XWING
                    char x,y,z;
                    int x1,y1,z1;
                    cout<<"Your Board: "<<endl;
                    p1->getBoard1().printBoard();
                    cout<<"Place your new X-WING Squadron"<<endl<<endl;
                    cout<<"Enter in format (a1 a2 a3...)"<<endl;
                    cin>>x>>x1 >>y>>y1>> z>>z1;
                    p1->getBoard1().placeShip(x,x1,y,y1,z,z1);
                    cout<<"Your new board is:"<<endl;
                    p1->getBoard1().printBoard();
                }

                else if(gift == 14){    // gifted Mon calmari
                    char x,y,z,q;
                    int x1,y1,z1,q1;
                    cout<<"Your Board: "<<endl;
                    p1->getBoard1().printBoard();
                    cout<<"Place your new Mon Calmari Cruiser"<<endl<<endl;
                    cout<<"Enter in format (a1 a2 a3 a4...)"<<endl;
                    cin>>x>>x1 >>y>>y1>> z>>z1>> q>>q1;
                    p1->getBoard1().placeShip(x,x1,y,y1,z,z1,q,q1);
                    cout<<"Your new board is:"<<endl;
                    p1->getBoard1().printBoard();
                }
                else if(gift == 15){    // gifted star destroyer
                    char x,y,z,q,v;
                    int x1,y1,z1,q1,v1;
                    cout<<"Your Board: "<<endl;
                    p1->getBoard1().printBoard();
                    cout<<"Place your new Star Destroyer"<<endl<<endl;
                    cout<<"Enter in format (a1 a2 a3 a4...)"<<endl;
                    cin>>x>>x1 >>y>>y1>> z>>z1>> q>>q1>> v>>v1;
                    p1->getBoard1().placeShip(x,x1,y,y1,z,z1,q,q1,v,v1);
                    cout<<"Your new board is:"<<endl;
                    p1->getBoard1().printBoard();
                }

                else if(gift == 2){ // gifted one more shooting
                    cout << endl << "You can shoot one more time. Chose wisely" << endl;
                    cout << "Your Board" << endl;
                    p1->getBoard1().printBoard();

                    cout << "Enemy Board" << endl;
                    p1->getBoard2().printBoard();
                    cout << "Please enter in format (a1...)" << endl;
                    cin >> a >> b;
                    temp = p1->getBoard1().getCharVal(a); // just to convert character to integer value. (Ex: a1 -> 0 1)
                    char result = p2->getBoard1().hit_or_miss(b - 1, temp); // this will return hit value, if missed->0, if hit-> size value of the ship;
                    if (result != 0) { // if hit
                        p1->getBoard2().setBoardWithIndex(b - 1, temp, result); // set player 1, board 2 with hit info.
                        p2->getBoard1().setBoardWithIndex(b - 1, temp, '*');  // set player 2, board 1 with '*'. Means that opponent shot that tile.
                        hit_p1++;
                    }
                    else {
                        p1->getBoard2().setBoardWithIndex(b - 1, temp, '0'); // set player 1, board 2 with miss info.
                        p2->getBoard1().setBoardWithIndex(b - 1, temp, '*'); // set player 2, board 1 with '*' symbol, means that opponent shot that tile.
                        miss_p1++;
                    }

                    cout<<"Your Board: "<<endl;
                    p1->getBoard1().printBoard();
                    cout<<"Enemy Board: "<<endl;
                    p1->getBoard2().printBoard();
                }

                else if(gift == 3)  // gifted decrement enemy shoot by one
                {
                    restrictionP2 = 99; // I will check this when enemy player shoots.
                }
                else if(gift == 4)
                {
                    restrictionP2 = 1;
                }
                else
                {
                    antiFlag = 1;
                }

            }




            cout<<endl;
            cout<<"Player 1: "<<p1->getName()<<"                  Player 2: "<<p2->getName()<<endl;
            cout<<"Total Shoots: "<<miss_p1+hit_p1<<"                  Total Shoots: "<<miss_p2+hit_p2<<endl;
            cout<<"Hits: "<<hit_p1<<"                          Hits: "<<hit_p2<<endl;
            cout<<"Misses: "<<miss_p1<<"                        Misses: "<<miss_p2<<endl;
            cout<<"Lost: "<<miss_p2+hit_p2<<"                          Lost: "<<miss_p1+hit_p1<<endl;
            if(op==1){
                cout<<"Lost Star Destroyer(1): "<<p1_lost_Star<<"        Lost Star Destroyer(1): "<<p2_lost_Star<<endl;
                cout<<"Lost Mon Calmari Cruiser(1): "<<p1_lost_MonCal<<"   Lost Mon Calmari Cruiser(1): "<<p2_lost_MonCal<<endl;
                cout<<"Lost X-WING Squadron(1): "<<p1_lost_XWING<<"       Lost X-WING Squadron(1): "<<p2_lost_XWING<<endl;
                cout<<"Lost TIE Fighter(2): "<<p1_lost_TIE<<"           Lost TIE Fighter(2): "<<p2_lost_TIE<<endl;
            }
            else if(op==2){
                cout<<"Lost Star Destroyer(2): "<<p1_lost_Star<<"        Lost Star Destroyer(2): "<<p2_lost_Star<<endl;
                cout<<"Lost Mon Calmari Cruiser(2): "<<p1_lost_MonCal<<"   Lost Mon Calmari Cruiser(2): "<<p2_lost_MonCal<<endl;
                cout<<"Lost X-WING Squadron(2): "<<p1_lost_XWING<<"       Lost X-WING Squadron(2): "<<p2_lost_XWING<<endl;
                cout<<"Lost TIE Fighter(4): "<<p1_lost_TIE<<"           Lost TIE Fighter(4): "<<p2_lost_TIE<<endl;
            }
            else{
                cout<<"Lost Star Destroyer(4): "<<p1_lost_Star<<"        Lost Star Destroyer(4): "<<p2_lost_Star<<endl;
                cout<<"Lost Mon Calmari Cruiser(3): "<<p1_lost_MonCal<<"   Lost Mon Calmari Cruiser(3): "<<p2_lost_MonCal<<endl;
                cout<<"Lost X-WING Squadron(2): "<<p1_lost_XWING<<"       Lost X-WING Squadron(2): "<<p2_lost_XWING<<endl;
                cout<<"Lost TIE Fighter(4): "<<p1_lost_TIE<<"           Lost TIE Fighter(4): "<<p2_lost_TIE<<endl;
            }
            cout<<endl;

            if(p2->loseCondition()==0){ // if alive ships is 0.
                cout<<"Player 2 lost all of their battleships. Player 1 WON!!!!!!!!!!!"<<endl;
                break;
            }


            cout<<"Player 1: "<<p1->getName()<<", you are out of shots. Enter any button to hide your board.";
            cin>>temp;
            cout<<". . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . ."<<endl;
            cout<<". . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . ."<<endl;
            cout<<". . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . ."<<endl;
            cout<<". . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . ."<<endl;
            cout<<". . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . ."<<endl;
            cout<<". . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . ."<<endl;
            cout<<". . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . ."<<endl;
            cout<<". . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . ."<<endl;
            cout<<". . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . ."<<endl;
            cout<<". . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . ."<<endl;
            cout<<". . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . ."<<endl;
            cout<<". . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . ."<<endl;
            cout<<". . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . ."<<endl;
            cout<<". . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . ."<<endl;

            p1hitRound = 0;
            if (antiFlag==1){   // if gifted one more round, then dont change flag, so that this player will play one more round.
                flag = 0;
                antiFlag = 0;
            }
            else
            {
                flag = 1;   // now other player will play
            }
        }




        /// PLAYER 2 SHOOTS HERE.
        else {      // if-else conditions to make it turn based.
            if (first_turn==0){
                cout<<"Player 2: "<<p2->getName()<<" will start first, press any button to start!";
                cin>>temp;
                first_turn=1; // set first turn as 1 so that it will not be called again.
            }
            else {
                cout << "Are you ready ? Player 2:" << p2->getName() << " Enter any button to start";
                cin>>temp;
            }

            for(int i=p2->highestShooter();i>0;i--) {

                if(restrictionP2 == 1){ // if player 1 won gifts that restrict shooting, then come here.
                    i = 1;                 // this will cause player 2 to shoot just once.
                    restrictionP2 = 0;
                }

                if(restrictionP2==99){  // this will cause player 2 to shoot one less.
                    i--;
                    restrictionP2 = 0;
                }

                cout << endl << "You can shoot " << i << " times. Chose wisely" << endl;
                cout << "Your Board" << endl;
                p2->getBoard1().printBoard();

                cout << "Enemy Board" << endl;
                p2->getBoard2().printBoard();
                cout << "Please enter in format (a1 b1 c1 ...)" << endl;
                cin >> a >> b;
                temp = p2->getBoard1().getCharVal(a); // just to convert character to integer value. (Ex: a1 -> 0 1) ( a will become 0 in this case )
                char result = p1->getBoard1().hit_or_miss(b - 1, temp); // this will return hit value, if missed->0, if hit-> size value of the ship;

                if (result != 0) { // if hit
                    p2->getBoard2().setBoardWithIndex(b - 1, temp, result); // set player 2, board 2 with hit info.
                    p1->getBoard1().setBoardWithIndex(b - 1, temp, '*');  // set player 1, board 1 with '*'. Means that opponent shot that tile.
                    hit_p2++;
                    p2hitRound++;
                }
                else{
                    p2->getBoard2().setBoardWithIndex(b - 1, temp, '0'); // set player 2, board 2 with miss info.
                    p1->getBoard1().setBoardWithIndex(b - 1, temp, '*'); // set player 1, board 1 with '*'. Means that opponent shot that tile.
                    miss_p2++;
                }

                if (op==1) {
                    if (result-'0' == 1){   // char result will be integer value after I subtract '0'
                        player1_ones++;
                        if(player1_ones==1) {
                            p1->getBattleships(3).decrementHP(); // first size 1 ship is sunk now
                            if(p1->getBattleships(3).getStatus()==true) {

                                p1_lost_TIE++;
                                lost = 1;
                            }
                        }
                        else if(player1_ones==2) {
                            p1->getBattleships(4).decrementHP(); // second size 1 ship is sunk now
                            if(p1->getBattleships(4).getStatus()==true) {

                                p1_lost_TIE++;
                                anotherLost = 1;
                            }
                        }   // until this part, default ship number (no gifts) is processed. If they are sunk edit status.
                        else{   // if gifted ship is TIE ship, I will manage information here. I think assumption of 5 gifted TIE is fair.
                            if(player1_ones==3 || player1_ones==4|| player1_ones==5 || player1_ones==6 || player1_ones==7){

                                p1_lost_TIE++;
                                anotherLost = 1;
                            }
                        }
                    }   // lost TIE fighter logic on game mode 1.


                    else if (result-'0' == 3){  // char result will be integer value after I subtract '0'
                            player1_threes++;
                            if(player1_threes == 1 || player1_threes == 2) {
                                p1->getBattleships(2).decrementHP();  // if hit 2 times, then ship is sunk. edited inside decrementHP
                                if (p1->getBattleships(2).getStatus() == true) {

                                    p1_lost_XWING++;
                                    lost = 3;
                                }
                            }   // until this part, default ship number (no gifts) is processed. If they are sunk edit status.
                            else{   // if gifted ship is XWING, I will manage information here. Assumption of 4 gifted XWINGs is relatively fair.
                                if(player1_threes == 4 || player1_threes == 6 || player1_threes == 8 || player1_threes == 10){

                                    p1_lost_XWING++;
                                    anotherLost = 3;
                                }
                            }
                    }   // lost XWING logic on game mode 1.

                    else if (result-'0' == 4){  // char result will be integer value after I subtract '0'
                        player1_fours++;
                        if(player1_fours == 1 || player1_fours == 2 || player1_fours == 3) {
                            p1->getBattleships(1).decrementHP();  // if hit 3 times, then ship is sunk. edited inside decrementHP
                            if (p1->getBattleships(1).getStatus() == true) {

                                p1_lost_MonCal++;
                                lost = 4;
                            }
                        }// until this part, default ship number (no gifts) is processed. If they are sunk edit status.
                        else{// if gifted ship is Mon calmari, I will manage information here. Assumption of 4 gifted mon calmaris is relatively fair.
                            if(player1_fours == 6 || player1_fours == 9 || player1_fours == 12 || player1_fours == 15){

                                p1_lost_MonCal++;
                                anotherLost = 4;
                            }
                        }
                    }

                    else if (result-'0' == 5){  // char result will be integer value after I subtract '0'
                        player1_fives++;
                        if(player1_fives==1 || player1_fives==2 || player1_fives==3 || player1_fives==4) {
                            p1->getBattleships(0).decrementHP(); // if hit 4 times, then ship is sunk. edited inside decrementHP
                            if (p1->getBattleships(0).getStatus() == true) {

                                p1_lost_Star++;
                                lost = 5;
                            }
                        }// until this part, default ship number (no gifts) is processed. If they are sunk edit status.
                        else{// if gifted ship is Star destroyer, I will manage information here. Assumption of 3 gifted star destroyers is relatively fair.
                            if(player1_fives == 8 || player1_fives == 12 || player1_fives == 16){

                                p1_lost_Star++;
                                anotherLost = 5;
                            }
                        }
                    }

                    else
                        cout << endl;
                }                       // end of sinking ships for battle mode 1.
                else if(op ==2){
                    if (result-'0' == 1){   // char result will be integer value after I subtract '0'
                        player1_ones++;
                        if(player1_ones==1) {
                            p1->getBattleships(6).decrementHP(); // first size 1 ship is sunk now
                            if(p1->getBattleships(6).getStatus()==true) {

                                p1_lost_TIE++;
                                lost = 1;
                            }
                        }
                        else if(player1_ones==2) {
                            p1->getBattleships(7).decrementHP(); // second size 1 ship is sunk now
                            if(p1->getBattleships(7).getStatus()==true) {

                                p1_lost_TIE++;
                                anotherLost = 1;
                            }
                        }
                        else if(player1_ones==3) {
                            p1->getBattleships(8).decrementHP(); // second size 1 ship is sunk now
                            if(p1->getBattleships(8).getStatus()==true) {

                                p1_lost_TIE++;
                                anotherLost = 1;
                            }
                        }
                        else if(player1_ones==4) {
                            p1->getBattleships(9).decrementHP(); // second size 1 ship is sunk now
                            if(p1->getBattleships(9).getStatus()==true) {

                                p1_lost_TIE++;
                                anotherLost = 1;
                            }
                        }// until this part default number of TIE fighters are managed. Game mode = 2.
                        else {  // this part is for gift management. If gifted ship is TIE fighter and this ship is shot, we will come here.

                            p1_lost_TIE++;
                            anotherLost = 1;
                        }

                    }   // lost TIE part

                    else if (result-'0' == 3){  // char result will be integer value after I subtract '0'
                        player1_threes++;
                        if(player1_threes==1 || player1_threes==2){
                            p1->getBattleships(4).decrementHP();  // if hit 2 times, then ship is sunk. edited inside decrementHP
                            if(p1->getBattleships(4).getStatus()==true) {

                                p1_lost_XWING++;
                                lost = 3;
                            }
                        }
                        else if(player1_threes==3 || player1_threes==4){
                            p1->getBattleships(5).decrementHP();  // if hit 2 times, then ship is sunk. edited inside decrementHP
                            if(p1->getBattleships(5).getStatus()==true) {

                                p1_lost_XWING++;
                                anotherLost = 3;
                            }
                        }// until this part default number of XWINGS are managed. No gifts. Game mode = 2.
                        else{ // this part is for gift management. If gifted ship is XWING and this ship is shot, we will come here.
                            if(player1_threes==6 || player1_threes==8 || player1_threes==10){

                                p1_lost_XWING++;
                                anotherLost = 3;
                            }
                        }
                    }   // lost xwing part.

                    else if (result-'0' == 4){  // char result will be integer value after I subtract '0'
                        player1_fours++;
                        if(player1_fours==1 || player1_fours==2 || player1_fours==3){
                            p1->getBattleships(2).decrementHP();  // if hit 3 times, then ship is sunk. edited inside decrementHP
                            if(p1->getBattleships(2).getStatus()==true) {

                                p1_lost_MonCal++;
                                lost = 4;
                            }
                        }
                        else if(player1_fours==4 || player1_fours==5 || player1_fours==6 ){
                            p1->getBattleships(3).decrementHP();  // if hit 3 times, then ship is sunk. edited inside decrementHP
                            if(p1->getBattleships(3).getStatus()==true) {

                                p1_lost_MonCal++;
                                anotherLost = 4;
                            }
                        }// until this part default number of mon calmaris are managed. No gifts. Game mode = 2.
                        else{// this part is for gift management. If gifted ship is mon calmari and this ship is shot, we will come here.
                            if(player1_fours==9 || player1_fours==12 || player1_fours==15){

                                p1_lost_MonCal++;
                                anotherLost = 4;
                            }
                        }
                    }   // lost mon calmari part.

                    else if (result-'0' == 5){  // char result will be integer value after I subtract '0'
                        player1_fives++;
                        if(player1_fives==1 || player1_fives==2 || player1_fives==3 || player1_fives==4){
                            p1->getBattleships(0).decrementHP();  // if hit 2 times, then ship is sunk. edited inside decrementHP
                            if(p1->getBattleships(0).getStatus()==true) {

                                p1_lost_Star++;
                                lost = 5;
                            }
                        }
                        else if(player1_fives==5 || player1_fives==6 || player1_fives==7 || player1_fives==8){
                            p1->getBattleships(1).decrementHP();  // if hit 2 times, then ship is sunk. edited inside decrementHP
                            if(p1->getBattleships(1).getStatus()==true) {

                                p1_lost_Star++;
                                anotherLost = 5;
                            }
                        }// until this part default number of Star destroyers are managed. No gifts. Game mode = 2.
                        else{   // this part is for gift management. If gifted ship is star destoyer and this ship is shot, we will come here.
                            if(player1_fives==12 || player1_fives==16 || player1_fives==20){

                                p1_lost_Star++;
                                anotherLost = 5;
                            }
                        }
                    } // lost Star destroyer part.
                }

                else { // op == 3.
                    if (result - '0' == 1) {   // char result will be integer value after I subtract '0'
                        player1_ones++;
                        if (player1_ones == 1) {
                            p1->getBattleships(9).decrementHP(); // first size 1 ship is sunk now
                            if (p1->getBattleships(9).getStatus() == true) {

                                p1_lost_TIE++;
                                lost = 1;
                            }
                        } else if (player1_ones == 2) {
                            p1->getBattleships(10).decrementHP(); // second size 1 ship is sunk now
                            if (p1->getBattleships(10).getStatus() == true) {

                                p1_lost_TIE++;
                                anotherLost = 1;
                            }
                        } else if (player1_ones == 3) {
                            p1->getBattleships(11).decrementHP(); // second size 1 ship is sunk now
                            if (p1->getBattleships(11).getStatus() == true) {

                                p1_lost_TIE++;
                                anotherLost = 1;
                            }
                        } else if (player1_ones == 4) {
                            p1->getBattleships(12).decrementHP(); // second size 1 ship is sunk now
                            if (p1->getBattleships(12).getStatus() == true) {

                                p1_lost_TIE++;
                                anotherLost = 1;
                            }
                        }// until this part default number of TIE fighters are managed. Game mode = 3.
                        else {  // this part is for gift management. If gifted ship is TIE fighter and this ship is shot, we will come here.

                            p1_lost_TIE++;
                            anotherLost = 1;
                        }
                    }// end of game mode = 3, Lost TIE Fighter logic

                    else if (result-'0' == 3){  // char result will be integer value after I subtract '0'
                        player1_threes++;
                        if(player1_threes==1 || player1_threes==2){
                            p1->getBattleships(7).decrementHP();  // if hit 2 times, then ship is sunk. edited inside decrementHP
                            if(p1->getBattleships(7).getStatus()==true) {

                                p1_lost_XWING++;
                                lost = 3;
                            }
                        }
                        else if(player1_threes==3 || player1_threes==4){
                            p1->getBattleships(8).decrementHP();  // if hit 2 times, then ship is sunk. edited inside decrementHP
                            if(p1->getBattleships(8).getStatus()==true) {

                                p1_lost_XWING++;
                                anotherLost = 3;
                            }
                        }// until this part default number of XWINGS are managed. No gifts. Game mode = 3.
                        else{ // this part is for gift management. If gifted ship is XWING and this ship is shot, we will come here.
                            if(player1_threes==6 || player1_threes==8 || player1_threes==10){

                                p1_lost_XWING++;
                                anotherLost = 3;
                            }
                        }
                    }  // end of lost XWING Squadron logic, game mode = 3.

                    else if (result-'0' == 4){  // char result will be integer value after I subtract '0'
                        player1_fours++;
                        if(player1_fours==1 || player1_fours==2 || player1_fours==3){
                            p1->getBattleships(4).decrementHP();  // if hit 3 times, then ship is sunk. edited inside decrementHP
                            if(p1->getBattleships(4).getStatus()==true) {

                                p1_lost_MonCal++;
                                lost = 4;
                            }
                        }
                        else if(player1_fours==4 || player1_fours==5 || player1_fours==6 ){
                            p1->getBattleships(5).decrementHP();  // if hit 3 times, then ship is sunk. edited inside decrementHP
                            if(p1->getBattleships(5).getStatus()==true) {

                                p1_lost_MonCal++;
                                anotherLost = 4;
                            }
                        }// until this part default number of mon calmaris are managed. No gifts. Game mode = 3.
                        else if(player1_fours==7 || player1_fours==8 || player1_fours==9 ){
                            p1->getBattleships(6).decrementHP();  // if hit 3 times, then ship is sunk. edited inside decrementHP
                            if(p1->getBattleships(6).getStatus()==true) {

                                p1_lost_MonCal++;
                                anotherLost = 4;
                            }
                        }// until this part default number of mon calmaris are managed. No gifts. Game mode = 3.
                        else{// this part is for gift management. If gifted ship is mon calmari and this ship is shot, we will come here.
                            if(player1_fours==12 || player1_fours==15 || player1_fours==18){

                                p1_lost_MonCal++;
                                anotherLost = 4;
                            }
                        }
                    }   // lost mon calmari part.

                    else if (result-'0' == 5){  // char result will be integer value after I subtract '0'
                        player1_fives++;
                        if(player1_fives==1 || player1_fives==2 || player1_fives==3 || player1_fives==4){
                            p1->getBattleships(0).decrementHP();  // if hit 2 times, then ship is sunk. edited inside decrementHP
                            if(p1->getBattleships(0).getStatus()==true) {

                                p1_lost_Star++;
                                lost = 5;
                            }
                        }
                        else if(player1_fives==5 || player1_fives==6 || player1_fives==7 || player1_fives==8){
                            p1->getBattleships(1).decrementHP();  // if hit 2 times, then ship is sunk. edited inside decrementHP
                            if(p1->getBattleships(1).getStatus()==true) {

                                p1_lost_Star++;
                                anotherLost = 5;
                            }
                        }
                        else if(player1_fives==9 || player1_fives==10 || player1_fives==11 || player1_fives==12){
                            p1->getBattleships(2).decrementHP();  // if hit 2 times, then ship is sunk. edited inside decrementHP
                            if(p1->getBattleships(2).getStatus()==true) {

                                p1_lost_Star++;
                                anotherLost = 5;
                            }
                        }
                        else if(player1_fives==13 || player1_fives==14 || player1_fives==15 || player1_fives==16){
                            p1->getBattleships(3).decrementHP();  // if hit 2 times, then ship is sunk. edited inside decrementHP
                            if(p1->getBattleships(3).getStatus()==true) {

                                p1_lost_Star++;
                                anotherLost = 5;
                            }
                        }// until this part default number of Star destroyers are managed. No gifts. Game mode = 3.
                        else{   // this part is for gift management. If gifted ship is star destoyer and this ship is shot, we will come here.
                            if(player1_fives==20 || player1_fives==24 || player1_fives==28){

                                p1_lost_Star++;
                                anotherLost = 5;
                            }
                        }
                    } // lost Star destroyer part.
                } /// END OF LOST SHIPS LOGIC
/////////////////////////////////////////////////////////////////////


                cout << "Your Board" << endl;
                p2->getBoard1().printBoard();

                cout << "Enemy Board" << endl;
                p2->getBoard2().printBoard();

                if(lost != 0) {
                    p1->lostPrint(lost);    // just for printing lost ship
                    lost = 0;
                }
                if(anotherLost != 0){
                    p1->anotherlostPrint(anotherLost);  // for printing lost ship. p1 , p2 does not matter.
                    anotherLost = 0;
                }
            }

            /// GIFT DISTRIBUTION SYSTEM
            if(p2hitRound>1) {  // if hit more than one times
                cout << "Player 2: " << p2->getName() << ", " << p2hitRound
                     << " of your shots were successful. Rolling the dice for your gift gift!!!"<<endl;
                int gift = p2->rollDice();  // roll a die

                if(gift == 11){ // gifted TIE fighter
                    char x;
                    int x1;
                    cout<<"Your Board: "<<endl;
                    p2->getBoard1().printBoard();
                    cout<<"Place your new TIE Fighter!"<<endl<<endl;
                    cout<<"Enter in format (a1...)"<<endl;
                    cin>>x>>x1;
                    p2->getBoard1().placeShip(x,x1);
                    cout<<"Your new board is:"<<endl;
                    p2->getBoard1().printBoard();
                }

                else if(gift == 13){    // gifted XWING
                    char x,y,z;
                    int x1,y1,z1;
                    cout<<"Your Board: "<<endl;
                    p2->getBoard1().printBoard();
                    cout<<"Place your new X-WING Squadron"<<endl<<endl;
                    cout<<"Enter in format (a1 a2 a3...)"<<endl;
                    cin>>x>>x1 >>y>>y1>> z>>z1;
                    p2->getBoard1().placeShip(x,x1,y,y1,z,z1);
                    cout<<"Your new board is:"<<endl;
                    p2->getBoard1().printBoard();
                }

                else if(gift == 14){    // gifted Mon calmari
                    char x,y,z,q;
                    int x1,y1,z1,q1;
                    cout<<"Your Board: "<<endl;
                    p2->getBoard1().printBoard();
                    cout<<"Place your new Mon Calmari Cruiser"<<endl<<endl;
                    cout<<"Enter in format (a1 a2 a3 a4...)"<<endl;
                    cin>>x>>x1 >>y>>y1>> z>>z1>> q>>q1;
                    p2->getBoard1().placeShip(x,x1,y,y1,z,z1,q,q1);
                    cout<<"Your new board is:"<<endl;
                    p2->getBoard1().printBoard();
                }
                else if(gift == 15){    // gifted star destroyer
                    char x,y,z,q,v;
                    int x1,y1,z1,q1,v1;
                    cout<<"Your Board: "<<endl;
                    p2->getBoard1().printBoard();
                    cout<<"Place your new Star Destroyer"<<endl<<endl;
                    cout<<"Enter in format (a1 a2 a3 a4...)"<<endl;
                    cin>>x>>x1 >>y>>y1>> z>>z1>> q>>q1>> v>>v1;
                    p2->getBoard1().placeShip(x,x1,y,y1,z,z1,q,q1,v,v1);
                    cout<<"Your new board is:"<<endl;
                    p2->getBoard1().printBoard();
                }

                else if(gift == 2){ // gifted one more shooting
                    cout << endl << "You can shoot one more time. Chose wisely" << endl;
                    cout << "Your Board" << endl;
                    p2->getBoard1().printBoard();

                    cout << "Enemy Board" << endl;
                    p2->getBoard2().printBoard();
                    cout << "Please enter in format (a1...)" << endl;
                    cin >> a >> b;
                    temp = p1->getBoard1().getCharVal(a); // just to convert character to integer value. (Ex: a1 -> 0 1)
                    char result = p1->getBoard1().hit_or_miss(b - 1, temp); // this will return hit value, if missed->0, if hit-> size value of the ship;
                    if (result != 0) { // if hit
                        p2->getBoard2().setBoardWithIndex(b - 1, temp, result); // set player 2, board 2 with hit info.
                        p1->getBoard1().setBoardWithIndex(b - 1, temp, '*');  // set player 1, board 1 with '*'. Means that opponent shot that tile.
                        hit_p2++;
                    }
                    else {
                        p2->getBoard2().setBoardWithIndex(b - 1, temp, '0'); // set player 2, board 2 with miss info.
                        p1->getBoard1().setBoardWithIndex(b - 1, temp, '*'); // set player 1, board 1 with '*' symbol, means that opponent shot that tile.
                        miss_p2++;
                    }
                    cout<<"Your Board: "<<endl;
                    p2->getBoard1().printBoard();
                    cout<<"Enemy Board: "<<endl;
                    p2->getBoard2().printBoard();
                }

                else if(gift == 3)  // gifted decrement enemy shoot by one
                {
                    restrictionP1 = 99; // I will check this when enemy player shoots.
                }
                else if(gift == 4)  // gift 4, enemy will shoot just once next round.
                {
                    restrictionP1 = 1;
                }
                else       // gift 5, one more round.
                {
                    antiFlag = 1;
                }
            }



            cout<<endl;
            cout<<"Player 1: "<<p1->getName()<<"                  Player 2: "<<p2->getName()<<endl;
            cout<<"Total Shoots: "<<miss_p1+hit_p1<<"                  Total Shoots: "<<miss_p2+hit_p2<<endl;
            cout<<"Hits: "<<hit_p1<<"                          Hits: "<<hit_p2<<endl;
            cout<<"Misses: "<<miss_p1<<"                        Misses: "<<miss_p2<<endl;
            cout<<"Lost: "<<miss_p2+hit_p2<<"                          Lost: "<<miss_p1+hit_p1<<endl;
            if(op==1){
                cout<<"Lost Star Destroyer(1): "<<p1_lost_Star<<"        Lost Star Destroyer(1): "<<p2_lost_Star<<endl;
                cout<<"Lost Mon Calmari Cruiser(1): "<<p1_lost_MonCal<<"   Lost Mon Calmari Cruiser(1): "<<p2_lost_MonCal<<endl;
                cout<<"Lost X-WING Squadron(1): "<<p1_lost_XWING<<"       Lost X-WING Squadron(1): "<<p2_lost_XWING<<endl;
                cout<<"Lost TIE Fighter(2): "<<p1_lost_TIE<<"           Lost TIE Fighter(2): "<<p2_lost_TIE<<endl;
            }
            else if(op==2){
                cout<<"Lost Star Destroyer(2): "<<p1_lost_Star<<"        Lost Star Destroyer(2): "<<p2_lost_Star<<endl;
                cout<<"Lost Mon Calmari Cruiser(2): "<<p1_lost_MonCal<<"   Lost Mon Calmari Cruiser(2): "<<p2_lost_MonCal<<endl;
                cout<<"Lost X-WING Squadron(2): "<<p1_lost_XWING<<"       Lost X-WING Squadron(2): "<<p2_lost_XWING<<endl;
                cout<<"Lost TIE Fighter(4): "<<p1_lost_TIE<<"           Lost TIE Fighter(4): "<<p2_lost_TIE<<endl;
            }
            else{
                cout<<"Lost Star Destroyer(4): "<<p1_lost_Star<<"        Lost Star Destroyer(4): "<<p2_lost_Star<<endl;
                cout<<"Lost Mon Calmari Cruiser(3): "<<p1_lost_MonCal<<"   Lost Mon Calmari Cruiser(3): "<<p2_lost_MonCal<<endl;
                cout<<"Lost X-WING Squadron(2): "<<p1_lost_XWING<<"       Lost X-WING Squadron(2): "<<p2_lost_XWING<<endl;
                cout<<"Lost TIE Fighter(4): "<<p1_lost_TIE<<"           Lost TIE Fighter(4): "<<p2_lost_TIE<<endl;
            }
            cout<<endl;

            if(p1->loseCondition()==0){ // if alive ships is 0.
                cout<<"Player 1 lost all of their battleships. Player 2 WON!!!!!!!!!!!"<<endl;
                break;
            }


            cout<<"Player 2: "<<p2->getName()<<", you are out of shots. Enter any button to hide your board.";
            cin>>temp;
            cout<<". . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . ."<<endl;
            cout<<". . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . ."<<endl;
            cout<<". . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . ."<<endl;
            cout<<". . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . ."<<endl;
            cout<<". . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . ."<<endl;
            cout<<". . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . ."<<endl;
            cout<<". . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . ."<<endl;
            cout<<". . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . ."<<endl;
            cout<<". . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . ."<<endl;
            cout<<". . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . ."<<endl;
            cout<<". . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . ."<<endl;
            cout<<". . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . ."<<endl;
            cout<<". . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . ."<<endl;
            cout<<". . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . ."<<endl;

            p2hitRound = 0;
            if (antiFlag==1){   // if gifted one more round, then dont change flag, so that this player will play one more round.
                flag = 1;
                antiFlag = 0;
            }

            else{
                flag = 0;   // now other player will play
            }

        }
    }





    return 0;
}
