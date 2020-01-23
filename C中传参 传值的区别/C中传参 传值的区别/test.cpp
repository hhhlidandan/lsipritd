#include<iostream>
#include<cstdlib>
using namespace std;



//int TestAuto()
//{
//	return 10;
//}
void TestAuto()
{
	auto a = 1, b = 2;//同一类型，正确
	//auto c = 3.0, d = 4;//该行代码编译会失败，因为c和d的初始化表达式类型不同
}
int main()
{
	int x = 10;
	auto a = &x;
	auto* b = &x;
	auto& c = x;
	cout << typeid(a).name() << endl;//int*
	cout << typeid(b).name() << endl;//int*
	cout << typeid(c).name() << endl;//int
	//int a = 10;
	//auto b = a;
	//auto c = 'a';
	//auto d = TestAuto();
	//auto e;无法通过编译，使用auto定义变量时必须对其进行初始化
	//cout << typeid(b).name() << endl;//int
	//cout << typeid(c).name() << endl;//char
	//cout << typeid(d).name() << endl;//int
	system("pause");
	return 0;
}


//void swap(int a, int b)
//{
//	cout << "swap:" << " &a=" << &a << " &b=" << &b << endl;
//	int temp = a;
//	a = b;
//	b = temp;
//	
//}
//void swap(int *pa, int *pb)
//{
//	cout << "my_swap:" << " &a=" << pa << " &b=" << pb << endl;
//	int temp = *pa;
//	*pa = *pb;
//	*pb = temp;
//	
//}
////传地址
////优点：可以通过形参改变外部的实参，传参效率高
////缺点：不安全（指针要判空），可读性不高
////传值
////优点：可以起到对实参的保护
////缺点：不能通过形参改变外部实参，效率低
//int main()
//{
//	int a = 10;
//	int b = 20;
//	cout << "main:" << "&a=" << &a << " &b=" << &b << endl;
//	swap(a, b);
//	swap(&a, &b);
//	system("pause");
//	return 0;
//}