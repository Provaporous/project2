#include "date.h"
#include <iostream>
#include <iomanip>
using namespace std;

// Autsin Gottselig
// COP 3330
// Date.cpp
//
//	This class creates and modifies Date objects for use in other main functions.
//	This class will also handle leap years and julian date output formatting.
//
//


//CONSTRUCTORS
//
//	The caller can either call with no parameters, or all 3
//	If the date is invalid, the date is set to jan 1, 2000
//	only positive years allowed

Date::Date()
{
	month = 1;
	day = 1;
	year = 2000;
	format = 'D';
}
Date::Date(int m, int d, int y)
{
	if (CheckDate(m, d, y))
	{
		month = m;
		day = d;
		year = y;
		format = 'D';
	}
	else
	{
		month = 1;
		day = 1;
		year = 2000;
		format = 'D';
	}
	
}

//	const bool Date::CheckDate
//	
//	PARAMETERS: (const int m,const int d,const int y)
//
//	const int m : month, is not changed by function.
//	const int d : day, is not changed by function.
//	const int y : year, is not changed by function.
// 
//
//	This member function checks if a date is valid for the year given.
//	Handles leapyears
const bool Date::CheckDate(const int m,const int d,const int y)
{
	
	bool leapyear = false;
	if (y % 4 == 0) leapyear = true;
	if (y % 4 == 0 && y % 100 == 0) leapyear = false;
	if (y % 4 == 0 && y % 100 == 0 && y % 400 == 0) leapyear = true;
	if (leapyear)
	{
		if (m == 1 && (d < 1 || d>31)) return false;
		if (m == 2 && (d < 1 || d>29)) return false;
		if (m == 3 && (d < 1 || d>31)) return false;
		if (m == 4 && (d < 1 || d>30)) return false;
		if (m == 5 && (d < 1 || d>31)) return false;
		if (m == 6 && (d < 1 || d>30)) return false;
		if (m == 7 && (d < 1 || d>31)) return false;
		if (m == 8 && (d < 1 || d>31)) return false;
		if (m == 9 && (d < 1 || d>30)) return false;
		if (m == 10 && (d < 1 || d>31)) return false;
		if (m == 11 && (d < 1 || d>30)) return false;
		if (m == 12 && (d < 1 || d>31)) return false;
		if (m > 12 || m < 1) return false;
		else if (y < 1) return false;
		else return true;
	}
	if (!leapyear)
	{
		if (m == 1 && (d < 1 || d>31)) return false;
		if (m == 2 && (d < 1 || d>28)) return false;
		if (m == 3 && (d < 1 || d>31)) return false;
		if (m == 4 && (d < 1 || d>30)) return false;
		if (m == 5 && (d < 1 || d>31)) return false;
		if (m == 6 && (d < 1 || d>30)) return false;
		if (m == 7 && (d < 1 || d>31)) return false;
		if (m == 8 && (d < 1 || d>31)) return false;
		if (m == 9 && (d < 1 || d>30)) return false;
		if (m == 10 && (d < 1 || d>31)) return false;
		if (m == 11 && (d < 1 || d>30)) return false;
		if (m == 12 && (d < 1 || d>31)) return false;
		if (m > 12 || m < 1) return false;
		else if (y < 1) return false;
		else return true;
	}
}

//	const int Date::GetMonth() const
//	
//	PARAMETERS: none
// 
//	This member function returns the month, a private data item.
const int Date::GetMonth() const 
{
	return month;
}

//	const int Date::GetDay() const
//	
//	PARAMETERS: none
// 
//	This member function returns the day, a private data item.
const int Date::GetDay() const 
{
	return day;
}

//	const int Date::GetYear() const
//	
//	PARAMETERS: none
// 
//	This member function returns the year, a private data item.
const int Date::GetYear() const
{
	return year;
}

//	bool Date::SetFormat
//	
//	PARAMETERS: (char f)
// 
//	char f : The format requested, D,T,L, or J are allowed
//
//	This member finction mutates the private data item format, to either default,two digit, long, or julian format.
//	returns true if exits correctly.
bool Date::SetFormat(char f)
{
	if (f == 'D' || f == 'T' || f == 'L'|| f=='J')
	{
		format = f;
		return true;
	}
	else return false;
}

