/************************************************************************
** Program name:  Break Room Class Declaration
** Author:        Patrick Oh
** Date:          06/11/19
** Description:   This file contains the class declaration for the break
**                room class.
************************************************************************/

#ifndef FINAL_BREAK_ROOM_HPP
#define FINAL_BREAK_ROOM_HPP

#include "Player.hpp"
#include "Space.hpp"


class Break_Room : public Space
{
public:
    explicit Break_Room(Player*);
    ~Break_Room() override;
    void enterRoom() override;
    void prompt_ActionsMenu(Player*);

private:
    int visits;
    Item* card;

};


#endif //FINAL_BREAK_ROOM_H
