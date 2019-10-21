#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#pragma warning(disable:4996)
//4. 编写一个函数 reverse_string(char * string)（递归实现）
//实现：将参数字符串中的字符反向排列。
//要求：不能使用C函数库中的字符串操作函数。
//非递归
//void reverse_str(char *str)
//{
//	int len = strlen(str);
//	int end = len - 1;
//	while (end>=0)
//	{
//		printf("%c ", *(str+end));
//		end--;
//	}
//	printf("\n");	
//}
//递归
//void reverse_str(char *str)
//{
//	if (*str == '\0')
//	{
//		return;	
//	}
//	reverse_str(str + 1);
//	printf("%c", *str);
//	
//}
//int main()
//{
//	char *str = "abcdef";
//	reverse_str(str);
//	//printf("%s\n", ret);
//	system("pause");
//	return 0;
//}

//3. 写一个递归函数DigitSum(n)，输入一个非负整数，返回组成它的数字之和，
//例如，调用DigitSum(1729)，则应该返回1 + 7 + 2 + 9，它的和是19
//int Dig(int n)
//{
//	if (n < 10)
//		return n;
//	return n % 10 + Dig(n / 10);
//}
//int main()
//{
//	int n = 0;
//	printf("Please Enter#\n");
//	scanf("%d", &n);
//	int ret = Dig(n);
//	printf("%d\n", ret);
//	system("pause");
//	return 0;
//}
//2.编写一个函数实现n^k，使用递归实现
//int mul(int n,int k)
//{
//	if (k==1)
//		return n;
//	return n*mul(n, k - 1);
//}
//int main()
//{
//	int k = 0;
//	int n = 0;
//	printf("Please Enter#\n");
//	scanf("%d %d",&n,&k);
//	
//	printf("%d^%d=%d\n",n,k, mul(n, k));
//	system("pause");
//	return 0;
//}
//1.递归和非递归分别实现求第n个斐波那契数
//递归
//int fib(int n)
//{
//	if (n <= 2)
//		return 1;
//	return fib(n - 1) + fib(n - 2);
//}
//非递归
//int fib(int n)
//{
//	int first = 1;
//	int second = 1;
//	int third = 1;
//	int i = 1;
//	if (n > 2)
//	{
//		for (; i <= n - 2; i++)
//		{
//			third = first + second;
//			first = second;
//			second = third;
//		}
//	}
//	return third;	
//}
//int main()
//{
//	int n = 0;
//	printf("Please Enter#\n");
//	scanf("%d", &n);
//	
//	int ret=fib(n);
//	printf("%d\n", ret);
//
//	system("pause");
//	return 0;
//}


