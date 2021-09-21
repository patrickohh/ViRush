/************************************************************************
** Program name:  Game Class Functions
** Author:        Patrick Oh
** Date:          06/11/19
** Description:   This file contains the function definitions of the
**                game class which contains functions that actually
**                runs the program.
************************************************************************/

#include <iostream>
#include <vector>
#include "Game.hpp"
#include "Player.hpp"
#include "Space.hpp"
#include "Menu.hpp"
#include "Equip_Room.hpp"
#include "Lobby.hpp"
#include "Break_Room.hpp"
#include "Chemical_Room.hpp"
#include "Secret_Room.hpp"
#include "Janitor.hpp"
#include "inputValidate.hpp"
using std::vector;
using std::cout;
using std::endl;
using std::cin;

/*****************************************************************
** Description: Constructor for object of game
**              class.
*****************************************************************/
Game::Game()
{
    scientist = new Player(140);

    setupSpaces();

    currentSpace = nullptr;
}

/*****************************************************************
** Description: Destructor for game object.
*****************************************************************/
Game::~Game()
{
    delete scientist;
    delete lobby;
    delete breakRoom;
    delete chemRoom;
    delete secret;
    delete equipRoom;
    delete janitor;
}

/*****************************************************************
** Description: This function allows runs the actually game.
*****************************************************************/
void Game::startGame()
{
    int decision,
        input;


    Inventory* bag = scientist -> getInventory();

    baseMenu(decision);//menu prompt

    if(decision == 1)
    {
        currentSpace = lobby;

        do
        {
            playerMenu();

            input = choiceThreeValidate();

            switch(input)
            {
                case 1:
                    bag -> showInventory();
                    break;
                case 2:
                    cout << "The disease is still killing you..." << endl
                         << "Current Health at: " << scientist -> getHealth()
                         << " Points" << endl << endl;

                    break;

                case 3:
                    playerTurn();
                    break;
                default:
                    cout << "Error with game." << endl;
                    break;
            }

            win = scientist -> getWin() == 1;
            lose = scientist -> getHealth() <= 0;

            if(lose && !win)
            {
                cout << "You feel the virus spread throughout your body..." << endl
                     << "Blood spills constantly from your mouth and you collapse " << endl
                     << "to the floor unconscious..." << endl << endl;
            }

        }while(input != 4 && !(win || lose));//loops until user loses or wins

    }

    else
    {
        exit(0);
    }
}

/*****************************************************************
** Description: This function allows the user to choose which
**              rooms to go to.
*****************************************************************/
void Game::playerTurn()
{
    int choice;
    vector<Space*> spaces;

    if(currentSpace -> getUp() != nullptr)//prints out which rooms are available where
    {
        cout << "Up ahead: " << currentSpace -> getUp() -> getName()
             << endl;

        spaces.push_back(currentSpace -> getUp());
    }

    if(currentSpace -> getDown() != nullptr)
    {
        cout << "Behind: " << currentSpace -> getDown() -> getName()
             << endl;

        spaces.push_back(currentSpace -> getDown());
    }

    if(currentSpace -> getRight() != nullptr)
    {
        cout << "On your Right: " << currentSpace -> getRight() -> getName()
             << endl;

        spaces.push_back(currentSpace -> getRight());
    }

    if(currentSpace -> getLeft() != nullptr)
    {
        cout << "On your Left: " << currentSpace -> getLeft() -> getName()
             << endl;

        spaces.push_back(currentSpace -> getLeft());
    }

    cout << endl;

    for(int i = 0; i < spaces.size(); i++)
    {
        cout << "Type " << i + 1 << ":"
             << spaces[i] -> getName() << endl << endl;
    }

    choice = choiceFourValidate();

    cout << endl;

    if((choice - 1) != spaces.size())
    {
        scientist -> healthDecrease(10);//player health decreases at each turn

        spaces.at(choice - 1) -> enterRoom();

        currentSpace = spaces.at(choice -1);
    }

    else
    {
        cout << "No such room to navigate to..." << endl << endl;
    }
}

/*****************************************************************
** Description: This function sets up the actual board for the
**              game.
*****************************************************************/
void Game::setupSpaces()
{
    lobby = new Lobby(scientist);
    chemRoom = new Chemical_Room(scientist);
    equipRoom = new Equip_Room(scientist);
    breakRoom = new Break_Room(scientist);
    secret = new Secret_Room(scientist);
    janitor = new Janitor(scientist);

    lobby -> setRight(equipRoom);
    lobby -> setLeft(chemRoom);
    lobby -> setUp(breakRoom);

    chemRoom -> setRight(lobby);
    chemRoom -> setUp(janitor);

    janitor -> setDown(chemRoom);

    equipRoom -> setLeft(lobby);
    equipRoom -> setUp(breakRoom);

    breakRoom -> setDown(equipRoom);
    breakRoom -> setUp(secret);

    secret -> setDown(breakRoom);
}

