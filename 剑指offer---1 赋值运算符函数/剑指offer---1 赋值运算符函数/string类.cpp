#include<iostream>
using namespace std;
namespace bit
{
	class string
	{
	public:
		//构造
		string(const char* str)
		{
			if (str == nullptr)
				str = "";
			_size = strlen(str) + 1;
			_capacity = _size;
			_str = new char[strlen(str) + 1];

			strcpy(_str, str);
		}
		string(char c, int n)
			:_str(new char[n + 1]),
			_size(n),
			_capacity(_size)
		{
			memset(_str, c, _size);
		}
		string(char* pstr,int n)//前n个字符
		{
			_size = strlen(pstr) > n ? n : strlen(pstr);
			_capacity = _size;
			_str = new char[_capacity + 1];
			for (int i = 0; i < _size; i++)
				_str[i] = pstr[i];
			_str[_size] = '\0';
		}
		//拷贝构造
		string(const string& s) :_str(new char[strlen(_str)+1])
		{
			strcpy(_str, s._str);
		}
		//赋值运算符重载
		string& operator=(const string& s)
		{
			if (this != &s)//判断是否自己给自己赋值
			{
				char *ptr = new char[strlen(s._str) + 1];
				strcpy(ptr, s._str);
				delete[] _str;//释放之前已有的
				_str = ptr;
			}
			return *this;
		}
		//析构函数
		~string()
		{
			if (_str)
			{
				delete[] _str;
				_str == nullptr;
			}
		}
	private:
		char* _str;
		int _size;
		int _capacity;
	};
}
int main()
{
	return 0;
}