#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
��������������ֵ����������ʱ����
int main()
{
	int a, b;
	int tmp;
	scanf("%d %d", &a, &b);
	printf("a=%d b=%d\n", a, b);
	tmp = a;
	a = b;
	b = tmp;
	printf("a=%d b=%d\n", a, b);
	system("pause");
	return 0;
}
//��������������ֵ������������ʱ����
int main()
{
	int a, b;
	scanf("%d %d", &a, &b);
	printf("a=%d b=%d\n", a, b);
	a = a^b;
	b = a^b;
	a = a^b;
	printf("a=%d b=%d\n", a, b);
	system("pause");
	return 0;
}