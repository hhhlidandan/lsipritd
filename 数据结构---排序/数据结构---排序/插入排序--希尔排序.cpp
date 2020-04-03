//#include<stdio.h>
//#include<stdlib.h>
//#pragma warning(disable:4996)
//void shellsort(int *a, int n)
//{
//	int gap = n;
//	while (gap > 1)
//	{
//		gap = gap / 3 + 1;
//		for (int i = 0; i < n; i++)//不需要改成i+gap
//		{
//			int end = i;
//			int key = a[i + gap];
//			while (key < a[end] && end>=0&& i+gap < n)
//			{
//				a[end + gap] = a[end];
//				end-=gap;
//			}
//			a[end+gap] = key;
//		}
//	}	
//}
//int main()
//{
//	int array[] = { 9, 1, 2, 5, 7, 4, 8, 6, 3, 5 };
//	int size = sizeof(array) / sizeof(array[0]);
//	shellsort(array, size);
//	for (int i = 0; i < size; i++)
//	{
//		printf("%d ", array[i]);
//	}	
//	system("pause");
//	return 0;
//}