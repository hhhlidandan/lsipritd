#include<stdio.h>
#include<stdlib.h>
#pragma warning(disable:4996)
//7.�ݹ鷽ʽʵ�ִ�ӡһ��������ÿһλ
void print(int n)
{
	if (n > 9)
		print(n / 10);
	printf("%d ", n%10);
}
int main()
{
	int n = 0;
	printf("��������Ҫ��ӡ����:>\n");
	scanf("%d", &n);
	print(n);//��ӡ����
	printf("\n");
	system("pause");
	return 0;
}
//6.�ݹ�ͷǵݹ�ֱ�ʵ����n�Ľ׳�
////�ݹ�
//int _mul(int n)
//{
//	if (n == 1||n==0)
//		return 1;
//	return n*_mul(n - 1);
//}
////�ǵݹ�
//
//int mul(int n)
//{
//	int i = 1;
//	int sum = 1;
//	for (; i <= n; i++)
//	{
//		sum *= i;
//	}
//	return sum;
//}
//int main()
//{
//
//	int num = 0;
//	printf("Please Enter a number:>\n");
//	scanf("%d", &num);
//	int ret=mul(num);
//	int ret1 = _mul(num);
//	printf("%d�Ľ׳���:%d\n",num,ret);
//	printf("%d�Ľ׳���:%d\n",num, ret1);
//	system("pause");
//	return 0;
//}

//5.�ݹ�ͷǵݹ�ֱ�ʵ��strlen
//�ݹ�
//int my_strlen(char *a)
//{
//	if (*a == '\0')
//		return 0;
//	return (1 + my_strlen(a+1));	
//}
//�ǵݹ�
int _strlen(char *a)
{
	int count = 0;
	while (*a != '\0')
	{
		a++;
		count++;
	}
	return count;
}
//int main()
//{
//	char *a = "abcdef";
//	int ret=my_strlen(a);
//	int len=_strlen(a);
//	printf("%d\n", ret);
//	printf("%d\n", len);
//	system("pause");
//	return 0;
//}