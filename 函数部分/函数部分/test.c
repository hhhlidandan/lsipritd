#include<stdio.h>
#include<windows.h>
#pragma warning(disable:4996)

void Swap(int *ap, int *bp)
{
	*ap = *ap^*bp;//对指针解引用，指向其内容
	*bp = *ap^*bp;
	*ap = *ap^*bp;
}
int main()
{
	int a = 5;
	int b = 6;
	printf("交换前:%d %d\n", a, b);
	Swap(&a, &b);
	printf("交换后:%d %d\n", a, b);

	system("pause");
	return 0;
}


////MAX函数实现
//int MAX(int a, int b)
//{
//	return (a > b) ? (a) : (b);
//}
//
//int main()
//{
//	int a = 0;
//	int b = 0;
//	printf("请输入两个数:>\n");
//	scanf("%d %d", &a, &b);
//	int ret = MAX(a, b);//自定义一个MAX函数,定义ret变量来接收
//	printf("%d\n", ret);
//	system("pause");
//	return 0;
//}

