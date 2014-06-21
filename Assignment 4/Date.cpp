/**
@file    Date.cpp
@author  Almozaini:Mazen:A00323488:csc34118
@version 1.0
@date	 2014-05-20
@brief

 */

#include "Date.h"

// includes
#include <iostream>
using namespace std;

Date::Date(int year, int month, int day)
{
	if(set(year, month, day))
	{
		y = year;
		m = month;
		d = day;
	}
	else
	{
		set(2014, 01, 01);
	}
}
bool Date::set(int year, int month, int day)
{
	int maxDays = daysInMonth(month,year);
	if(year > 0 && (month > 0 && month < 13) && day > 0 && day <= maxDays)
	{
		y = year;
		m = month;
		d = day;
		return true;
	}
	return false;
}

void Date::print() const
{
    cout << y << "-" << (getMonth()/10) << (getMonth()%10) << "-"<< (getDay()/10)
		 << (getDay()%10)<< endl;
}

int Date::getYear() const
{
	return y;
}

int Date::getMonth() const
{
	return m;
}

int Date::getDay() const
{
	return d;
}

bool Date::equals(Date other) const
{
	if(y == other.y && m == other.m 
		&& d == other.d)
		return true;
	else
		return false;
}

bool Date::before(Date other) const
{
	if(y < other.y || (y == other.y && m < other.m)
		|| y == other.y && m == other.m && d < other.d)
		return true;
	else
		return false;
}

bool Date::isLeapYear(int y)
{
    if(y % 4 == 0 && y % 100 != 0 || y % 400 == 0)
    {
        return true;
    }
    else 
        return false;
}

int Date::daysInMonth(int m, int y)
{
    int Days;
 
    if (m == 4 || m == 6 || m == 9 || m == 11)
    {
        Days = 30;
    }
    else if (m == 2)
    {
       if (isLeapYear(y))
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
