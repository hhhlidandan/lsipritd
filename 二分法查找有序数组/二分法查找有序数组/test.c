#define _CRT_SECURE_NO_WARNINGS
//2.���ַ�
//д����������������������в�����Ҫ�����֣� 
//�ҵ��˷����±꣬�Ҳ������� - 1.���۰���ң�
#include<stdio.h>
#include<stdlib.h>

int binary_search(int arr[], int k, int left, int right, int sz)
{
	int mid = left + (right - left) / 2;//�м�Ԫ�ص��±�
	if (k >= left&&k <= right)
	{
		while (left <= right)
		{
			if (arr[mid] < k)
			{
				left = mid + 1;
				mid = left + (right - left) / 2;
			}
			else if (arr[mid]>k)
			{
				right = mid - 1;
				mid = left + (right - left) / 2;
			}
			else
			{
				return mid;
			}
		}
	}
	else
	{
		return -1;
	}
}
int main()
{
	int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };//����������������10��Ԫ��
	int k = 7;//����
	int sz = sizeof (arr) / sizeof(arr[0]);//��������ĳ���
	int left = 0;//���
	int right = sz - 1;//�ұ�
	int ret = binary_search(arr,k,left,right,sz);//���Һ���binary_search
	if (ret==-1)
	{
		printf("�Ҳ���\n");
		
	}
	else
	{
		printf("�ҵ���");
		printf("%d\n",ret);
	}
	system("pause");
	return 0;
}