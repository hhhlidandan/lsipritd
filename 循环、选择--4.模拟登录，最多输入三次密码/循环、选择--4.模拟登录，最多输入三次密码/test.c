#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
#pragma warning(disable:4996)

//#define Password "123456"
//int main()
//{
//	int count = 3;
//	while (count>0)
//	{
//		char pwd[20];
//		printf("Please Enter#\n");
//		scanf("%s", pwd);
//		if (strcmp(Password, pwd) == 0)
//		{
//			printf("success...welcome\n");
//			printf("正在为你加载\n");
//			break;
//		}
//		else
//		{
//			printf("密码错误，请重新输入\n");
//			printf("你还有%d次机会\n",--count);
//		}
//	}
//	if (count > 0)
//	{
//		int i = 9;
//		while (i >= 0)
//		{
//			printf("%d\r", i);
//			Sleep(1000);
//			i--;
//		}
//	}	
//	system("pause");
//	return 0;
//}

//用函数写
#define PASSWORD "abc123"
void menu()
{
	printf("*******************************\n");
	printf("****** 1.enter    2.exit ******\n");
	printf("*******************************\n");
}

void ter(char pwd[])
{
	int n = 3;
	while (n>0)
	{
		
		printf("请输入密码#");
		scanf("%s", pwd);
		if (strcmp(PASSWORD, pwd) == 0)
		{
			printf("登录成功\n");
			break;
		}
		else
		{
			printf("密码错误，请重新输入你还有%d次机会\n",--n);
		}
	}
	if (n>0)
	{
		int i = 9;
		for (; i > 0; i--)
		{
		printf("%d\r", i);
		Sleep(1000);
		}
		/*while (i >= 0)
		{
			printf("正在加载页面%d\r", i);
			Sleep(1000);
			i--;
		}*/
	}
}
int main()
{
	printf("Please Enter.#\n");

	char pwd[] = "";
	menu();
	int n = 0;
	scanf("%d", &n);
	switch (n)
	{
	case 1:
		ter(&pwd);
		break;
	case 2:
		printf("退出成功！\n");
			break;
	default:
		printf("选择错误\n");
		break;
	}
	system("pause");
	return 0;
}