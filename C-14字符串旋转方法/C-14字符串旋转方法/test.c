#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<windows.h>
#pragma warning(disable:4996)

//方法一：
void LeftMove(char *str, int len,int num)
{
	assert(str);
	assert(len>0);
	assert(num);
	num %= len;//有效次数
	while (num--)//左旋次数
	{
		//左旋一次
		int i = 0;
		char temp = *str;//放第一个字符
		for (; i < len - 1; i++)
		{
			str[i] = str[i + 1];//指针可以下标引用式访问
		}
		str[i] = temp;//注意临界
	}	
}
//方法二：
void reserve(char* start, char* end)
{
	while (start<end)
	{
		*start ^= *end;
		*end ^= *start;
		*start ^= *end;
		start++;
		end--;
	}
}
void LeftMove1(char *str, int len, int num)
{
	assert(str);
	assert(len>0);
	assert(num);
	num %= len;//有效次数

	char *mid = str + num - 1;

	reserve(str, mid);//逆置前面
	reserve(mid + 1, str + len - 1);//逆置后面
	reserve(str, str + len - 1);//逆置整体
}
void LeftMove2(char* str, int len, int num)
{
	assert(str);
	assert(len > 0);
	assert(num);
	num %= len;

	char *buf = (char*)malloc(2 * len + 1);//申请放两个字符串的空间
	strcpy(buf, str);//把str拷到buf里
	strcat(buf, str);//把str拼接到buf里得到双倍串
	//左旋
	strncpy(str, buf + num, len);//
	free(buf);// (在堆上开辟的空间，自己释放)
	buf = NULL;
}
int main()
{
	int num = 0;
	char str[] = "ABCD";//要改字符串，所以这里不能用char *str=...
	int len = strlen(str);//有效元素个数，不包括'\0'
	printf("before:%s\n", str);
	printf("请问你需要左旋几个字符\n");
	scanf("%d", &num);
	LeftMove(str, len, num);
	LeftMove1(str, len, num);
	LeftMove2(str, len, num);
	printf("after:%s\n", str);
	system("pause");
	return 0;
}