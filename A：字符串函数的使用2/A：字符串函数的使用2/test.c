#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<assert.h>
#pragma warning(disable:4996)
int main()
{
	//�ڴ��������
	//����������ͼ��������޹أ������ַ����顢���͡��ṹ���

	char dst[] = "abcdef";
	char src[] = "def";
	//char *src = "acd";

	//void * memcpy ( void * destination, const void * source, size_t num );
	//memcpy(dst,dst+1,sizeof(dst));//���ֽڿ�������һ���ڴ�����ݿ�������һ���ڴ�
	//printf("%s\n", dst);

	//memset        �ڴ�ռ��ʼ��
	//����ԭ��void * memset ( void * ptr, int value, size_t num );
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