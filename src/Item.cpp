/************************************************************************
** Program name:  Item Class Functions
** Author:        Patrick Oh
** Date:          06/11/19
** Description:   This file contains the function definitions of the
**                item class which allows for the creation of items
**                in the game.
************************************************************************/
#include <string>
#include <iostream>
#include "Item.hpp"
using std::string;

/*****************************************************************
** Description: Constructor for object of inventory class.
*****************************************************************/
Item::Item()
{
    setItemName(name);
    setItemDescription(description);
    index = 0;
}


/*****************************************************************
** Description: Setter for the description of an item. A string
**              variable is passed as an argument.
*****************************************************************/
void Item::setItemDescription(string description)
{
    this -> description = description;
}


/*****************************************************************
** Description: Getter for description of an object
*****************************************************************/
string Item::getDescription()
{
    return description;
}


/*****************************************************************
** Description: Setter for the name of an item. Passes string
**              variable as an argument
*****************************************************************/
void Item::setItemName(string name)
{
    this -> name = name;
}


/*****************************************************************
** Description: Getter for the name of an item.
*****************************************************************/
string Item::getItemName()
{
    return name;
}


/*****************************************************************
** Description: Setter for index number of an object.
*****************************************************************/
void Item::setIndex(int num)
{
    index = num;
}


/*****************************************************************
** Description: Getter for index number of item
*****************************************************************/
int Item::getIndex()
{
    return index;
}
