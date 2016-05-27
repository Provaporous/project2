#include <iostream>
#include "date.h"

using namespace std;

int main()
{
	Date d1;             // initializes to Jan 1, 2000 
	Date d2(3, 4, 1992);   // initializes to March 4, 1992 
	Date d3(13, 30, 1990); // invalid month, initializes to Jan 1, 2000 instead. 

	
	d3.Show();
	cout << endl;
	d3.Increment(5);
	cout << endl;
	d3.Show();
	cout << endl<<d3.Compare(d2);
}