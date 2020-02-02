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
		if (this != &d)//排除对象自己给己赋值
		{
			_year = d._year;
			_month = d._month;
			_day = d._day;
		}
		return *this;
	}
	//取地址重载	//返回普通类型的成员方法
	Date* operator&()//返回对象的地址
	{
		return this;
	}
	//const取地址重载  //调用const类型的成员方法/
	// Date* p=&d2//代码不安全，可以通过p修改空间中的内容
	const Date* operator&() const //不能修改当前对象的成员变量
	{
		return this;
	}
	void TestFunc1()
	{
		_day++;
	}
	//this的类型：Date* const  //指针指向不能修改
	//const Date* const this  //指针指向的空间的内容不能修改（不能修改成员变量）
	//const修饰this指针
	void TestFunc2() const
	{
		//_day++;//不能加，因为不能修改类中成员变量
		this->_day;//加了mutable可以被修改了
	}

	~Date()
	{
		cout << "`Date():" << this << endl;
	}
private:
	int _year;
	int _month;
	mutable int _day;//加了mutable可以在const类型成员函数体内被修改
};

void TestDate()
{
	Date d1(2019,3,25);
	cout << &d1 << endl;//这行就够了

	const Date d2(2019,3,3);
	cout << &d2 << endl;
	//一般不需要取地址重载，除非有别的用
}
int main()
{
	TestDate();
	system("pause");
	return 0;
}
