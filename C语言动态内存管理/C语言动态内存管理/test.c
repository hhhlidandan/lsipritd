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
	//����ɹ�
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
		ptr = q;//��һ��ָ�룬��������ʹ�Լ����������ʹ�ø����㣬
	}
	printf("after:%p\n", q);
	free(ptr);
	ptr = NULL;
	//free(ptr);
	//ptr = NULL;
	//int a = 10;//��ջ�Ͽ����ĸ��ֽڵĴ�С
	//char arr[10] = { 0 };//��ջ�Ͽ���10���ֽڵ������ռ�
	system("pause");
	return 0;
}
#endif







