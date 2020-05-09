#include<stdio.h>
#include<stdlib.h>
#pragma warning(disable:4996)
int B_search(int a[], int k, int left, int right, int sz)
{
	int mid = left + (right - left) / 2;
	if (k >= left&&k <= right)
	{
		while (left <= right)
		{
			if (a[mid] < k)
			{
				left = mid + 1;
				mid = left + (right - left) / 2;
			}
			else if (a[mid]>k)
			{
				right = mid - 1;
				mid = left + (right - left) / 2;
			}
			else
				return mid;
		}
	}
	else
		return -1;
}
int main()
{
	int a[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 0 };
	int k = 7;//查找的元素
	int sz = sizeof(a) / sizeof(a[0]);
	int left = 0;
	int right = sz - 1;
	int ret = B_search(a, k, left, right, sz);

	if (ret == -1)
		printf("找不到要查的\n");
	else printf("%d\n", ret);

	system("pause");
	return 0;
}