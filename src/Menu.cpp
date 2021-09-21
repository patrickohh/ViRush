/************************************************************************
** Program name:  Menu Functions
** Author:        Patrick Oh
** Date:          06/11/19
** Description:   This file contains the function definitions that print
**                out prompts for the user throughout the game.
************************************************************************/
#include <iostream>
#include "Menu.hpp"
#include "inputValidate.hpp"
using std::cout;
using std::cin;
using std::endl;

/*****************************************************************
** Description: This function prints out and prompts the user to
**              start the game or not
*****************************************************************/
void baseMenu(int &choice)
{
    cout << "It is 2030 and a global pandemic as hit the majority of "
         << "the human population..." << endl
         << "You are a scientist who has been trying to find a cure or vaccine "
         << "to this widespread virus." << endl
         << "Your research and efforts into the matter has lead you to a " << endl
         << "discrete and secretive lab where other scientists had been looking " << endl
         << "into a cure for the virus." << endl << endl
         << "Your goal now is to finish what these scientists have started " << endl
         << "and formulate a vaccine." << endl << endl
         << "But the vaccine isn't only for what's left of humanity..." << endl
         << "You must formulate and administer the cure on yourself before the virus kills you." << endl
         << "Find clues and the right components in making the vaccine once you enter " << endl
         << "the facility." << endl << endl
         << "Good luck! The fate of humanity and your own rests on your shoulders..." << endl << endl;

    cout << "You approach a run down and decrepit looking facility..." << endl
         << "The door looks rusted and hasn't been used in years." << endl
         << "Do you enter or leave?" << endl
         << "1. Enter" << endl
         << "2. Leave" << endl;

    choice = choiceValidate();
}

/*****************************************************************
** Description: This function prints out and prompts the user to
**              perform when first entering a room.
*****************************************************************/
void initialEnter(int room)
{
    switch(room)
    {
        case 1:
            cout << "You enter a lobby" << endl
                 << "and it is weirdly immaculate, except for a few " << endl
                 << "over turned chairs..." << endl
                 << "You head over to the receptionist desk and look through the drawers" << endl
                 << "and computer terminal." << endl;
            break;

        case 2:
            cout << "You have entered the Break Room" << endl
                 << "You spot vending machines and a fridge lined up against the wall." << endl
                 << "On a table you spot a tupperware tub filled with what seems to be fungus." << endl
                 << "There seems to be nothing out of the ordinary here..." << endl
                 << "On one of the walls there are lab coats hung on rungs..." << endl << endl;
            break;


        case 3:
            cout << "You have entered the Chemical Room" << endl
                 << "There are jars and jars filled with liquids and solids." << endl
                 << "Most of the contents you can't make out." << endl
                 << "There are shelves that seemed to have been all open as if someone was " << endl
                 << "was searching for something." << endl
                 << "In the corner you see the remains of a scientist grasping at a locked " << endl
                 << "shelf" << endl
                 << "If you had something to break open the case..." << endl << endl;
            break;

        case 4:
            cout << "You have entered the Equipment Room" << endl
                 << "You spot various lab coats, goggles, gloves, and glassware." << endl
                 << "On the wall there's a novelty poster keeping track of days since last" << endl
                 << "accident with the number being zero." << endl
                 << "In the middle of the room is a peculiar machine you have never seen before..." << endl
                 << "Walking up to it you dust off the machinery a bit and can make out what seems to be" << endl
                 << "four slots for the vials? And a button to turn the machine on." << endl << endl;

            break;

        case 5:
            cout << "Grasping the card key in your hand you walk over to the vending machine near the wall that "
                 << endl
                 << "was indicated by the note." << endl;
            break;

        case 6:
            cout << "You walk into a small space..." << endl
                 << "Nothing seems too out of the ordinary." << endl
                 << "It's a good place to rest..." << endl << endl;
            break;

        default:
            cout << "Error with entering rooms" << endl << endl;

            break;
    }
}


/*****************************************************************
** Description: This function prints out a narrative when a user
**              has entered the space more than once.
*****************************************************************/
void repeatEnter(int visit)
{
    switch(visit)
    {
        case 1:
            cout << "You step back into the lobby." << endl;

            cout << "Nothing seems out of the ordinary..." << endl;

            break;

        case 2:
            cout << "You step back into the Break Room." << endl;

            cout << "Nothing seems out of the ordinary..." << endl;

            break;

        case 3:
            cout << "You step back into the Chemical Room." << endl;

            cout << "Nothing seems out of the ordinary..." << endl;

            break;

        case 4:
            cout << "You step back into the Equipment Room." << endl;

            cout << "Nothing seems out of the ordinary..." << endl;

            break;

        case 5:
            cout << "You step back into the hidden room." << endl;

            cout << "Nothing seems out of the ordinary..." << endl;

            break;

        case 6:
            cout << "You step back into the closet." << endl;

            cout << "The space that once seemed restful is claustrophobic instead." << endl;

            cout << "You decide to step back out." << endl;

            break;

        default:
            cout << "Error with re-entering room." << endl;

            break;
    }
}

/*****************************************************************
** Description: This function prints out player menu after each
**              turn.
*****************************************************************/
void playerMenu()
{
    cout << "1: Look at contents of your bag" << endl
         << "2: Show current health" << endl
         << "3. Move to a room" << endl << endl;
}
