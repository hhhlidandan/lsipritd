#include<stdio.h>
#include<stdlib.h>
#pragma warning(disable:4996)


//计算N的阶乘
//#include<stdio.h>
//int main()
//{
//	//顺序求1*2*3.....（正确）
//	/*int i = 0;
//	int n = 0;
//	int sum = 1;
//	printf("Please Enter:>\n");
//	scanf("%d", &n);
//	for (i = 1; i <= n; i++)
//	{
//		sum *= i;;
//	printf("%d\n", sum);*/
//
//	////倒序求.....3*2*1  数字大会溢出（错误）
//	//int sum = 1;
//	//int n = 0;
//	//printf("Please Enter;>");
//	//scanf("%d", &n);
//	//while (n > 0){
//	//	sum *= n;
//	//	n--;
//	//}
//	//printf("%d\n", sum);
//	system("pause");
//	return 0;
//}

////输出1-100之间的奇数
//void PrintNum(int i)
//{
//	for (i = 1; i <= 100; i++)
//	{
//		/*if (i % 2 == 0)*/
//		if ((i&1)==0)//按位与，检测最低bit位
//			continue;
//		else
//			printf("%d ", i);
//	}
//}
//int main()
//{
//	int i = 0;
//	PrintNum(i);
//	system("pause");
//	return 0;
//}
////1.判断一个数是否为奇数
//int IsNum(int n)
//{
//	if (n % 2 == 0)
//		return 0;
//	return 1;
//}
//int main()
//{
//	int num = 0;
//	printf("Please Enter num:>");
//	scanf("%d", &num);
//	int ret=IsNum(num);
//	if (ret)
//	{
//		printf("奇数\n",ret);
//	}
//	else
//	{
//		printf("偶数\n", ret);
//	}
//	system("pause");
//	return 0;
//}

//int main()
//{
//	int i = 0;
//	int k = 0;
//	for (i = 0,k = 0; k = 0; i++, k++)//判断部分，k=0，条件为假，不执行
//	{
//		k++;
//		printf("%d ", k);
//	}
//
//	system("pause");
//	return 0;
//}

//int main()
//{
//	int x = 0;
//	int y = 0;
//	for (x = 0, y = 0; y < 5, x < 2; ++x, y++)
//	{
//		printf("hehe\n");
//	}
//	system("pause");
//	return 0;
//}
