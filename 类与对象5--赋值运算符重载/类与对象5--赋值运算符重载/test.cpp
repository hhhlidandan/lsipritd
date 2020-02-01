#include<iostream>
using namespace std;
class Date
{
public:
	Date(int year = 2019, int month = 6, int day = 8)
	{
		cout << "Date(int,int,int):" << this << endl;
		_year = year;
		_month = month;
		_day = day;
	}
	
	Date(const Date& d)
	{
		_year = d._year;
		_month = d._month;
		_day = d._day;
		cout << "Date& (int):" << this << endl;
	}
	//赋值运算符重载
	Date& operator=(const Date& d)
	{
		if (this != &d)//排除对象自己给自己赋值
		{
			_year = d._year;
			_month = d._month;
			_day = d._day;
		}
		return *this;
	}
	//运算符重载
	//+号重载
	Date operator+(int day)//this相当于const Date& d,第一个参数
	{
		//_day: *this+day//加号不改变左右操作数的值
		Date temp(*this);
		temp._day += day;//构造临时对象用this构造
		return temp;//返回的对象生命周期要比函数的生命周期长
		//所以，临时变量就不能用引用返回了
	}
	//引用作为函数的返回值类型，要注意：不能返回函数栈上的空间
	//栈上的：函数体里面的局部变量，已经被系统回收，没有意义
	//
	Date& DateAdd(int day)
	{
		_day += day;
		return *this;
	}
	//重载==
	bool operator==(const Date& d)//操作符左边的操作数是this，所以只需要传右边的操作数
	{
		return _year == d._year&&\
			_month == d._month&&\
			_day == d._day;
	}
	////重载!=
	bool operator!=(const Date& d)
	{
		return !(*this == d);
	}
	//前置++  d2 = ++d1
	Date& operator++()//直接加到this上返回，所以用引用
	{
		_day += 1;
		return *this;
	}
	//后置++
	Date operator++(int)//返回+完之后的新值，所以不能用引用，
	{
		Date temp = (*this);//先将之前的值保存起来
		_day += 1;
		return temp;//返回函数体里的林斯和变量，不能用引用
	}
	//前置--
	Date& operator--()
	{
		_day -= 1;
		return *this;
	}
	//后置--
	Date operator--(int)//加参数是为了区分前置还是后置
	{
		Date temp = (*this);
		_day -= 1;
		return temp;
	}

	~Date()
	{
		cout << "`Date():" << this << endl;
	}
private:
	int _year;
	int _month;
	int _day;
};

void TestDate()
{
	Date d1(2019, 2, 22);
	d1.DateAdd(3);
	d1 = d1 + 3;///重载 +  =
	

	Date d2(d1);//拷贝构造

	Date d3(2018, 2, 22);
	d3 = d1;//d1的值给d3  重载 =
	d3.operator=(d1);//d3=d1 实际上是这样的
	d1 = d2 = d3;
	//连续赋值
	d1.operator=(d2.operator = (d3));
	
	//前置++、后置++
	d2 = d1++;
	d1 = ++d1;
	//前置--、后置--
	d2 = d1--;
	d2 = --d1;

}
int main()
{
	TestDate();
	system("pause");
	return 0;
}