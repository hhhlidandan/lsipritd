#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
交换两个变量的值，允许创建临时变量
int main()
{
	int a, b;
	int tmp;
	scanf("%d %d", &a, &b);
	printf("a=%d b=%d\n", a, b);
	tmp = a;
	a = b;
	b = tmp;
	printf("a=%d b=%d\n", a, b);
	system("pause");
	return 0;
}
//交换两个变量的值，不允许创建临时变量
int main()
{
	int a, b;
	scanf("%d %d", &a, &b);
	printf("a=%d b=%d\n", a, b);
	a = a^b;
	b = a^b;
	a = a^b;
	printf("a=%d b=%d\n", a, b);
	system("pause");
	return 0;
}