#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<mutex>
#include<thread>
using namespace std;
//懒汉模式
class Singleton
{
public:
	static volatile Singleton* GetInstance()
	{
		//防止线程阻塞
		if (m_In == nullptr)
		{
			m_mutex.lock();//加锁
			//检测单个的实例有无创建
			if (m_In == nullptr)
				m_In = new Singleton;
			m_mutex.unlock();//解锁
		}
		return m_In;
	}
	//直接写析构，不会直接调用析构函数,为保证调用析构函数，就要定义一个内部类
	class CG
	{
	public:
		~CG()
		{
			if (m_In)
			{
				delete m_In;
				m_In = nullptr;
			}
		}
	};
private:
	Singleton()//构造函数
	{}
	//防拷贝
	Singleton(const Singleton&) = delete;//拷贝构造
	Singleton& operator=(const Singleton&) = delete;//赋值运算符重载

	static volatile Singleton* m_In;//静态对象在程序启动时就创建好了,在程序退出的时候销毁
	static mutex m_mutex;
	static CG m_gc;
};
volatile Singleton* Singleton::m_In = nullptr;
mutex Singleton::m_mutex;
Singleton::CG m_gc;

void ThreadFunc()
{
	cout << Singleton::GetInstance() << endl;
}
void Test()
{
	thread t1(ThreadFunc);
	thread t2(ThreadFunc);
	thread t3(ThreadFunc);
	thread t4(ThreadFunc);

	t1.join();
	t2.join();
	t3.join();
	t4.join();
}
int main()
{
	Test();	
	system("pause");
	return 0;
}
//饿汉模式
//class Singleton
//{
//public:
//	static Singleton& GetInstance()//获取对象的别名，不会拷贝构造
//	{
//		return m_I;
//	}
//private:
//	//将构造函数设置为私有的，防止别人调
//	Singleton()
//	{}
//	Singleton(const Singleton&) = delete;
//	Singleton& operator=(const Singleton&) = delete;
//	static Singleton m_I;//静态成员变量  静态变量在程序启动时创建好
//};
//Singleton Singleton::m_I;//在类外初始化
//
//int main()
//{
//	Singleton& s= Singleton::GetInstance();
//	system("pause");
//	return 0;
//}
///防止类被拷贝
//将拷贝构造函数和赋值运算符重载声明成私有的
//class Test
//{
//public:
//	Test()
//	{}
//private:
//	//C++98
//	Test(Test& t);
//	Test& operator=(const Test&);
//	//C++11
//	//Test(Test& t) = delete;
//	//Test& operator=(const Test&) = delete;
//};
//int main()
//{
//	return 0;
//}
//静态变量不在对象里包含，在程序启动时就创建好
