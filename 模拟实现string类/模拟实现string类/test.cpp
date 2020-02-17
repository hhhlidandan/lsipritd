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
		//给左操作数减1 释放资源s4
		string& operator=(const string& s)
		{
			if (this != &s)
			{
				release();
				_str = s._str;//共用空间
				_pCount = s._pCount;//共用计数
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
				delete[] _str;//指向其他地方，所以把资源释放
				delete _pCount;
				_str = nullptr;
				_pCount = nullptr;
			}
		}
	private:
		char* _str;
		int* _pCount;//按照指针的方式共享
	};	
}
void TestString()
{
	bit::string s1("hello");
	bit::string s2(s1);
	bit::string s3("world");
	bit::string s4(s3);
	s1 = s3; //s123共用同一份空间   s4
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
	//现代版深拷贝
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
		//下面这个更方便
		string(const string& s) :_str(nullptr)//如果不初始化为空，那最开始它里面是随机值，不是我们申请的，在释放时就会崩溃
		{
			string strTemp(s._str);//用s里的字符串构造临时对象
			swap(_str, strTemp._str);//内容交换
			//临时对象销毁，这时临时对象的之前内容已经被交换啦
		}
		string& operator=(string s)
		{
			swap(_str, s._str);
			return *this;
		}

		//string& operator=(const string& s)
		//{
		//方法1
		//	if (this != &s)
		//	{
		//		//和拷贝构造一样
		//		string strTemp(s);
		//		swap(_str, strTemp._str);
		//	}
		////直接这样也可
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
//传统版的  深拷贝
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
		string(const char* str = " ")//构造
		{
			if (str == nullptr)
				str = "";
			_size = strlen(str);
			_capacity = _size;
			_str = new char[_capacity + 1];//开辟空间
			strcpy(_str, str);
		}
		string(size_t n, char c)//构造//放上n个字符c
			:_str(new char[n + 1])
			, _capacity(n)
			, _size(n)
		{
			memset(_str, c, _size);//设置_size个大小的字符c

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
		//深拷贝 拷贝构造
		string(const string& s) :_str(new char[strlen(s._str) + 1])
		{
			strcpy(_str, s._str);
		}
		//深拷贝  赋值运算符重载
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
		~string()//析构
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
		//将对象中有效元素个数改变到newSize,多出的字符用字符ch填充
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
			if (oldSize < newCapacity)//空间小，开辟新空间
			{
				char* pStr = new char[newCapacity + 1];
				strcpy(pStr, _str);
				//释放旧空间，使用新空间
				delete[] _str;
				_str = pStr;
				_capacity = newCapacity;
			}
		}
//////modify///////////////////////////////////////////////
		string& operator+=(const string& s)
		{
			size_t leftByte = _capacity - _size;//剩余空间
			size_t totalByte = s.size();//一共的
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
		void Append(size_t n, char c)//追加n个c
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
			for (int i = pos; i > 0; i--)//不能用size_t 这是无符号整型，会死循环
			{
				if (_str[i]==ch)
					return i;
			}
		}
		string StrSub(size_t pos, size_t n = npos) const//npos说明一直操作到结尾
		{
			//从pos位置开始，构造n个字符串
			return string(_str + pos, n);
		}
	private:
		char* _str;
		size_t _capacity;
		size_t _size;
		static const size_t npos;//npos从末尾开始找
	};
}
const size_t string::npos = -1;//默认npos=-1  (从末尾进行操作)

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
	//反例
	class string
	{
	public:
		//通过空串
		//通过C格式字符串构造 const char* s 
		string(const char* str = " ")//构造函数
		{
			//if (nullptr == str)
			//{
			//	_str = new char[1];
			//	*_str = '\0';
			//}
			//else
			//{
			//	//开辟空间
			//	_str = new char[strlen(str) + 1];
			//	strcpy(_str, str);
			//}
			if (nullptr == str)
				str = "";
			_str = new char[strlen(str) + 1];
			strcpy(_str, str);
		}
		//浅拷贝 
		string(const string& s):_str(s._str)//使用同一块内存空间
		{}
		//浅拷贝  导致资源多次释放、内存泄漏
		string& operator=(const string& s)
		{
			_str = s._str;
			return *this;
		}
		//拷贝构造编译器默认生成的是浅拷贝方式(如果类里面管理了资源，浅拷贝会出错)
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


