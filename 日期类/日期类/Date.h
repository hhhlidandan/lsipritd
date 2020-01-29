#include<iostream>
#include<cstdio>
#include<cstdlib>
using namespace std;
//日期类
class Date
{
public:
	//构造函数----完成初始化工作
	Date();//无参构造函数
	Date(int year, int month, int day);//有参构造函数 

	void showDate();//显示
	//void InitDate(int year, int month, int day);//初始化
private:
	int _year;
	int _month;
	int _day;

};
