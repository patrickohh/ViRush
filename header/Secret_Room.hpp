/************************************************************************
** Program name:  Secret Room Class Declaration
** Author:        Patrick Oh
** Date:          06/11/19
** Description:   This file contains the class declaration for the
**                secret room class.
************************************************************************/
#ifndef FINAL_SECRET_ROOM_HPP
#define FINAL_SECRET_ROOM_HPP

#include "Player.hpp"
#include "Space.hpp"

class Secret_Room : public Space
{
public:
    explicit Secret_Room(Player*);
    ~Secret_Room() override;
    void enterRoom() override;
    void prompt_ActionsMenu(Player*);

private:
    int visits;
    Item* doc4;
    Item* yellow;
};


#endif //FINAL_SECRET_ROOM_HPP
