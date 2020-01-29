#include "Date.h"

Date::Date()//无参构造函数
{
	_year = 1203;
	_month = 12;
	_day = 7;
}
//构造函数   完成初始化工作
Date::Date(int year, int month, int day)//构造函数   完成初始化工作
{
	_year = year;
	_month = month;
	_day = day;
}
//void Date::InitDate(int year, int month, int day)
//{
//	_year = year;
//	_month = month;
//	_day = day;
//}
void Date::showDate()
{
	cout << _year << "年" << _month << "月" << _day <<"日" <<endl;
}
int main()
{
	Date s1;//调用无参构造函数
	Date s2(2019, 12, 6);//调用有参构造函数
	//注意：如果通过无参构造函数创建对象时，对象后面不用括号，否则就成了函数声明
	//
	//Date s3();//函数声明

	/*Date s1;
	s1.InitDate(2019, 12, 6);*/
	s1.showDate();
	s2.showDate();
	system("pause");
	return 0;
}