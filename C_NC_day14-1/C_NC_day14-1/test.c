#include<stdio.h>
#include<windows.h>
#include<assert.h>
#pragma warning(disable:4996)


//1.实现一个函数，可以左旋字符串中的k个字符。
//ABCD左旋一个字符得到BCDA
void Print(char a[], int sz)
{
	int i = 0;
	for (; i<sz; i++)
	{
		printf("%c ", a[i]);
	}
	printf("\n");
}
void ZuoXuan(char a[], int sz)
{
	assert(a);
	assert(sz > 0);
	int i = 0;
	int temp = a[0];
	for (; i < sz - 1; i++)
	{
		a[i] = a[i + 1];
	}
	a[sz - 1] = temp;
}
int main()
{

	char a[] = "ABCD";
	int k = 0;
	int sz = sizeof(a) / sizeof(a[0]) - 1;
	Print(a, sz);
	printf("请问要左旋几个字符：\n");
	scanf("%d", &k);
	while (k--)
	{
		ZuoXuan(a, sz);
	}
	Print(a, sz);
	system("pause");
	return 0;
}