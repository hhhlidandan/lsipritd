#include<iostream>
#include<stdio.h>
#include<stdlib.h>
using namespace std;

#if 0
int main()
{
	//申请单个元素空间
	//new+类型
	int* p1 = new int;//申请一个整型类型的空间
	//不用类型转化、不用求字节数
	//
	int *p2 = new int(10);//申请并初始化
	delete p1;//释放
	delete p2;

	//申请连续空间
	//int array[10];//int是数组中所放元素的类型，
	//数组类型：10个整型空间
	int* p3 = new int[10];//申请连续空间
	int* p4 = new int[4]{1, 2, 3, 4};//申请并初始化
	delete[] p3;//释放
	delete[] p4;
	//为什么new申请出的空间不需要类型转化
	//malloc参数是字节数，不知道是什么类型
	//new后跟的是类型，本来就有类型，不需要强转
	system("pause");
	return 0;
}
#endif

#if 1
class Test
{
public:
	Test() :_a(0)
	{
		cout << "Test():" << this << endl;
	}
	~Test()
	{
		cout << "`Test():" << this << endl;
	}
private:
	int _a;
};
void TestNewDelete()
{
	Test *p = (Test*)malloc(sizeof(Test));//申请一段大小与Test相同的空间
	new(p)Test;//调用构造函数对空间初始化  
	//构造函数有参时，要传参

	//new一个Test的对象，->创建对象  在堆上//调用构造函数
	Test* pt1 = new Test;//申请一个Test类型的对象
	Test* pt2 = new Test[10];//申请10个Test类型的对象
	delete pt1;//释放  自动调析构函数
	delete[] pt2;

	//不调构造、析构函数 所以创建的不是对象
	Test* pt11 = (Test*)malloc(sizeof(Test));
	if (pt11 == nullptr)
	{
		;
	}
	free(pt11);
}
int main()
{

	system("pause");
	return 0;
}
#endif

//int globalVar = 1; 
//static int staticGlobalVar = 1; 
//
//void Test() 
//{
//	static int staticVar = 1;
//	int localVar = 1;        
//	int num1[10] = { 1, 2, 3, 4 };    
//	char char2[] = "abcd";    
//	char* pChar3 = "abcd";   
//	int* ptr1 = (int*)malloc(sizeof (int)* 4);  
//	int* ptr2 = (int*)calloc(4, sizeof(int)); 
//	int* ptr3 = (int*)realloc(ptr2, sizeof(int)* 4);   
//	free(ptr1);   
//	free(ptr3); 
//}
