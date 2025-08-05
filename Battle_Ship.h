/* Murat Doruk Güneş – 2453272, Turab Erkin Akdeniz – 2452936
We read and accept the submission rules and the extra rules specified
in each question. This is our own work that is done by us only */

#ifndef ASSIGNMENT3_BATTLE_SHIP_H
#define ASSIGNMENT3_BATTLE_SHIP_H

class Battle_Ship{
protected:
    int size;
    int hits_to_destroy;
    int laser_bursts;
    bool sunk;
    int *coords;
public:
    Battle_Ship();
    Battle_Ship(int,int,int);
    virtual void printShip() = 0;
    virtual void setStatus(bool) = 0;
    virtual bool getStatus() = 0;    // to learn whether ship is alive or sunk.
    virtual int getSize() = 0;
    virtual int getLazerBurst() = 0;
    virtual void decrementHP() = 0;
    virtual int getHP() = 0;
};


class Star_Destroyer_Ship : public Battle_Ship{
private:


public:
    Star_Destroyer_Ship();
    void setStatus(bool)override;
    bool getStatus()override;
    void printShip()override;
    int getSize()override;
    int getLazerBurst()override;
    void decrementHP()override;
    int getHP()override;
};


class Mon_Calmari_Cruiser : public Battle_Ship{
private:


public:
    Mon_Calmari_Cruiser();
    void setStatus(bool)override;
    bool getStatus()override;
    void printShip()override;
    int getSize()override;
    int getLazerBurst()override;
    void decrementHP()override;
    int getHP()override;
};


class XWing_Squadron : public Battle_Ship{
private:


public:
    XWing_Squadron();
    void setStatus(bool)override;
    bool getStatus()override;
    void printShip()override;
    int getSize()override;
    int getLazerBurst()override;
    void decrementHP()override;
    int getHP()override;
};

class TIE_Fighter : public Battle_Ship{
private:


public:
    TIE_Fighter();
    void setStatus(bool)override;
    bool getStatus()override;
    void printShip()override;
    int getSize()override;
    int getLazerBurst()override;
    void decrementHP()override;
    int getHP()override;
};

#endif //ASSIGNMENT3_BATTLE_SHIP_H
