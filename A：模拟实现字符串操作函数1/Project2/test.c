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
////�򵥲���
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
//�򻯴�������
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
	while (*dst == *src && *dst!='\0' && src!='\0')//����Ҳ�Ϊ0��һֱ���Ƚ�
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
//	if (*src == '\0')//���Ϊ'\0',��˵��û���ַ�������NULL
//	{
//		return NULL;
//	}
//	const char *p1 = dst;//ָ��ʼ
//	const char *p2 = src;
//	char *q = NULL;//
//	while (*p1 != '\0')//�����￪ʼ
//	{
//		q = p1;//ÿ�ζ�����
//		p2 = src;//ÿ�ζ����ʼƥ��
//		//�����Ӵ�
//		while (*p2 && *p1 == *p2 && *p1)
//		{
//				p1++;
//				p2++;
//		}
//		if (*p2 == '\0')//����˵��p2��p1ƥ�����ˣ����Ƚ�����
//		{
//			return q;
//		}
//		//û���ҵ�������++����һ���Ƿ����ƥ��
//		p1++;
//	}
//	return NULL;//û���ҵ�����NULL	
//}
int main()
{
	//��ָ�붨��һ������str,��ջ��ָ���ַ����������ַ���������ֱ�ӱ��޸ģ����Լ�const�Ϻã�������ǰ���ִ���
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