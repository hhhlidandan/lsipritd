#include "Date.h"

void Date::InitDate(int year, int month, int day)
{
	_year = year;
	_month = month;
	_day = day;
}
void Date::showDate()
{
	cout << _year << " " << _month << " " << _day << endl;
}
int main()
{
	Date s1;
	s1.InitDate(2019, 12, 6);
	s1.showDate();
	system("pause");
	return 0;
}