#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
//switch���
//int main()
//{
//	int day = 0;
//	scanf("%d", &day);
//	switch (day)
//	{
//	case 1:
//		printf("����һ\n");
//		break;
//	case 2:
//		printf("���ڶ�\n");
//		break;
//	case 3:
//		printf("������\n");
//		break;
//	case 4:
//		printf("������\n");
//		break;
//	case 5:
//		printf("������\n");
//		break;
//	default:
//		printf("ѡ�����\n");
//		break;
//	}
//	system("pause");
//	return 0;
//}

//int main()
//{
//	int day = 0;
//	scanf("%d", &day);
//	switch (day)
//	{
//	case 1:
//	case 2:
//	case 3:
//	case 4:
//	case 5:
//		printf("weekday\n");
//		break;
//	case 6:
//	case 7:
//		printf("weekend\n");
//		break;
//	default:
//		printf("ѡ�����\n");
//		break;
//	}
//	system("pause");
//	return 0;
//}

//while���
//int main()
//{
	/*int i = 0;
	while (i < 10)
	{
		i++;
		printf("%d ", i);
	}*/
	//int j = 0;
	//while (j < 10)
	//{
	//	j++;
	//	if (5 == j){
	//		//break;
	//		continue;
	//	}
	//	printf("%d ", j);
	//}
	//printf("\n");
	//system("pause");
	//return 0;
//}

//��ȡ�ַ�
//int main()
//{
//	int ch = 0;
//	while ((ch = getchar()) != EOF)
//	{
//		putchar(ch);
//	}
//	printf("success\n");//������ctrl Z
//	system("pause");
//	return 0;
//}

//�������ַ������ж���ֻ���0-9֮���
//int main()
//{
//	int ch = 0;
//	while ((ch = getchar()) != EOF)
//	{
//		if (ch < '0'||ch > '9')
//			continue;
//		putchar(ch);//����ֻ����0-9
//	}
//	system("pause");
//	return 0;
//}

//for���
//int main()
//{
//	int i = 0;
//	for (; i < 10; i++)
//	{
//		if (i == 5){
//			break;
//		}
//		printf("%d ", i);
//	}
//	printf("\n");
//	system("pause");
//	return 0;
//}

//int main()
//{
//	int i = 0;
//	for (; i < 10; i++)
//	{
//		if (i == 5){
//			continue;
//		}
//		printf("%d ", i);
//	}
//	printf("\n");
//	system("pause");
//	return 0;
//}

//do ..while
int main()
{
	int i = 0;
	do{
		printf("%d ", i);
		i++;
	} while (i < 10);
	printf("\n");
	system("pause");
	return 0;
}