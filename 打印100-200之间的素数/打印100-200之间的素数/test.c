#define _CRT_SECURE_NO_WARNINGS
//��ӡ100-200֮�������
#include<stdio.h>
#include<math.h>
#include<stdio.h>
#include<stdlib.h>
int main()
{
	int i = 0;
	int j = 0;
	int count = 0;//ֻ�ܱ�1���������
	for (i = 101; i < 200; i++)
	{
		for (j = 2; j < i; j++)
		{
			if (i%j == 0)
				break;
		}
		//1.����
		//2.����j++
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