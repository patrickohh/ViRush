/*****************************************************************
** Description: This function prints out and prompts the user to
**              perform an action depending on the janitor  room.
**              Takes a player pointer as an argument.
*****************************************************************/
void Janitor::prompt_ActionsMenu(Player* player)
{
    visits++;

    int choice;

    if (visits == 1)
    {
        cout << "Choose to rest here for a bit?" << endl
            << "1. Yes" << endl
            << "2. No" << endl;

        choice = choiceValidate();//input validation

        if (choice == 1)
        {
            cout << "Actually sitting down and taking a breather makes you feel a bit "
                << "better." << endl << endl;

            player->healthIncrease(5);//health increase
        }

        else
        {
            cout << "You decide the small space makes you claustrophobic so you walk back out." << endl
                << endl;
        }
    }
}
