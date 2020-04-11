#include<stdio.h>
#include<stdlib.h>
#pragma warning(disable:4996)
int main()
{
	int n = 0, i = 0, j = 0,count = 0;
	int arr[4] = {1,2,0,4};
	n = sizeof(arr) / sizeof(arr[0]);
	for (i = 0; i < n; i++)
		count += arr[i];
	printf("平均数是%d:", count / n);
	//排序
	for (i = 0; i < n - 1; i++)
	{
		for (j = 1; j <= n - 1 - i; j++)
		{
			if (arr[j - 1]>arr[j])
			{
				int tmp = arr[j - 1];
				arr[j - 1] = arr[j];
				arr[j] = tmp;
			}
		}
	}
	if (n % 2 == 0)//偶数
		printf("中位数是%d\n", (arr[n / 2] + arr[n / 2 - 1]) / 2);
	else//奇数
		printf("中位数是%d\n", arr[n / 2]);
	system("pause");
	return 0;
}