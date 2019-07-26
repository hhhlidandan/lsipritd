#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
//1 1 2 3 5 8
int main()
{
	int i = 0;
	int a = 1;
	int b = 1;
	int c = 1;
	int n = 0;
	scanf("%d", &n);
	for (i = 1; i <= n - 2; i++)
	{
		a = b;
		b = c;
		c = a + b;
	}
	printf("%d\n", c);
	system("pause");
	return 0;
}