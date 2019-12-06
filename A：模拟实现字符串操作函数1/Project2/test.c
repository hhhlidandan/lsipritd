#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#pragma warning(disable:4996)
//int my_strlen(char* str)
//{
//	assert(str);
//	if (*str != '\0')
//	{
//		return (1 + my_strlen(str + 1));
//	}
//	return 0;
//	int count = 0;
//	while (*str != '\0')
//	{
//		str++;
//		count++;
//	}
//	return count;
//}
//char* my_strcpy(char* dst, const char* src)
//{
//	assert(dst);
//	assert(src);
//	char* ret = dst;
//	/*while (*src != '\0')
//	{
//		*dst++ = *src++;
//
//	}
//	*dst = '\0';*/
////简单步骤
//	while (*dst++ = *src++)
//	{
//		;
//	}
//	//
//	return ret;
//}
//char* my_strcat(char* dst, const char* src)
//{
//	assert(dst);
//	assert(src);
//	char* ret = dst;
//	while (*dst != '\0')
//	{
//		dst++;
//	}
//	while (*dst++ = *src++)
//	{
//		;
//	}
//简化代码如上
//	/*while (*src != '\0')
//	{
//		*dst = *src;
//		dst++, src++;
//	}
//	*dst = '\0';*/
//	return ret;
//}

int my_strcmp(const char* dst, const char* src)
{
	assert(dst);
	assert(src);

	int ret = 0;
	while (*dst == *src && *dst!='\0' && src!='\0')//相等且不为0，一直向后比较
	{
		dst++, src++;
	}
	ret = *dst - *src;
	if (ret > 0)
	{
		return 1;
	}
	else if (ret < 0)
	{
		return -1;
	}
	return 0;

//const char *my_strstr(const char *dst, const char *src)
//{
//	assert(dst);
//	assert(src);
//	
//	if (*src == '\0')//如果为'\0',则说明没有字符，返回NULL
//	{
//		return NULL;
//	}
//	const char *p1 = dst;//指向开始
//	const char *p2 = src;
//	char *q = NULL;//
//	while (*p1 != '\0')//从哪里开始
//	{
//		q = p1;//每次都更新
//		p2 = src;//每次都从最开始匹配
//		//查找子串
//		while (*p2 && *p1 == *p2 && *p1)
//		{
//				p1++;
//				p2++;
//		}
//		if (*p2 == '\0')//到这说明p2与p1匹配完了，即比较完了
//		{
//			return q;
//		}
//		//没有找到，继续++看下一个是否可以匹配
//		p1++;
//	}
//	return NULL;//没有找到返回NULL	
//}
int main()
{
	//用指针定义一个变量str,在栈上指向字符常量区的字符串，不能直接被修改，所以加const较好，可以提前发现错误
	const char *str = "abcdef";
	const char *sub_str = "cd";
	//int ret = my_strlen(str);
	//printf("%d\n", ret);
	//my_strcpy(dst, src);
	//printf("my_strcpy: %s\n", dst);
	//my_strcat(dst, src);
	//printf("my_strcat: %s\n", dst);
	//int ret = my_strcmp(dst, src);
	//printf("my_strcmp ret is: %d\n",ret);
	/*printf("%s\n", my_strstr(str, sub_str));*/

	system("pause");
	return 0;
}