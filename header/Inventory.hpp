/************************************************************************
** Program name:  Inventory Class Declaration
** Author:        Patrick Oh
** Date:          06/11/19
** Description:   This file contains the class declaration for the
**                inventory class.
************************************************************************/
#ifndef FINAL_INVENTORY_HPP
#define FINAL_INVENTORY_HPP

#include <vector>
#include <string>
#include "Item.hpp"

class Inventory
{
public:
    Inventory();
    void setMaxLoad(int);
    void addItem(Item*);
    void showInventory();
    bool itemExists(int);
private:
    int maxLoad;
    std::vector <Item*> bag;

};


#endif //FINAL_INVENTORY_HPP
