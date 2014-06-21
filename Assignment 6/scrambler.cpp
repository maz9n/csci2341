/**
@file    scrambler.cpp
@author  Almozaini:Mazen:A00323488:csc34118
@version 1.0
@date    2014-05-28
*   Assignment #6 
*   due 2014-05-29
@brief
     a program that scrambles and unscrambles lines of text using
     a simple, recursive method.
 */

/*
    the program is working fine.
*/

//-------- includes and usings section --------
#include <iostream>

using namespace std;

#include "utilities.h"

using Scobey::DisplayOpeningScreen;
using Scobey::Pause;
using Scobey::Menu;


//------ function prototypes section ------
void BuildMenu
    (
    Menu& menu // in-out
    );
/**<
*  buildes a menu from the menu class
*  @return     void
*  @param      menu an object of the menu class.
*  @pre        none
*  @post       a menu with a title and options is set
*/
string ScrambleText
    (
    const string scramble // in
    );
/**<
*  Returns a scrambled string 
*  @return     string
*  @param      scramble  a string variable to be scrambled
*  @pre        string length > 1
*  @post       a scambled string has been returned
*/


string UnscrambleText
    (
    const string unscramble // in
    );
/**<
*  Returns an unscrambled string 
*  @return     string
*  @param      unscramble  a string variable to be unscrambled
*  @pre        string length > 1
*  @post       an unscambled string has been returned
*/

//-------- main function ---------
int main()
{
    DisplayOpeningScreen("Almozaini:Mazen:A00323488:csc34118",
        "Assignment 06: Menu-Driven Scrambler/Descrambler Program");

    Menu menu;
    BuildMenu(menu);
    menu.display();

    int choice;
    choice = menu.getChoice();
    while(choice > 0)
    {
        //if user chooses 1, terminate program
        if(choice == 1)
        {
            cout << "\nGoodbye!\n\n";
            Pause();
            return 0;
        }
        //if user chooses 2, scramble text
        if(choice == 2)
        {
            string text;
            cout << "Enter text to be scrambled below:\n";
            getline(cin,text);
            // loop until the user press the return key
            while(!text.empty())
            {
                cout << endl << endl;
                cout << "Scrambled:   " << "\"" << ScrambleText(text)
                     << "\"\n";
                Pause();
                cout << endl;
                cout << "Enter more text to be scrambled, or"
                     << "press enter to return to the menu:\n";
                getline(cin,text);
            }
        }
        //if user chooses 3, unscramble text
        if(choice == 3)
        {
            string text;
            cout << "Enter text to be unscrambled below:\n";
            getline(cin,text);
            // loop until the user press the return key
            while(!text.empty())
            {
                cout << endl << endl;
                cout << "Unscrambled:   " << "\"" <<UnscrambleText(text) 
                     << "\"\n";
                Pause();
                cout << endl;
                cout << "Enter more text to be unscrambled,"
                     << "or press enter to return to the menu:\n";
                getline(cin,text);
            }
        }
        menu.display();
        choice = menu.getChoice();
    }
}

// -------- function definitions section ---------
void BuildMenu(Menu& menu)
{
    menu.setTitle("Choose Action:");
    menu.addOption("Quit");
    menu.addOption("Scramble Text");
    menu.addOption("Unscramble Text");
}

string ScrambleText(const string scramble)
{
    string lower, upper;
    // set base condition
    if(scramble.length() > 1)
    {
        int mid = scramble.size()/2;
        // recursive function for lower part of the string
        lower = ScrambleText(scramble.substr(0,mid));
        // recursive function for upper part of the string
        upper = ScrambleText(scramble.substr(mid+1));
        // return the unscrambled string
        return scramble[mid] + lower + upper;
    }
    else
    {
        return scramble;
    }
}

string UnscrambleText(const string unscramble)
{
    string lower, upper;
    // set base condition
    if(unscramble.length() > 1)
    {
        int mid = unscramble.size()/2;
        // recursive function for lower part of the string
        lower = UnscrambleText(unscramble.substr(1, mid));
        // recursive function for upper part of the string
        upper = UnscrambleText(unscramble.substr(mid+1));
        // return the scrambled string
        return lower + unscramble[0] + upper;
    }
    else
    {
        return unscramble;
    }
}