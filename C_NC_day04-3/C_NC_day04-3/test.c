#define _CRT_SECURE_NO_WARNINGS
//��Sn = a + aa + aaa + aaaa + aaaaa��ǰ5��֮�ͣ�����a��һ�����֣�
//���磺2 + 22 + 222 + 2222 + 22222

#include<stdio.h>
#include<stdlib.h>
int main()
{
	int a = 0;
	int sum = 0;
	int n = 0;
	int i = 0;
	scanf("%d", &a);
	for (i = 1; i <= 5; i++)
	{
		n = n * 10 + a;
		sum = sum + n;
	}
	printf("%d\n", sum);
	system("pause");
	return 0;
}