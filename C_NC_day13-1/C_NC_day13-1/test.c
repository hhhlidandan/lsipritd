#include<stdio.h>
#include<windows.h>
#pragma warning(disable:4996)


//1.调整数组使奇数全部都位于偶数前面。
//
//题目：
//
//输入一个整数数组，实现一个函数，
//来调整该数组中数字的顺序使得数组中所有的奇数位于数组的前半部分，
//所有偶数位于数组的后半部分。
//
void TiaoZheng(int a[],int sz)
{
	int *first = a;
	int *end = a + sz - 1;
	while (first<end)
	{
		while (first<end&&(*first % 2 != 0))
		{
			first++;
		}
		while (first<end && (*end % 2 == 0))
		{
		
			end--;
		}
		*first ^= *end;
		*end ^= *first;
		*first ^= *end;
	}
}
int main()
{
	int a[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 0 };
	int sz = sizeof(a) / sizeof(a[0]);
	int i = 0;
	for (i = 0; i < 10; i++)
	{
		printf("%d ", a[i]);
	}
	printf("\n");
	TiaoZheng(a, sz);
	for (i = 0; i < 10; i++)
	{
		printf("%d ", a[i]);
	}
	printf("\n");
	
	system("pause");
	return 0;
}
