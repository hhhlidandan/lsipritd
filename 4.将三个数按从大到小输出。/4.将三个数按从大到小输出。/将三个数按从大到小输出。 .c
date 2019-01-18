#define _CRT_SECURE_NO_WARNINGS
//将三个数按从大到小输出
#include<stdio.h>
#include<stdlib.h>
int main()
{
	int a, b, c;
	int tmp = 0;
	scanf("%d %d %d", &a, &b, &c);
	if (a < b)
	{
		tmp = a;
		a = b;
		b = tmp;
	}
	if (a < c)
	{
		tmp = a;
		a = c;
		c = tmp;
	}
	if (b < c)
	{
		tmp = b;
		b = c;
		c = tmp;
	}
	printf("%d %d %d\n",a,b,c);
	system("pause");
	return 0;
}