#include<stdio.h>
#include<windows.h>
#pragma warning(disable:4996)

void Swap(int *ap, int *bp)
{
	*ap = *ap^*bp;//��ָ������ã�ָ��������
	*bp = *ap^*bp;
	*ap = *ap^*bp;
}
int main()
{
	int a = 5;
	int b = 6;
	printf("����ǰ:%d %d\n", a, b);
	Swap(&a, &b);
	printf("������:%d %d\n", a, b);

	system("pause");
	return 0;
}


////MAX����ʵ��
//int MAX(int a, int b)
//{
//	return (a > b) ? (a) : (b);
//}
//
//int main()
//{
//	int a = 0;
//	int b = 0;
//	printf("������������:>\n");
//	scanf("%d %d", &a, &b);
//	int ret = MAX(a, b);//�Զ���һ��MAX����,����ret����������
//	printf("%d\n", ret);
//	system("pause");
//	return 0;
//}

