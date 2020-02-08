#include<iostream>
#include<stdio.h>
#include<stdlib.h>
using namespace std;
//牛客网上通过的代码
//class Solution {//求1+2+3+...+n，要求不能使用乘除法、for、while、if、else、switch、case等关键字及条件判断语句（A?B:C）
//	class Sum
//	{
//	public:
//		Sum()
//		{
//			a++;
//			sum += a;
//		}
//		static void resSum()
//		{
//			a = 0;
//			sum = 0;
//		}
//		static int GetSum()
//		{
//			return sum;
//		}
//	private:
//		static int a;
//		static int sum;
//	};
//public:
//	int Sum_Solution(int n) {
//		Solution::Sum::resSum();//每次计算前先把上次的结果清空
//		Sum s[n];
//		return Solution::Sum::GetSum();
//	}
//};
//int Solution::Sum::a = 0;
//int Solution::Sum::sum = 0;
////创建10个对象，调用10次构造函数
/////////////////////////////////////////////////////////////////
//测试代码
//class Sum
//{
//public:
//	Sum()
//	{
//		_count++;
//		_sum += _count;
//	}
//	static int GetSum()
//	{
//		return _sum;
//	}
//	static void RESSum()
//	{
//		_count = 0;
//		_sum = 0;
//	}
//private:
//	static int _count;
//	static int _sum;
//};
//int Sum::_count = 0;
//int Sum::_sum = 0;
//int main()
//{
//	Sum::RESSum();
//	int n;
//	cin >> n;
//	Sum *p = new Sum[n];//数组下标不能是变量
//	cout << Sum::GetSum() << endl;
//	system("pause");
//	return 0;
//}
//递归方法求下
int Sum(int n)
{
	if (n == 1)
		return 1;
	return Sum(n-1) + n;
}
int main()
{
	int n;
	cin >> n;
	Sum(n);
	cout << Sum(n) << endl;
	system("pause");
	return 0;
}