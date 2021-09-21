/************************************************************************
** Program name:  Player Class Functions Definitions
** Author:        Patrick Oh
** Date:          06/11/19
** Description:   This file contains the function definitions for the
**                player class.
************************************************************************/
#include "Player.hpp"
#include "Inventory.hpp"

/*****************************************************************
** Description: Constructor for object of player
**              class.
*****************************************************************/
Player::Player(int health)
{
    this -> health = health;

    bag = new Inventory;

    bag -> setMaxLoad(10);

    vialCount = 0;

    winFlag = 0;
}

/*****************************************************************
** Description: Destructor for player object. Deletes inventory
**              object.
*****************************************************************/
Player::~Player()
{
    delete bag;
}

/*****************************************************************
** Description: Getter function that returns health points of
**              player.
*****************************************************************/
int Player::getHealth()
{
    return health;
}

/*****************************************************************
** Description: Getter function that returns inventory of
**              player.
*****************************************************************/
Inventory* Player::getInventory()
{
    return bag;
}


/*****************************************************************
** Description: Function that decreases player's health.
*****************************************************************/
void Player::healthDecrease(int decrease)
{
    this -> health -= decrease;
}


/*****************************************************************
** Description: Function that increases player's health.
*****************************************************************/
void Player::healthIncrease(int increase)
{
    this -> health += increase;
}


/*****************************************************************
** Description: Function that increases vial count for player.
*****************************************************************/
void Player::vialCountIncrease()
{
    vialCount++;
}


/*****************************************************************
** Description: Getter function that returns number of vials
**              player owns.
*****************************************************************/
int Player::getVial()
{
    return vialCount;
}


/*****************************************************************
** Description: Setter for win flag variable in game.
*****************************************************************/
void Player::setWin(int win)
{
    winFlag = win;
}


/*****************************************************************
** Description: Getter function that returns flag variable that
**              keeps track if player won the game or not.
*****************************************************************/
int Player::getWin()
{
    return winFlag;
}
