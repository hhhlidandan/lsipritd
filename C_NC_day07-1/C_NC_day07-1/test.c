#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#pragma warning(disable:4996)
//4. ��дһ������ reverse_string(char * string)���ݹ�ʵ�֣�
//ʵ�֣��������ַ����е��ַ��������С�
//Ҫ�󣺲���ʹ��C�������е��ַ�������������
//�ǵݹ�
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
//�ݹ�
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

//3. дһ���ݹ麯��DigitSum(n)������һ���Ǹ����������������������֮�ͣ�
//���磬����DigitSum(1729)����Ӧ�÷���1 + 7 + 2 + 9�����ĺ���19
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
//2.��дһ������ʵ��n^k��ʹ�õݹ�ʵ��
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
//1.�ݹ�ͷǵݹ�ֱ�ʵ�����n��쳲�������
//�ݹ�
//int fib(int n)
//{
//	if (n <= 2)
//		return 1;
//	return fib(n - 1) + fib(n - 2);
//}
//�ǵݹ�
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


