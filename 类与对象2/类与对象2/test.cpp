#include "test.h"

int main()
{
	//cout << sizeof(A) << endl;//4  可以看出，类中有成员变量和方法时，大小跟成员方法无关
	//cout << sizeof(B) << endl;//1  只有成员方法，没有成员变量
	//cout << sizeof(C) << endl;//1  空类的大小是1，
	//如果占0个字节，创建出的对象会在同一个位置，有矛盾，所以，占了一个字节可以区分类创建出的对象
	cout << sizeof(A) << endl;//16
	cout << offsetof(A, _a) << endl;//  0
	cout << offsetof(A, _b) << endl;//8
	system("pause");
	return 0;
}