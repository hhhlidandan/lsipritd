#include<stdio.h>
#include<stdlib.h>
#pragma warning(disable:4996)

int main()
{
	int a = 1;//1Ϊ��ַ��С��   0000 ...0001 1 Ϊ32��bitλ�е�ַ��С���ֽ�
	char* p = (char*)&a;//pָ��x����С���ֽ�(&��ַ�õ�ַ��С��)
	if (*p == 1)
	{
		printf("С��\n");
	}
	else
	{
		printf("���\n");
	}
	system("pause");
	return 0;
}