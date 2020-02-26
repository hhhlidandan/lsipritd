#include<iostream>
#include<stdio.h>
#include<stdlib.h>
using namespace std;

////会出错
//template<class T>
//T MAX(T left, T right)
//{
//	return left > right ? left : right;
//}
////对上面的特化、
//template<>
//char* MAX<char*>(char* left, char* right)
//{
//	if (strcmp(left, right) > 0)
//		return left;
//	return right;
//}
//函数形式
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

//类模板特化
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
//class Data<int, char>//全特化
//{
//public:
//	Data(){ cout << "Data<int,char>" << endl; }
//private:
//	int _d1;
//	char _d2;
//};
//template<class T1>
//class Data<T1, int>//部分特化  第一个参数任意类型都可以
//{
//public:
//	Data(){ cout << "Data<int,char>" << endl; }
//private:
//	T1 _d1;
//	char _d2;
//};
//int main()
//{
//	Data<int, double> d1;//调用基础版本
//	Data<int, char> d2;//调用全特化版本
//	Data<char, int> d3;//调用部分特化
//	system("pause");
//	return 0;
//}
//


//类型萃取
//代表内置类型/////////////////////////////////////////////////////
struct TrueType
{
	static bool Get(){return true;}
};
//代表自定义类型
struct FalseType
{
	static bool Get(){return false;}
};
//用户对类模板进行实例化，T可以是任意类型////////////////////////////
template<class T>//自定义类型特化
struct TypeTraits
{
	typedef FalseType IsPODType;//定义别名
};
/////////////////////////////////////////////////////////////////////
template<>//内置类型特化
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
//所有内置类型都特化一下...
//////拷贝函数/////////////////////////////////////////////////////
template<class T>
void Copy(T* dst, const T* src, size_t size)
{
	if (TypeTraits<T>::IsPODType::Get())//识别出类型
		memcpy(dst, src, sizeof(T)*size);
	else//如果不是上述类型
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
	Copy(a2, a1, 10);//内置类型就调用内置类型的版本  浅拷贝
	string s1[] = { "1111", "2222", "3333", "4444" };
	string s2[4];
	Copy(s2, s1, 4);//自定义就调用自定义类型   深拷贝
	system("pause");
	return 0;
}