//	void Date::Input()
//	
//	PARAMETERS: none
//
//	This member function mutates the date member data based on what the user enters on the keyboard.
//	error checks usign the checkdate function.
void Date::Input()
{
	int m, d, y;
	char trash;
	bool flag=true;
	while (flag)
	{
		flag = true;
		cout <<endl<< "Enter a date in the format month/day/year: ";
		cin >> m >> trash >> d >> trash >> y;
		if (CheckDate(m,d,y)) flag=false;
		else cout << "Invalid date.  Try again YOU CLOD!";
	} 
	month = m;
	day = d;
	year = y;
}

//	void Date::Show()
//	
//	PARAMETERS: none
//
//	This member function prints the date to the screen based on the current format of the object.
//	Handles leap years and the Julian calendar
//	resets changes to the output stream
void Date::Show()
{
	// capture current output stream settings
	int oldprecision = cout.precision();
	char oldfill = cout.fill();
	ios_base::fmtflags oldflags = cout.flags();

	bool leapyear = false;
	if (year % 4 == 0) leapyear = true;
	if (year % 4 == 0 && year % 100 == 0) leapyear = false;
	if (year % 4 == 0 && year % 100 == 0 && year % 400 == 0) leapyear = true;

	switch (format)
	{
	case 'D':
		cout << month << '/' << day << '/' << year;
		break;
	case 'T':
		cout <<fixed<< setw(2) << setfill('0') << month << '/' << fixed << setw(2) << setfill('0') << day << '/' << fixed << setw(2) << setfill('0') <<year%100;
		break;
	case 'L':
		switch (month)
		{
		case 1:
			cout << "Jan ";
			break;
		case 2:
			cout << "Feb ";
			break;
		case 3:
			cout << "Mar ";
			break;
		case 4:
			cout << "Apr ";
			break;
		case 5:
			cout << "May ";
			break;
		case 6:
			cout << "June ";
			break;
		case 7:
			cout << "July ";
			break;
		case 8:
			cout << "Aug ";
			break;
		case 9:
			cout << "Sept ";
			break;
		case 10:
			cout << "Oct ";
			break;
		case 11:
			cout << "Nov ";
			break;
		case 12:
			cout << "Dec ";
			break;
		default: cout << "ERR0R 37";
		}
		cout << day << ", " << year;
		break;
	case 'J':
		cout << fixed << setw(2) << setfill('0') << year % 100<<'-';
		switch (month)
		{
		case 1:
			cout << fixed << setw(3) << setfill('0') << day;
			break;
		case 2:
			cout << fixed << setw(3) << setfill('0') << day+31;
			break;
		case 3:
			if(leapyear)cout << fixed << setw(3) << setfill('0') << day + 31 + 29;
			else cout << fixed << setw(3) << setfill('0') << day + 31 + 28;
			break;
		case 4:
			if (leapyear)cout << fixed << setw(3) << setfill('0') << day + 31 + 29 + 31;
			else cout << fixed << setw(3) << setfill('0') << day + 31 + 28+31;
			break;
		case 5:
			if (leapyear)cout << fixed << setw(3) << setfill('0') << day + 31 + 29 + 31+30;
			else cout << fixed << setw(3) << setfill('0') << day + 31 + 28 + 31+30;
			break;
		case 6:
			if (leapyear)cout << fixed << setw(3) << setfill('0') << day + 31 + 29 + 31 + 30 + 31;
			else cout << fixed << setw(3) << setfill('0') << day + 31 + 28 + 31 + 30 + 31;
			break;
		case 7:
			if (leapyear)cout << fixed << setw(3) << setfill('0') << day + 31 + 29 + 31 + 30 + 31 + 30;
			else cout << fixed << setw(3) << setfill('0') << day + 31 + 28 + 31 + 30 + 31 + 30;
			break;
		case 8:
			if (leapyear)cout << fixed << setw(3) << setfill('0') << day + 31 + 29 + 31 + 30 + 31 + 30 + 31;
			else cout << fixed << setw(3) << setfill('0') << day + 31 + 28 + 31 + 30 + 31 + 30 + 31;
			break;
		case 9:
			if (leapyear)cout << fixed << setw(3) << setfill('0') << day + 31 + 29 + 31 + 30 + 31 + 30 + 31 + 31;
			else cout << fixed << setw(3) << setfill('0') << day + 31 + 28 + 31 + 30 + 31 + 30 + 31 + 31;
			break;
		case 10:
			if (leapyear)cout << fixed << setw(3) << setfill('0') << day + 31 + 29 + 31 + 30 + 31 + 30 + 31 + 31 +30;
			else cout << fixed << setw(3) << setfill('0') << day + 31 + 28 + 31 + 30 + 31 + 30 + 31 + 31 +30;
			break;
		case 11:
			if (leapyear)cout << fixed << setw(3) << setfill('0') << day + 31 + 29 + 31 + 30 + 31 + 30 + 31 + 31 + 30 + 31;
			else cout << fixed << setw(3) << setfill('0') << day + 31 + 28 + 31 + 30 + 31 + 30 + 31 + 31 + 30 + 31;
			break;
		case 12:
			if (leapyear)cout << fixed << setw(3) << setfill('0') << day + 31 + 29 + 31 + 30 + 31 + 30 + 31 + 31 + 30 + 31 + 30;
			else cout << fixed << setw(3) << setfill('0') << day + 31 + 28 + 31 + 30 + 31 + 30 + 31 + 31 + 30 + 31 + 30;
			break;
		default: cout << "this shouldnt't happen, what did you do!";
		}
	}



	// PUT THINGS BACK THE WAY THEY WERE WHEN I FOUND THEM
	cout.precision(oldprecision);	// restore old precision setting
	cout.fill(oldfill);			// restore old fill char setting
	cout.flags(oldflags);		// restore all prior format flags
}

