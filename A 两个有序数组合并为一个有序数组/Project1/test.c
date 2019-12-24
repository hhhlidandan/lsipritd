#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
#pragma warning(disable:4996)
	

int main()
{
	//两个有序数组合并为一个有序数组
	int a1[] = { 0, 3, 4, 6, 8 };
	int a2[] = { 1, 2, 5, 7, 9 };
	int sz1 = sizeof(a1) / sizeof(a1[0]);
	int sz2 = sizeof(a2) / sizeof(a2[0]);
	//
	int a[20];
	int index1 = 0;
	int index2 = 0;
	int index = 0;
	int i = 0;
	while (index1 < sz1&& index2 < sz2)
	{
		if (a1[index1] < a2[index2])
			a[index++] = a1[index1++];	
		else
			a[index++] = a2[index2++];
	}
	while (index1 < sz1)//数组a1还有元素
	{
		a[index++] = a1[index1++];
	}
	while (index2 < sz2)//数组a2还有元素
	{
		a[index++] = a2[index2++];
	}

	for (i=0; i < sz1+sz2; i++)
	{
		printf("%d ", a[i]);
	}
	printf("\n");


	system("pause");
	return 0;
}