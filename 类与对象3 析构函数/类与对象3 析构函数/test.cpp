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
class String//��װ�ַ���
{
public:
	//���캯��
	String(const char* str="")
	{
		cout << "String(const char* ):" << this << endl;
		_str = (char*)malloc(strlen(str) + 1);//���ٿռ�
		strcpy(_str, str);
	}
	//��������
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
class Person//д������Ŀ���ǣ����Ա������᲻��ϳ�Ĭ�ϵ���������
{
	//���ɣ�Ĭ�Ϲ��캯�����������е�_name��_gender����String���͵Ķ������

private:////����String��Ķ��󣬺�һ�����ͱ�����
	String _name;//
	String _gender;
	int _age;
//���ԣ���������String��Ķ��󣬾�Ҫ����String��Ĺ��캯��
};
void TestPerson()
{
	Person s;//��������   �����캯����û���ṩ��������������Ĭ�ϵĹ��캯��
}
//����������Ҫ���ٺ�����Person��û�У�
//���ɣ�Ĭ�������������������е�_name��_gender����String���͵Ķ�������
//���� s����Ҫ�Ѱ���String��Ķ������٣�����Ҫ��String�����������
//���϶��Ǳ������Զ���ɵ�
int main()
{
	TestPerson();
	system("pause");
	return 0;
}


