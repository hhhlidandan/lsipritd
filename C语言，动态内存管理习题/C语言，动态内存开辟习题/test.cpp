#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#pragma warning(disable:4996)

////��NULLָ��Ľ����ò���
//void test() {
//	int *p = (int *)malloc(INT_MAX / 4);
//	*p = 20;//���p��ֵ��NULL���ͻ�������    
//	free(p);
//}
////�Զ�̬���ٿռ��Խ�����
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
//		*(p + i) = i;//��i��10��ʱ��Խ�����
//	}
//	free(p);
//}
//
//
////�ԷǶ�̬�����ڴ�ʹ��free�ͷ�
//void test()
//{
//	int a = 10;
//	int *p = &a;
//	free(p);//ok?free�ͷŵ��Ƕ��ϵĿռ�
//}
//
////ʹ��free�ͷ�һ�鶯̬�����ڴ��һ����
//void test()
//{
//	int *p = (int *)malloc(100);
//	p++;//�ѿռ�����������������ͷ�
//	free(p);//p����ָ��̬�ڴ����ʼλ��
//}
////��ͬһ�鶯̬�ڴ����ͷ�
//void test()
//{
//	int *p = (int *)malloc(100);
//	free(p);
//	free(p);//�ظ��ͷ�
//}
////��̬�����ڴ������ͷţ��ڴ�й©��
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
//��������ı�����
//��Ŀ1��
//void GetMemory(char *p)//p����ʱ����
//{
//	p = (char *)malloc(100);//str��û�п��ٳ��ռ�
//}
//void Test(void)
//{
//	char *str = NULL;
//	GetMemory(str);
//	strcpy(str, "hello world");
//	printf(str);
//}
//��
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


//��Ŀ2��
////��������Test ��������ʲô���Ľ����
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


//��Ŀ3��
////��������Test ��������ʲô���Ľ����
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
////��Ŀ4��
//��������Test ��������ʲô���Ľ����
//free�ͷ��˿ռ���ǷǷ����ˣ��������word
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
////��������Test ��������ʲô���Ľ����
//
