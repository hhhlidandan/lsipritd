#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#pragma warning(disable:4996)

////对NULL指针的解引用操作
//void test() {
//	int *p = (int *)malloc(INT_MAX / 4);
//	*p = 20;//如果p的值是NULL，就会有问题    
//	free(p);
//}
////对动态开辟空间的越界访问
//void test()
//{
//	int i = 0;
//	int *p = (int *)malloc(10 * sizeof(int));
//	if (NULL == p)
//	{
//		exit(EXIT_FAILURE);
//	}
//	for (i = 0; i <= 10; i++)
//	{
//		*(p + i) = i;//当i是10的时候越界访问
//	}
//	free(p);
//}
//
//
////对非动态开辟内存使用free释放
//void test()
//{
//	int a = 10;
//	int *p = &a;
//	free(p);//ok?free释放的是堆上的空间
//}
//
////使用free释放一块动态开辟内存的一部分
//void test()
//{
//	int *p = (int *)malloc(100);
//	p++;//堆空间必须整体申请整体释放
//	free(p);//p不再指向动态内存的起始位置
//}
////对同一块动态内存多次释放
//void test()
//{
//	int *p = (int *)malloc(100);
//	free(p);
//	free(p);//重复释放
//}
////动态开辟内存忘记释放（内存泄漏）
//void test()
//{
//	int *p = (int *)malloc(100);
//	if (NULL != p)
//	{
//		*p = 20;
//	}
//}
//int main()
//{
//	test();
//	while (1);
//}
//几个经典的笔试题
//题目1：
//void GetMemory(char *p)//p是临时变量
//{
//	p = (char *)malloc(100);//str并没有开辟出空间
//}
//void Test(void)
//{
//	char *str = NULL;
//	GetMemory(str);
//	strcpy(str, "hello world");
//	printf(str);
//}
//改
//void GetMemory(char **p)
//{
//	*p = (char *)malloc(100);
//void Test(void)
//{
//	char *str = NULL;
//	GetMemory(&str);
//	strcpy(str, "hello world");
//	printf(str);
//	free(str);
//	str = NULL;
//}


//题目2：
////请问运行Test 函数会有什么样的结果？
//char *GetMemory(void)
//{
//	char p[] = "hello world";
//	return p;
//}
//int main()
//{
//	char *str = NULL;
//	str = GetMemory();
//	printf(str);
//	system("pause");
//	return 0;
//}


//题目3：
////请问运行Test 函数会有什么样的结果？
//void GetMemory(char **p, int num)
//{
//	*p = (char *)malloc(num);
//}
//int main()
//{
//	char *str = NULL;
//	GetMemory(&str, 100);
//	strcpy(str, "hello");
//	printf(str);
//	system("pause");
//	return 0;
//}
////
////题目4：
//请问运行Test 函数会有什么样的结果？
//free释放了空间就是非法的了，最后会输出word
int main()
{
	char *str = (char *)malloc(100);
	strcpy(str, "hello");
	free(str);//
	if (str != NULL)
	{
		strcpy(str, "world");
		printf(str);
	}
	system("pause");
	return 0;
}
////请问运行Test 函数会有什么样的结果？
//