//	void Date::Increment
//	
//	PARAMETERS: (const int n)
//
//	const int n: the number of days to increment by.
//
//	This member function increments the date.
//	Handles leap years and the Julian calendar.
//	Handles values of n that go over multiple months and years.
void Date::Increment(const int n)
{
	
	
	
	int tempDay=day+n;
	int tempMonth=month;
	int tempYear=year;


	if (CheckDate(tempMonth, tempDay, tempYear))
	{
		day=tempDay;
		return;
	}
	while (CheckDate(tempMonth, tempDay, tempYear)==false)
	{
		bool leapyear = false;
		if (tempYear % 4 == 0) leapyear = true;
		if (tempYear % 4 == 0 && tempYear % 100 == 0) leapyear = false;
		if (tempYear % 4 == 0 && tempYear % 100 == 0 && tempYear % 400 == 0) leapyear = true;
		
		
		if (tempMonth == 1 && (tempDay > 31))
		{
			tempMonth++;
			tempDay= tempDay - 31;
		};
		if (tempMonth == 2 && (tempDay > 29))
		{
			tempMonth++;
			if(leapyear)tempDay = tempDay -29;
			else tempDay = tempDay - 28;
		};
		if (tempMonth == 3 && (tempDay > 31))
		{
			tempMonth++;
			tempDay = tempDay - 31;
		};
		if (tempMonth == 4 && (tempDay > 30))
		{
			tempMonth++;
			tempDay = tempDay - 30;
		};
		if (tempMonth == 5 && (tempDay > 31))
		{
			tempMonth++;
			tempDay = tempDay - 31;
		};
		if (tempMonth == 6 && (tempDay > 30))
		{
			tempMonth++;
			tempDay = tempDay - 30;
		};
		if (tempMonth == 7 && (tempDay > 31))
		{
			tempMonth++;
			tempDay = tempDay - 31;
		};
		if (tempMonth == 8 && (tempDay > 31))
		{
			tempMonth++;
			tempDay = tempDay - 31;
		};
		if (tempMonth == 9 && (tempDay > 30))
		{
			tempMonth++;
			tempDay = tempDay - 30;
		};
		if (tempMonth == 10 && (tempDay > 31))
		{
			tempMonth++;
			tempDay = tempDay - 31;
		};
		if (tempMonth == 11 && (tempDay > 30))
		{
			tempMonth++;
			tempDay = tempDay - 30;
		};
		if (tempMonth == 12 && (tempDay > 31))
		{
			tempMonth=1;
			tempYear++;
			tempDay = tempDay - 31;
		};
		year = tempYear;
		month = tempMonth;
		day = tempDay;
	}
	
	

}

//	int Date::Compare(const Date& d)
//	
//	PARAMETERS: (const Date& d)
//
//	const Date& d: the date object to be compared to
//
//	This member function returns -1 if the caller comes before the parameter,
//	0 if it is the same date, and 1 if the callign object is after the parameter.
int Date::Compare(const Date& d)
{
	if (year < d.year) return -1;
	if (year > d.year) return 1;
	if (year == d.year)
	{
		if (month < d.month) return -1;
		if (month > d.month) return 1;
		if (month == d.month)
		{
			if (day < d.day)return -1;
			if (day > d.day)return 1;
			if (day == d.day) return 0;
		}
	}
}