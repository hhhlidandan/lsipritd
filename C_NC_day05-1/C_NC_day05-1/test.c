#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
#pragma warning(disable:4996)


//2.��дһ�����򣬿���һֱ���ռ����ַ���
//�����Сд�ַ��������Ӧ�Ĵ�д�ַ���
//������յ��Ǵ�д�ַ����������Ӧ��Сд�ַ���
//��������ֲ������

int main()
{
	char ch = 0;
	printf("Please Enter a ch...#\n");
	while (1)
	{
		scanf("%c", &ch);
		if (ch >= 'A' && ch <= 'Z')
		{
			ch += 32;
			printf("%c", ch);
		}
		else if (ch >= 'a'&& ch <= 'z')
		{
			ch -= 32;
			printf("%c", ch);
		}
	}	
	system("pause");
	return 0;
}

//1.��ɲ�������Ϸ��
//void menu()
//{
//	printf("*****************************\n");
//	printf("*****  1.play   2.exit  *****\n");
//	printf("*****************************\n");
//}
//void play()
//{
//	int ret=rand()%100+1;
//	int num = 0;
//	while (1)
//	{
//		printf("Please Enter an number#\n");
//		scanf("%d", &num);
//		if (num > ret)
//		{
//			printf("�´���\n");
//		}
//		else if (num < ret)
//		{
//			printf("��С��\n");
//		}
//		else
//		{
//			printf("�¶���\n");
//			break;
//		}
//	}	
//}
//int main()
//{
//	int n = 0;
//	menu();
//	printf("Please Enter...#\n");
//	scanf("%d", &n);
//	switch (n)
//	{
//	case 1:
//		play();
//		break;
//	case 0:
//		break;
//
//	}
//	srand((unsigned long)time(NULL));
//	system("pause");
//	return 0;
//}
