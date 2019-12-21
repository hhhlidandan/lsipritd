#include<stdio.h>
#include<windows.h>
#pragma warning(disable:4996)
struct a
{
	char c;//1
	int x;//4
};
struct b
{
	int x;//4
	double c;//8
};

int main()
{
	printf("struct a:%d\n", sizeof(struct a));//8
	printf("struct b:%d\n", sizeof(struct b));//16
	system("pause");
	return 0;
}