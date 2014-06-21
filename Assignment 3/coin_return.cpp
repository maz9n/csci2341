///////////////////////////////////////////////////////////////////////
// identification section
///////////////////////////////////////////////////////////////////////
/**
@file    coin_return.cpp
@author  Almozaini:Mazen:A00323488:csc34118
@version 1.0
@date	 2014-05-19
@brief
This program works like a change machine, it reports how many of each 
kind of coin is required to make a given amount.
 */

///////////////////////////////////////////////////////////////////////
// self-assessment section
///////////////////////////////////////////////////////////////////////
/*
Program is working as intended
*/

///////////////////////////////////////////////////////////////////////
// includes and usings section
///////////////////////////////////////////////////////////////////////
#include <iostream>
#include <iomanip>
#include "utilities.h"
using namespace std;
using Scobey::DisplayOpeningScreen;
using Scobey::Pause;
using Scobey::ReadDouble;

///////////////////////////////////////////////////////////////////////
// constants section
///////////////////////////////////////////////////////////////////////
const double TOONIE  = 2.00;
const double LOONIE  = 1.00;
const double QUARTER = 0.25;
const double DIME    = 0.10;
const double NICKEL  = 0.05;


/////////////////////////////////////////////////////////////////////////
// function prototypes section
///////////////////////////////////////////////////////////////////////

bool GetAmount
(
    double& amount     // out
);
/**<
 *  Gets the amount in dollars and cents (less than $5.00) from the user.
 *  @return <tt>true</tt> if the amount entered is positive; 
            <tt>false<tt> otherwise.
 *  @param  amount  the variable the amount entered is to be returned in.
 *  @pre    cin is not in a fail state.
 *  @post
 *   -# amount is a multiple of 0.01 (1 cent)
 *   -# cin is empty
 *   -# amount has been set to a value between 0.01 and 4.99 
          and <tt>true</tt> is returned
 *      OR amount is a value &lt;= 0.00 and <tt>false</tt> has been returned
 */

double roundTo
(
    double amount,  // in
    double factor   // in
);
/**<
 *  Returns amount rounded off to the nearest multiple of factor.
 *  @return amount rounded off to the nearest integer multiple of factor.
 *  @param  amount  the amount to be rounded off.
 *  @param  factor  the number to find a multiple of.
 *  @pre    factor != 0.0
 *  @post   no side effects
 */

void ShowChange
(
    double amount   // in
);
/**<
/**<
 *  Prints a table showing the amount of coins required 
 *  to make the given amount in change.
 *  @param  amount  the amount of change to be made.
 *  @pre    none
 *  @post   a table has been printed as follows:
 *   - a title showing the amount to make change for (in dollars)
 *   - a line each for toonies, loonies, quarters, dimes, and nickels,
 *     showing the face value of the coin (in dollars),
 *     the number of that coin required,
 *     and the total value of those coins, and
 *   - a message reminding the user that change amounts are rounded 
 *     to the nearest 5 cents.
 */

void GetAndShowCoins
(
    double coinValue,   // in
    int&   coinCount,   // out
    double& amount      // in-out
);
/**<
 *  Calculates how many coins of the given value are required for change,
 *  and prints one line of a table showing the amount of coins required
 *  to make the given amount in change.
 *  @param  coinValue  the value of the coin to be used in making change.
 *  @param  coinCoint  a variable to hold the number of coins required.
 *  @param  amount     a variable tracking the amount of change required.
 *  @pre
 *   -# coinValue > 0.00
 *   -# amount >= 0.00
 *  @post
 *   -# coinCount has been set to the number of coinValue coins required 
 *      to make change for amount.
 *   -# amount has been reduced by the value of those coins.
 *   -# a formatted line has been printed
 *      showing the face value of the coin (in dollars),
 *      the number of that coin required,
 *      and the total value of those coins.
 */

