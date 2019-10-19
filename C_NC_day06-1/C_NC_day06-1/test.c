#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
#pragma warning(disable:4996)

//创建一个数组，
//实现函数init（）初始化数组、
//实现empty（）清空数组、
//实现reverse（）函数完成数组元素的逆置。
//要求：自己设计函数的参数，返回值。

void init(int arr[10],int sz)
{
	int i = 0;
	for (i = 0; i < sz; i++)
	{
		arr[i] = i;
		printf("%d ", arr[i]);
	}
	/*printf("初始化之后:\n");
	for (i = 0; i < 10; i++)
	{
		printf("%d ", arr[i]);
	}*/
	printf("\n");
	
}
void empty(int arr[10],int sz)
{
	int i = 0;
	for (; i < sz; i++)
	{
		arr[i] = 0;
		printf("%d ", arr[i]);
	}
	printf("\n");
}
void reverse(int arr[10],int sz)
{
	int left = 0;
	int i = 0;
	int right = sz - 1;

	printf("逆置之前:\n");
	for (i = 0; i < sz; i++)
	{
		arr[i] = i;
		printf("%d ", arr[i]);
	}
	printf("\n");
	while (left < right)
	{
		arr[left] = arr[left] ^ arr[right];
		arr[right] = arr[left] ^ arr[right];
		arr[left] = arr[left] ^ arr[right];
		left++;
		right--;
	}
	printf("逆置之后\n");
	for (i=0; i < sz; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
}
int main()
{
	int arr[10] = {0};
	int sz = sizeof(arr) / sizeof(arr[0]);

	printf("init#\n");
	init(arr,sz);

	printf("empty#\n");
	empty(arr,sz);

	printf("reverse#\n");
	reverse(arr,sz);

	system("pause");
	return 0;
}

//1.实现一个函数，打印乘法口诀表，口诀表的行数和列数自己指定，
//输入9，输出9 * 9口诀表，输入12，输出12 * 12的乘法口诀表。
//void mul(int num)
//{
//	int i = 1;
//	int j = 1;
//	for (; i <= num; i++)
//	{
//		for (j=1; j <= i; j++)
//		{
//			printf("%d*%d=%2d ", i, j, i*j);
//		}
//		printf("\n");
//	}
//}
//int main()
//{
//	int num = 0;
//	printf("Please Enter a number#\n");
//	scanf("%d", &num);
//	mul(num);
//
//	system("pause");
//	return 0;
//}
