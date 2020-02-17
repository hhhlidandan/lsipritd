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
#include<assert.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ostream>
using namespace std;
namespace bit
{
	class string
	{
	public:
		typedef char* iterator;//begin end
	public:
		string(const char* str = " ")//����
		{
			if (str == nullptr)
				str = "";
			_size = strlen(str);
			_capacity = _size;
			_str = new char[_capacity + 1];//���ٿռ�
			strcpy(_str, str);
		}
		string(size_t n, char c)//����//����n���ַ�c
			:_str(new char[n + 1])
			, _capacity(n)
			, _size(n)
		{
			memset(_str, c, _size);//����_size����С���ַ�c

		}
		string(char* pstr, size_t n)
		{
			size_t length = strlen(pstr);
			_size = length > n ? n : length;
			_capacity = _size;
			_str = new char[_capacity + 1];
			for (size_t i = 0; i < _size; i++)
				_str[i] = pstr[i];
			_str[_size] = '\0';
		}
		//��� ��������
		string(const string& s) :_str(new char[strlen(s._str) + 1])
		{
			strcpy(_str, s._str);
		}
		//���  ��ֵ���������
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
		~string()//����
		{
			if (_str)
			{
				delete[] _str;
				_str = nullptr;
			}
		}
///////////////////Iterator
		iterator Begin()
		{
			return _str;
		}
		iterator End()
		{
			return _str + _size;
		}
/////////////////////////////////////////////////////
/////capacity
		size_t size() const
		{
			return _size;
		}
		size_t Length() const
		{
			return _size;
		}
		size_t Capacity() const
		{
			return _capacity;
		}
		bool Empty() const
		{
			return 0 == _size;
		}
		void Clear()
		{
			_size = 0;
			_str[0] = '\0';
		}
		//����������ЧԪ�ظ����ı䵽newSize,������ַ����ַ�ch���
		void Resize(size_t newSize, char ch = char())
		{
			if (newSize>_size)
			{
				if (newSize > _capacity)
				{
					Reserve(newSize);
				}
				memset(_str+_size, ch, newSize - _size);
			}
			_size = newSize;
			_str[newSize] = '\0';
		}
		void Reserve(size_t newCapacity)
		{
			size_t oldSize = _capacity;
			if (oldSize < newCapacity)//�ռ�С�������¿ռ�
			{
				char* pStr = new char[newCapacity + 1];
				strcpy(pStr, _str);
				//�ͷžɿռ䣬ʹ���¿ռ�
				delete[] _str;
				_str = pStr;
				_capacity = newCapacity;
			}
		}
//////modify///////////////////////////////////////////////
		string& operator+=(const string& s)
		{
			size_t leftByte = _capacity - _size;//ʣ��ռ�
			size_t totalByte = s.size();//һ����
			if (totalByte > leftByte)
			{
				Reserve(totalByte + _size);
			}
			strcpy(_str + _size, s._str);
			_size += totalByte;
		}
		void PushBack(char c)
		{
			if (_size == _capacity)
				Reserve(2 * _capacity);
			_str[_size++] = c;
			_str[_size] = '\0';

		}
		void Append(size_t n, char c)//׷��n��c
		{
			for (size_t i = 0; i < n; i++)
			{
				PushBack(c);
			}
		}
		void Swap(string& s)
		{
			std::swap(_str, s._str);
			std::swap(_size, s._size);
			std::swap(_capacity, s._capacity);
		}
		const char* c_str() const
		{
			return _str;
		}
///////////////////access/////////
		char& operator[](size_t index)
		{
			assert(index < _size);
			return _str[index];
		}
		const char& operator[](size_t index) const
		{
			assert(index < _size);
			return _str[index];
		}
		size_t Find(char ch, size_t pos = 0)
		{
			for (size_t i = pos; i < _size; i++)
			{
				if (_str[i] == ch)
					return i;
			}
			return npos;
		}
		size_t Rfind(char ch, size_t pos=npos) 
		{
			if (pos == npos)
				pos = _size - 1;
			for (int i = pos; i > 0; i--)//������size_t �����޷������ͣ�����ѭ��
			{
				if (_str[i]==ch)
					return i;
			}
		}
		string StrSub(size_t pos, size_t n = npos) const//npos˵��һֱ��������β
		{
			//��posλ�ÿ�ʼ������n���ַ���
			return string(_str + pos, n);
		}
	private:
		char* _str;
		size_t _capacity;
		size_t _size;
		static const size_t npos;//npos��ĩβ��ʼ��
	};
}
const size_t string::npos = -1;//Ĭ��npos=-1  (��ĩβ���в���)

void TestString()
{
	bit::string s1("hello");
	bit::string s2(10, 'a');
	bit::string s3("world", 3);
	bit::string s4(s3);
	bit::string s5;


	cout << s1.size() << endl;
	cout << s1.Capacity() << endl;
	auto it = s1.Begin();
	while (it != s1.End())
	{
		cout << *it << " ";
		it++;
	}
	cout << endl;
	s1 += s3;
	s1.PushBack(' ');
	s1.PushBack('b');
	cout << s1.size() << endl;
	cout << s1.Capacity() << endl;
	//s1.PushBack(' ');
	//s1.PushBack('b');
	//s1.Append(1, 'i');
	//cout << s1 << endl;

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


