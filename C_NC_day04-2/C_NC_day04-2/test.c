#define _CRT_SECURE_NO_WARNINGS
//2.���0��999֮������С�ˮ�ɻ������������
//��ˮ�ɻ�������ָһ����λ�������λ���ֵ�������ȷ�õ��ڸ��������磻153��1��5��3 ? ����153��һ����ˮ�ɻ�������
//�������У�ˮ�ɻ�����Narcissistic number��Ҳ��Ϊ������������������ķ˹׳����ķ˹��������Armstrong number������ָһNλ�����������֮N�η��͵��ڸ�����
//����153��370��371��407������λ����ˮ�ɻ������������֮�����͵��ڸ�����
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int main()
{
	int n = 0;
	int m = 0;
	int k = 0;
	int i = 0;
	for (i = 0; i <= 999; i++)
	{
		n = i / 100;
		m = i / 10 % 10;
		k = i % 10;
		if (pow(n, 3) + pow(m, 3) + pow(k, 3) == i)
		{
			printf("%d ", i);
		}
		else
			continue;
	}
	printf("\n");
	system("pause");
	return 0;
}


//�ж�һ�����Ƿ�Ϊˮ�ɻ���
//#include<stdio.h>
//#include<stdlib.h>
//
//int main()
//{
//	int num = 0;
//	scanf("%d", &num);
//	int i = 0;
//	int j = 0;
//	int k = 0;
//	i = num / 100;
//	j = num / 10 % 10;
//	k = num % 10;
//	if (i*i*i + j*j*j + k*k*k == num)
//	{
//		printf("%d��ˮ�ɻ���",num);
//	}
//	else
//	{
//		printf("%d����ˮ�ɻ���",num);
//	}
//	printf("\n");
//	system("pause");
//	return 0;
//}