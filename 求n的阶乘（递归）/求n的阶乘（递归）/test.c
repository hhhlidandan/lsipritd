//6.递归和非递归分别实现求n的阶乘
#include<stdio.h>
#include<stdlib.h>
int fun_r(int n)
{
	int i = 0;
	int ret = 1;
	for (i = 1; i <= n; i++)
	{
		ret = ret*i;
	}
	return ret;
}
int main()
{
	int n;
	scanf("%d", &n);
	printf("%d\n", fun_r(n));
	system("pause");
	return 0;
}

#include<stdio.h>
#include<stdlib.h>
int fun_r(int n)
{
	if (n == 1)
		return 1;
	return n*fun_r(n - 1);
}
int main()
{
	int n;
	scanf("%d", &n);
	printf("%d\n", fun_r(n));
	system("pause");
	return 0;
}