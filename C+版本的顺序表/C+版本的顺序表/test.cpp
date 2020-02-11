#include<iostream>
#include<assert.h>
using namespace std;

template<class T>
class SeqList
{
public:
	SeqList(size_t capacity = 10)
		:_array(new T[capacity]),
		_size(0),
		_capacity(capacity)//构造函数初始化
	{}
	~SeqList()//析构函数
	{
		if (_array)
		{
			delete[] _array;
			_array = nullptr;
			_capacity = 0;
			_size = 0;
		}
	}
	void CheckCapaticy()
	{
		if (_size == _capacity)
		{
			cout << "需要扩容" << endl;
			//申请新空间
			size_t newCapacity = _capacity * 2;
			T* temp = new T[newCapacity];
			//拷贝元素
			for (size_t i = 0; i < _size; i++)
			{
				temp[i] = _array[i];
			}
			//释放旧空间
			delete[] _array;
			_array = temp;
			_capacity = newCapacity;
			cout << "扩容成功" << endl;
		}
	}
	void PushBack(const T& data);//尾插
	void PopBack();//尾删
	void PushFront(const T& data);//头插
	void PopFront();//头删
	size_t Size();
	size_t Capacity();
	void PrintTest();//打印
	
	//重载下标运算符[]   下标运算符成对重载
	T& operator[](size_t index)
	{
		assert(index < _size);
		return _array[index];
	}
	//对象的内容不能修改
	const T& operator[](size_t index) const
	{
		assert(index < _size);
		return _array[index];
	}
private:
	T* _array;//数组放元素  T代表顺序表中存放元素的类型
	size_t _size;//有效元素个数
	size_t _capacity;//数组总容量	
};

template<class T>
void SeqList<T>::PushBack(const T& data)//尾插
{
	CheckCapaticy();
	_array[_size++] = data;
}
template<class T>
void SeqList<T>::PopBack()//尾删
{
	_size--;
}
template<class T>
void SeqList<T>::PushFront(const T& data)//头插
{
	CheckCapaticy();
	size_t i = 0;
	for (i=_size; i >0; i--)
	{
		_array[i]=_array[i - 1];
	}
	_array[0] = data;
	_size++;//插完有效元素个数也要+1
}
template<class T>
void SeqList<T>::PopFront()//头删
{
	if (_size == 0)
		return;
	size_t i = 1;
	while (i<_size)
	{
		_array[i-1] = _array[i];
		i++;
	}
	_size--;
}
template<class T>
size_t SeqList<T>::Size()
{
	return _size;
}
template<class T>
size_t SeqList<T>::Capacity()
{
	return _capacity;
}
template<class T>
void SeqList<T>::PrintTest()
{
	size_t i = 0;
	for (; i < _size - 1; i++)
	{
		cout << _array[i]<<"-->";
	}
	cout << _array[_size - 1] << endl;
}
int main()
{
	SeqList<int> s1;
	s1.PushBack(1);
	s1.PushBack(2);
	s1.PushBack(3);
	s1.PushBack(4);
	s1.PushBack(5);
	s1.PushBack(6);
	s1.PushBack(7);
	s1.PushBack(8);
	s1.PushBack(9);
	s1.PushBack(9);
	s1.PrintTest();
	cout << s1[4]<<"号元素没改之前是"<<s1[5] << endl;
	s1[5] = 20;
	s1.PopBack();
	s1.PrintTest();
	s1.PushFront(1);
	s1.PushFront(2);
	s1.PushFront(3);
	s1.PushFront(4);
	s1.PushFront(5);
	s1.PrintTest();
	s1.PopFront();
	s1.PrintTest();
	cout << "有效元素个数为:" << s1.Size() << endl;
	cout << "容量为" << s1.Capacity() << endl;
	system("pause");
	return 0;
}



//顺序表不适合头插头删 任意位置插入删除，适合尾删尾插
//void PushFront(const T& data)//头插
//{
//	while (_size)
//	{
//		_array[_size] = _array[_size - 1];
//		_size--;
//	}
//	_array[_size] = data;
//	_size++;//插完有效元素个数也要+1
//}
//void PopFront()//头删
//{
//	if (_size == 0)
//		return;
//	int i = 1;
//	while (i<_size)
//	{
//		_array[0] = _array[i];
//		i++;
//	}
//	_size--;
//}