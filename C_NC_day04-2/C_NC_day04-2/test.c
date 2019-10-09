#define _CRT_SECURE_NO_WARNINGS
//2.求出0～999之间的所有“水仙花数”并输出。
//“水仙花数”是指一个三位数，其各位数字的立方和确好等于该数本身，如；153＝1＋5＋3 ? ，则153是一个“水仙花数”。
//在数论中，水仙花数（Narcissistic number）也称为自恋数、自幂数、阿姆斯壮数或阿姆斯特朗数（Armstrong number），是指一N位数，其各个数之N次方和等于该数。
//例如153、370、371及407就是三位数的水仙花数，其各个数之立方和等于该数：
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


//判断一个数是否为水仙花数
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
//		printf("%d是水仙花数",num);
//	}
//	else
//	{
//		printf("%d不是水仙花数",num);
//	}
//	printf("\n");
//	system("pause");
//	return 0;
//}