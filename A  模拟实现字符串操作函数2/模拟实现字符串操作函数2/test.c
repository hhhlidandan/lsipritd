#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<assert.h>
#pragma warning(disable:4996)
//void *my_memcpy(void *dst, void *src, int num)
//{
//	assert(dst);
//	assert(src);
//	//得有一个容器
//	char *dst_p = (char*)dst;//强转成char*   因为以字节为单位，char 占一个字节
//	char *src_p = (char*)src;
//	//拷num个字节，循环一次拷一个
//	while (num--)
//	{
//		*dst_p = *src_p;
//		dst_p++, src_p++;
//	}
//	return dst;
//}

//void *my_memset(void *arr, int value, size_t num)
//{
//	assert(arr);
//	char *dst = (char*)arr;
//	size_t i = 0;
//	for (; i < num; i++)
//	{
//		*(dst + i) = (char)value;
//	}
//	return arr;
//}

//int my_memcmp(const void *dst,const void *src, int num)
//{
//	assert(dst);
//	assert(src);
//	char *p1 = (char*)dst;
//	char *p2 = (char*)src;
//	while (num&&*p1 == *p2)
//	{
//			p1++; 
//			p2++;
//			num--;
//	}
//	if (*p1 > *p2)
//	{
//		return 1;
//	}
//	else if (*p1 < *p2)
//	{
//		return -1;
//	}
//	return 0;
//}

int main()
{
	//mem的操作函数与类型无关

	//char *arr = "hello world";
	//char arr1[32];
	//my_memcpy(arr1, arr, strlen(arr)+1);//按字节拷贝
	//################################################3
	/*int arr2[] = { 1, 2, 3, 4, 5 };
	int sz = sizeof(arr2) / sizeof(arr2[0]);
	int i = 0;
	printf("before:\n");
	for (; i < sz; i++)
	{
		printf("%d", arr2[i]);
	}
	printf("\n");

	my_memset(arr2, 0, sizeof(arr2));

	printf("after:\n");
	for (i=0; i < sz; i++)
	{
		printf("%d", arr2[i]);
	}
	printf("\n");*/
	//###############################################
	/*const char *a1 = "abcdef";
	const char *a2 = "abcdef";
	int ret = my_memcmp(a1, a2, 3);
	printf("%d\n", ret);*/
	//################################################

	system("pause");
	return 0;
}