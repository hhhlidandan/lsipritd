//whileѭ��
#include<stdio.h>

int main()
{
	int i = 0;
	while (i < 10)// i<10��ѭ������
	{
		printf("%d ", i);
		i++;
	}
	return 0;
}

//forѭ��
#include<stdio.h>
int main()
{
	int i = 0;
	// i=0;��ʼ����i<10;�жϲ��֣� i++;��������
	for (i = 0; i < 10; i++)
	{
		printf("%d ", i);
	}
	return 0;
}

//do..whileѭ��

#include<stdio.h>
int main()
{
	int i = 0;
	do
	{//ѭ�����
		printf("%d ", i);
		i++;
	} while (i < 10);//���ʽ
	return 0;
}