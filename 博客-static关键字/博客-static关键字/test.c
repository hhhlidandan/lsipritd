//修饰局部变量
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
void test1()
{
	int i = 0;//局部变量，出了作用域就销毁
	i++;
	printf("%d ", i);//打印了10个1
}

void test2()
{
	//static修饰局部变量
	static int k = 0;//静态局部变量 //k保留的是上次留下来的，只初始化一次
	k++;
	printf("%d ", k);//打印 1 2 3 4 5 6 7 8 9 10
}

int main()
{
	int j = 0;
	int m = 0;
	for (j = 0; j < 10; j++)
	{
		test1();//10个1
	}
	printf("\n");
	for (m = 0; m < 10; m++)
	{
		test2();//1 2 3 4 5 6 7 8 9 10
	}
	system("pause");
	return 0;
}

//修饰全局变量**
//代码1:(正常打印)
	//add.c
	int g_val = 2018;
	//test.c
   #include<stdio.h>
	extern g_val;//extern声明外部符号
	int main()
	{
		printf("%d\n", g_val);//2018
		system("pause");
		return 0;
	}

		//代码2（出现连接性错误）
//add.c
		static int g_val = 2018;//作用域从全局到了add.c的文件里，导致出现错误
	//test.c
#include<stdio.h>
	extern g_val;//extern声明外部符号
	int main()
	{
		printf("%d\n", g_val);//出现错误
		system("pause");
		return 0;
	}

//	修饰函数
//	代码1（正常打印）

		//add.c
		int add(int x, int y)
	{
			return x + y;
		}
	//test.c
#include<stdio.h>
	int main()
	{
		printf("%d \n", add(2, 3));// 5
		return 0;
	}
//		代码2（出现连接性错误）

		//add.c
		int add(int x, int y)
	{
			return x + y;
		}
	//test.c
#include<stdio.h>
	int main()
	{
		printf("%d \n", add(2, 3));// 出现错误
		return 0;
	}