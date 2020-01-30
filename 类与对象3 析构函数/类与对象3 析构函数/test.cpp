#include<cstdio>
#include<cstdlib>
#include<cassert>
#include<iostream>

using namespace std;
#if 0
class SeqList
{
public:
	SeqList(int capacity = 10)
	{
		cout << "SeqList(int):" << this << endl;
		_array = (int*)malloc(capacity*sizeof(int));
		assert(_array);
		_capacity = capacity;
		_size = 0;
	}
	~SeqList()
	{
		if (_array)
		{
			free(_array);
			_array = nullptr;
			_capacity = 0;
			_size = 0;
		}
		cout << "~SeqList():" << this << endl;
	}
private:
	int* _array;
	int _capacity;
	int _size;
};
void TestSeqList()
{
	SeqList s;
}
int main()
{
	TestSeqList();
	system("pause");
	return 0;
}
#endif
class String//封装字符串
{
public:
	//构造函数
	String(const char* str="")
	{
		cout << "String(const char* ):" << this << endl;
		_str = (char*)malloc(strlen(str) + 1);//开辟空间
		strcpy(_str, str);
	}
	//析构函数
	~String()
	{
		if (_str == nullptr)
		{
			_str = "";
		}
		free(_str);
		_str == nullptr;
		cout << "~String():" << this << endl;
	}
private:
	char* _str;
};
class Person//写这个类的目的是，测试编译器会不会合成默认的析构函数
{
	//生成：默认构造函数，将对象中的_name和_gender两个String类型的对象构造好

private:////两个String类的对象，和一个整型变量，
	String _name;//
	String _gender;
	int _age;
//所以，创建两个String类的对象，就要调用String类的构造函数
};
void TestPerson()
{
	Person s;//创建对象   调构造函数，没有提供，编译器调生成默认的构造函数
}
//出了作用域，要销毁函数，Person里没有，
//生成：默认析构函数，将对象中的_name和_gender两个String类型的对象销毁
//销毁 s对象，要把包含String类的对象销毁，所以要调String类的析构函数
//以上都是编译器自动完成的
int main()
{
	TestPerson();
	system("pause");
	return 0;
}