void GetCoins
(
    double coinValue,   // in
    int&   coinCount,   // out
    double& amount      // in-out
);
/**<
 *  Calculates how many coins of the given value are required for change.
 *  @param  coinValue  the value of the coin to be used in making change
 *  @param  coinCoint  a variable to hold the number of coins required
 *  @param  amount     a variable tracking the amount of change required
 *  @pre
 *   -# coinValue > 0.00
 *   -# amount >= 0.00
 *  @post
 *   -# coinCount has been set to the number of coinValue coins 
 *      required to make change for amount
 *   -# amount has been reduced by the value of those coins
 */

void ShowCoins
(
    double coinValue,   // in
    int    coinCount    // in
);
/**<
 *  Prints one line of a table showing the amount of coins required
 *  to make the given amount in change
 *  @param  coinValue  the value of the coin used in making change
 *  @param  coinCoint  the number of coins used
 *  @pre
 *   -# coinValue > 0.00
 *  @post   a formatted line has been printed showing
 *      - the face value of the coin (in dollars),
 *      - the number of that coin required,
 *      - and the total value of those coins.
 */


///////////////////////////////////////////////////////////////////////
// main function
///////////////////////////////////////////////////////////////////////

int main()
{
    DisplayOpeningScreen("Almozaini:Mazen:A00323488:csc34118",
        "A03:Coin Change Machine");

    cout << "\nThis program reports how much of each coin you need in order to make up a\n"
         << "given amount of change. The amount must be between $0.01 and $4.99 inclusive.\n" << endl;
    Pause();
	double roundIt; 
    double amount = 0.00;
	while(GetAmount(amount))
	{
		roundIt = roundTo(amount,0.01);
		ShowChange(amount);
	}
}

///////////////////////////////////////////////////////////////////////
// function definitions section
///////////////////////////////////////////////////////////////////////

bool GetAmount(double& amount)
{
	cout << "\nEnter 0 or a negative amount to quit.\n";
	ReadDouble("\nEnter the amount of change required: $",amount);
    while(amount >= 5.00)
	{		
		cerr << "I'm afraid the amount must be less than $5.00.\n"
				 << "Please try again.\n";
		cout << "Enter 0 or a negative amount to quit.\n";
		ReadDouble("\nEnter the amount of change required: $",amount);
	}
	while(cin.fail())
	{		
		cerr << "Error: That was not a valid real number. Try again.\n";
		ReadDouble("\nEnter the amount of change required: $",amount);
	}
	if (amount <= 0.00)
	{
        return false;
	}
    else
        return true;
}

double roundTo(double amount, double factor)
{
	return (floor((amount/factor)+0.5))*factor;
}

void GetCoins(double coinValue, int& coinCount, double& amount)
{
	
	while(amount >= coinValue)
	{
		amount = amount - coinValue;
		coinCount++;
	}
}

void ShowCoins(double coinValue,int coinCount)
{
	cout.precision(2);
	cout << fixed;
	cout << "     $" << coinValue << "     " << coinCount << "     $" << coinValue*coinCount << "\n";

}

void GetAndShowCoins(double coinValue, int& coinCount, double& amount)
{
	GetCoins(coinValue, coinCount, amount); 
	ShowCoins(coinValue,coinCount);
	coinCount = 0;
}

void ShowChange(double amount)
{
	double change = amount;
	change = roundTo(change,0.05);
	int coinCount = 0;
	double coinValue = 0.00;
    cout << "\n\nChange for $" << amount << "\n";
    cout << "----------------\n";

	double roundHim = roundTo(amount,0.05);

	GetAndShowCoins(TOONIE, coinCount, roundHim);
	GetAndShowCoins(LOONIE, coinCount, roundHim);
	GetAndShowCoins(QUARTER, coinCount, roundHim);
	GetAndShowCoins(DIME, coinCount, roundHim);
	GetAndShowCoins(NICKEL, coinCount, roundHim);
	roundHim = roundTo(amount,0.05);

	cout << "                     -----\n";
	cout << "                     $" << change << "\n\n";




	cout << "(Reminder: change amounts are rounded to nearest multiple of 5 cents.)\n\n";
	Pause();
}
