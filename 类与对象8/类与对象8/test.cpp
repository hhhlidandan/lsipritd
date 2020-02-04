#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#pragma warning(disable:4996)
using namespace std;
//类共创建了多少个变量？
//计数的变量---不能包含在每个对象中，应该时所有对象共享
//int t_count = 0;//全局变量计数
//使用全局变量的缺陷：不安全（如果将全局变量在内部改了）
//方法：作为类的成员变量，，，，
//（定义一个共享的成员变量）（直接定义是针对每个对象的(只能记录当前对象)，所以引入static）
class Test
{
public:
	Test() :_a(0)
	{
		t_count++;
	}
	Test(Test& a)
	{
		t_count++;
	}
	~Test()
	{
		t_count--;
	}
	static int GetCount()//静态成员函数
	{
		return t_count;
	}
	//int GetCount1()//普通成员函数
	//{
	//	cout<<this<<endl;
	//
	//	return this->_a;
	//}
private:
	int _a;
	static int t_count;//静态成员变量
};
int Test::t_count = 0;//静态成员变量在类外初始化
void testCount()
{
	Test t1, t2;
	cout << Test::GetCount() << endl;
	//cout << t_count << endl;
}
int main()
{
	Test::GetCount();
	Test t1, t2;
	cout << Test::GetCount() << endl;
	//cout << t1.GetCount() << endl;//也可以通过对象访问
	testCount();
	cout << Test::GetCount() << endl;

	//cout << &t1.t_count << "=" << &t2.t_count << endl;
	system("pause");
	return 0;
}
//普通成员变量：
//可以在初始化列表中初始化
//每个对象都包含
//必须通过对象访问
//static成员变量：
//不行
//只有一份，没有包含在具体的对象中，且是所有对象共享的，
//可以通过对象直接访问，也可通过类名+作用域限定符直接访问(不属于某一个具体的对象)
//
//编译器都会把它当成第二种访问
//静态成员函数：可以不通过对象访问

//普通类型的成员函数必须通过对象访问

//普通的成员函数：
//有一个隐藏的this指针，
//可以访问普通的成员变量
//静态成员函数：
//没有this指针
//不能访问普通的成员变量
int main()
{
	Test::GetCount();
	Test t1, t2;
	cout << Test::GetCount() << endl;
	//cout << t1.GetCount() << endl;//也可以通过对象访问
	return 0;
}
