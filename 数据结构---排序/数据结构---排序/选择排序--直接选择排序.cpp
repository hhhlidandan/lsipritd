//#include<stdio.h>
//#include<stdlib.h>
//#pragma warning(disable:4996)
//
//void Swap(int *number, int *a)
//{
//	int tmp = *number;
//	*number = *a;
//	*a = tmp;
//}
////void SelectSort(int *a, int size)
////{
////	int start = 0;
////	int end = size - 1;
////	while (start<end)
////	{
////		//先找最小的
////		int min = start + 1;
////		for (int i = start; i <= end; i++)
////		{
////			if (a[i]<a[min])
////				min = i;
////		}
////		if (a[min] != a[start])
////		{
////			Swap(&a[start], &a[min]);
////		}
////		start++;
////	}
////}
//
//void Select1(int *a, int size)
//{
//	for (int i = 0; i < size - 1; i++)
//	{
//		int max = 0;
//		for (int start = 0; start < size-i; start++)
//		{
//			if (a[start]>a[max])
//				max = start;
//		}
//		if (a[max] != a[size - 1 - i])
//			Swap(&a[max], &a[size - 1- i]);
//	}
//}
//int main()
//{
//	int a[] = { 7, 4, 5, 9, 8, 2, 1 };
//	int size = sizeof(a) / sizeof(a[0]);
//	//SelectSort(a, size);
//	Select1(a, size);
//	for (int i = 0; i < size; i++)
//		printf("%d ", a[i]);
//	system("pause");
//	return 0;
//}