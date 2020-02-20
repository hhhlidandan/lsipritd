#include<iostream>
using namespace std;
template<class T>
struct ListNode
{
	ListNode(const T& data = T())
	:_pNext(nullptr)
	, _pPre(nullptr)
	, _data(data)
	{}
	ListNode<T>* _pNext;//ָ��ǰ������һ�����
	ListNode<T>* _pPre;//ָ��ǰ����ǰһ�����
	T _data;//����ŵ�ֵ��
};
namespace bid
{
	template<class T>
	struct ListIterator//�������������
	{
		typedef T ValueType;//��Tȡ����
		//���ŵ�����
		typedef ListNode<T> Node;
		typedef Node* PNode;
		//insert�ķ���ֵ�����ǵ��������������õ����������������
		typedef ListIterator<T> Self;
		ListIterator(PNode pNode = nullptr)
			:_pNode(pNode)
		{}
		ListIterator(const Self& s)
			:_pNode(s._pNode)
		{}
		T& operator*()
		{
			return _pNode->_data;
		}
		T& operator->()
		{
			return &(_pNode->_data);
		}
		Self& operator++()
		{
			_pNode = _pNode->_pNext;
			return *this;
		}
		Self operator++(int)
		{
			Self temp(*this);
			_pNode = _pNode->_pNext;
			return temp;
		}
		Self& operator--()
		{
			_pNode = _pNode->_pPre;
			return *this;
		}
		Self operator--(int)
		{
			Self temp(*this);
			_pNode = _pNode->_pPre;
			return temp;
		}
		bool operator!=(const Self& s) const
		{
			return _pNode != s._pNode;//ָ���Ƿ�ָ��ͬһ���
		}
		bool operator==(const Self& s) const
		{
			return _pNode == s._pNode;
		}
		PNode _pNode;//��ָ���װ  ����list����
	};
	template<class Iterator>//���������
	struct ListReverseIterator
	{
		typedef ListReverseIterator<Iterator> Self;
		//����typename���ܻ����ΪValueType��Iterator�ľ�̬��Ա��������̬��Ա������ͨ���������ʵģ�
		typename typedef Iterator::ValueType T;//�ڵ�������Ԫ�ص�����  
		ListReverseIterator(Iterator it) :_it(it)//����
		{}
		ListReverseIterator(const Self& s) :_it(s._it)//��������
		{}
		T& operator*()
		{
			Iterator temp(_it);
			--temp;
			return *temp;
		}
		T* operator->()
		{
			return &(operator*());
		}
		Self& operator++()
		{
			--_it;
			return *this;
		}
		Self operator++(int)
		{
			Self temp(*this);
			--_it;
			return temp;
		}
		Self& operator--()
		{
			++_it;
			return *this;
		}
		Self operator--(int)
		{
			Self temp(*this);
			++_it;
			return temp;
		}
		bool operator!=(const Self& l) const
		{
			return _it != l._it;//���������Ƿ���Ⱦ�����
		}
		bool operator==(const Self& l) const
		{
			return _it == l._it;
		}
		Iterator _it;
	};
	template<class T>
	class list
	{
		typedef ListNode<T> Node;//���
		typedef Node* PNode;//���ָ��
	public:
		typedef ListIterator<T> iterator;//��������ȡ����
		typedef ListReverseIterator<iterator> reverse_iterator;
	public:
		list()
		{
			CreateHead();
		}
		list(size_t n, const T& data = T())
		{
			CreateHead();
			for (size_t i = 0; i < n; i++)
			{
				push_back(data);
				/*_pHead->_pNext = data;
				_pHead = _pHead->_pNext;*/
			}
		}
		list(T* first, T* last)
		{
			CreateHead();
			while (first != last)
			{
				push_back(*first);
				++first;
			}
		}
		list(const list<T>& l)
		{
			CreateHead();
			PNode pCur = l._pHead->_pNext;//�����е�һ�����
			while (pCur != l._pHead)//��pCur==_pHeadʱ������һȦ��
			{
				push_back(pCur->_data);
				pCur = pCur->_pNext;
			}
		}
	/*	list<T>& operator=(const list<T>& l)
		{
			if (this != &l)
			{

			}
		}*/
		~list()
		{
			clear();
			delete _pHead;
			_pHead = nullptr;
		}
/////////////////////////////////////////////////////////
/////iterator������
		iterator begin()
		{
			return iterator(_pHead->_pNext);
		}
		iterator end()
		{
			return iterator(_pHead);
		}
		reverse_iterator rbegin()
		{
			return reverse_iterator(end());
		}
		reverse_iterator rend()
		{
			return reverse_iterator(begin());
		}
////////////////////////////////////////////////////////
/////capacity��������
		size_t size() const
		{
			size_t count = 0;
			PNode pCur = _pHead->_pNext;
			while (pCur != _pHead)
			{
				count++;
				pCur = pCur->_pNext;
			}
			return count;
		}
		bool empty() const
		{
			return _pHead->_pNext == _pHead;
		}
		void resize(size_t newSize, const T& data = T())
		{
			size_t oldSize = size();
			if (newSize > oldSize)
			{
				for (size_t i = oldSize; i < newSize; i++)
					push_back(data);
			}
			else//oldSize>newSize
			{
				for (size_t i = newSize; i<oldSize; i++)
					pop_back();
			}
		}
//////////////////////////////////////////////////////
/////access���ʲ��� ��ʽ�ṹ����֧��������ʣ�ֻ�ṩfront,back
		T& front()
		{
			return _pHead->_pNext->_data;
		}
		const T& front() const
		{
			return _pHead->_pNext->_data;
		}
		T& back()
		{
			return _pHead->_pPre->_data;
		}
		const T& back() const
		{
			return _pHead->_pPre->_data;
		}
//////////////////////////////////////////////////////
/////modify �޸�
		void push_back(const T& data)//����ֵΪdata�Ľ��
		{
			PNode pNewNode = new Node(data);//����ֵΪdata�Ľ��
			pNewNode->_pNext = _pHead;
			pNewNode->_pPre = _pHead->_pPre;

			_pHead->_pPre->_pNext = pNewNode;
			_pHead->_pPre = pNewNode;
			/*_pHead->_pPre = pNewNode;//���У�ֻ������˳��һ��
			pNewNode->_pNext->_pPre = pNewNode;*/			
		}
		void pop_back()
		{
			PNode pDelNode = _pHead->_pPre;//�ҽ��
			_pHead->_pPre = pDelNode->_pPre;
			pDelNode->_pPre->_pNext = _pHead;
			delete pDelNode;
		}
		void push_front(const T& data)
		{
			PNode pNewNode = new Node(data);
			pNewNode->_pPre = _pHead;
			pNewNode->_pNext = _pHead->_pNext;

			_pHead->_pNext = pNewNode;
			pNewNode->_pNext->_pPre = pNewNode;
		}
		void pop_front()
		{
			PNode pDelNode = _pHead->_pNext;//�ҵ�ɾ�Ľ��
			_pHead->_pNext = pDelNode->_pNext;
			_pHead->_pNext->_pPre = _pHead;
			delete pDelNode;
		}
		void swap(list<T>& l)//����_pHead��ָ��
		{
			std::swap(_pHead, l._pHead);
		}
		void clear()
		{
			PNode pCur = _pHead->_pNext;
			while (pCur != _pHead)
			{
				_pHead->_pNext = pCur->_pNext;
				delete pCur;
				pCur = _pHead->_pNext;
			}
			_pHead->_pNext = _pHead;
			_pHead->_pPre = _pHead;
		}
		iterator insert(iterator position,const T& data=T())//����position ��ǰ��
		{
			PNode pNewNode = new Node(data);
			PNode pCur = position._pNode;//������������һ�����
			pNewNode->_pPre = pCur->_pPre;
			pNewNode->_pNext = pCur;
			pNewNode->_pPre->_pNext = pNewNode;
			pCur->_pPre = pNewNode;
			return iterator(pNewNode);
		}
		iterator erase(iterator pos)//���ص���λ����ɾ��Ԫ�ص���һ�����
		{

			PNode  pDelNode = pos._pNode;
			if (pDelNode == _pHead) 
				return end();
			PNode pRet = pDelNode->_pNext;

			pDelNode->_pPre->_pNext = pDelNode->_pNext;
			pDelNode->_pNext->_pPre = pDelNode->_pPre;
			delete pDelNode;
			return iterator(pRet);
		}
	private:
		void CreateHead()
		{
			_pHead = new Node;
			_pHead->_pNext = _pHead;
			_pHead->_pPre = _pHead;
		}
	private:
		PNode _pHead;
	};
}
template<class T>
void PrintList(bid::list<T>& l)
{
	auto it = l.begin();
	while (it != l.end())
	{
		cout << *it << " ";
		it++;
	}
	cout << endl;
}
template<class T>
void ReversePrintList(bid::list<T>& l)
{
	auto it = l.rbegin();
	while (it != l.rend())
	{
		cout << *it << " ";
		it++;
	}
	cout << endl;
}
void Test1()
{
	bid::list<int> l1;//�޲ι���
	bid::list<int> l2(10, 5);//����10��5
	int array[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 0 };
	bid::list<int> l3(array, array + sizeof(array) / sizeof(array[0]));
	PrintList(l3);

	l3.push_back(50);
	l3.push_front(0);
	PrintList(l3);
	l3.pop_back();
	l3.pop_front();
	PrintList(l3);

	cout << "front" << l3.front() << endl;
	cout << "back" << l3.back() << endl;

	if (l3.empty())
		cout << "��" << endl;
	else
		cout << l3.size() << endl;

	l3.resize(5);
	PrintList(l3);
	l3.resize(15, 7);
	PrintList(l3);
	l2.resize(15, 8);
	l2.swap(l3);
	PrintList(l2);
	PrintList(l3);

	l3.clear();
	PrintList(l3);
	if (l3.empty())
		cout << "��" << endl;
	else
		cout << l3.size() << endl;
}
void Test2()
{
	bid::list<int> l2(10, 5);//����10��5
	PrintList(l2);
	int array[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 0 };
	bid::list<int> l3(array, array + sizeof(array) / sizeof(array[0]));//���乹��
	PrintList(l3);
	ReversePrintList(l3);

	l3.insert(l3.begin(), 100);
	PrintList(l3);
	l3.erase(l3.begin());
	PrintList(l3);
	//��������
	bid::list<int> l4(l3);
	PrintList(l4);
}
int main()
{
	//Test1();
	Test2();

	//clear()  swap push_back(const T& data)//����ֵΪdata�Ľ��   back() front()  resize empty()size()  insert
	
	

	
	system("pause");
	return 0;
}