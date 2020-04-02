//#include<stdio.h>
//#include<stdlib.h>
//#pragma warning(disable:4996)
//void shellsort(int *a, int n)
//{
//	int gap = 3;
//	while (gap > 0)
//	{
//		for (int i = 0; i < n; i+=gap)
//		{
//			int end = i;
//			int key = a[i + gap];
//			while (key < a[end] && end + gap < n && end>=0)
//			{
//				a[end + gap] = a[end];
//				end-=gap;
//			}
//			a[end+gap] = key;
//		}
//		gap--;
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