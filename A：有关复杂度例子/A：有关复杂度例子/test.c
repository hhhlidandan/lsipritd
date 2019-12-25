#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
#pragma warning(disable:4996)

void Print(int a[], int sz)
{
	int i = 0;
	for (; i < sz; i++)
	{
		printf("%d ", a[i]);
	}
	printf("\n");
}
//void BubbleSort(int a[], int sz)
//{
//	int i = 0;
//	int j = 0;
//	//һ����Ҫ���ٴ�
//	for (; i < sz - 1; i++)
//	{
//		//һ��
//		for (j = 0; j < sz - i - 1; j++)
//		{
//			if (a[j]>a[j + 1])
//			{
//				int temp = a[j];
//				a[j] = a[j + 1];
//				a[j + 1] = temp;
//			}
//		}
//	}
//}
int BinarySearch(int a[], int sz, int k)
{
	int left = 0;
	int right = sz - 1;
	
	while (left <= right)
	{
		int mid = left + (right - left) / 2;
		if (k < a[mid])
			right = mid - 1;
		else if (k>a[mid])
			left = mid + 1;
		else
			return mid;
	}
	return -1;
}
int main()
{
	//ð������  ʱ�临�Ӷ�O(N^2)
	
	int a[] = { 2, 4, 8, 9, 1, 0, 5, 3 };
	int sz = sizeof(a) / sizeof(a[0]);
	Print(a, sz);

	int k = 8;
	int ret=BinarySearch(a, sz, k);
	if (ret == -1)
	{
		printf("û�ҵ�\n");
	}
	else
	{
		printf("�ҵ���%d,λ��Ϊ:a[%d]\n",k, ret);
	}
	
	//BubbleSort(a, sz);
	//Print(a, sz);

	system("pause");
	return 0;
}