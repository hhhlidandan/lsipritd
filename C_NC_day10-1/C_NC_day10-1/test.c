#include<stdio.h>
#include<windows.h>
#pragma warning(disable:4996)

//1.
//дһ���������ز����������� 1 �ĸ���
//���磺 15 0000 1111 4 �� 1
//����ԭ�ͣ�
//int count_one_bits(unsigned int value)
//{
//	// ���� 1��λ�� 
//}
//����
//1.  %2 ?1 ->/=2...0
//2.  &
//3.
//1100
//1011 &
//------
//1000
//0100 &
//------
//0000
//value &= (value - 1);//��ԭֵ��-1��ֵ &��value-1�����ٶ�λ�������1��
//�����ú���������0��ǰ���λ��ǰ��Ϊ0������Ϊ1��&���0������ĩβ��1
int count_one_bits(unsigned int value)
{
	//1500001111
	//����1
	int count = 0;
	while (value)
	{
		value &= (value - 1);
		count++;
	}
	return count;

	//����2
	//int count = 0;
	//while (value)
	//{
	//	if (value & 1)
	//	{
	//		count++;
	//		value = value >> 1;
	//	}
	//}
	//return count;

	//����3
	/*int count = 0;
	while (value)
	{
		if (value%2 == 1)
		{
			count++;
		}
		value /= 2;
	}
	return count;*/
}
int main()
{
	int value=15;
	int count = count_one_bits(value);
	printf("%d\n", count);
	system("pause");
	return 0;
}

