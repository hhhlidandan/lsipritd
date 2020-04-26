//#include<iostream>
//using namespace std;
//
//class MyClass
//{
//public:
//	MyClass(int i = 0)
//	{
//		cout << 1;
//	}
//	MyClass(const MyClass& x)
//	{
//		cout << 2;
//	}
//	MyClass& operator=(const MyClass& x)
//	{
//		cout << 3;
//		return *this;
//	}
//	~MyClass()
//	{
//		cout << 4;
//	}
//};
//int main()
//{
//	MyClass obj1(1);
//	MyClass obj(2);
//	MyClass obj3(obj1);
//	return 0;
//}