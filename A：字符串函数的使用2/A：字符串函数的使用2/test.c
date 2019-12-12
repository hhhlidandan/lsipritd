#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<assert.h>
#pragma warning(disable:4996)
int main()
{
	//内存操作函数
	//针对任意类型即与类型无关，例如字符数组、整型、结构体等

	char dst[] = "abcdef";
	char src[] = "def";
	//char *src = "acd";

	//void * memcpy ( void * destination, const void * source, size_t num );
	//memcpy(dst,dst+1,sizeof(dst));//按字节拷贝，把一块内存的数据拷贝到另一块内存
	//printf("%s\n", dst);

	//memset        内存空间初始化
	//函数原型void * memset ( void * ptr, int value, size_t num );
	//memset(dst, 'a',strlen(dst));
	//printf("%s\n", dst);

	//memcmp  
	//int memcmp(const void * ptr1, const void * ptr2, size_t num);
	//int ret= memcmp(dst, src, 4);
	//printf("%d\n", ret);//-1

	//memmove
	//void * memmove(void * destination, const void * source, size_t num);
	memmove(dst, dst + 1, sizeof(dst));
	printf("%s\n", dst);
	system("pause");
	return 0;
}