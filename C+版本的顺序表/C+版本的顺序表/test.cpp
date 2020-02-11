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
		_capacity(capacity)//���캯����ʼ��
	{}
	~SeqList()//��������
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
			cout << "��Ҫ����" << endl;
			//�����¿ռ�
			size_t newCapacity = _capacity * 2;
			T* temp = new T[newCapacity];
			//����Ԫ��
			for (size_t i = 0; i < _size; i++)
			{
				temp[i] = _array[i];
			}
			//�ͷžɿռ�
			delete[] _array;
			_array = temp;
			_capacity = newCapacity;
			cout << "���ݳɹ�" << endl;
		}
	}
	void PushBack(const T& data);//β��
	void PopBack();//βɾ
	void PushFront(const T& data);//ͷ��
	void PopFront();//ͷɾ
	size_t Size();
	size_t Capacity();
	void PrintTest();//��ӡ
	
	//�����±������[]   �±�������ɶ�����
	T& operator[](size_t index)
	{
		assert(index < _size);
		return _array[index];
	}
	//��������ݲ����޸�
	const T& operator[](size_t index) const
	{
		assert(index < _size);
		return _array[index];
	}
private:
	T* _array;//�����Ԫ��  T����˳����д��Ԫ�ص�����
	size_t _size;//��ЧԪ�ظ���
	size_t _capacity;//����������	
};

template<class T>
void SeqList<T>::PushBack(const T& data)//β��
{
	CheckCapaticy();
	_array[_size++] = data;
}
template<class T>
void SeqList<T>::PopBack()//βɾ
{
	_size--;
}
template<class T>
void SeqList<T>::PushFront(const T& data)//ͷ��
{
	CheckCapaticy();
	size_t i = 0;
	for (i=_size; i >0; i--)
	{
		_array[i]=_array[i - 1];
	}
	_array[0] = data;
	_size++;//������ЧԪ�ظ���ҲҪ+1
}
template<class T>
void SeqList<T>::PopFront()//ͷɾ
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
	cout << s1[4]<<"��Ԫ��û��֮ǰ��"<<s1[5] << endl;
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
	cout << "��ЧԪ�ظ���Ϊ:" << s1.Size() << endl;
	cout << "����Ϊ" << s1.Capacity() << endl;
	system("pause");
	return 0;
}



//˳����ʺ�ͷ��ͷɾ ����λ�ò���ɾ�����ʺ�βɾβ��
//void PushFront(const T& data)//ͷ��
//{
//	while (_size)
//	{
//		_array[_size] = _array[_size - 1];
//		_size--;
//	}
//	_array[_size] = data;
//	_size++;//������ЧԪ�ظ���ҲҪ+1
//}
//void PopFront()//ͷɾ
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