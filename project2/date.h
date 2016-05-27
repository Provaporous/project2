#ifndef DATE_H_
#define	DATE_H_
class Date
{

public:
	Date();															//	Default constructor, sets date to Jan 1, 2000, default format.
	Date(int month, int day, int year);								//	Checks date, if valid sets to the paramaeters entered, default format.
	const int GetMonth() const;										//	Returns month.
	const int GetDay() const;										//	Returns day.
	const int GetYear() const;										//	Returns year.
	const bool CheckDate(const int m,const int d,const int y);		//	Checks if the date is valid, handles leapyears.
	bool SetFormat(char f);											//	Mutates Format. Returns false if a bad param is passed in, handles Julian calendar.
	void Input();													//	Mutates month,day, and year if the date entered is valid, handles leapyears
	void Show();													//	Sends the date in the current format to the output stream, handles Julian claendar
	void Increment(const int numDays = 1);							//	incriments the date, 1 day by default, handles Julian calendar and leap years.
	int Compare(const Date& d);										//	compares two dates and returns an int if the caller is before, the same , or after the parameter

private:
	int month;						//	Month
	int day;						//	Day of the month
	int year;						//	Year
	char format;					//	The format for the show() function

};

#endif