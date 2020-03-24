#include<iostream>
using namespace std;
#if 0
class A
{
public:
	void Testfunc1()
	{}
protected:
	int _a;
};
//基类公有成员在派生类中权限已经变成保护，
//在类外不能通过派生类对象直接访问基类成员函数
//但该基类成员函数可以在派生类成员函数中直接被访问
class B :protected A
{
public:
	void Testfunc2()
	{
		Testfunc1();
	}
	
protected:
	int _b;
};
int main()
{
	A a;
	B b;
	//b.Testfunc1();
	return 0;
}
#endif

class A
{
public:
	void Testfunc1()
	{}
protected:
	int _a;
};
class B
{
public:
	void Testfunc2()
	{
		_a.Testfunc1();
	}

protected:
	A _a;
	int _b;
};
int main()
{
	A a;
	B b;
	return 0;
}