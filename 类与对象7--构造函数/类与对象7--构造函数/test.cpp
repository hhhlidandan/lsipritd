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
		: _year(year),//this->_year(year)  ����this�����ﻹ�����ã�����û�й������
		_month(month),
		_day(day),
		_r(_day),
		_a(_day),
		_t(0,0,0)//�Լ��ֶ���ʼ���ģ����û�г�ʼ�������������Զ���Ĭ�ϵģ������˾ͳ���
		//_t()  //�����޲�Ĭ�Ϲ��캯�� 
		//��time����û���޲ι��캯�������Ե�����
		//PS�����������˹��캯�������Բ�������Ĭ�Ϲ��캯��
	{
		//���������Ѿ�����ɹ�
		cout << "Date(int,int,int):" << this << endl;
		_year = year;//��ֵ
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
	int& _r;//���ó�Ա����
	const int _a;//const��Ա����
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
		: _year(year),//this->_year(year)  ����this�����ﻹ�����ã�����û�й������
		_month(month),
		_day(day)
	{
		//���������Ѿ�����ɹ�
		cout << "Date(int,int,int):" << this << endl;
		_year = year;//��ֵ
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
		: _year(year)//this->_year(year)  ����this�����ﻹ�����ã�����û�й������
	{
		//���������Ѿ�����ɹ�
		cout << "Date(int,int,int):" << this << endl;
		_year = year;//��ֵ
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
	d1 = 2019;//�����ͱ������������Ͷ���ֵ
	//����������2019����һ������������������������d1����ֵ
	//2020-->ͨ�����ι��캯��-->��ʱ����
}
int main()
{
	TestDate();
	system("pause");
	return 0;
}
//���ɹ��캯����
//ʲôʱ�򣬱������Ż����ɣ�
//��������Ҫ��ʱ�򣬾ͻ�����    ��������Ҫ�ģ�
//