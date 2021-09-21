/************************************************************************
** Program name:  Lobby Class Functions
** Author:        Patrick Oh
** Date:          06/11/19
** Description:   This file contains the function definitions of the
**                secret room class which is a child class of Space.
************************************************************************/

#include "Secret_Room.hpp"
#include <iostream>
#include <string>
#include <cstdlib>
#include "Inventory.hpp"
#include "Space.hpp"
#include "Player.hpp"
#include "Menu.hpp"
#include "inputValidate.hpp"
using std::string;
using std::cout;
using std::endl;
using std::cin;

/*****************************************************************
** Description: Constructor for object of secret room child
**              class.
*****************************************************************/
Secret_Room::Secret_Room(Player* player) : Space(player)
{
    setName("Secret Room");
    setPlayer(player);
    visits = 0;
    doc4 = nullptr;
    yellow = nullptr;
}

/*****************************************************************
** Description: Destructor for chemical room object.
*****************************************************************/
Secret_Room::~Secret_Room()
{
    delete doc4;
    delete yellow;
}

/*****************************************************************
** Description: This function allows runs the actually action
**              of moving user to another space. Prints out
**              narrative plus prompts.
*****************************************************************/
void Secret_Room::enterRoom()
{
    Player* user = this -> getPlayer();

    if(visits == 0)//if user has never entered the room before
    {
        initialEnter(5);
    }

    else
    {
        repeatEnter(5);
    }

    prompt_ActionsMenu(user);

}

/*****************************************************************
** Description: This function prints out and prompts the user to
**              perform an action depending on the janitor  room.
**              Takes a player pointer as an argument.
*****************************************************************/
void Secret_Room::prompt_ActionsMenu(Player* player)
{
    visits++;//updates counter of "visits" to room

    doc4 = new Item;
    yellow = new Item;

    doc4 -> setItemName("Document 4");//item creation
    doc4 -> setIndex(8);
    yellow -> setItemName("Yellow Vial");
    yellow -> setIndex(9);

    string description1 = "The YELLOW has been the 1ST component found that is necessary for the cure!";
    string description2 = "A vial filled with a yellow colored chemical...";

    doc4 -> setItemDescription(description1);
    yellow -> setItemDescription(description2);

    int choice;

    Inventory* baggage = player -> getInventory();

    static const double ratio = 1.0 / (RAND_MAX + 1.0); //Learncpp
    int chance = 1 + static_cast<int> ((100 - 1 + 1) * (rand() * ratio));
    //returns rand num between one and max number of sides

    if(baggage -> itemExists(9)) //if item exists
    {
        cout << "You have nothing more to discover here..." << endl << endl;
    }

    else
    {
        cout << "You walk into the room, and it is lighted by various lit up screens " << endl
             << "and you see the remains of one of the scientists sitting at a chair with " << endl
             << "it's hand over a small button." << endl
             << "Press the button?" << endl
             << "1. Yes" << endl
             << "2. No" << endl;

        choice = choiceValidate();

        if(choice == 1)
        {
            cout << "A vial slides out the dashboard with a note." << endl
                 << "The vial is filled with a yellow colored substance." << endl
                 << endl
                 << "You put the contents into your bag." << endl;

            baggage -> addItem(yellow);
            baggage -> addItem(doc4);

            player -> vialCountIncrease();

            cout << "Yellow Vial and Document 4 added to bag." << endl << endl;

            if(chance <= 30)
            {
                cout << "You feel a great pain stemming from your heart..." << endl
                     << "Blood surges from out of your mouth and you stare at your hand " << endl
                     << "which is crimson red from coughing up blood into it." << endl
                     << "You feel the virus has progressed even more..." << endl << endl;

                player -> healthDecrease(50);
            }

        }

        else
        {
            cout << "You decide not to press the button and so you walk out of the room." << endl
                 << endl;

            if(chance <= 50)
            {
                cout << "You feel a sudden pain stemming from your stomach..." << endl
                     << "Blood surges from out of your mouth and you stare at your hand " << endl
                     << "which is crimson red from coughing up blood into it." << endl
                     << "You feel the virus progressing..." << endl << endl;

                player -> healthDecrease(10);
            }

        }
    }
}
