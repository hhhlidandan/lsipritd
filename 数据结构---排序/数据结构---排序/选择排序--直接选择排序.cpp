#include<stdio.h>
#include<stdlib.h>
#pragma warning(disable:4996)

void Swap(int *number, int *a)
{
	int tmp = *number;
	*number = *a;
	*a = tmp;
}
void SelectSort(int *a, int size)
{
	int start = 0;
	int end = size - 1;
	while (start<end)
	{
		//先找最小的
		int min = start + 1;
		for (int i = start; i <= end; i++)
		{
			if (a[i]<a[min])
				min = i;
			else
				continue;
		}
		if (a[min] != a[start])
		{
			Swap(&a[start], &a[min]);
		}
		start++;
	}
}
int main()
{
	int a[] = { 7, 4, 5, 9, 8, 2, 1 };
	int size = sizeof(a) / sizeof(a[0]);
	SelectSort(a, size);
	for (int i = 0; i < size; i++)
		printf("%d ", a[i]);
	system("pause");
	return 0;
}