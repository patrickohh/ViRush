/************************************************************************
** Program name:  Break Room Class Functions
** Author:        Patrick Oh
** Date:          06/11/19
** Description:   This file contains the function definitions of the
**                break room class which is a child class of Space.
************************************************************************/

#include <iostream>
#include <string>
#include "Break_Room.hpp"
#include "inputValidate.hpp"
#include "Player.hpp"
#include "Item.hpp"
#include "Menu.hpp"
using std::cout;
using std::cin;
using std::endl;
using std::string;

/*****************************************************************
** Description: Constructor for object of break room child
**              class.
*****************************************************************/
Break_Room::Break_Room(Player* player):Space(player)
{
    setName("Break Room");
    setPlayer(player);
    visits = 0;
    card = nullptr;
}

/*****************************************************************
** Description: Destructor for break room object.
*****************************************************************/
Break_Room::~Break_Room()
{
    delete card;
}

/*****************************************************************
** Description: This function allows runs the actually action
**              of moving user to another space. Prints out
**              narrative plus prompts.
*****************************************************************/
void Break_Room::enterRoom()
{
    Player* user = this -> getPlayer();
    //If user visited only once
    if(visits == 0)
    {
        initialEnter(2);
    }

    else
    {
        repeatEnter(2);
    }

    prompt_ActionsMenu(user);
}

/*****************************************************************
** Description: This function prints out and prompts the user to
**              perform an action depending on the space/room.
**              Takes a player pointer as an argument.
*****************************************************************/
void Break_Room::prompt_ActionsMenu(Player* player)
{
    visits++;//update counter for "visits" to room

    card = new Item();//creation of item

    card -> setItemName("Employee Key Card");
    card -> setIndex(0);

    string description1 = "A metallic looking card a number '1' inscribed on the front. "
                          "Looks like it opens something.";


    card -> setItemDescription(description1);

    Inventory* baggage = player -> getInventory();

    int choice,
        input;

    if(!(baggage -> itemExists(0)))//if item wasn't already picked up
    {
        do
        {
            cout << "You decide to pick up on of the four coats hanging on the wall."
                 << endl
                 << "Which one do you decide to pick? The coats are numbered one through four " << endl
                 << "from left to right." << endl << endl
                 << "Enter your choice: " << endl;

            choice = choiceFourValidate();

            if(choice == 3)
            {
                cout << "You pick up the coat and when you do something seems to be hanging in its pocket..." << endl
                     << "You reach in to find a note and what seems to be a key card." << endl;

                baggage -> addItem(card);

                cout << "Employee Key Card added to bag." << endl << endl;

                do
                {
                    cout << "The note reads: Vending Machines.." << endl
                         << "You head over to the row of vending machines against the wall." << endl
                         << "There are three machines lined up next to each other with small numbers " << endl
                         << "labeling each machine on the upper right hand corners." << endl
                         << "They are labeled in the order of 3, 1 , 2 from left to right." << endl << endl
                         << "Which machine do you choose to insert the card?" << endl;

                    cout << "Type 1 for '1'" << endl
                         << "Type 2 for '2'" << endl
                         << "Type 3 for '3'" << endl;

                    input = choiceThreeValidate();//input validation

                    if (input == 1)
                    {
                        cout << "You approach the vending machine with the card in hand." << endl
                             << "Where the machine excepts credit cards you slide the key card, and a deep rumbling is heard."
                             << endl
                             << "What seemed like a vending machine starts sliding out and reveals a dark passageway to who knows where..."
                             << endl
                             << endl;
                    }

                    else
                    {
                        cout << "There seems to be no slots on the vending machine you picked to accept the card."
                             << endl << endl;
                    }
                }while(input != 1);
            }

            else
            {
                cout << "You approach the coat and don't notice anything in particular..." << endl
                     << "So you decide to hang it back and try a different coat." << endl << endl;
            }
        }while(choice != 3);
    }

    else
    {
        cout << "There is nothing more for you to discover here..." << endl
             << endl;
    }
}
