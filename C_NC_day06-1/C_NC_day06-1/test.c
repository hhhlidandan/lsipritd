#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
#pragma warning(disable:4996)

//����һ�����飬
//ʵ�ֺ���init������ʼ�����顢
//ʵ��empty����������顢
//ʵ��reverse���������������Ԫ�ص����á�
//Ҫ���Լ���ƺ����Ĳ���������ֵ��

void init(int arr[10],int sz)
{
	int i = 0;
	for (i = 0; i < sz; i++)
	{
		arr[i] = i;
		printf("%d ", arr[i]);
	}
	/*printf("��ʼ��֮��:\n");
	for (i = 0; i < 10; i++)
	{
		printf("%d ", arr[i]);
	}*/
	printf("\n");
	
}
void empty(int arr[10],int sz)
{
	int i = 0;
	for (; i < sz; i++)
	{
		arr[i] = 0;
		printf("%d ", arr[i]);
	}
	printf("\n");
}
void reverse(int arr[10],int sz)
{
	int left = 0;
	int i = 0;
	int right = sz - 1;

	printf("����֮ǰ:\n");
	for (i = 0; i < sz; i++)
	{
		arr[i] = i;
		printf("%d ", arr[i]);
	}
	printf("\n");
	while (left < right)
	{
		arr[left] = arr[left] ^ arr[right];
		arr[right] = arr[left] ^ arr[right];
		arr[left] = arr[left] ^ arr[right];
		left++;
		right--;
	}
	printf("����֮��\n");
	for (i=0; i < sz; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
}
int main()
{
	int arr[10] = {0};
	int sz = sizeof(arr) / sizeof(arr[0]);

	printf("init#\n");
	init(arr,sz);

	printf("empty#\n");
	empty(arr,sz);

	printf("reverse#\n");
	reverse(arr,sz);

	system("pause");
	return 0;
}

//1.ʵ��һ����������ӡ�˷��ھ����ھ���������������Լ�ָ����
//����9�����9 * 9�ھ�������12�����12 * 12�ĳ˷��ھ���
//void mul(int num)
//{
//	int i = 1;
//	int j = 1;
//	for (; i <= num; i++)
//	{
//		for (j=1; j <= i; j++)
//		{
//			printf("%d*%d=%2d ", i, j, i*j);
//		}
//		printf("\n");
//	}
//}
//int main()
//{
//	int num = 0;
//	printf("Please Enter a number#\n");
//	scanf("%d", &num);
//	mul(num);
//
//	system("pause");
//	return 0;
//}
