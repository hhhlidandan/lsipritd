#define _CRT_SECURE_NO_WARNINGS
//4.
//����һ�����飬
//ʵ�ֺ���init������ʼ�����顢
//ʵ��empty����������顢
//ʵ��reverse���������������Ԫ�ص����á�
//Ҫ���Լ���ƺ����Ĳ���������ֵ��
#include<stdio.h>
#include<stdlib.h>
void init(int a[])
{
	int i;
	for (i = 0; i <= 9; i++)
	{
		a[i] = 1;
		printf("%d", a[i]);
	}
	printf("\n");
}
void empty(int a[])
{
	int j;
	for (j = 0; j <= 9; j++)
	{
		a[j] = 0;
		printf("%d", a[j]);
	}
	printf("\n");
}
void reverse(int a[], int sz)
{
	int left = 0;
	int right = sz - 1;
	while (left < right)
	{
		int tmp;
		tmp = a[left];
		a[left] = a[right];
		a[right] = tmp;
		left++;
		right--;
	}
	for (int i = 0; i <= 9; i++)
	{
		printf("%d", a[i]);
	}
	printf("\n");


}
int main()
{
	int a[10] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	init(a);
	empty(a);
	int sz = sizeof(a) / sizeof(a[0]);
	reverse(a, sz);
	system("pause");
	return 0;
}