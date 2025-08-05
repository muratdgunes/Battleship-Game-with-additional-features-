/* Murat Doruk Güneş – 2453272, Turab Erkin Akdeniz – 2452936
We read and accept the submission rules and the extra rules specified
in each question. This is our own work that is done by us only */

#include "Player.h"

Player::Player(char *n,int len,int wid): board1(len,wid), board2(len,wid){
    name = new char[strlen(n)+1];
    strcpy(name,n);


    if(len == 5){
        shipNum = 5;
        battleships = new Battle_Ship*[shipNum];

        battleships[0]=new Star_Destroyer_Ship();
        battleships[1]=new Mon_Calmari_Cruiser();
        battleships[2]=new XWing_Squadron();
        battleships[3]=new TIE_Fighter();
        battleships[4]=new TIE_Fighter();
    }

    else if(len == 8){
        shipNum = 10;
        battleships = new Battle_Ship*[shipNum];

        battleships[0]=new Star_Destroyer_Ship();
        battleships[1]=new Star_Destroyer_Ship();
        battleships[2]=new Mon_Calmari_Cruiser();
        battleships[3]=new Mon_Calmari_Cruiser();
        battleships[4]=new XWing_Squadron();
        battleships[5]=new XWing_Squadron();
        battleships[6]=new TIE_Fighter();
        battleships[7]=new TIE_Fighter();
        battleships[8]=new TIE_Fighter();
        battleships[9]=new TIE_Fighter();
    }

    else if(len == 10){
        shipNum = 13;
        battleships = new Battle_Ship*[shipNum];

        battleships[0]=new Star_Destroyer_Ship();
        battleships[1]=new Star_Destroyer_Ship();
        battleships[2]=new Star_Destroyer_Ship();
        battleships[3]=new Star_Destroyer_Ship();
        battleships[4]=new Mon_Calmari_Cruiser();
        battleships[5]=new Mon_Calmari_Cruiser();
        battleships[6]=new Mon_Calmari_Cruiser();
        battleships[7]=new XWing_Squadron();
        battleships[8]=new XWing_Squadron();
        battleships[9]=new TIE_Fighter();
        battleships[10]=new TIE_Fighter();
        battleships[11]=new TIE_Fighter();
        battleships[12]=new TIE_Fighter();
    }

}

Board Player::getBoard1() {
    return board1;
}


Board Player::getBoard2() {
    return board2;
}


void Player::printShips() {
    for(int i=0;i<board1.getLen();i++){
        battleships[i]->printShip();
    }
}

Player::~Player() {
    delete[] name;
    for(int i=0;i<shipNum;i++){
        delete battleships[i];
    }
    delete[] battleships;
}

char *Player::getName() {
    return name;
}




Battle_Ship& Player::getBattleships(int num) {
    return *battleships[num];
}


int Player::getshipNum() {
    return shipNum;
}



int Player::highestShooter() {
    int max=0;
    for(int i=0;i<shipNum;i++){
        if(battleships[i]->getStatus()==false){ // if ship is alive
            if (max < battleships[i]->getLazerBurst())
                max = battleships[i]->getLazerBurst();
        }
        else
            continue;
    }
    return max;
}

void Player::lostPrint(int n) {
    if(n==1)
        cout<<"Enemy TIE Fighter is sunk!"<<endl;
    else if(n==3)
        cout<<"Enemy X-WING Squadron is sunk!"<<endl;
    else if(n==4)
        cout<<"Enemy Mon Calmari Cruiser is sunk!"<<endl;
    else
        cout<<"Enemy Star Destroyer is sunk!"<<endl;
}

void Player::anotherlostPrint(int m) {
    if(m==1)
        cout<<"Another Enemy TIE Fighter is sunk!"<<endl;
    else if(m==3)
        cout<<"Another Enemy X-WING Squadron is sunk!"<<endl;
    else if(m==4)
        cout<<"Another Enemy Mon Calmari Cruiser is sunk!"<<endl;
    else
        cout<<"Another Enemy Star Destroyer is sunk!"<<endl;
}

int Player::rollDice() {
    int roll = rand() % 100 + 1; // 1–100 total distribution

    if (roll <= 10) {
        cout << "Gift #1: Add a new ship!\n\n";

        int shipRoll = rand() % 100 + 1;
        // ship distribution, it will return a specific value that will be processed in main.
        if (shipRoll <= 10) {
            cout << "  -> Star Destroyer (10%)\n\n";
            return 15;
        } else if (shipRoll <= 30) {
            cout << "  -> Mon Calamari Cruiser (20%)\n\n";
            return  14;
        } else if (shipRoll <= 60) {
            cout << "  -> X-Wing Squadron (30%)\n\n";
            return 13;  // 1 for gift #1, 3 for XWING
        } else {
            cout << "  -> TIE Fighter (40%)\n\n";
            return 11;  // gift number 1, TIE fighter
        }
        // remaining gifts
    } else if (roll <= 40) { // 11–40 = 30%
        cout << "Gift #2: One extra shot! (30%)\n\n";
        return 2;
    } else if (roll <= 60) { // 41–60 = 20%
        cout << "Gift #3: Enemy loses one shot next round. (20%)\n\n";
        return 3;
    } else if (roll <= 80) { // 61–80 = 20%
        cout << "Gift #4: Enemy can shoot only once next round. (20%)\n\n";
        return 4;
    } else { // 81–100 = 20%
        cout << "Gift #5: You get one more full round! (20%)\n\n";
        return 5;
    }
}


int Player::countShipType(int a) {  // if 'a' is 5, this will return number of active ships with size on specific player.
    int count=0;
    for(int i = 0;i<getshipNum();i++)
    {
        if(battleships[i]->getSize()==a && battleships[i]->getStatus()==0) // if alive and matches type increment count;
            count++;

    }
    return count;
}

int Player::loseCondition() {
    int count=0;
    for(int i = 0;i<getshipNum();i++)
    {
        if(battleships[i]->getStatus()==0) // if alive
            count++;

    }
    return count;
}

