#define _CRT_SECURE_NO_WARNINGS
//5.ʵ��һ���������ж�һ�����ǲ���������
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
		printf("%d������\n", n);
	}
	else
	{
		printf("%d��������\n", n);
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