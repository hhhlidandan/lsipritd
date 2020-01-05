#define _CRT _SECURE_NO_WARNINGS

//
//namespace N1
//{
//	int a;//定义变量
//	int Add(int left, int right)//定义函数
//	{
//		return left + right;
//	}
//	namespace N2 //在命名空间N1里，嵌套了命名空间N2
//	{
//		int b;
//		int Sub(int left, int right)
//		{
//			return left - right;
//		}
//	}
//}
//
//namespace N1 // 相同名称的命名空间N1，编译器最后会合成同一个命名空间中
//{
//	int Mul(int left, int right)
//	{
//		return left*right;
//	}
//}
//namespace N
//{
//	int b;
//}
//using N::b;
//
//int main()
//{
//	printf("%d\n", b);
//	return 0;
//}
#include<iostream>
using namespace std;
//int main()
//{
//	int a;
//	double b;
//	char c;
//
//	cin >> a;
//	cin >> b >> c;
//
//	cout << a << endl;
//	cout << b <<" " << c << endl;
//	return 0;
//}
//半缺省
//void TestFunc(int a , int b = 20, int c = 30)//传参时，使用指定的参数 
//{
//	cout << "a= " << a << endl;
//	cout << "b= " << b << endl;
//	cout << "c= " << c << endl;
//}
//int main()
//{
//
//	//至少传一个参数 
	//TestFunc(1);// a=1,b=20,c=30
	//TestFunc(1, 2);//a=10,b=2,c=30
	//TestFunc(1, 2, 3);//a=1,b=2,c=3
	//system("pause");
	//return 0;
//}
//重载
//int Add(int left, int right)
//{
//	return left + right;
//}
//double Add(double left, double right)
//{
//	return left + right;
//}
////不能重载
//short Add(short left, short right)
//{
//	return left + right;
//}
//short Add(int left, int right)
//{
//	return left + right;
//}
//引用
//void TestRef()
//{
//	int a = 10;//引用定义时必须初始化
//	int& b = a;
//	int& c = b;//一个变量可以有多个引用
//	
//	printf("%d\n", a);//10
//	printf("%d\n", b);//10
//	printf("%d\n", c);//10

//	int d = 20;
//	c = d;//把d赋给c
//	printf("%d\n", a);//20
//	printf("%d\n", b);//20
//	printf("%d\n", c);//20
//	return;
//}
//常引用
//void ConstTestRef()
//{
//	const int a = 10;
//	//int& b = a;
//	const int& b = a;
//}
//void ConstTestRef()
//{
//	int a = 10;
//	const int& b = a;
//}
//int main()
//{
//	//TestRef();
//	system("pause");
//	return 0;
//}
//使用场景
//1.做参数
//void Swap(int& left, int& right)// left,right分别为a,b 的别名
//{
//	int temp = left;
//	left = right;
//	right = temp;
//}
//int main()
//{
//	int a = 1;
//	int b = 2;
//	Swap(a, b);
//	return 0;
//}
//C语言中的Swap函数
//#include<stdio.h>
//void Swap(int* left, int* right)
//{
//	int temp = *left;
//	*left = *right;
//	*right = temp;
//}
//int main()
//{
//	int a = 1;
//	int b = 2;
//	Swap(&a, &b);
//	return 0;
//}
//2.做返回值
//int TestRefReturn(int& a)
//{
//	a += 10;
//	return a;
//}
//int main()
//{
//	int x = 10;
//	int y = TestRefReturn(x);
//	return 0;
//}
//int main() 
//{
//	int a = 10; 
//	int& ra = a;
//
//	cout << "&a = " << &a << endl;
//	cout << "&ra = " << &ra << endl;
//	system("pause");
//	return 0;
//}
int main()
{
	int a = 10;
	int& ra = a;

	ra = 20;
	int* pa = &a;
	*pa = 20;
	system("pause");
	return 0;
}


//类与对象1
//class Student//声明
//{
//	void func()//默认的为私有的
//	{
//
//	}
//public://共有，可在类外访问
//	void ShowInfo()////想给看，不被修改,提供了ShowInfo函数
//	{
//		cout << _name << " " << endl;
//		cout << _age << " " << endl;
//		cout << _studentid << " " << endl;
//	}
//	
//private://在类外不想被访问，私有
//	char* _name;
//	int _age;
//	int _studentid;
//};
//int main()
//{
//	Student s;//实例化为对象
//	s.ShowInfo();//只能访问它，共有的
//}
