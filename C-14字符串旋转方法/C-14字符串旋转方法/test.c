#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<windows.h>
#pragma warning(disable:4996)

//����һ��
void LeftMove(char *str, int len,int num)
{
	assert(str);
	assert(len>0);
	assert(num);
	num %= len;//��Ч����
	while (num--)//��������
	{
		//����һ��
		int i = 0;
		char temp = *str;//�ŵ�һ���ַ�
		for (; i < len - 1; i++)
		{
			str[i] = str[i + 1];//ָ������±�����ʽ����
		}
		str[i] = temp;//ע���ٽ�
	}	
}
//��������
void reserve(char* start, char* end)
{
	while (start<end)
	{
		*start ^= *end;
		*end ^= *start;
		*start ^= *end;
		start++;
		end--;
	}
}
void LeftMove1(char *str, int len, int num)
{
	assert(str);
	assert(len>0);
	assert(num);
	num %= len;//��Ч����

	char *mid = str + num - 1;

	reserve(str, mid);//����ǰ��
	reserve(mid + 1, str + len - 1);//���ú���
	reserve(str, str + len - 1);//��������
}
void LeftMove2(char* str, int len, int num)
{
	assert(str);
	assert(len > 0);
	assert(num);
	num %= len;

	char *buf = (char*)malloc(2 * len + 1);//����������ַ����Ŀռ�
	strcpy(buf, str);//��str����buf��
	strcat(buf, str);//��strƴ�ӵ�buf��õ�˫����
	//����
	strncpy(str, buf + num, len);//
	free(buf);// (�ڶ��Ͽ��ٵĿռ䣬�Լ��ͷ�)
	buf = NULL;
}
int main()
{
	int num = 0;
	char str[] = "ABCD";//Ҫ���ַ������������ﲻ����char *str=...
	int len = strlen(str);//��ЧԪ�ظ�����������'\0'
	printf("before:%s\n", str);
	printf("��������Ҫ���������ַ�\n");
	scanf("%d", &num);
	LeftMove(str, len, num);
	LeftMove1(str, len, num);
	LeftMove2(str, len, num);
	printf("after:%s\n", str);
	system("pause");
	return 0;
}