//while循环
#include<stdio.h>

int main()
{
	int i = 0;
	while (i < 10)// i<10是循环条件
	{
		printf("%d ", i);
		i++;
	}
	return 0;
}

//for循环
#include<stdio.h>
int main()
{
	int i = 0;
	// i=0;初始化，i<10;判断部分， i++;调整部分
	for (i = 0; i < 10; i++)
	{
		printf("%d ", i);
	}
	return 0;
}

//do..while循环

#include<stdio.h>
int main()
{
	int i = 0;
	do
	{//循环语句
		printf("%d ", i);
		i++;
	} while (i < 10);//表达式
	return 0;
}