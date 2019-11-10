#include<stdio.h>
#include<windows.h>
#pragma warning(disable:4996)

////3.编程实现：
////一组数据中只有一个数字出现了一次。其他所有数字都是成对出现的。
////请找出这个数字。（使用位运算）
//int FindNum(int *arr,int num)
//{
//	//方法一：排序，元素一定是奇数个，定义两个指针，指向第一个和第二个
//	//方法二：异或
//	int x = arr[0];//int x=0 (不可)如果数组里面有0，且单独出现，则不确定0是哪的
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

////2.不使用（a + b） / 2这种方式，求两个数的平均值。
//int agv(int a, int b)
//{
//	return a + ((b - a) >> 1);
//}//数字过大，可能会溢出
//
////一样的各自保留，不一样的一人一半
//int agv1(int a, int b)
//{
//	return (a&b) + ((a^b) >> 1);
//}//只检测最低bit位，不会溢出
//int main()
//{
//	
//	printf("%d\n", agv(10, 16));
//	printf("%d\n", agv1(10, 16));
//	system("pause");
//	return 0;
//}

//1.编写函数：
//unsigned int reverse_bit(unsigned int value);
//这个函数的返回值value的二进制位模式从左到右翻转后的值。
//
//如：
//在32位机器上25这个值包含下列各位：
//00000000000000000000000000011001
//翻转后：（2550136832）
//10011000000000000000000000000000
//程序结果返回：
//2550136832

//unsigned int reverse_bit(unsigned int value)
//{
//	int i = 0;
//	int flag = 1;
//	int num = sizeof(value)* 8;
//	unsigned int result = 0;//存结果
//
//	for (; i < num; i++)
//	{
//		if (value & (flag<<i))//让value右移，或让1左移
//		{
//			result |= (1 << (num - 1 - i));//让1左移
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