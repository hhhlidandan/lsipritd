#include<iostream>
#include<stdio.h>
#include<stdlib.h>
using namespace std;
//ţ������ͨ���Ĵ���
//class Solution {//��1+2+3+...+n��Ҫ����ʹ�ó˳�����for��while��if��else��switch��case�ȹؼ��ּ������ж���䣨A?B:C��
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
//		Solution::Sum::resSum();//ÿ�μ���ǰ�Ȱ��ϴεĽ�����
//		Sum s[n];
//		return Solution::Sum::GetSum();
//	}
//};
//int Solution::Sum::a = 0;
//int Solution::Sum::sum = 0;
////����10�����󣬵���10�ι��캯��
/////////////////////////////////////////////////////////////////
//���Դ���
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
//	Sum *p = new Sum[n];//�����±겻���Ǳ���
//	cout << Sum::GetSum() << endl;
//	system("pause");
//	return 0;
//}
//�ݹ鷽������
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