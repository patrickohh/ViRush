/************************************************************************
** Program name:  Chemical Room Class Declaration
** Author:        Patrick Oh
** Date:          06/11/19
** Description:   This file contains the class declaration for the equip
**                room class.
************************************************************************/

#ifndef FINAL_EQUIP_ROOM_HPP
#define FINAL_EQUIP_ROOM_HPP

#include "Player.hpp"
#include "Space.hpp"

class Equip_Room : public Space
{
public:
    explicit Equip_Room(Player*);
    ~Equip_Room() override;
    void enterRoom() override;
    void prompt_ActionsMenu(Player*);

private:
    int visits;
    Item* green;
    Item* pipe;
    Item* doc2;
};


#endif //FINAL_EQUIP_ROOM_HPP
