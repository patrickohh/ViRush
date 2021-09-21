/************************************************************************
** Program name:  Game Class Declaration
** Author:        Patrick Oh
** Date:          06/11/19
** Description:   This file contains the class declaration for the Game
**                class.
************************************************************************/
#ifndef FINAL_GAME_HPP
#define FINAL_GAME_HPP

#include "Player.hpp"
#include "Space.hpp"
#include "Equip_Room.hpp"
#include "Lobby.hpp"
#include "Break_Room.hpp"
#include "Chemical_Room.hpp"
#include "Secret_Room.hpp"
#include "Janitor.hpp"

class Game
{
public:
    Game();
    ~Game();
    void startGame();
    void playerTurn();
    void setupSpaces();

private:
    Player* scientist;
    Space* currentSpace;
    Space* lobby;
    Space* secret;
    Space* chemRoom;
    Space* equipRoom;
    Space* breakRoom;
    Space* janitor;
    bool win;
    bool lose;
};


#endif //FINAL_GAME_HPP
