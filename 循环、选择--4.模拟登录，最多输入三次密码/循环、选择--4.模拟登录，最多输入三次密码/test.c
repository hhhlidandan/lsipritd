#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
#pragma warning(disable:4996)

//#define Password "123456"
//int main()
//{
//	int count = 3;
//	while (count>0)
//	{
//		char pwd[20];
//		printf("Please Enter#\n");
//		scanf("%s", pwd);
//		if (strcmp(Password, pwd) == 0)
//		{
//			printf("success...welcome\n");
//			printf("����Ϊ�����\n");
//			break;
//		}
//		else
//		{
//			printf("�����������������\n");
//			printf("�㻹��%d�λ���\n",--count);
//		}
//	}
//	if (count > 0)
//	{
//		int i = 9;
//		while (i >= 0)
//		{
//			printf("%d\r", i);
//			Sleep(1000);
//			i--;
//		}
//	}	
//	system("pause");
//	return 0;
//}

//�ú���д
#define PASSWORD "abc123"
void menu()
{
	printf("*******************************\n");
	printf("****** 1.enter    2.exit ******\n");
	printf("*******************************\n");
}

void ter(char pwd[])
{
	int n = 3;
	while (n>0)
	{
		
		printf("����������#");
		scanf("%s", pwd);
		if (strcmp(PASSWORD, pwd) == 0)
		{
			printf("��¼�ɹ�\n");
			break;
		}
		else
		{
			printf("������������������㻹��%d�λ���\n",--n);
		}
	}
	if (n>0)
	{
		int i = 9;
		for (; i > 0; i--)
		{
		printf("%d\r", i);
		Sleep(1000);
		}
		/*while (i >= 0)
		{
			printf("���ڼ���ҳ��%d\r", i);
			Sleep(1000);
			i--;
		}*/
	}
}
int main()
{
	printf("Please Enter.#\n");

	char pwd[] = "";
	menu();
	int n = 0;
	scanf("%d", &n);
	switch (n)
	{
	case 1:
		ter(&pwd);
		break;
	case 2:
		printf("�˳��ɹ���\n");
			break;
	default:
		printf("ѡ�����\n");
		break;
	}
	system("pause");
	return 0;
}