#include<stdio.h>
#include<windows.h>
#pragma warning(disable:4996)

int Add(int x, int y)
{
	return x + y;
}
int Sub(int x, int y)
{
	return x - y;
}
int Mul(int x, int y)
{
	return x * y;
}
int Div(int x, int y)
{
	return x / y;
}
int Mod(int x, int y)
{
	return x % y;
}

int main()
{
	printf("##################################\n");
	printf("######## 1.add      2.sub   ######\n");
	printf("######## 3.mul      4.div   ######\n");
	printf("######## 5.mod      6.exit  ######\n");
	printf("##################################\n");
	printf("Please Enter#\n");
	int input = 0;
	int result = 0;
	int x = 0;
	int y = 0;
	scanf("%d", &input);
	switch (input)
	{
	case 1:
		printf("Please in two numbers:");
		scanf("%d %d", &x, &y);
		result = Add(x, y);
		break;
	case 2:
		printf("Please in two numbers:");
		scanf("%d %d", &x, &y);
		result = Sub(x, y);
		break;
	case 3:
		printf("Please in two numbers:");
		scanf("%d %d", &x, &y);
		result = Mul(x, y);
		break;
	case 4:
		printf("Please in two numbers:");
		scanf("%d %d", &x, &y);
		result = Div(x, y);
		break;
	case 5:
		printf("Please in two numbers:");
		scanf("%d %d", &x, &y);
		result = Mod(x, y);
		break;
	default:
		printf("error\n");
		printf("Please Enter Again\n");
		break;
	}
	printf("result is %d\n", result);
	system("pause");
	return 0;
}
//函数指针数组
int main()
{
	    int x, y;
		int input = 1;
		int result = 0;
		
		//定义一个函数指针数组
	    int (*a[])(int x,int y) = { 0, Add, Sub, Mul, Div, Mod };
		while (input)
		{
			printf("##################################\n");
			printf("######## 1.add      2.sub   ######\n");
			printf("######## 3.mul      4.div   ######\n");
			printf("######## 5.mod              ######\n");
			printf("##################################\n");
			printf("Please Enter#\n");
			scanf("%d", &input);
			if (input >= 1 && input <= 5)
			{
				printf("Please Enter two numbers:");
				scanf("%d%d", &x, &y);
				result = (*a[input])(x, y);
			}
			else
			{
				printf("input error\n");
			}
			printf("%d\n", result);
		}
		system("pause");
		return 0;
}