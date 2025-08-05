/* Murat Doruk Güneş – 2453272, Turab Erkin Akdeniz – 2452936
We read and accept the submission rules and the extra rules specified
in each question. This is our own work that is done by us only */

#include "Battle_Ship.h"
#include <iostream>
using namespace std;

//////////////////////////////// START OF BATTLE SHIP
Battle_Ship::Battle_Ship() {
    size = 0;
    hits_to_destroy = 0;
    laser_bursts = 0;
    sunk = false;     // initially sunk = false, means ship is alive.

}

Battle_Ship::Battle_Ship(int s, int hp, int l) {
    size = s;
    hits_to_destroy = hp;
    laser_bursts = l;
    sunk = false;
}

int Battle_Ship::getSize() {return 0;}

void Battle_Ship::printShip() {

}

bool Battle_Ship::getStatus() {return 0;}

void Battle_Ship::setStatus(bool){}

void Battle_Ship::decrementHP() {}

//int Battle_Ship::getHP() {return 0;}



///----------------------------- END OF BATTLE SHIP


//////////////////////////////// START OF STAR DESTROYER
Star_Destroyer_Ship::Star_Destroyer_Ship() : Battle_Ship(5,4,3) {

}

void Star_Destroyer_Ship::printShip() {
    cout<<"Star Destroyer: "<<endl<<"Size: "<< size<<" | Hit Points: "<<hits_to_destroy;
    cout<<" | Laser bursts: "<<laser_bursts<<endl;
}

bool Star_Destroyer_Ship::getStatus() {
    return sunk;
}

int Star_Destroyer_Ship::getSize() {
    return size;
}

int Star_Destroyer_Ship::getLazerBurst() {
    return laser_bursts;
}

void Star_Destroyer_Ship::setStatus(bool a) {
    sunk = a;
}

void Star_Destroyer_Ship::decrementHP() {
    if (hits_to_destroy<=0)
        hits_to_destroy=0;
    else
        hits_to_destroy--;

    if(hits_to_destroy==0)
        sunk = true;
}

int Star_Destroyer_Ship::getHP() {
    return hits_to_destroy;
}



///------------------------------- END OF STAR DESTROYER SHIP


//////////////////////////////// START OF MON CALMARI CRUISER
Mon_Calmari_Cruiser::Mon_Calmari_Cruiser() : Battle_Ship(4,3,4) {

}

bool Mon_Calmari_Cruiser::getStatus() {
    return sunk;
}

void Mon_Calmari_Cruiser::printShip() {
    cout<<"Mon Calmari Cruiser: "<<endl<<"Size: "<< size<<" | Hit Points: "<<hits_to_destroy;
    cout<<" | Laser bursts: "<<laser_bursts<<endl;
}


int Mon_Calmari_Cruiser::getSize() {
    return size;
}

int Mon_Calmari_Cruiser::getLazerBurst() {
    return laser_bursts;
}

void Mon_Calmari_Cruiser::setStatus(bool a) {
    sunk = a;
}

void Mon_Calmari_Cruiser::decrementHP() {
    if (hits_to_destroy<=0)
        hits_to_destroy=0;
    else
        hits_to_destroy--;

    if(hits_to_destroy==0)
        sunk = true;
}

int Mon_Calmari_Cruiser::getHP() {
    return hits_to_destroy;
}



///-------------------------------- END OF MON CALMARI CRUISER


//////////////////////////////// START OF X-WING SQUADRON
XWing_Squadron::XWing_Squadron() : Battle_Ship(3,2,2){

}

bool XWing_Squadron::getStatus() {
    return sunk;
}


void XWing_Squadron::printShip() {
    cout<<"XWing Squadron: "<<endl<<"Size: "<< size<<" | Hit Points: "<<hits_to_destroy;
    cout<<" | Laser bursts: "<<laser_bursts<<endl;
}

int XWing_Squadron::getSize() {
    return size;
}

int XWing_Squadron::getLazerBurst() {
    return laser_bursts;
}

void XWing_Squadron::setStatus(bool a) {
    sunk = a;
}

void XWing_Squadron::decrementHP() {
    if (hits_to_destroy<=0)
        hits_to_destroy=0;
    else
        hits_to_destroy--;

    if(hits_to_destroy==0)
        sunk = true;
}

int XWing_Squadron::getHP() {
    return hits_to_destroy;
}


///------------------------------ END OF X-WING SQUADRON


//////////////////////////////// START OF TIE FIGHTER
TIE_Fighter::TIE_Fighter() : Battle_Ship(1,1,1){

}

bool TIE_Fighter::getStatus() {
    return sunk;
}

void TIE_Fighter::printShip() {
    cout<<"TIE Fighter: "<<endl<<"Size: "<< size<<" | Hit Points: "<<hits_to_destroy;
    cout<<" | Laser bursts: "<<laser_bursts<<endl;
}

int TIE_Fighter::getSize() {
    return size;
}

int TIE_Fighter::getLazerBurst() {
    return laser_bursts;
}

void TIE_Fighter::setStatus(bool a) {
    sunk = a;
}

void TIE_Fighter::decrementHP() {
    if (hits_to_destroy<=0)
        hits_to_destroy=0;
    else
        hits_to_destroy--;

    if(hits_to_destroy==0)
        sunk = true;
}

int TIE_Fighter::getHP() {
    return hits_to_destroy;
}


///-------------------------------- END OF TIE FIGHTER