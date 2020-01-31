#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<assert.h>
#include<malloc.h>
#pragma warning(disable:4996)
using namespace std;

#if 1
class Date
{
public:
	//���캯��
	Date(int year = 2019, int month = 5, int day = 14)
	{
		cout << "Date(int,int,int):" << this << endl;
		_year = year;
		_month = month;
		_day = day;
	}
	//�������캯��
	Date(const Date& d)
	{
		cout << "Date(const Date&)"<< this << endl;
		_year = d._year;
		_month = d._month;
		_day = d._day;
	}
	~Date()//��������
	{
		cout << "~Date()" << this << endl;
	}
private:
	int _year;
	int _month;
	int _day;
};

void TestDate()
{
	Date d1(2019, 3, 29);
	Date d2(d1);
	Date d3(2018, 3, 29);//�������ڴ��ˣ����Ը�ֵ������
	d3 = d1;//������d1��ֵ��������d3//������Դ�������ͻᵼ���ڴ�й©
	//���ǲ���Ϊ��

}


int main()
{
	TestDate();
	system("pause");
	return 0;
}
#endif

#if 0
#include<cstring>
class String//��װ�ַ���
{
public:
	//���캯��
	String(const char* str = "")
	{
		cout << "String(const char* ):" << this << endl;
		if (_str == nullptr)
		{
			_str = "";
		}
		_str = (char*)malloc(strlen(str) + 1);//���ٿռ�
		strcpy(_str, str);
	}
	//��������
	~String()
	{
		if (_str == nullptr)
		{
			_str = "";
		}
		free(_str);
		_str = nullptr;
		cout << "~String():" << this << endl;
	}
private:
	char* _str;
};
void TestString()
{
	String s1("hello");
	String s2(s1);
}
int main()
{
	TestString();
	system("pause");
	return 0;
}
#endif
