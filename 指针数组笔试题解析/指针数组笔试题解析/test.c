#include<stdio.h>
#include<string.h>
#include<windows.h>
#pragma warning(disable:4996)

//sizeof 字符串开辟空间的大小，包括'\0'
//strlen 字符串长度，求的是字符串的有效个数,不包括'\0'
//数组名一般代表首元素的地址
//只有两种情况，代表整个数组的地址 1.sizeof(数组名)单独使用时，2.&数组名
int main()
{
	//一维数组 
	//int a[] = { 1, 2, 3, 4 };
	//printf("%d\n", sizeof(a));//16 整个数组的地址
	//printf("%d\n", sizeof(a + 0));//4  首元素地址
	//printf("%d\n", sizeof(*a));//4 首元素
	//printf("%d\n", sizeof(a + 1));//4 第二个元素的地址
	//printf("%d\n", sizeof(a[1])); //4 第二个元素的地址
	//printf("%d\n", sizeof(&a));// 4 整个数组的地址
	//printf("%d\n", sizeof(*&a));//16 整个数组 *&a相当于a
	//printf("%d\n", sizeof(&a + 1));// 4 下一个数组的地址
	//printf("%d\n", sizeof(&a[0]));//4 首元素的地址
	//printf("%d\n", sizeof(&a[0] + 1));//4 第二个元素的地址

	//字符数组 
	char arr[] = {'a','b','c','d','e','f'}; //在32位平台下，char类型占1个字节大小
	//printf("%d\n", sizeof(arr)); //6 整个数组，里面有6个字符
	//printf("%d\n", sizeof(arr+0)); //4 首元素地址，指针就是地址，所以为4
	//printf("%d\n", sizeof(*arr)); //1 首元素 
	//printf("%d\n", sizeof(arr[1])); //1 第二个元素
	//printf("%d\n", sizeof(&arr)); //4 数组的地址
	//printf("%d\n", sizeof(&arr+1)); //4 指向下一个数组
	//printf("%d\n", sizeof(&arr[0]+1));//4第二个元素的地址

	//printf("%d\n", strlen(arr)); //错误 找不到'\0'（不知道'\0'的位置）
	//printf("%d\n", strlen(arr + 0)); //错误 
	//printf("%d\n", strlen(*arr)); // 报错 strlen需要传过去的是地址

	//printf("%d\n", strlen(arr[1])); //报错
	//printf("%d\n", strlen(&arr)); //错误 找不到'\0'
	//printf("%d\n", strlen(&arr + 1));//？ 指向下一个元素的首地址，但仍然不知道'\0'的位置
	//printf("%d\n", strlen(&arr[0] + 1));// 第二个元素的地址，但仍然不知道'\0'的位置


	//char arr[] = "abcdef"; 
	//sizeof 求字符串长度包含'\0'
	//printf("%d\n", sizeof(arr)); //7 整个数组  字符串开辟空间的大小包括'\0'
	//printf("%d\n", sizeof(arr + 0));//4 首元素地址
	//printf("%d\n", sizeof(*arr)); //1 首元素
	//printf("%d\n", sizeof(arr[1])); //1 第二个元素
	//printf("%d\n", sizeof(&arr)); //4 整个数组的地址
	//printf("%d\n", sizeof(&arr + 1));//4 下一个数组的地址
	//printf("%d\n", sizeof(&arr[0] + 1));//4 第二个元素的地址

	//strlen求有效元素个数，不包括'\0'
	//printf("%d\n", strlen(arr)); //6 数组的长度 到'\0'停下
	//printf("%d\n", strlen(arr + 0)); //6 
	//printf("%d\n", strlen(*arr)); //错 需要传地址
	//printf("%d\n", strlen(arr[1])); //错
	//printf("%d\n", strlen(&arr));//6 整个数组的地址
	//printf("%d\n", strlen(&arr + 1)); //随机值， 指向'\0'后面（跳过了这个数组）
	//printf("%d\n", strlen(&arr[0] + 1));//5  从第二元素开始

	//char *p = "abcdef"; 
	//printf("%d\n", sizeof(p)); //4 首字符的地址 指针的大小
	//printf("%d\n", sizeof(p + 1)); // 4 第二个字符的地址
	//printf("%d\n", sizeof(*p)); //1 第一个元素的大小
	//printf("%d\n", sizeof(p[0])); //1 第一个元素的大小
	//printf("%d\n", sizeof(&p)); //4 p的地址（二级指针）
	//printf("%d\n", sizeof(&p + 1));//4 下一个数组的地址
	//printf("%d\n", sizeof(&p[0] + 1));//4 下一个元素的地址

	//printf("%d\n", strlen(p));//6
	//printf("%d\n", strlen(p + 1));//5 
	////printf("%d\n", strlen(*p)); //错 
	////printf("%d\n", strlen(p[0])); //错
	//printf("%d\n", strlen(&p)); //随机值 二级指针的'\0'不确定
	//printf("%d\n", strlen(&p + 1)); //随机值 
	//printf("%d\n", strlen(&p[0] + 1));//5 从第二个元素开始

	//二维数组 
	//可以把它当成一维数组
	//a[3][4]:一个一维数组里有3个元素，每个元素里又有4个元素
	//int a[3][4] = {0}; 
	//printf("%d\n",sizeof(a)); //48 整个数组的大小
	//printf("%d\n",sizeof(a[0][0])); //4 第一行第一个元素的大小（第一个数字的大小）
	//printf("%d\n",sizeof(a[0])); //16 第一行的元素（数组）的大小
	//printf("%d\n",sizeof(a[0]+1)); //4 第一行第二个元素的地址
	//printf("%d\n",sizeof(*(a[0]+1)));// 4 第一行第二个元素
	//printf("%d\n",sizeof(a+1)); //4 第二行元素的地址
	//printf("%d\n",sizeof(*(a+1))); //16 第二行元素的大小
	//printf("%d\n",sizeof(&a[0]+1));//4 第二行元素的地址 （第二个元素）
	//printf("%d\n",sizeof(*(&a[0]+1))); //16 第二行元素的大小
	//printf("%d\n",sizeof(*a)); //16 第一行元素的大小
	//printf("%d\n",sizeof(a[3]));//16 越界，但sizeof是关键字，不关心空间是否为真

	
	system("pause");
	return 0;
}
