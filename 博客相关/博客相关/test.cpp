#define _CRT _SECURE_NO_WARNINGS

//
//namespace N1
//{
//	int a;//�������
//	int Add(int left, int right)//���庯��
//	{
//		return left + right;
//	}
//	namespace N2 //�������ռ�N1�Ƕ���������ռ�N2
//	{
//		int b;
//		int Sub(int left, int right)
//		{
//			return left - right;
//		}
//	}
//}
//
//namespace N1 // ��ͬ���Ƶ������ռ�N1������������ϳ�ͬһ�������ռ���
//{
//	int Mul(int left, int right)
//	{
//		return left*right;
//	}
//}
//namespace N
//{
//	int b;
//}
//using N::b;
//
//int main()
//{
//	printf("%d\n", b);
//	return 0;
//}
#include<iostream>
using namespace std;
//int main()
//{
//	int a;
//	double b;
//	char c;
//
//	cin >> a;
//	cin >> b >> c;
//
//	cout << a << endl;
//	cout << b <<" " << c << endl;
//	return 0;
//}
//��ȱʡ
//void TestFunc(int a , int b = 20, int c = 30)//����ʱ��ʹ��ָ���Ĳ��� 
//{
//	cout << "a= " << a << endl;
//	cout << "b= " << b << endl;
//	cout << "c= " << c << endl;
//}
//int main()
//{
//
//	//���ٴ�һ������ 
	//TestFunc(1);// a=1,b=20,c=30
	//TestFunc(1, 2);//a=10,b=2,c=30
	//TestFunc(1, 2, 3);//a=1,b=2,c=3
	//system("pause");
	//return 0;
//}
//����
//int Add(int left, int right)
//{
//	return left + right;
//}
//double Add(double left, double right)
//{
//	return left + right;
//}
////��������
//short Add(short left, short right)
//{
//	return left + right;
//}
//short Add(int left, int right)
//{
//	return left + right;
//}
//����
//void TestRef()
//{
//	int a = 10;//���ö���ʱ�����ʼ��
//	int& b = a;
//	int& c = b;//һ�����������ж������
//	
//	printf("%d\n", a);//10
//	printf("%d\n", b);//10
//	printf("%d\n", c);//10

//	int d = 20;
//	c = d;//��d����c
//	printf("%d\n", a);//20
//	printf("%d\n", b);//20
//	printf("%d\n", c);//20
//	return;
//}
//������
//void ConstTestRef()
//{
//	const int a = 10;
//	//int& b = a;
//	const int& b = a;
//}
//void ConstTestRef()
//{
//	int a = 10;
//	const int& b = a;
//}
//int main()
//{
//	//TestRef();
//	system("pause");
//	return 0;
//}
//ʹ�ó���
//1.������
//void Swap(int& left, int& right)// left,right�ֱ�Ϊa,b �ı���
//{
//	int temp = left;
//	left = right;
//	right = temp;
//}
//int main()
//{
//	int a = 1;
//	int b = 2;
//	Swap(a, b);
//	return 0;
//}
//C�����е�Swap����
//#include<stdio.h>
//void Swap(int* left, int* right)
//{
//	int temp = *left;
//	*left = *right;
//	*right = temp;
//}
//int main()
//{
//	int a = 1;
//	int b = 2;
//	Swap(&a, &b);
//	return 0;
//}
//2.������ֵ
//int TestRefReturn(int& a)
//{
//	a += 10;
//	return a;
//}
//int main()
//{
//	int x = 10;
//	int y = TestRefReturn(x);
//	return 0;
//}
//int main() 
//{
//	int a = 10; 
//	int& ra = a;
//
//	cout << "&a = " << &a << endl;
//	cout << "&ra = " << &ra << endl;
//	system("pause");
//	return 0;
//}
int main()
{
	int a = 10;
	int& ra = a;

	ra = 20;
	int* pa = &a;
	*pa = 20;
	system("pause");
	return 0;
}


//�������1
//class Student//����
//{
//	void func()//Ĭ�ϵ�Ϊ˽�е�
//	{
//
//	}
//public://���У������������
//	void ShowInfo()////������������޸�,�ṩ��ShowInfo����
//	{
//		cout << _name << " " << endl;
//		cout << _age << " " << endl;
//		cout << _studentid << " " << endl;
//	}
//	
//private://�����ⲻ�뱻���ʣ�˽��
//	char* _name;
//	int _age;
//	int _studentid;
//};
//int main()
//{
//	Student s;//ʵ����Ϊ����
//	s.ShowInfo();//ֻ�ܷ����������е�
//}
