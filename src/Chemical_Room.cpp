/************************************************************************
** Program name:  Chemical Room Class Functions
** Author:        Patrick Oh
** Date:          06/11/19
** Description:   This file contains the function definitions of the
**                chemical room class which is a child class of Space.
************************************************************************/

#include <iostream>
#include <string>
#include <cstdlib>
#include "Chemical_Room.hpp"
#include "inputValidate.hpp"
#include "Inventory.hpp"
#include "Space.hpp"
#include "Player.hpp"
#include "Menu.hpp"
using std::string;
using std::cout;
using std::endl;
using std::cin;

/*****************************************************************
** Description: Constructor for object of chemical room child
**              class.
*****************************************************************/
Chemical_Room::Chemical_Room(Player* player) : Space(player)
{
    setName("Chemical Room");
    setPlayer(player);
    visits = 0;
    doc1 = nullptr;
    blue = nullptr;

}

/*****************************************************************
** Description: Destructor for chemical room object.
*****************************************************************/
Chemical_Room::~Chemical_Room()
{
    delete doc1;
    delete blue;
}

/*****************************************************************
** Description: This function allows runs the actually action
**              of moving user to another space. Prints out
**              narrative plus prompts.
*****************************************************************/
void Chemical_Room::enterRoom()
{
    Player* user = this -> getPlayer();

    if(visits == 0)//if user visits room for first time
    {
        initialEnter(3);
    }

    else
    {
        repeatEnter(3);
    }

    prompt_ActionsMenu(user);
}

/*****************************************************************
** Description: This function prints out and prompts the user to
**              perform an action depending on the space/room.
**              Takes a player pointer as an argument.
*****************************************************************/
void Chemical_Room::prompt_ActionsMenu(Player* player)
{
    visits++;//updates "visits" counter

    doc1 = new Item;
    blue = new Item;


    doc1 -> setItemName("Document 1");
    doc1 -> setIndex(1);
    blue -> setItemName("Blue Vial");
    blue -> setIndex(2);

    string description1 = "The RED has been the 2ND component found that is necessary for the cure!";
    string description2 = "A vial filled with a blue colored chemical...";

    doc1 -> setItemDescription(description1);
    blue -> setItemDescription(description2);

    int choice;

    Inventory* baggage = player -> getInventory();

    static const double ratio = 1.0 / (RAND_MAX + 1.0); //Learncpp
    int chance = 1 + static_cast<int> ((100 - 1 + 1) * (rand() * ratio));
    //returns rand num between one and max number of sides

    if(chance <= 30 )//random event
    {
        cout << "You spot something glistening on a nearby table..." << endl
             << "You pick up a bottle filled with liquid and read the label: 'Medasin'"
             << endl
             << "Seems like medication that can temporarily prolong the detrimental "
             << "effects of the disease." << endl << endl;

        player -> healthIncrease(10);

        cout << "Taking the medicine makes you feel a bit better!" << endl << endl;
    }

    if(baggage -> itemExists(4) && !(baggage -> itemExists(2)))
    {
        cout << "You approach the shelf case again." << endl
             << "Do you use the pipe to break open the shelf case?" << endl
             << "1. Yes" << endl
             << "2. No" << endl;

        choice = choiceValidate();

        if(choice == 1)
        {
            cout << "You step back and swing the pipe at the case." << endl
                 << "The glass shatters and inside you see a document and a vial."
                 << endl
                 << "You reach and grab the contents of the broken-into shelf case."
                 << endl << endl;

            baggage -> addItem(blue);
            baggage -> addItem(doc1);

            player -> vialCountIncrease();

            cout << "Blue Vial and Document 1 added to your bag!" << endl << endl;
        }

        else
        {
            if(chance <= 30)
            {
                cout << "You spot something glistening on a nearby table..." << endl
                     << "You pick up a bottle filled with liquid and read the label: 'Medasin'"
                     << endl
                     << "Seems like medication that can temporarily prolong the detrimental"
                     << "effects of the disease." << endl << endl;

                player -> healthIncrease(10);

                cout << "Taking the medicine makes you feel a bit better!" << endl << endl;
            }

            cout << "You decide to leave the shelf case alone." << endl;
        }

    }

    else
    {
        cout << "Looks like there's nothing else for you to discover here..." << endl << endl;
    }
}

