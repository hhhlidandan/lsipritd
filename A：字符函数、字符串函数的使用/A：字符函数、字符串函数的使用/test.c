#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<errno.h>
#pragma warning(disable:4996)

int main()
{
	//strlen
	//求字符串的个数，不包括'\0'
	/*const char *str = "abcdef";
	int len = strlen(str);
	printf("%d\n", len);*/

	//比较两个字符串的长度
	//char *str1 = "abcdef";
	//char *str2 = "cccc";
	//if (strlen(str2) > strlen(str1))
	//{
	//	printf("str2>str1\n");
	//}
	//else
	//{
	//	printf("str1>str2\n");
	//}
	//错误示例：
	/*char *str1 = "abcdef";
	char *str2 = "cccc";
	if (strlen(str2) - strlen(str1) > 0)
	{
		printf("str2>str1\n");
	}
	else
	{
		printf("str1>str2\n");
	}*/

	//strcpy
	//字符串拷贝会覆盖之前的内容,会把'\0'也考到目标字符串中
	//char * strcpy(char * destination, const char * source);
	char str1[20] = "abcdef";
	char *str2 = "hijk";
	printf("before:%s\n", str1);
	strcpy(str1, str2);
	printf("after:%s\n", str1);//结果是hijk

	//strcat
	//char * strcat ( char * destination, const char * source );
	//char str1[20] = "abcdef";
	//char *str2 = "hijk";
	//printf("before:%s\n", str1);
	//strcat(str1, str2);
	//printf("after:%s\n", str1);

	//strcmp
	//与字符的长度无关，比较的是ASCII
	//int strcmp(const char * str1, const char * str2);
	//char *str1 = "abcdef";
	//char *str2 = "hlcdef";
	//int ret = strcmp(str1, str2);
	//printf("%d\n", ret);

	//if (ret == 0)
	//{
	//	printf("str1==str2\n");
	//}
	//else
	//{
	//	printf("str1!=str2\n");
	//}
	//看'\0',由'\0'结束

	//返回值，特性，与上面一样
	//带n不看'\0'，更安全
	//strncpy
	//char* strncpy(char * destination, const char * source, size_t num);
	/*char str1[] = "abcd";
	char *str2 = "hij";
	printf("before:%s\n", str1);
	strncpy(str1, str2, strlen(str2)+1);
	printf("after:%s\n", str1);*/
	//strncat
	//char* strncat ( char * destination, const char * source, size_t num );
	/*char str1[20] = "abcd";
	const char *str2 = "hij";
	printf("before:%s\n", str1);
	strncat(str1, str1, strlen(str1));
	printf("after:%s\n", str1);*/

	//strncmp
	/*const char* str1 = "ab cd";
	const char* str2 = "ab def";
	int ret = strncmp(str1, str2, 4);
	printf("%d\n", ret);*/

	//strstr求子串
	//const char * strstr(const char * str1, const char * str2);
	//const char* str = "abcdefghij";
	//const char* str1 = "cde";
	//char* ret = strstr(str, str1);//求str1是否为str的子串,找到之后，从子串起始位置开始返回
	//char* ret1 = strstr(str, "bcd");
	//printf("ret:%s\n", ret);
	//printf("ret1:%s\n", ret1);

	//strtok 子串截取
	//用多种分隔符截取
	//char str[] = "he_llo world,!";
	//char* ch = strtok(str, " _,");//跟分隔符发顺序没有关系，调一次拿一个子串
	//while (ch != NULL)
	//{
	//	printf("%s\n", ch);
	//	ch = strtok(NULL, " _,");// 继续截取子串
	//}

	//strerror 将错误码输出为错误信息
//
//int i = 0;
//for (; i < 50; i++)
//{
//	printf("%d:%s\n",i, strerror(i));
//}
	//打开失败时，errno会被设置：没有错误，为0；有错误，errno会设置成对应的错误码(用strerror知道错误码描述)
	/*FILE* fp=fopen("a.txt","r");
	if (NULL == fp)
	{
		printf("%d:%s\n", errno, strerror(errno));
	}*/


	//memcpy

	//memmove
	//memset
	//memcmp
	system("pause");
	return 0;
}