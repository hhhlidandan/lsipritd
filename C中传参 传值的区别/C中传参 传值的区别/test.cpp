#include<iostream>
#include<cstdlib>
using namespace std;



//int TestAuto()
//{
//	return 10;
//}
void TestAuto()
{
	auto a = 1, b = 2;//ͬһ���ͣ���ȷ
	//auto c = 3.0, d = 4;//���д�������ʧ�ܣ���Ϊc��d�ĳ�ʼ�����ʽ���Ͳ�ͬ
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
	//auto e;�޷�ͨ�����룬ʹ��auto�������ʱ���������г�ʼ��
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
////����ַ
////�ŵ㣺����ͨ���βθı��ⲿ��ʵ�Σ�����Ч�ʸ�
////ȱ�㣺����ȫ��ָ��Ҫ�пգ����ɶ��Բ���
////��ֵ
////�ŵ㣺�����𵽶�ʵ�εı���
////ȱ�㣺����ͨ���βθı��ⲿʵ�Σ�Ч�ʵ�
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