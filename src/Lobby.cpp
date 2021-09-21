/************************************************************************
** Program name:  Lobby Class Functions
** Author:        Patrick Oh
** Date:          06/11/19
** Description:   This file contains the function definitions of the
**                lobby class which is a child class of Space.
************************************************************************/
#include "Lobby.hpp"
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
** Description: Constructor for object of lobby child
**              class.
*****************************************************************/
Lobby::Lobby(Player* player) : Space(player)
{
    setName("Lobby");
    setPlayer(player);
    visits = 0;
    doc3 = nullptr;
    red = nullptr;
}

/*****************************************************************
** Description: Destructor for chemical room object.
*****************************************************************/
Lobby::~Lobby()
{
    delete doc3;
    delete red;
}

/*****************************************************************
** Description: This function allows runs the actually action
**              of moving user to another space. Prints out
**              narrative plus prompts.
*****************************************************************/
void Lobby::enterRoom()
{
    Player* user = this -> getPlayer();

    if(visits == 0)//if user's first time entering room
    {
        initialEnter(1);
    }

    else
    {
        repeatEnter(1);
    }

    prompt_ActionsMenu(user);

}

/*****************************************************************
** Description: This function prints out and prompts the user to
**              perform an action depending on the janitor  room.
**              Takes a player pointer as an argument.
*****************************************************************/
void Lobby::prompt_ActionsMenu(Player* player)
{
    visits++;//updates counter that keeps track of user visiting room
    doc3 = new Item;
    red = new Item;

    doc3 -> setItemName("Document 3");//item creations
    doc3 -> setIndex(6);
    red -> setItemName("Red Vial");
    red -> setIndex(7);

    string description1 = "The GREEN has been the 3RD component found that is necessary for the cure!";
    string description2 = "A vial filled with a red colored chemical...";

    doc3 -> setItemDescription(description1);
    red -> setItemDescription(description2);

    int choice;

    Inventory* baggage = player -> getInventory();

    static const double ratio = 1.0 / (RAND_MAX + 1.0); //Learncpp
    int chance = 1 + static_cast<int> ((100 - 1 + 1) * (rand() * ratio));
    //returns rand num between one and max number of sides

    int prob = 1 + static_cast<int> ((100 - 1 + 1) * (rand() * ratio));

    cout << "Log into the computer terminal?" << endl
         << "1. Yes" << endl
         << "2. No" << endl;

    choice = choiceValidate();

    if(choice == 1 && !(baggage -> itemExists(7)))//if user selection matches and item doesn't exist
    {
        cout << "Logging into the computer terminal you find it odd that there is nothing but " << endl
             << "one file on the desktop. It seems to be a document file...You click on it." << endl
             << "The document opened reveals the following description: " << endl
             << "'The doctor looked flustered as he was running towards the doors of the lab...'" << endl
             << "'Seeing me he handed me a vial, which I have stored in one of the drawers, and " << endl
             << "looked at me with eyes of a mad but dying man. He told me to keep this somewhere " << endl
             << " safe for the time being and collapsed at my feet. Bewildered at what had just transpired " << endl
             << "I placed the vial in my desk and tried to call help for the doctor.'" << endl
             << "'I hope this last memo serves anyone who finds this vial important. The doctor sure " << endl
             << "thought so...'" << endl << endl
             << "Looks like that's where the document ends." << endl
             << "Looking through the desk you find a small vial filled with a opaque, " << endl
             << "yellow - colored liquid as well as a note." << endl
             << "You decide to store both in your bag for safe - keeping." << endl << endl;

        baggage -> addItem(doc3);
        baggage -> addItem(red);

        player -> vialCountIncrease();

        cout << "Document 3 and Red Vial added to bag." << endl << endl;

        if(prob <= 75)
        {
            cout << "While looking though the desk you find an old candy bar..." << endl
                 << "Looks safe to eat! You know what they say...you only live once." << endl;

            player -> healthIncrease(15);

            cout << "Taking the candy bar makes you feel a bit better!" << endl << endl;
        }

        if(chance <= 50)
        {
            cout << "You feel a sudden pain stemming from your stomach..." << endl
                 << "Blood surges from out of your mouth and you stare at your hand " << endl
                 << "which is crimson red from coughing up blood into it." << endl
                 << "You feel the virus progressing..." << endl << endl;

            player -> healthDecrease(15);
        }
    }

    else if(choice == 1)
    {
        cout << "The computer has not changed since you last checked it..." << endl << endl;
    }

    else
    {
        cout << "You decide not to log on, so you stand up and walk away from the desk and terminal " << endl
             << endl;

        if(chance <= 50)
        {
            cout << "You feel a sudden pain stemming from your stomach..." << endl
                 << "Blood surges from out of your mouth and you stare at your hand " << endl
                 << "which is crimson red from coughing up blood into it." << endl
                 << "You feel the virus progressing..." << endl << endl;

            player -> healthDecrease(20);
        }

    }
}
