/************************************************************************
** Program name:  Chemical Room Class Declaration
** Author:        Patrick Oh
** Date:          06/11/19
** Description:   This file contains the class declaration for the chemical
**                room class.
************************************************************************/
#ifndef FINAL_CHEMICAL_ROOM_HPP
#define FINAL_CHEMICAL_ROOM_HPP

#include "Player.hpp"
#include "Space.hpp"

class Chemical_Room:public Space
{
public:
    explicit Chemical_Room(Player*);
    ~Chemical_Room() override;
    void enterRoom() override;
    void prompt_ActionsMenu(Player*);

private:
    int visits;
    Item* blue;
    Item* doc1;

};


#endif //FINAL_CHEMICAL_ROOM_HPP
