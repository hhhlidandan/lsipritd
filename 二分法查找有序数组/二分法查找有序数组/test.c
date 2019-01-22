#define _CRT_SECURE_NO_WARNINGS
//2.二分法
//写代码可以在整型有序数组中查找想要的数字， 
//找到了返回下标，找不到返回 - 1.（折半查找）
#include<stdio.h>
#include<stdlib.h>

int binary_search(int arr[], int k, int left, int right, int sz)
{
	int mid = left + (right - left) / 2;//中间元素的下标
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
	int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };//假设有序数组里存放10个元素
	int k = 7;//查找
	int sz = sizeof (arr) / sizeof(arr[0]);//计算数组的长度
	int left = 0;//左边
	int right = sz - 1;//右边
	int ret = binary_search(arr,k,left,right,sz);//查找函数binary_search
	if (ret==-1)
	{
		printf("找不到\n");
		
	}
	else
	{
		printf("找到了");
		printf("%d\n",ret);
	}
	system("pause");
	return 0;
}