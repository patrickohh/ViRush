/************************************************************************
** Program name:  Inventory Class Functions
** Author:        Patrick Oh
** Date:          06/11/19
** Description:   This file contains the function definitions of the
**                inventory class which contains functions that actually
**                runs the program.
************************************************************************/
#include "Inventory.hpp"
#include "Item.hpp"
#include <vector>
#include <iostream>
using std::vector;
using std::cout;
using std::cin;
using std::endl;
using std::string;

/*****************************************************************
** Description: Constructor for object of inventory class.
*****************************************************************/
Inventory::Inventory()
{
    vector <Item*> bag;
    maxLoad = 10;
}

/*****************************************************************
** Description: Setter function for max size of inventory
*****************************************************************/
void Inventory::setMaxLoad(int maxLoad)
{
    this -> maxLoad = maxLoad;
}

/*****************************************************************
** Description: Function that adds item to vector that is the
**              inventory.
*****************************************************************/
void Inventory::addItem(Item* item)
{
    bag.push_back(item);
}

/*****************************************************************
** Description: Displays inventory for user
*****************************************************************/
void Inventory::showInventory()
{
    string input;
    string output;

    if(bag.empty())
    {
        cout << "Bag is empty at the moment." << endl << endl;
    }

    else
    {

        for(int i = 0; i < bag.size(); i++)
        {
            cout << "(" << i + 1 << ") " << bag[i] -> getItemName()
                 << endl
                 << bag[i] -> getDescription() << endl
                 << endl;
        }

        cout << endl;
    }
}

/*****************************************************************
** Description: Function that determines if a certain item exists
*****************************************************************/
bool Inventory::itemExists(int input)
{
    for(int i = 0; i < bag.size(); i++)
    {
        if(bag[i] -> getIndex() == input)
        {
            return true;
        }
    }

    return false;
}
