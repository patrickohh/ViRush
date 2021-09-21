/************************************************************************
** Program name:  Space Class Functions
** Author:        Patrick Oh
** Date:          06/11/19
** Description:   This file contains the function definitions of the
**                space room class which is a parent class of all the
**                rooms in the game.
************************************************************************/
#include <iostream>
#include <string>
#include "Space.hpp"
#include "Player.hpp"
#include "Item.hpp"
#include "Menu.hpp"
using std::string;
using std::cout;
using std::endl;

/*****************************************************************
** Description: Constructor for object of space object
**              class.
*****************************************************************/
Space::Space(Player* playerPtr)
{
    visits = 0;
    setPlayer(player);
    setName(name);
    up = nullptr;
    down = nullptr;
    left = nullptr;
    right = nullptr;
}

/*****************************************************************
** Description: Destructor for space object.
*****************************************************************/
Space::~Space()
{

}

/*****************************************************************
** Description: Setter for top pointer in class. Takes a space
**              pointer as an argument.
*****************************************************************/
void Space::setUp(Space* top)
{
    up = top;
}

/*****************************************************************
** Description: Setter for down pointer in class. Takes a space
**              pointer as an argument.
*****************************************************************/
void Space::setDown(Space* bottom)
{
    down = bottom;
}

/*****************************************************************
** Description: Setter for right pointer in class. Takes a space
**              pointer as an argument.
*****************************************************************/
void Space::setRight(Space* rPtr)
{
    right = rPtr;
}

/*****************************************************************
** Description: Setter for left pointer in class. Takes a space
**              pointer as an argument.
*****************************************************************/
void Space::setLeft(Space* lPtr)
{
    left = lPtr;
}

/*****************************************************************
** Description: Getter for space pointer in class. Returns
**              pointer.
*****************************************************************/
Space* Space::getRight()
{
    return right;
}

/*****************************************************************
** Description: Getter for space pointer in class. Returns
**              pointer.
*****************************************************************/
Space* Space::getLeft()
{
    return left;
}

/*****************************************************************
** Description: Getter for space pointer in class. Returns
**              pointer.
*****************************************************************/
Space* Space::getUp()
{
    return up;
}

/*****************************************************************
** Description: Getter for space pointer in class. Returns
**              pointer.
*****************************************************************/
Space* Space::getDown()
{
    return down;
}

/*****************************************************************
** Description: Setter for name of space object.
*****************************************************************/
void Space::setName(string name)
{
    this -> name = name;
}

/*****************************************************************
** Description: Getter for name of space object.
*****************************************************************/
string Space::getName()
{
    return name;
}

/*****************************************************************
** Description: Setter for player in object.
*****************************************************************/
void Space::setPlayer(Player* playPtr)
{
    this -> player = playPtr;
}

/*****************************************************************
** Description: Getter for player object.
*****************************************************************/
Player* Space::getPlayer()
{
    return player;
}

/*****************************************************************
** Description: This function prints out and prompts the user to
**              perform an action depending on space object
**              Takes a player pointer as an argument.
*****************************************************************/
void Space::prompt_ActionsMenu()
{

    cout << "You have entered a room." << endl;
}

/*****************************************************************
** Description: This function allows runs the actually action
**              of moving user to another space. Prints out
**              narrative plus prompts.
*****************************************************************/
void Space::enterRoom()
{
    initialEnter(0);

    visits++;
}
