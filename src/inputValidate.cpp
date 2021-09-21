/************************************************************************
** Program name:  Input Validation
** Author:        Patrick Oh
** Date:          06/11/19
** Description:   This file contains the function definitions of the
**                functions that validate input for when the program
**                asks for user input.
************************************************************************/
#include <iostream>
#include <string>
#include <sstream>
#include <stdexcept>
#include "inputValidate.hpp"
using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::getline;
using std::stringstream;
using std::invalid_argument;


/*****************************************************************
** Description: This is function that validates input for
**              whenever the user is prompted for an input.
**              Validates that the user enters an 1 or 2.
** Source cited: https://stackoverflow.com/questions/18728754/
**               checking-cin-input-stream-produces-an-integer
*****************************************************************/
int choiceValidate()
{
    string input;
    int numInput = 0;

    getline(cin, input);

    while(cin.fail() || cin.eof() || input.find_first_not_of("12") != string::npos)
    {
        cout << "Invalid entry please enter again." << endl
             << endl;

        if(input.find_first_not_of("12") == string::npos)//scans string
        {
            cin.clear();
            cin.ignore(1000, '\n');
        }

        getline(cin, input);
    }

    stringstream convert(input); //learncpp

    convert >> numInput; //converts string into int

    return numInput;
}

/*****************************************************************
** Description: This is function that validates input for
**              whenever the user is prompted for an input.
**              Validates that the user enters an 1,2,3, or 4.
** Source cited: https://stackoverflow.com/questions/18728754/
**               checking-cin-input-stream-produces-an-integer
*****************************************************************/
int choiceFourValidate()
{
    string input;
    int numInput = 0;

    getline(cin, input);

    while(cin.fail() || cin.eof() || input.find_first_not_of("1234") != string::npos)
    {
        cout << "Invalid entry please enter again." << endl
             << endl;

        if(input.find_first_not_of("1234") == string::npos)//scans string
        {
            cin.clear();
            cin.ignore(1000, '\n');
        }

        getline(cin, input);
    }

    stringstream convert(input); //learncpp

    convert >> numInput; //converts string into int

    return numInput;
}

/*****************************************************************
** Description: This is function that validates input for
**              whenever the user is prompted for an input.
**              Validates that the user enters an 1,2,3.
** Source cited: https://stackoverflow.com/questions/18728754/
**               checking-cin-input-stream-produces-an-integer
*****************************************************************/
int choiceThreeValidate()
{
    string input;
    int numInput = 0;

    getline(cin, input);

    while(cin.fail() || cin.eof() || input.find_first_not_of("123") != string::npos)
    {
        cout << "Invalid entry please enter again." << endl
             << endl;

        if(input.find_first_not_of("123") == string::npos)//scans string
        {
            cin.clear();
            cin.ignore(1000, '\n');
        }

        getline(cin, input);
    }

    stringstream convert(input); //learncpp

    convert >> numInput; //converts string into int

    return numInput;
}
