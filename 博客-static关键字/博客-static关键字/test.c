//���ξֲ�����
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
void test1()
{
	int i = 0;//�ֲ����������������������
	i++;
	printf("%d ", i);//��ӡ��10��1
}

void test2()
{
	//static���ξֲ�����
	static int k = 0;//��̬�ֲ����� //k���������ϴ��������ģ�ֻ��ʼ��һ��
	k++;
	printf("%d ", k);//��ӡ 1 2 3 4 5 6 7 8 9 10
}

int main()
{
	int j = 0;
	int m = 0;
	for (j = 0; j < 10; j++)
	{
		test1();//10��1
	}
	printf("\n");
	for (m = 0; m < 10; m++)
	{
		test2();//1 2 3 4 5 6 7 8 9 10
	}
	system("pause");
	return 0;
}

//����ȫ�ֱ���**
//����1:(������ӡ)
	//add.c
	int g_val = 2018;
	//test.c
   #include<stdio.h>
	extern g_val;//extern�����ⲿ����
	int main()
	{
		printf("%d\n", g_val);//2018
		system("pause");
		return 0;
	}

		//����2�����������Դ���
//add.c
		static int g_val = 2018;//�������ȫ�ֵ���add.c���ļ�����³��ִ���
	//test.c
#include<stdio.h>
	extern g_val;//extern�����ⲿ����
	int main()
	{
		printf("%d\n", g_val);//���ִ���
		system("pause");
		return 0;
	}

//	���κ���
//	����1��������ӡ��

		//add.c
		int add(int x, int y)
	{
			return x + y;
		}
	//test.c
#include<stdio.h>
	int main()
	{
		printf("%d \n", add(2, 3));// 5
		return 0;
	}
//		����2�����������Դ���

		//add.c
		int add(int x, int y)
	{
			return x + y;
		}
	//test.c
#include<stdio.h>
	int main()
	{
		printf("%d \n", add(2, 3));// ���ִ���
		return 0;
	}