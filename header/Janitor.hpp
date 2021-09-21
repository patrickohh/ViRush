/************************************************************************
** Program name:  Janitor Room Class Declaration
** Author:        Patrick Oh
** Date:          06/11/19
** Description:   This file contains the class declaration for the
**                janitor room class.
************************************************************************/
#ifndef FINAL_JANITOR_HPP
#define FINAL_JANITOR_HPP

#include "Player.hpp"
#include "Space.hpp"


class Janitor : public Space
{
public:
    explicit Janitor(Player*);
    void enterRoom() override;
    void prompt_ActionsMenu(Player*);

};


#endif //FINAL_JANITOR_H
