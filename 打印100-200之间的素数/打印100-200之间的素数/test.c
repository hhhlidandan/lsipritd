#define _CRT_SECURE_NO_WARNINGS
//打印100-200之间的素数
#include<stdio.h>
#include<math.h>
#include<stdio.h>
#include<stdlib.h>
int main()
{
	int i = 0;
	int j = 0;
	int count = 0;//只能被1和它本身除
	for (i = 101; i < 200; i++)
	{
		for (j = 2; j < i; j++)
		{
			if (i%j == 0)
				break;
		}
		//1.不是
		//2.大于j++
		if (j >= i)
		{
			printf("%d ", i);
			count++;
		}
	}
	printf("\n");
	printf("count=%d\n", count);
	system("pause");
	return 0;
}