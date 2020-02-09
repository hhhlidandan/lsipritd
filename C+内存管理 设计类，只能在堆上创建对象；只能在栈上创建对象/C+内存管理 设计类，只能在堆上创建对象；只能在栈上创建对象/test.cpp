#include<iostream>
using namespace std;
//只能在堆上创建
//class HeapOnly
//{
//	
//public:
//	static HeapOnly* CreateObject()//静态成员函数可以不通过对象调用
//	{
//		return new HeapOnly;
//	}
//	~HeapOnly()
//	{}
//private:
//	//C++98中
//	HeapOnly(const HeapOnly&);//只给声明
//
//	///在C++11中，delete不仅可以释放空间，还可控制默认的成员函数，它告诉编译器：删除拷贝构造函数 
//	HeapOnly(const HeapOnly&) = delete;//不用管权限
//private:
//	HeapOnly()//构造函数
//	{}
//};
//int main()
//{
//	HeapOnly *p = HeapOnly::CreateObject();//在堆上创建对象（1.开辟空间2.调用构造函数）
//	HeapOnly o(*p);
//	system("pause");
//	return 0;
//}

//只在栈上创建
//

//class StackOnly
//{
//public:
//	static StackOnly CreateObject()//以值的方式返回
//	{
//		return StackOnly();
//	}
//private:
//	StackOnly()//构造函数
//	{}
//};
//int main()
//{
//	StackOnly::CreateObject();
//	system("pause");
//	return 0;
//}

class StackOnly1//不能绝对的在栈上创建
{
public:
	StackOnly1()
	{
		cout << "StackOnly():" << endl;
	}
	StackOnly1(const StackOnly1&)
	{
		cout << "StackOnly(StackOnly&)" << endl;
	}
private:
	void* operator new(size_t size);

};
int main()
{
	return 0;
}