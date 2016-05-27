#ifndef DATE_H_
#define	DATE_H_
class Date
{
public:
	Date();
	Date(int month, int day, int year);
	const int GetMonth() const;
	const int GetDay() const;
	const int GetYear() const;
	const bool CheckDate(const int m,const int d,const int y);
	bool SetFormat(char f);
	void Input();
	void Show();
	void Increment(const int numDays = 1);
	int Compare(const Date& d);
private:
	int month;
	int day;
	int year;
	char format;
};

#endif