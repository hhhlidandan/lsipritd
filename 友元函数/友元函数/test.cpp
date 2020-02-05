#include<iostream>
#include<stdio.h>
#include<stdlib.h>
using namespace std;
class Date
{
	friend ostream& operator<<(ostream& _cout, const Date& d);//��Ԫ���� ��������˽�г�Ա
	friend istream& operator>>(istream& _cin, Date& d);
public:
	Date(int year=1888, int month=11, int day=1)
		:_year(year),
		_month(month),
		_day(day)
	{
		cout << "Date():" << this << endl;
	}
	Date(const Date& d)
	{
		cout << "Date&():" << this << endl;
		_year = d._year;
		_month = d._month;
		_day = d._day;
	}
	
	void PrintDate()
	{
		cout << _year << "--" << _month << "--" << _day << endl;
	}
	//���������������operator<<
	//void operator<<(const Date& d)//ostream��cout��һ������
	//{
	//	_cout << _year << "--" << _month << "--" << _day << endl;
	//}
	~Date()
	{
		cout << "~Date():" << endl;
	}
private:
	int _year;
	int _month;
	int _day;
};
//���س�ȫ�ֵĺ���
ostream& operator<<(ostream& _cout, const Date& d)//ostream��cout��һ������
{
	_cout << d._year << "--" << d._month << "--" << d._day;
	return _cout;
}
istream& operator>>(istream& _cin, Date& d)
{
	_cin >> d._year;
	_cin >> d._month;
	_cin >> d._day;
	return _cin;
}
int main()
{
	Date d;
	cin >> d;
	d.PrintDate();//��ӡ
	cout << d << endl;
	system("pause");
	return 0;
}