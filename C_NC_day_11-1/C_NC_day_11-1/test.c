#include<stdio.h>
#include<windows.h>
#pragma warning(disable:4996)
//在屏幕上打印杨辉三角。
//1
//1 1
//1 2 1
//1 3 3 1
//void Show()
//{
//	int i = 0;
//	int j = 0;
//	int arr[4][4] = { 0 };
//	for (; i < 4; i++)
//	{
//		arr[i][0] = 1;
//		arr[i][i] = 1;
//	}
//	for (i = 2; i <= 3; i++)
//	{
//		for (j = 1; j <= 2; j++)
//		{
//			arr[i][j] = arr[i-1][j] + arr[i-1][j-1];
//		}
//	}
//	for (i = 0; i < 4; i++)
//	{
//		for (j = 0; j <= i; j++)
//		{
//			printf("%2d ", arr[i][j]);
//		}
//		printf("\n");
//	}
//}
//int main()
//{
//	Show();
//	system("pause");
//	return 0;
//}

//日本某地发生了一件谋杀案，警察通过排查确定杀人凶手必为4个
//嫌疑犯的一个。以下为4个嫌疑犯的供词。
//A说：不是我。
//B说：是C。
//C说：是D。
//D说：C在胡说
//已知3个人说了真话，1个人说的是假话。
//现在请根据这些信息，写一个程序来确定到底谁是凶手。
//void Judge()
//{
//	char killer = 'A';
//
//	for (; killer <= 'D'; killer++)
//	{
//		if ((killer != 'A') + (killer == 'C') + (killer == 'D') + (killer != 'D') == 3)
//		{
//			printf("killer is %c\n", killer);
//		}
//	}
//	
//}
//int main()
//{
//	Judge();
//	system("pause");
//	return 0;
//}

////5位运动员参加了10米台跳水比赛，有人让他们预测比赛结果
////
////比赛结束后，每位选手都说对了一半，请编程确定比赛的名次。
//
//void Judge(int a, int b, int c, int d, int e)
//{
//	for (a = 1; a <= 5; a++)
//	{
//		for (b = 1; b <= 5; b++)
//		{
//			for (c = 1; c <= 5; c++)
//			{
//				for (d = 1; d <= 5; d++)
//				{
//					for (e = 1; e <= 5; e++)
//					{
//						    //A选手说：B第二，我第三；
//							//B选手说：我第二，E第四；
//							//C选手说：我第一，D第二；
//							//D选手说：C最后，我第三；
//							//E选手说：我第四，A第一；
//						if ((b == 2) + (a == 3) == 1 && \
//							(b == 2) + (e == 4) == 1 && \
//							(c == 1) + (d == 2) == 1 && \
//							(c == 5) + (d == 3) == 1 && \
//							(e == 4) + (a == 1) == 1 && \
//							(a*b*c*d*e==120))
//						{
//							printf("a=%d,b=%d,c=%d,d=%d,e=%d\n", a,b,c,d,e);
//						}
//					}
//				}
//			}
//		}
//	}
//}
//int main()
//{
//	int a = 0;
//	int b = 0;
//	int c = 0;
//	int d = 0;
//	int e = 0;
//	Judge(a, b, c, d, e);
//	system("pause");
//	return 0;
//}