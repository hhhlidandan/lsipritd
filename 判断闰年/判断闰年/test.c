#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
int main()
{
	int year = 0;
	scanf("%d", &year);
	if ((year % 4 == 0) && (year % 100 != 0) || (year % 400 == 0))
	{
		printf("%d������\n", year);
	}
	else
	{
		printf("%d��������\n", year);
	}
	system("pause");
	return 0;
}