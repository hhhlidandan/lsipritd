#include<stdio.h>
#include<windows.h>
#pragma warning(disable:4996)

//1.
//写一个函数返回参数二进制中 1 的个数
//比如： 15 0000 1111 4 个 1
//程序原型：
//int count_one_bits(unsigned int value)
//{
//	// 返回 1的位数 
//}
//方法
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
//value &= (value - 1);//让原值和-1的值 &（value-1，快速定位到最近的1：
//可以让后面连续的0向前面借位，前面为0，后面为1，&变成0，消掉末尾的1
int count_one_bits(unsigned int value)
{
	//1500001111
	//方法1
	int count = 0;
	while (value)
	{
		value &= (value - 1);
		count++;
	}
	return count;

	//方法2
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

	//方法3
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

