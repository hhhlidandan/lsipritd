#define _CRT_SECURE_NO_WARNINGS
//5.实现一个函数，判断一个数是不是素数。
#include<stdio.h>
#include<stdlib.h>
void panduan(int n)
{
	int i;
	for (i = 2; i <= n - 1; i++)
	{
		if (n%i == 0)
			break;
	}
	if (i >= n - i)
	{
		printf("%d是素数\n", n);
	}
	else
	{
		printf("%d不是素数\n", n);
	}

}
int main()
{
	int n;
	scanf("%d", &n);
	panduan(n);

	system("pause");
	return 0;
}