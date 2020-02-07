#include<iostream>
#include<stdio.h>
#include<stdlib.h>
using namespace std;
class Date
{
public:
	Date(int year, int month, int day)//���캯��
	{
		if (year > 0 && month > 0 && month<13 && day>0 && day <= GetMonthDay(year, month))
		{
			_year = year;
			_month = month;
			_day = day;
		}
		else
		{
			cout << "error!" << endl;
		}
	}
	~Date()//��������
	{}
	Date(const Date& d)//�������캯��
	{
		_year = d._year;
		_month = d._month;
		_day = d._day;
	}
	Date& operator=(const Date& d)//��ֵ���������
	{
		if (this != &d)
		{
			_year = d._year;
			_month = d._month;
			_day = d._day;
		}
		return *this;
	}
	//���������== != > >= < <=
	bool operator==(const Date& d) const
	{
		return _year == d._year&&
			_month == d._month&&
			_day == d._day;
	}
	bool operator!=(const Date& d) const
	{
		return !(*this == d);
	}
	bool operator>(const Date& d)
	{
		return ((_year > d._year) || \
			(_year == d._year&&_month > d._month) || \
			(_year == d._year&&_month == d._month&&_day > d._day));
	}
	bool operator>=(const Date& d)//����������>  ==ʵ�ֹ���
	{
		return (*this > d) || (*this == d);
	}
	bool operator<(const Date& d)
	{
		return !(*this >= d);
	}
	bool operator<=(const Date& d)
	{
		return !(*this>d);
	}
	//ǰ��++��--����++��--
	Date& operator++()
	{
		*this += 1;
		return *this;
	}
	Date operator++(int)
	{
		Date temp = (*this);
		*this += 1;
		return temp;
	}
	Date& operator--()
	{
		*this -= 1;
		return *this;
	}
	Date operator--(int)
	{
		Date temp = (*this);
		*this -= 1;
		return temp;
	}
////////////////////////////////////
	//����һ�������
	int GetMonthDay(int year, int month)
	{
		static int GetMonthDay[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
		//�����ƽ�꣬2����29��
		if ((month == 2) && ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)))
		{
			return 29;
		}
		return GetMonthDay[month];
	}
////////////////////////////////////////
	//���ں������ļӼ�
	Date operator+(int day)
	{
		Date temp(*this);
		temp += day;
		return temp;
	}
	Date operator-(int day)
	{
		Date temp(*this);
		temp -= day;
		return temp;
	}
	Date& operator+=(int day)
	{	
		if (day<0)
		{
			return *this -= -day;
		}
		_day += day;
		while (_day>GetMonthDay(_year, _month))
		{
			_day -= GetMonthDay(_year, _month);
			_month++;
			if (_month>12)
			{
				_year++;
				_month = 1;
			}
		}
		return *this;
	}
	Date& operator -= (int day)
	{
		if (day < 0)
		{
			return *this += (-day);
		}
		_day -= day;
		while (_day <= 0)
		{
			_month--;
			if (_month == 0)
			{
				_year--;
				_month = 12;
			}
			_day += GetMonthDay(_year, _month);
		}
		return *this;
	}
	//����-����
	int operator-(const Date& d)
	{	
		int flag = 1;
		int day = 0;
		Date max = *this;
		Date min = d;
		if (*this < d)
		{
			max = d;
			min = *this;
			flag = -1;
		}
		//С������һֱ++���ӵ��ʹ������һ��ʱ�����˶�����Ͳ���ٴ�
		while (min != max)
		{
			min++;
			day++;
		}
		return day*flag;
	}
/////////////////////////////////////////////////////	
	void Test()
	{
		cout << _year << "--" << _month << "--" << _day << endl;
	}
private:
	int _year;
	int _month;
	int _day;
};
int main()
{
	Date d1(2019, 1, 1);
	d1 += 100;//����+����
	d1.Test();
	d1 -= 100;//����-����
	d1.Test();

	(++d1).Test();
	(d1++).Test();
	d1.Test();

	Date d2(2019, 1, 28);
	Date d3(2019, 5, 1);
	cout << (d2 - d3) << endl;//����������
	cout << (d3 - d2) << endl;

	system("pause");
	return 0;
}