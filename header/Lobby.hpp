/************************************************************************
** Program name:  Janitor Room Class Declaration
** Author:        Patrick Oh
** Date:          06/11/19
** Description:   This file contains the class declaration for the
**                lobby class.
************************************************************************/

#ifndef FINAL_LOBBY_HPP
#define FINAL_LOBBY_HPP

#include "Player.hpp"
#include "Space.hpp"

class Lobby : public Space
{
public:
    explicit Lobby(Player*);
    ~Lobby() override;
    void enterRoom() override;
    void prompt_ActionsMenu(Player*);

private:
    int visits;
    Item* red;
    Item* doc3;

};


#endif //FINAL_LOBBY_HPP
