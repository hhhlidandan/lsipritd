////2.
//////杨氏矩阵 
////有一个二维数组.
////数组的每行从左到右是递增的，每列从上到下是递增的.
////在这样的数组中查找一个数字是否存在。
////时间复杂度小于O(N);
//
////数组：
//
//#include<stdio.h>
//#include<assert.h>
//#include<windows.h>
//#pragma warning(disable:4996)
//
//
//int Check(int a[][3], int sz,int k)
//{
//	assert(a);//检测指针不能为空
//	assert(sz > 0);
//	//1 2 3
//	//2 3 4
//	//3 4 5
//	int i = 0;//从 [0][2](3)开始找
//	int j = 2;
//	while (i<3&&j>=0)
//	{
//		if (k > a[i][j])
//		{//不在i行
//			i++;
//		}
//		else if (k < a[i][j])
//		{//不在j列
//			j--;
//		}
//		else
//		{
//			printf("找到了：%d,a[%d][%d]\n", k, i, j);
//			return 1;
//		}	
//		
//	}
//	return 0;
//			
//}
//int main()
//{
//	int a[][3] = { 1, 2, 3, 2, 3, 4, 3, 4, 5 };
//	int sz = sizeof(a) / sizeof(a[0]);
////	int i = 0;
////显示数组	
//	/*for (; i < sz; i++)
//	{
//		int j = 0;
//		for (; j < sz; j++)
//		{
//			printf("%d ", a[i][j]);
//		}
//		printf("\n");
//	}*/
//	int ret = Check(a, sz, 4);
//	printf("%d\n", ret);
//	system("pause");
//	return 0;
//}