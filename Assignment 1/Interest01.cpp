/**
@file Interest01.cpp
@author Almozaini:Mazen:A00323488:csc34118
@version 1.0
@date	 2014-05-08
@brief
This program demonstrate the use of namespaces and doxygen doxygen.
*/

/*
(Scobey) namespace was used in this assignment.
*/

// includes + usings
#include <iostream>
#include "utilities.h"
using namespace std;
using namespace Scobey;

int main()
{
    cout << "Almozaini:Mazen:A00323488:CSCI2341" << endl;
    cout << "A01:Interest payments on loans\n\n" << endl;
    
    // Program description ...
    cout << "This program calculates payments on a consumer loan.  You enter\n"
         << "the amount of the loan, the annual interest rate, and the\n"
         << "amount of the monthly payment.  It reports month by month on\n"
         << "how much interest you're charged, and the amount remaining on\n"
         << "the loan.  At the end it reports how many months it took to\n"
         << "repay the loan, and how much interest you paid in total.";
    Pause(0,"\n\n");

    // Asks the user for input ...
    double loan, Aintrest, payment, Mintrest;
    ReadDouble("\nEnter amount of the loan: $",loan);
    ReadDouble("Enter the annual interest rate (in %): ",Aintrest);
    ReadDouble("Enter your monthly payment: $",payment);
    Pause(0,"\n");

    // Display the input with Monthly intrest rate ...
    Mintrest = Aintrest/12;
    cout << "\nLoan Amount:     $" << loan << endl;
    cout << "Monthly Payment: $" << payment << endl;
    cout << "Annual Interest:  " << Aintrest << "%" << endl;
    cout << "Monthly Interest: " << Mintrest << "%\n" << endl;
    Pause();
    cout << "\n\n";

    int months = 0;
    double total= 0;
    double amount = loan;
    while(amount > 0)
    {
            months ++;
            double intrest = (amount/100)*Mintrest;
            cout << "Month " << months << ", amount owed $" << amount << ", interest charged $" << intrest << endl;
            amount = amount + intrest - payment;
            total += intrest;
    }
    cout << "\n";
    Pause();
    cout << "\n\n";

    cout << "Loan paid off in " << months << " months.\n";
    cout << "Total interest paid was $" << total << ".";

    cout << "\n\nPress enter to finish...";
    cin.ignore(80,'\n');
}