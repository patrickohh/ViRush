/************************************************************************
** Program name:  Player Class Functions Declaration
** Author:        Patrick Oh
** Date:          06/11/19
** Description:   This file contains function declarations for the
**                Player class.
************************************************************************/
#ifndef FINAL_PLAYER_HPP
#define FINAL_PLAYER_HPP

#include "Inventory.hpp"

class Player
{
public:
    explicit Player(int);
    ~Player();
    int getHealth();
    Inventory* getInventory();
    void healthDecrease(int);
    void healthIncrease(int);
    void vialCountIncrease();
    int getVial();
    void setWin(int);
    int getWin();

private:
    int health;
    Inventory* bag;
    int vialCount;
    int winFlag;

};


#endif //FINAL_PLAYER_HPP
