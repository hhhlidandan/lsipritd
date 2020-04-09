#include<iostream>
using namespace std;
namespace bit
{
	class string
	{
	public:
		//����
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
		string(char* pstr,int n)//ǰn���ַ�
		{
			_size = strlen(pstr) > n ? n : strlen(pstr);
			_capacity = _size;
			_str = new char[_capacity + 1];
			for (int i = 0; i < _size; i++)
				_str[i] = pstr[i];
			_str[_size] = '\0';
		}
		//��������
		string(const string& s) :_str(new char[strlen(_str)+1])
		{
			strcpy(_str, s._str);
		}
		//��ֵ���������
		string& operator=(const string& s)
		{
			if (this != &s)//�ж��Ƿ��Լ����Լ���ֵ
			{
				char *ptr = new char[strlen(s._str) + 1];
				strcpy(ptr, s._str);
				delete[] _str;//�ͷ�֮ǰ���е�
				_str = ptr;
			}
			return *this;
		}
		//��������
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