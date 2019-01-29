#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
int main()
{
	int n = 0;
	scanf("%d", &n);
	//1 1 2 3 5 8 13
	//a b c
	//  a b c
	int a = 1;
	int b = 1;
	int c = 1;
	for (int i = 1; i <= n-2; i++)
	{
			a = b;
			b = c;
			c = a + b;
	}
	printf("%d\n", c);
	system("pause");
	return c;
	
}