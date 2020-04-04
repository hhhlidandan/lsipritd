#include<stdio.h>
#include<stdlib.h>
#pragma warning(disable:4996)
//vim 文本编辑工具  g++/gcc编译  调试 ：打印日志+gdb
//VS:集成开发工具---剪辑器+预处理器+编译器+连接器
void Swap(int *number, int *a)
{
	int tmp = *number;
	*number = *a;
	*a = tmp;
}
//void SelectSort(int *a, int size)
//{
//	int start = 0;
//	int end = size - 1;
//	while (start<end)
//	{
//		//先找最小的
//		int min = start + 1;
//		for (int i = start; i <= end; i++)
//		{
//			if (a[i]<a[min])
//				min = i;
//		}
//		if (a[min] != a[start])
//		{
//			Swap(&a[start], &a[min]);
//		}
//		start++;
//	}
//}

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

//void Select2(int *n, int size)
//{
//	int start = 0;
//	int end = size - 1;
//	while (start < end)
//	{
//		int max = end;
//		int min = start;
//		for (int i = start + 1; i <= end; i++)
//		{
//			if (n[i]>n[max])	max = i;
//			if (n[i] < n[min])	min = i;
//		}
//		if (max != end)	 Swap(&n[max], &n[end]);
//		if (min == end)	 min = max;
//		if (min != start)	Swap(&n[min], &n[start]);
//		start++, end--;
//	}
//}
//int main()
//{
//	int a[] = { 4, 1, 8, 3, 6, 7, 2, 9, 5, 0 };
//	int size = sizeof(a) / sizeof(a[0]);
//	//SelectSort(a, size);
//	//Select1(a, size);
//	Select2(a, size);
//	for (int i = 0; i < size; i++)
//		printf("%d ", a[i]);
//	system("pause");
//	return 0;
//}