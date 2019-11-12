#include<stdio.h>
#include<windows.h>
void bubble_sort(int *parr,int sz)
{
	//1, 5, 3, 6, 7, 8, 0, 2
	//1 5
	
	int max = parr[0];
	int temp = 0;
	int i = 0;
	for (; i < sz - 1; i++)
	{
		int j = 0;
		for (; j < sz-1-i; j++)
		{
			if (parr[j]>parr[j+1])
			{
				temp = parr[j];
				parr[j]=parr[j+1];
				parr[j+1] = temp;
			}
		}
	}
	for (i = 0; i < sz; i++)
	{
		printf("%d", parr[i]);
	}
	printf("\n");
}
int main()
{
	int arr[] = { 1, 5, 3, 6, 7, 8, 0, 2 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	bubble_sort(arr,sz);
	system("pause");
	return 0;
}