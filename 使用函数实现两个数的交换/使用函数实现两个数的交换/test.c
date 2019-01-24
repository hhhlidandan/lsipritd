#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
void swap(int *a, int *b)
{
	*a = *a^*b;
	*b = *a^*b;
	*a = *a^*b;
}
int main()
{
	int i = 0, j = 0;
	scanf("%d %d", &i, &j);
	printf("a=%d b=%d\n", i, j);
	swap(&i, &j);
	printf("a=%d b=%d\n", i, j);
	system("pause");
	return 0;
}