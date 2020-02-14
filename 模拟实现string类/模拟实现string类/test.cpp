#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#pragma warning(disable:4996)
using namespace std;
#if 0
namespace bit
{
	class string
	{
	public:
		string(const char* str = "")
		{
			if (str == nullptr)
				str = "";
			_str = new char[strlen(str) + 1];
			strcpy(_str, str);
			_pCount = new int(1);
			//_pCount++;
		}
		string(const string& s) :_str(s._str), _pCount(s._pCount)
		{
			++(*_pCount);
		}
		//�����������1 �ͷ���Դs4
		string& operator=(const string& s)
		{
			if (this != &s)
			{
				release();
				_str = s._str;//���ÿռ�
				_pCount = s._pCount;//���ü���
				++(*_pCount);
			}
			return *this;
		}
		char& operator[](size_t index)
		{
			if (*_pCount > 1)
			{
				string strTemp(_str);
				Swap(strTemp);
			}
			return _str[index];
		}
		const char& operator[](size_t index) const
		{
			return _str[index];
		}
		~string()
		{
			release();
		}
	private:
		void Swap(string& s)
		{
			swap(_str, s._str);
			swap(_pCount, s._pCount);
		}
		void release()
		{
			if (_str && 0 == --(*_pCount))
			{
				delete[] _str;//ָ�������ط������԰���Դ�ͷ�
				delete _pCount;
				_str = nullptr;
				_pCount = nullptr;
			}
		}
	private:
		char* _str;
		int* _pCount;//����ָ��ķ�ʽ����
	};	
}
void TestString()
{
	bit::string s1("hello");
	bit::string s2(s1);
	bit::string s3("world");
	bit::string s4(s3);
	s1 = s3; //s123����ͬһ�ݿռ�   s4
	s4 = s2;
}
int main()
{
	TestString();
	system("pause");
	return 0;
}
#endif
#if 0
namespace bit
{
	//�ִ������
	class string
	{
	public:
		string(const char* str = "")
		{
			if (str == nullptr)
				str = "";
			_str = new char[strlen(str) + 1];
			strcpy(_str, str);
		}
		/*string(const string& s) :_str(new char[strlen(s._str)+1])
		{
			strcpy(_str, s._str);
		}*/
		//�������������
		string(const string& s) :_str(nullptr)//�������ʼ��Ϊ�գ����ʼ�����������ֵ��������������ģ����ͷ�ʱ�ͻ����
		{
			string strTemp(s._str);//��s����ַ���������ʱ����
			swap(_str, strTemp._str);//���ݽ���
			//��ʱ�������٣���ʱ��ʱ�����֮ǰ�����Ѿ���������
		}
		string& operator=(string s)
		{
			swap(_str, s._str);
			return *this;
		}

		//string& operator=(const string& s)
		//{
		//����1
		//	if (this != &s)
		//	{
		//		//�Ϳ�������һ��
		//		string strTemp(s);
		//		swap(_str, strTemp._str);
		//	}
		////ֱ������Ҳ��
			//string strTemp(s);
			//swap(_str, strTemp._str);
			//return *this;
		//}
		
		~string()
		{
			if (_str)
			{
				delete[] _str;
				_str = nullptr;
			}
		}
	private:
		char* _str;
	};
}
void TestString()
{
	bit::string s1("hello");
	bit::string s2(nullptr);
	bit::string s3(s1);
}
int main()
{
	TestString();
	system("pause");
	return 0;
}
#endif
#if 1
//��ͳ���  ���
namespace bit
{
	class string
	{
	public:
		string(const char* str = " ")
		{
			if (str == nullptr)
				str = "";
			_size = strlen(str);
			_capacity = _size;
			_str = new char[_capacity + 1];//���ٿռ�
			strcpy(_str, str);
		}
		string(size_t n, char c)//����n���ַ�c
			:_str(new char[n + 1])
			, _capacity(n)
			, _size(n)
		{
			memset(_str, c, _size);//����_size����С���ַ�c

		}
		//���
		string(const string& s) :_str(new char[strlen(s._str) + 1])
		{
			strcpy(_str, s._str);
		}
		//���
		string& operator=(const string& s)
		{
			if (this != &s)
			{
				char* ptr = new char[strlen(s._str) + 1];
				strcpy(ptr, s._str);
				delete[] _str;
				_str = ptr;
			}
			return *this;
		}
		~string()
		{
			if (_str)
			{
				delete[] _str;
				_str = nullptr;
			}
		}
		/////////////////////////////////////////////////////
		void append(size_t n, char c)//׷��n��ch
		{

		}
		//����������ЧԪ�ظ����ı䵽newSize,������ַ����ַ�c���
		void resize(size_t newSize, char ch = char())
		{

		}

	private:
		char* _str;
		size_t _capacity;
		size_t _size;
	};
}
int main()
{
	system("pause");
	return 0;
}
#endif

#if 0
namespace bit
{
	//����
	class string
	{
	public:
		//ͨ���մ�
		//ͨ��C��ʽ�ַ������� const char* s 
		string(const char* str = " ")//���캯��
		{
			//if (nullptr == str)
			//{
			//	_str = new char[1];
			//	*_str = '\0';
			//}
			//else
			//{
			//	//���ٿռ�
			//	_str = new char[strlen(str) + 1];
			//	strcpy(_str, str);
			//}
			if (nullptr == str)
				str = "";
			_str = new char[strlen(str) + 1];
			strcpy(_str, str);
		}
		//ǳ���� 
		string(const string& s):_str(s._str)//ʹ��ͬһ���ڴ�ռ�
		{}
		//ǳ����  ������Դ����ͷš��ڴ�й©
		string& operator=(const string& s)
		{
			_str = s._str;
			return *this;
		}
		//�������������Ĭ�����ɵ���ǳ������ʽ(����������������Դ��ǳ���������)
		~string()
		{
			if (_str)
			{
				delete[] _str;
				_str = nullptr;
			}
		}
	private:
		char* _str;
	};
}
void Teststring()
{
	bit::string s1("hello");
	bit::string s2(nullptr);
	bit::string s3(s1);
	
}
int main()
{
	Teststring();
	system("pause");
	return 0;
}
#endif


