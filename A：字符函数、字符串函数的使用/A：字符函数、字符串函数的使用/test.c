#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<errno.h>
#pragma warning(disable:4996)

int main()
{
	//strlen
	//���ַ����ĸ�����������'\0'
	/*const char *str = "abcdef";
	int len = strlen(str);
	printf("%d\n", len);*/

	//�Ƚ������ַ����ĳ���
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
	//����ʾ����
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
	//�ַ��������Ḳ��֮ǰ������,���'\0'Ҳ����Ŀ���ַ�����
	//char * strcpy(char * destination, const char * source);
	char str1[20] = "abcdef";
	char *str2 = "hijk";
	printf("before:%s\n", str1);
	strcpy(str1, str2);
	printf("after:%s\n", str1);//�����hijk

	//strcat
	//char * strcat ( char * destination, const char * source );
	//char str1[20] = "abcdef";
	//char *str2 = "hijk";
	//printf("before:%s\n", str1);
	//strcat(str1, str2);
	//printf("after:%s\n", str1);

	//strcmp
	//���ַ��ĳ����޹أ��Ƚϵ���ASCII
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
	//��'\0',��'\0'����

	//����ֵ�����ԣ�������һ��
	//��n����'\0'������ȫ
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

	//strstr���Ӵ�
	//const char * strstr(const char * str1, const char * str2);
	//const char* str = "abcdefghij";
	//const char* str1 = "cde";
	//char* ret = strstr(str, str1);//��str1�Ƿ�Ϊstr���Ӵ�,�ҵ�֮�󣬴��Ӵ���ʼλ�ÿ�ʼ����
	//char* ret1 = strstr(str, "bcd");
	//printf("ret:%s\n", ret);
	//printf("ret1:%s\n", ret1);

	//strtok �Ӵ���ȡ
	//�ö��ַָ�����ȡ
	//char str[] = "he_llo world,!";
	//char* ch = strtok(str, " _,");//���ָ�����˳��û�й�ϵ����һ����һ���Ӵ�
	//while (ch != NULL)
	//{
	//	printf("%s\n", ch);
	//	ch = strtok(NULL, " _,");// ������ȡ�Ӵ�
	//}

	//strerror �����������Ϊ������Ϣ
//
//int i = 0;
//for (; i < 50; i++)
//{
//	printf("%d:%s\n",i, strerror(i));
//}
	//��ʧ��ʱ��errno�ᱻ���ã�û�д���Ϊ0���д���errno�����óɶ�Ӧ�Ĵ�����(��strerror֪������������)
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