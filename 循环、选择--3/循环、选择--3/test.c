#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>
#include<windows.h>
#pragma warning(disable:4996)

//��д����ʵ�֣�ģ���û���¼�龰������ֻ�ܵ�����

#define password "abc123"
int main()
{
	char pws[20] = "";
	int i = 0;
	int count = 3;
	
	while(count>0){
		printf("Please Enter Your password:>\n");
		scanf("%s", pws);
		if (strcmp(password, "pws") == 0)
		{
			printf("��¼�ɹ�\n");
			break;
		}
		else
		{
			printf("��������㻹��%d�λ���\n",--count);
		}	
	}
	system("pause");
	return 0;

	/*int n = 0;
	switch (n)
	{
	case 1:
		play();
		break;
	case 2:
		printf("exit success!\n");
		break;
	default:
		break;
	}*/
	
}
//��д���룬��ʾ����ַ����������м���
//int main()
//{
//
//	char a1[] = "welcome to world!";
//	char a2[] = "*****************";
//	int left = 0;
//	int right = strlen(a2) - 1;
//	while (left<=right)
//	{
//		a2[left] = a1[left];
//		a2[right] = a1[right];
//		left++;
//		right--;
//		printf("%s\r", a2);	
//		Sleep(1000);
//	}
//	system("pause");
//	return 0;
//}

//����1��+2��+3��..+10!
//int mul(int i)
//{
//	int n = 1;
//	int sum = 0;
//	for (i = 1; i <= 10; i++)
//	{
//		n *= i;
//		sum += n;
//	}
//	return sum;
//}
//int main()
//{
//	int i = 0;
//	int sum=mul(i);
//	printf("%d\n", sum);
//	system("pause");
//	return 0;
//}