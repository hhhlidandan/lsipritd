#include<stdio.h>
#include<stdlib.h>
#pragma warning(disable:4996)

int main()
{
	int a = 1;//1为地址最小的   0000 ...0001 1 为32个bit位中地址最小的字节
	char* p = (char*)&a;//p指向x中最小的字节(&地址拿地址最小的)
	if (*p == 1)
	{
		printf("小端\n");
	}
	else
	{
		printf("大端\n");
	}
	system("pause");
	return 0;
}