#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
#pragma warning(disable:4996)
int main()
{
	int num[10] = { 2,7,11,15 };
	int target = 9;
	int sz = sizeof(num) / sizeof(num[0]);
	int i = 0;
		for (i = 0; i < sz; i++)
		{
			for (int j = 0; j < sz; j++)
			{
				if (num[i] + num[j] == target)
				{
					printf("%d,%d\n", i, j);
					break;
				}
				break;
			}
		}
		system("pause");
	return 0;
}
