//#include<iostream>
//using namespace std;
//
//class A
//{
//public:
//	A() :m_iVal(0)
//	{
//		test();
//	}
//	virtual void func()
//	{
//		std::cout << m_iVal << endl;
//	}
//	void test()
//	{
//		func();
//	}
//public:
//	int m_iVal;
//};
//class B :public A
//{
//public:
//	B()
//	{
//		test();
//	}
//	virtual void func()
//	{
//		++m_iVal;
//		cout << m_iVal << endl;
//	}
//};
//int main()
//{
//	A *p = new B;
//	p->test();
//	return 0;
//}