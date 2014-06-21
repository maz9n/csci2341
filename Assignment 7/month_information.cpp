/**
@file    month_information.cpp
@author  Almozaini:Mazen:A00323488:csc34118
@version 1.0
@date    2014-06-02
*   Assignment #7 
*   due 2014-06-04
@brief
a simple program that gives information about the months of the year.
*/

/*
the program is working fine.
*/

//-------- includes and usings section --------
#include <iostream>
#include <exception>
#include <stdexcept>
#include <algorithm> // for transform() function
using namespace std;

#include "utilities.h"

using Scobey::DisplayOpeningScreen;
using Scobey::Pause;
using Scobey::ReadThisLine;

//------ function prototypes section ------
int MonthNameToNumber
    (
    string name          //in
    );
/**<
*  Returns the number of the month (1..12) named in the given string
*  @return     the corresponding month number.
*  @param      name the month name to be converted to a number
*  @pre        the input stream is not empty
*  @post       
*   - a month name is converted to the corresponding number.
*   - if an invalid name is given throw an exception.
*/
int daysInMonth
    (
    int month,          // in
    bool isLeapYear     // in
    );
/**<
*  Returns the number of days in the given month; for leap year if isLeapYear is true.
*  @return     days of the given month and for leap year if isLeapYea is <tt>true</tt>
*  @param      month  
*  @param      isLeapYear
*  @pre        the month number is given by the user
*  @post       number of days is returned and displayed
*/
//-------- main function ---------
int main()
{
    DisplayOpeningScreen("Almozaini:Mazen:A00323488:csc34118",
        "Assignment 07: Month-Information Program");

    string text;
    int monthNum = 0;
    ReadThisLine("Enter the name of a month: ",text);
    while(!text.empty())
    {
        try
        {
            monthNum = MonthNameToNumber(text);
            cout << endl;
            cout << "\n" << text << " is month #" << monthNum
                << " in our calendar.\n";
            if(monthNum == 2)
            {
                cout << "It has " << daysInMonth(monthNum,false) 
                    << " days in a regular year,"
                    << "and " << daysInMonth(monthNum,true) 
                    << " days in a leap year.\n";
            }
            else
                cout << "It has " << daysInMonth(monthNum,false)
                << " days.\n";

            cout << endl;
            ReadThisLine("Enter the name of a month, or press enter to quit: ",text);
        }
        catch(const invalid_argument& e)
        {
            cerr << "'"<< e.what() << "' isn't the name of"
                << " a month.\n\n";
            ReadThisLine("Enter the name of a month, or press enter to quit: ",text);
        }
    }
    Pause();
    return(0);
}

// -------- function definitions section ---------

int MonthNameToNumber(string name)
{
    // transform to lower case for comparison
    transform(name.begin(), name.end(), name.begin(), tolower);

    if(name == "january")
        return 1;
    else if (name == "february")
        return 2;
    else if (name == "march")
        return 3;
    else if (name == "april")
        return 4;
    else if (name == "may")
        return 5;
    else if (name == "June")
        return 6;
    else if(name == "july")
        return 7;
    else if (name == "august")
        return 8;
    else if (name == "september")
        return 9;
    else if (name == "october")
        return 10;
    else if (name == "november")
        return 11;
    else if (name == "december")
        return 12;
    else
        throw invalid_argument(name);
}
int daysInMonth(int month, bool isLeapYear)
{
    int Days;

    if (month == 4 || month == 6 || month == 9 || month == 11)
    {
        Days = 30;
    }
    else if (month == 2)
    {
        if (isLeapYear == true)
        {
            Days = 29;
        }
        else
        {
            Days = 28;
        }
    }
    else
    {
        Days = 31;
    }
    return Days;
}