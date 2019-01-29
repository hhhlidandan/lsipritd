#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
//1 1 2 3 5 8 13 21
int fac(int n)
{
	if (n > 2)
		return fac(n - 1) + fac(n - 2);
	return 1;
}
int main()
{
	int n = 0;
	scanf("%d", &n);
	int ret=fac(n);
	printf("%d\n", ret);
	system("pause");
	return 0;
}