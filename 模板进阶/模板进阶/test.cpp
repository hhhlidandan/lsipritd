#include<iostream>
#include<stdio.h>
#include<stdlib.h>
using namespace std;

////�����
//template<class T>
//T MAX(T left, T right)
//{
//	return left > right ? left : right;
//}
////��������ػ���
//template<>
//char* MAX<char*>(char* left, char* right)
//{
//	if (strcmp(left, right) > 0)
//		return left;
//	return right;
//}
//������ʽ
//char* MAX(char* left, char* right)
//{
//	if (strcmp(left, right) > 0)
//		return left;
//	return right;
//}
//int main()
//{
//	char* p1 = "world";
//	char* p2 = "hello";
//	cout << MAX(p1, p2) << endl;
//	system("pause");
//	return 0;
//}

//��ģ���ػ�
//template<class T1,class T2>
//class Data
//{
//public:
//	Data(){cout << "Data<T1,T2>" << endl;}
//private:
//	T1 _d1;
//	T2 _d2;
//};
//template<>
//class Data<int, char>//ȫ�ػ�
//{
//public:
//	Data(){ cout << "Data<int,char>" << endl; }
//private:
//	int _d1;
//	char _d2;
//};
//template<class T1>
//class Data<T1, int>//�����ػ�  ��һ�������������Ͷ�����
//{
//public:
//	Data(){ cout << "Data<int,char>" << endl; }
//private:
//	T1 _d1;
//	char _d2;
//};
//int main()
//{
//	Data<int, double> d1;//���û����汾
//	Data<int, char> d2;//����ȫ�ػ��汾
//	Data<char, int> d3;//���ò����ػ�
//	system("pause");
//	return 0;
//}
//


//������ȡ
//������������/////////////////////////////////////////////////////
struct TrueType
{
	static bool Get(){return true;}
};
//�����Զ�������
struct FalseType
{
	static bool Get(){return false;}
};
//�û�����ģ�����ʵ������T��������������////////////////////////////
template<class T>//�Զ��������ػ�
struct TypeTraits
{
	typedef FalseType IsPODType;//�������
};
/////////////////////////////////////////////////////////////////////
template<>//���������ػ�
struct TypeTraits<char>
{
	typedef TrueType TsPODType;
};
template<>
struct TypeTraits<short>
{
	typedef TrueType IsPODType;
};
template<>
struct TypeTraits<int>
{
	typedef TrueType IsPODType;
};
template<>
struct TypeTraits<long>
{
	typedef TrueType IsPODType;
};
//�����������Ͷ��ػ�һ��...
//////��������/////////////////////////////////////////////////////
template<class T>
void Copy(T* dst, const T* src, size_t size)
{
	if (TypeTraits<T>::IsPODType::Get())//ʶ�������
		memcpy(dst, src, sizeof(T)*size);
	else//���������������
	{
		for (size_t i = 0; i < size; ++i)
			dst[i] = src[i];
	}
}
/////test///////////////////////////////////////////////////////
int main()
{
	int a1[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 0 };
	int a2[10];
	Copy(a2, a1, 10);//�������;͵����������͵İ汾  ǳ����
	string s1[] = { "1111", "2222", "3333", "4444" };
	string s2[4];
	Copy(s2, s1, 4);//�Զ���͵����Զ�������   ���
	system("pause");
	return 0;
}


