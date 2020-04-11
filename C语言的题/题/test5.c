//#include<stdio.h>
//#include<stdlib.h>
//#pragma warning(disable:4996)
//#define ROW 4
//#define COL 5
//void Swap(int *a, int *b)
//{
//	*a ^= *b;
//	*b ^= *b;
//	*a ^= *b;
//}
//void Print(int arr[ROW][COL],int row,int col)
//{
//	for (int i = 0; i < row; i++)
//	{
//		for (int j = 0; j < col; j++)
//			printf("%d ", arr[i][j]);
//		printf("\n");
//	}
//}
//int main()
//{
//	int arr[ROW][COL] = { 0 };
//	for (int i = 0; i < ROW; i++)
//	{
//		for (int j = 0; j < COL; j++)
//			arr[i][j] = i;
//	}
//	printf("调换前#\n");
//	Print(arr,ROW,COL);
//	for (int i = 0; i < 5; i++)
//		Swap(&arr[0][i], &arr[2][i]);
//	printf("调换后#\n");
//	Print(arr, ROW, COL);
//	system("pause");
//	return 0;
//}