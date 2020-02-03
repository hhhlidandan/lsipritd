#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#pragma warning(disable:4996)
using namespace std;
#if 0
class Time
{
public:
	Time(int hour, int minute, int second)
		:_hour(hour), _minute(minute), _second(second)
	{}
private:
	int _hour;
	int _minute;
	int _second;
};
class Date
{
public:
	Date(int year = 2009, int month = 1, int day = 5)
		: _year(year),//this->_year(year)  错误，this在这里还不能用，对象还没有构造完成
		_month(month),
		_day(day),
		_r(_day),
		_a(_day),
		_t(0,0,0)//自己手动初始化的，如果没有初始化，编译器会自动调默认的，调不了就出错
		//_t()  //调用无参默认构造函数 
		//在time类里没有无参构造函数，所以调不了
		//PS：编译器给了构造函数，所以不会生成默认构造函数
	{
		//对象在这已经构造成功
		cout << "Date(int,int,int):" << this << endl;
		_year = year;//赋值
		_month = month;
		_day = day;
	}
	Date(const Date& d) :_year(d._year), _month(d._month), _day(d._month), _r(d._r), _a(d._a)
	{
		cout << "Date(const Date&):" << this << endl;
		_year = d._year;
		_month = d._month;
		_day = d._day;
	}
	~Date()
	{
		cout << "~Date():" << this << endl;
	}
private:
	int _year;
	int _month;
	int _day;
	int& _r;//引用成员变量
	const int _a;//const成员变量
	Time _t;
};

void TestDate()
{
	Date d1(2019, 5, 2);
	//Date d2(d1);
}
int main()
{
	TestDate();
	system("pause");
	return 0;
}
#endif

#if 0
class Date
{
public:
	Date(int year = 2009, int month = 1, int day = 5)
		: _year(year),//this->_year(year)  错误，this在这里还不能用，对象还没有构造完成
		_month(month),
		_day(day)
	{
		//对象在这已经构造成功
		cout << "Date(int,int,int):" << this << endl;
		_year = year;//赋值
		_month = month;
		_day = day;
	}
	Date(const Date& d) :_year(d._year), _month(d._month), _day(d._day)
	{
		cout << "Date(const Date&):" << this << endl;
		_year = d._year;
		_month = d._month;
		_day = d._day;
	}
	~Date()
	{
		cout << "~Date():" << this << endl;
	}
private:
	int _year;
	int _month;
	int _day;
};

void TestDate()
{
	Date d1(2019, 5, 2);
	//Date d2(d1);
}
int main()
{
	TestDate();
	system("pause");
	return 0;
}
#endif

class Date
{
public:
	explicit Date(int year = 2009)
		: _year(year)//this->_year(year)  错误，this在这里还不能用，对象还没有构造完成
	{
		//对象在这已经构造成功
		cout << "Date(int,int,int):" << this << endl;
		_year = year;//赋值
	}
	Date(const Date& d) :_year(d._year)
	{
		cout << "Date(const Date&):" << this << endl;
		_year = d._year;
	}
	~Date()
	{
		cout << "~Date():" << this << endl;
	}
private:
	int _year;
};

void TestDate()
{
	Date d1(2019);
	d1 = 2019;//用整型变量给日期类型对象赋值
	//编译器会用2019构造一个无名对象，最后用无名对象给d1对象赋值
	//2020-->通过单参构造函数-->临时对象
}
int main()
{
	TestDate();
	system("pause");
	return 0;
}
//生成构造函数：
//什么时候，编译器才会生成？
//编译器需要的时候，就会生成    编译器需要的？
//