#include<stdio.h>
#include<windows.h>
#pragma warning(disable:4996)

////3.���ʵ�֣�
////һ��������ֻ��һ�����ֳ�����һ�Ρ������������ֶ��ǳɶԳ��ֵġ�
////���ҳ�������֡���ʹ��λ���㣩
//int FindNum(int *arr,int num)
//{
//	//����һ������Ԫ��һ��������������������ָ�룬ָ���һ���͵ڶ���
//	//�����������
//	int x = arr[0];//int x=0 (����)�������������0���ҵ������֣���ȷ��0���ĵ�
//	int i = 1;
//	for (; i < num; i++)
//	{
//		x ^= arr[i];
//	}
//	return x;
//
//}//10
//// 11
//int main()
//{
//	int arr[] = { 1, 2, 3, 4, 5, 1, 2, 3, 5 };
//	int num = sizeof(arr) / sizeof(arr[0]);
//	int ret = FindNum(arr,num);
//	printf("%d\n",ret);
//	system("pause");
//	return 0;
//}

////2.��ʹ�ã�a + b�� / 2���ַ�ʽ������������ƽ��ֵ��
//int agv(int a, int b)
//{
//	return a + ((b - a) >> 1);
//}//���ֹ��󣬿��ܻ����
//
////һ���ĸ��Ա�������һ����һ��һ��
//int agv1(int a, int b)
//{
//	return (a&b) + ((a^b) >> 1);
//}//ֻ������bitλ���������
//int main()
//{
//	
//	printf("%d\n", agv(10, 16));
//	printf("%d\n", agv1(10, 16));
//	system("pause");
//	return 0;
//}

//1.��д������
//unsigned int reverse_bit(unsigned int value);
//��������ķ���ֵvalue�Ķ�����λģʽ�����ҷ�ת���ֵ��
//
//�磺
//��32λ������25���ֵ�������и�λ��
//00000000000000000000000000011001
//��ת�󣺣�2550136832��
//10011000000000000000000000000000
//���������أ�
//2550136832

//unsigned int reverse_bit(unsigned int value)
//{
//	int i = 0;
//	int flag = 1;
//	int num = sizeof(value)* 8;
//	unsigned int result = 0;//����
//
//	for (; i < num; i++)
//	{
//		if (value & (flag<<i))//��value���ƣ�����1����
//		{
//			result |= (1 << (num - 1 - i));//��1����
//		}
//	}
//	return result;
//}
//
//int main()
//{
//	unsigned int ret = reverse_bit(25);
//	printf("%u\n", ret);
//	system("pause");
//	return 0;
//}