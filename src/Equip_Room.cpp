/************************************************************************
** Program name:  Equipment Room Class Functions
** Author:        Patrick Oh
** Date:          06/11/19
** Description:   This file contains the function definitions of the
**                equipment room class which is a child class of Space.
************************************************************************/
#include "Equip_Room.hpp"
#include "inputValidate.hpp"
#include <iostream>
#include <string>
#include <cstdlib>
#include "Inventory.hpp"
#include "Space.hpp"
#include "Player.hpp"
#include "Menu.hpp"
using std::string;
using std::cout;
using std::endl;
using std::cin;

/*****************************************************************
** Description: Constructor for object of equipment room child
**              class.
*****************************************************************/
Equip_Room::Equip_Room(Player* player) : Space(player)
{
    setName("Equipment Room");
    setPlayer(player);
    visits = 0;
    doc2 = nullptr;
    pipe = nullptr;
    green = nullptr;
}

/*****************************************************************
** Description: Destructor for chemical room object.
*****************************************************************/
Equip_Room::~Equip_Room()
{
    delete doc2;
    delete pipe;
    delete green;
}

/*****************************************************************
** Description: This function allows runs the actually action
**              of moving user to another space. Prints out
**              narrative plus prompts.
*****************************************************************/
void Equip_Room::enterRoom()
{
    Player* user = this -> getPlayer();

    if(visits == 0)//if user's first visit
    {
        initialEnter(4);
    }

    else
    {
        repeatEnter(4);
    }

    prompt_ActionsMenu(user);
}

/*****************************************************************
** Description: This function prints out and prompts the user to
**              perform an action depending on the space room.
**              Takes a player pointer as an argument.
*****************************************************************/
void Equip_Room::prompt_ActionsMenu(Player* player)
{
    visits++;

    doc2 = new Item;
    pipe = new Item;
    green = new Item;

    doc2 -> setItemName("Document 2");
    doc2 -> setIndex(3);
    pipe -> setItemName("Metal Pipe");
    pipe -> setIndex(4);
    green -> setItemName("Green Vial");
    green -> setIndex(5);

    string description1 = "The BLUE has been the 4TH component found that is necessary for the cure!";
    string description2 = "A vial filled with a green colored chemical...";
    string description3 = "A metal pipe. Looks like it could be used to break into something...";

    doc2 -> setItemDescription(description1);
    pipe -> setItemDescription(description3);
    green -> setItemDescription(description2);

    Inventory* baggage = player -> getInventory();

    int choice;

    static const double ratio = 1.0 / (RAND_MAX + 1.0); //Learncpp
    int chance = 1 + static_cast<int> ((100 - 1 + 1) * (rand() * ratio));
    //returns rand num between one and max number of sides


    if(chance >= 50)
    {
        cout << "You feel a sudden pain in the left side of your ribs." << endl
             << "You cough up blood and fall to the ground..." << endl
             << "The virus must have progressed faster within you body." << endl
             << endl;

        player -> healthDecrease(10);

    }

    cout << "Try to fill the slots and make the machine run?" << endl
         << "1. Yes" << endl
         << "2. No" << endl << endl;

    choice = choiceValidate();

    if(choice == 1)
    {
        if(player -> getVial() == 4)
        {
            cout << "The machine turns on with new life as you watch it accept all the vials..." << endl
                 << "In a flash a new substance is made, which seems to be the vaccine for the virus!"
                 << endl
                 << "Congratulations you have saved yourself and humanity!!" << endl << endl;

            player -> setWin(1);
        }

        else
        {
            cout << "You do not have any or all the necessary components to run the machine." << endl
                 << "Try again later." << endl << endl;
        }
    }

    else
    {
        cout << "You decide not to run the machine and so you walk away." << endl << endl;
    }


    if(!(baggage -> itemExists(5)))//if certain item already exits
    {
        cout << "Next to the machine, you spot the skeleton of one of the scientists sitting down." << endl
             << "In it's hands you see a folder and a dusty vial." << endl
             << "You reach out to grab both things..." << endl << endl;

        baggage -> addItem(doc2);
        baggage -> addItem(green);

        player -> vialCountIncrease();
    }

    if(!(baggage -> itemExists(4)))
    {
        cout << "You look around the room further and spot a silver, metal pipe in the corner " << endl
             << "propped up against the a piece of equipment." << endl << endl
             << "You walk over to it thinking it might come in handy later..." << endl << endl
             << "You pick it up and put it into your bag." << endl << endl;

        baggage -> addItem(pipe);

        cout << "Metal Pipe added to bag." << endl << endl;
    }
}
