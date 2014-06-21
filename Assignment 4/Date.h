/**
*  @file Date.h
*  @author Almozaini:Mazen:A00323488:csc34118
*  @version 1.0
*  @date 2014-05-15
*
*  A header file showing the set, get and print methods for the date.
*/
#ifndef DATE_H
#define DATE_H

class Date // of integer values
{
public:
	bool set(int y, int m, int d);
	/**<
	sets the date to the given values, if they are appropriate
	@return <tt>true</tt> if they areappropriate, <tt>false</tt> if they're not
	@param m the month
	@param y the year
	@param d the day
	*/
	void print() const;
	/**<
	prints the date to cout in the YYYY-MM-DD (SI) format
	@return void
	@param none
	*/
	int getYear() const;
	/**<
	gets the year
	@return int the year
	@param none
	*/
	int getMonth() const;
	/**<
	gets the month
	@return int the month (1..12)
	@param none
	*/
	int getDay() const;
	/**<
	gets the day
	@return int the day (1..31)
	@param none
	*/

	// whether this Date and other Date represent the same date
	bool equals(Date other) const;

	// whether this Date comes/came before other Date
	bool before(Date other) const;

	// whether the given year (y) is a leap year
	bool static isLeapYear(int y);

	// returns number of days in the given month of the given year (or year 1, if no year is given)
	int static daysInMonth(int m, int y = 1);
	
	// constructor
	Date(int y = 2014, int m = 01, int d = 01);

	private:
	int y;
	int m;
	int d;
};
#endif DATE_H