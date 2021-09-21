/************************************************************************
** Program name:  Item Class Declaration
** Author:        Patrick Oh
** Date:          06/11/19
** Description:   This file contains the class declaration for the
**                item class.
************************************************************************/
#ifndef FINAL_ITEM_HPP
#define FINAL_ITEM_HPP

#include <string>


class Item
{
public:
    Item();
    void setItemDescription(std::string);
    std::string getDescription();
    void setItemName(std::string);
    std::string getItemName();
    void setIndex(int);
    int getIndex();

private:
    std::string description;
    std::string name;
    int index;

};


#endif //FINAL_ITEMS_HPP
