#include<stdio.h>
#include<stdlib.h>
#pragma warning(disable:4996)

#if 0
int main()
{
	int n = 0;
	printf("Please Enter:\n");
	scanf("%d", &n);
	char *ptr = (char*)malloc(n*sizeof(char));
	//char *ptr = (char*)calloc(n,sizeof(char));
	if (NULL == ptr)//
	{
		perror("malloc");
		return 1;
	}
	//申请成功
	int i = 0;
	for (; i < n; i++)
	{
		ptr[i] = i;
	}
	printf("before:%p\n", ptr);
	char*q = realloc(ptr, n);
	if (q == NULL)
	{
		printf("realloc error!\n");
		free(ptr);//
		ptr = NULL;
		return 2;
	}
	else
	{
		ptr = q;//用一个指针，这样可以使自己看更清楚，使用更方便，
	}
	printf("after:%p\n", q);
	free(ptr);
	ptr = NULL;
	//free(ptr);
	//ptr = NULL;
	//int a = 10;//在栈上开辟四个字节的大小
	//char arr[10] = { 0 };//在栈上开辟10个字节的连续空间
	system("pause");
	return 0;
}
#endif







