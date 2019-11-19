#include<stdio.h>
#include<stdlib.h>
#include<windows.h>


//函数指针
void test()
{
	printf("hehe\n");
}
int main()
{
	printf("%p\n", test);
	printf("%p\n", &test);
	system("pause");
	return 0;
}
//
//void print1(int a[][5], int row, int col)
//{
//	int i = 0;
//	for (; i < row; i++)
//	{
//		int j = 0;
//		for (; j < col; j++)
//		{
//			printf("%d ", a[i][j]);
//		}
//		printf("\n");
//	}
//}
//void print2(int (*a)[5], int row, int col)
//{
//	int i = 0;
//	for (; i < row; i++)
//	{
//		int j = 0;
//		for (; j < col; j++)
//		{
//			printf("%d ", a[i][j]);
//		}
//		printf("\n");
//	}
//}
//int main()
//{
//	int a[3][5] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 0 };
//	print1(a, 3, 5);
//	print2(a, 3, 5);
//
//
//
//	/*int a[10] = { 0 };
//	printf("%p\n", a);
//	printf("%p\n", &a);
//
//	printf("%p\n", a + 1);
//	printf("%p\n", &a + 1);*/
//
//	//int *p[10];//指针数组
//	//int (*p)[10];//数组指针
//	////&数组名  VS  数组名
//	//int arr[10] = { 0 };
//	//int(*p)[10] = &arr;
//	system("pause");
//	return 0;
//}