#define _CRT_SECURE_NO_WARNINGS
//�������������Լ��
#include<stdio.h>
#include<stdlib.h>
int main()
{
	int a, b;
	int c = 0;
	scanf("%d %d", &a, &b);
	while (a%b != 0)
	{
		c = a%b;
		a = b;
		b = c;
	}
	printf("%d\n", c);
	system("pause");
	return 0;
}