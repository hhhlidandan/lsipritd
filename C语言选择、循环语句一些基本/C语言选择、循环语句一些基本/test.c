#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
//switch语句
//int main()
//{
//	int day = 0;
//	scanf("%d", &day);
//	switch (day)
//	{
//	case 1:
//		printf("星期一\n");
//		break;
//	case 2:
//		printf("星期二\n");
//		break;
//	case 3:
//		printf("星期三\n");
//		break;
//	case 4:
//		printf("星期四\n");
//		break;
//	case 5:
//		printf("星期五\n");
//		break;
//	default:
//		printf("选择错误\n");
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
//		printf("选择错误\n");
//		break;
//	}
//	system("pause");
//	return 0;
//}

//while语句
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

//获取字符
//int main()
//{
//	int ch = 0;
//	while ((ch = getchar()) != EOF)
//	{
//		putchar(ch);
//	}
//	printf("success\n");//结束用ctrl Z
//	system("pause");
//	return 0;
//}

//对输入字符进行判定，只输出0-9之间的
//int main()
//{
//	int ch = 0;
//	while ((ch = getchar()) != EOF)
//	{
//		if (ch < '0'||ch > '9')
//			continue;
//		putchar(ch);//这里只能是0-9
//	}
//	system("pause");
//	return 0;
//}

//for语句
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