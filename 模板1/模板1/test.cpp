#include<stdio.h>
#include<stdlib.h>
#include<iostream>
using namespace std;
//类模板
template<class T1,class T2,...,class Tn>

//int Add(int left, int right)
//{
//	return left + right;
//}
//template<class T>
//T Add(T left, T right)
//{
//	return left + right;
//}
//int main()
//{
//	int a = 10, b = 20;
//	double c = 2.3, d = 1.2;
//	Add(a, b);
//	Add(c, d);
//	cout << Add(1, 2) << endl;
//	//隐式实例化
//	cout << Add(1.0,(double)1) << endl;//自己强转
//	//显式实例化 
//	cout << Add<int>(1, 2) << endl;
//	system("pause");
//	return 0;
//}