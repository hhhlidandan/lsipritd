#include<stdio.h>
#include<windows.h>
//输入整数的每一个bit位
//1010 1010
void ShowNum(unsigned int data)
{
	int flag = 1;
	int num = sizeof(data)* 8;
	int i = 0;
	for (; i < num; i++)
	{
		if (i % 4 == 0)
		{
			printf(" ");
		}
		if (data&(flag << (num - 1-i)))
		{
			printf("1");
		}
		else{
			printf("0");
		}
	}
	printf("\n");
	
}
int main()
{
	ShowNum(0xAA);
	system("pause");
	return 0;
}