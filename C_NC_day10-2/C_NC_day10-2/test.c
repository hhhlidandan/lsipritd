
#include<stdio.h>
#include<windows.h>
#pragma warning(disable:4996)

//4.���ʵ�֣�
//����int��32λ������m��n�Ķ����Ʊ���У��ж��ٸ�λ(bit)��ͬ��
//�������� :
//1999 2299
//������� : 7
//10 -> 1010
//11 -> 1011  
//12 -> 1101
//^  -> 0111
//-1    0110
//&     0110

//void Compare(int m, int n)
//{
//	int count = 0;
//	int k = (m^n);
//	while (k)
//	{
//		k &= (k - 1);
//		count++;
//	}
//	printf("%d\n", count);
//}
//int main()
//{
//	Compare(11, 12);
//	system("pause");
//	return 0;
//}

//3. ���һ��������ÿһλ��
//�ݹ�
//void ShowNum(int n)
//{
//	if (n > 9)
//	{
//		ShowNum(n / 10);
//	}
//	printf("%d ", n % 10);
//}

//
//void ShowNum(int n)
//{
//	while (n)
//	{
//		printf("%d ", n % 10);
//		n /= 10;
//	}
//	
//}

//15-> 1111
//1010
//1001 >> 0001 0010
//0001
//void ShowNum(unsigned int n)
//{
//
//	int num = sizeof(n)* 8;
//}
//int main()
//{
//
//	ShowNum(1249);
//	printf("\n");
//	system("pause");
//	return 0;
//}

//2.��ȡһ�������������������е�ż��λ������λ��
//�ֱ�������������С�
//void ShowNum(unsigned int n)
//{
//	int i = 0;
//	int num = sizeof(n)* 8;
//	printf("����:>");
//	for (; i < num; i+=2)
//	{
//		if (n & (1 << i))
//		{
//			printf("1 ");	
//		}
//		else
//		{
//			printf("0 ");
//		}	
//	}
//	printf("\n");
//
//	printf("ż��:>");
//	for (i = 1; i < num; i += 2)
//	{
//		if (n & (1 << i))
//		{
//			printf("1 ");
//		}
//		else
//		{
//			printf("0 ");
//		}	
//	}
//	printf("\n");
//}
//
//int main()
//{
//	//1111
//	//����
//	ShowNum(15);
//	system("pause");
//	return 0;
//}