/************************************************************************
** Program name:  Pandemic Game Main Method
** Author:        Patrick Oh
** Date:          06/11/19
** Description:   This file contains the main method for the game
**                where the user plays as a scientist whose trying
**                to find a cure.
************************************************************************/
#include <iostream>
#include "Game.hpp"
#include "inputValidate.hpp"
using std::cout;
using std::endl;
using std::cin;

int main()
{
    int input;
    Game game;

    game.startGame();

    return 0;
}
