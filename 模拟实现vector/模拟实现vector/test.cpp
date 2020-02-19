#include<iostream>
#include<assert.h>
#include<stdio.h>
#include<vector>
#include<stdlib.h>
#include<algorithm>
using namespace std;
namespace bid
{
	template<class T>
	class vector
	{
	public:
		typedef T* iterator;
	public:
		vector()//空构造函数
			: _start(nullptr),
			_finish(nullptr),
			_endOfStorage(nullptr)
		{}
		vector(size_t n,const T& data=T())//n个值为data元素的构造
			:_start(new T[n])
			, _finish(_start+n)
			, _endOfStorage(_finish)
		{
			for (size_t i = 0; i < n; i++)
			{
				_start[i] = data;
			}
		}
		vector(T* first, T* last)//区间构造
		{
			size_t size = last - first;
			_start = new T[size];
			for (size_t i = 0; i < size; i++)
			{
				_start[i] = first[i];
			}
			_finish = _endOfStorage = _start + size;
		}
		vector(const vector<T>& v)//拷贝构造
			: _start(nullptr)
			, _finish(nullptr)
			, _endOfStorage(nullptr)
		{
			size_t size = v.size();
			_start = new T[size];
			for (size_t i = 0; i < size; i++)
				_start[i] = v[i];
			_finish = _endOfStorage = _start + size;
		}
		~vector()//析构
		{
			delete[] _start;
			_start = _finish = _endOfStorage = nullptr;
		}
/////////////////////////////////////////////////////////////////////
/////iterator
		iterator begin()
		{
			return _start;
		}
		iterator end()
		{
			return _finish;
		}
/////////////////////////////////////////////////////////////////////////
////////////capacity容量
		size_t size() const
		{
			return _finish - _start;
		}
		size_t capacity() const
		{
			return _endOfStorage - _start;
		}
		bool empty() const
		{
			return _start == _finish;
		}
		void resize(size_t newSize, const T& data = T())
		{
			size_t oldSize = size();
			size_t oldCapacity = capacity();
			if (newSize > oldSize)
			{
				if (newSize >= oldCapacity)//比容量小，比有效元素个数大
				{
					reserve(newSize);
				}	
				for (size_t i = oldSize; i <newSize; i++)
					*_finish++ = data;	
			}
			else
				_finish = _start + newSize;
		}
		void reserve(size_t n)//预留空间 只改变空间大小，不改变容量
		{
			if (n>capacity())
			{
				T* temp = new T[n];
				if (_start)
				{
					size_t osize = size();
					for (size_t i = 0; i < osize; i++)
						temp[i] = _start[i];
					delete[] _start;
					_start = temp;
					_finish = _start + osize;
					_endOfStorage = _start + n;
				}
			}
		}
//////////////////////////////////////////////////////////////////////
///////元素访问（access）
		T& operator[](size_t index)//访问任意位置元素
		{
			assert(index < size());
			return _start[index];
		}
		const T& operator[](size_t index) const
		{
			assert(index < size());
			return _start[index];
		}
		T& front()//访问头部元素
		{
			return *_start;
		}
		const T& front() const
		{
			return _start[0];
		}
		T& back()
		{
			return *(_finish - 1);
		}
		const T& back() const
		{
			return *(_finish - 1);
		}
/////////////////////////////////////////////////////
///modify
		void pushback(const T& data)
		{
			if (_finish == _endOfStorage)
				reserve(2 * capacity());
			*_finish++ = data;
		}
		void popback(const T& data)
		{
			if (_start == _finish)
				return;
			*_finish--;
		}
		iterator insert(iterator pos, const T& data)
		{
			if (_finish == _endOfStorage)
			{
				reserve(2 * capacity());
				pos = _start + size();
			}			
			iterator end = _finish - 1;
			while (end >= pos)
			{
				*(end + 1) = *end;
				end--;
			}
			*pos= data;
			_finish++;
			return pos;
		}
		iterator erase(iterator pos)
		{
			iterator cur = pos;
			iterator curNext = pos + 1;
			while ( curNext != _finish)
			{
				*cur++ = *curNext++;
			}
			_finish--;
			return pos;
		}
		void clear()
		{
			_finish = _start;
		}
		void swap(vector<T>& v)
		{
			std::swap(_start, v._start);
			std::swap(_finish, v._finish);
			std::swap(_endOfStorage, v._endOfStorage);
		}
	private:
		T* _start;//指向元素最开始
		T* _finish;//指向元素结尾
		T* _endOfStorage;//指向顺序表末尾


	};
}
void PrintVector(bid::vector<int>& s)
{
	auto it = s.begin();
	while (it != s.end())
	{
		cout << *it << " ";
		it++;
	}
	cout << endl;
	/*for (auto e : s)
	{
		cout << e << " ";
	}
	cout << endl;*/
}
void TestVector()
{
	bid::vector<int> s1;
	bid::vector<int> s2(10, 5);//10个5
	PrintVector(s2);
	int array[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 0 };
	bid::vector<int> s3(array, array + sizeof(array) / sizeof(array[0]));
	PrintVector(s3);
	bid::vector<int> s4(s3);
	PrintVector(s4);

	cout << "s3.size()" << s3.size() << endl;
	cout << "s3.capacity()" << s3.capacity() << endl;

	s3.resize(3);
	PrintVector(s3);
	cout << "s3.size()" << s3.size() << endl;
	cout << "s3.capacity()" << s3.capacity() << endl;

	s3.resize(6,6);
	PrintVector(s3);
	cout << "s3.size()" << s3.size() << endl;
	cout << "s3.capacity()" << s3.capacity() << endl;

	s3.resize(9);
	PrintVector(s3);
	cout << "s3.size()" << s3.size() << endl;
	cout << "s3.capacity()" << s3.capacity() << endl;

	s3.resize(20,6);
	PrintVector(s3);
	cout << "s3.size()" << s3.size() << endl;
	cout << "s3.capacity()" << s3.capacity() << endl;

	cout << s3[10] << endl;
	cout << s3.front() << endl;
	cout << s3.back() << endl;

	s3.insert(s3.begin(), 0);
	PrintVector(s3);
	cout << "s3.size()" << s3.size() << endl;
	cout << "s3.capacity()" << s3.capacity() << endl;

	s3.erase(s3.begin());
	PrintVector(s3);
	cout << "s3.size()" << s3.size() << endl;
	cout << "s3.capacity()" << s3.capacity() << endl;

	s3.clear();
	PrintVector(s3);
	cout << "s3.size()" << s3.size() << endl;
	cout << "s3.capacity()" << s3.capacity() << endl;
}
int main()
{
	TestVector();
	system("pause");
	return 0;
}
