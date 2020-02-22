#include<iostream>
#include<functional>
#include<vector>
#include<deque>

using namespace std;
#if 0
namespace bid
{
//ģ��ʵ��ջ
	template<class T, class Container = deque<T>>
	class Stack//ջ
	{
	public:

		Stack(){}//����ȳ�
		//��ջ  //ֱ�ӵ���������ķ�������	
		void push(const T& x){	_s.push_back(x);}
		void pop(){	_s.pop_back();}//��ջ
		T& top(){	return _s.back();	}
		const T& top() const{	return _s.back();	}
		size_t size() const	{	return _s.size();}
		bool empty() const{		return _s.empty();	}
	private:
		Container _s;
	};
}
void StackTest()
{
	bid::Stack<int> s1;
	s1.push(1);
	s1.push(2);
	s1.push(3);
	s1.push(4);
	cout << s1.size() << endl;
	cout << s1.top() << endl;

	s1.pop();
	s1.pop();
	cout << s1.size() << endl;
	cout << s1.top() << endl;

}
int main()
{
	StackTest();
	system("pause");
	return 0;
}
#endif

#if 0
namespace bit
{
	//ģ��ʵ�ֶ���
	template<class T, class Con = deque<T>>//�õ���˫�˶��У�Ҳ��list
	class Queue//����
	{//�Ƚ��ȳ�
	public:
		Queue(){}
		void push(const T& x){_q.push_back(x);}
		void pop(){		_q.pop_front();}
		//
		T& front(){return _q.front();}
		const T& front() const{	return _q.front();}
		T& back(){	return _q.back();}
		const T& back() const{ return _q.back();}
		size_t size() const{ return _q.size();	}
		bool empty() const{	return _q.empty();}
	private:
		Con _q;
	};
}
void QueueTest()
{
	bit::Queue<int> q;
	q.push(1);
	q.push(2);
	q.push(3);
	q.push(4);
	cout << q.size() << endl;
	cout << q.front() << endl;
	cout << q.back() << endl;

	q.pop();
	q.pop();
	cout << q.size() << endl;
	cout << q.front() << endl;
	cout << q.back() << endl;
}

int main()
{
	QueueTest();
	system("pause");
	return 0;	
}
#endif
#if 1

namespace bic
{
	//ģ��ʵ�����ȼ�����
	template<class T,class Con_ =vector<T> ,class Compare=less<T>>
	
	class priority_queue
	{
	public:
		priority_queue()//�չ���
		{}
		//Ϊ���乹��
		template<class Iterator>
		priority_queue(Iterator first, Iterator last)
		{
			while (first != last)
				push(*first++);
		}
		void push(const T& x)
		{
			_con.push_back(x);
			//���ϵ���
			_AdjustUp(_con.size() - 1);
		}
		void pop()
		{
			if (empty())
				return;

			_con.front() = _con.back();//�ѶѶ�Ԫ���ö�β���ǵ�
			_con.pop_back();//ɾ����βԪ��
			_AdjustDown(0);//�ٰѶѶ�Ԫ�����µ�����
		}
		T& top()
		{
			return _con.front();
		}
		const T& top() const
		{
			return _con.front();
		}
		T& back()
		{
			return _con.back();
		}
		const T& back() const
		{
			return _con.back();
		}
		size_t size() const
		{
			return _con.size();
		}
		bool empty() const
		{
			return _con.empty();
		}
	private:
		void _AdjustDown(size_t parent)//parent��֪
		{
			size_t child = parent * 2 + 1;
			// ��ΪĬ���Ǵ��
			while (child < _con.size())
			{
				//�ҳ����Һ��������ĺ��� 
				//��Ҫ��֤���Ӵ���  �ٱȽ��ĸ����Ӵ�
				if (child + 1 < _con.size() && Compare()(_con[child], _con[child + 1]))
					child += 1;
				//���parent�Ƿ�����ѵ�����
				if (_con[parent] < _con[child])
				{
					std::swap(_con[parent], _con[child]);
					parent = child;
					child = parent * 2 + 1;
				}
				else
					return;
			}
		}
		void _AdjustUp(size_t child)
		{
			size_t parent = ((child - 1) >> 1);
			while (child)
			{
				//����ǰ���Ƕѣ������������Һ��Ӳ��ñȽ�
				if (Compare()(_con[parent], _con[child]))
				{
					swap(_con[parent], _con[child]);
					child = parent;
					parent = ((child - 1) >> 1);
				}
				else
					return;
			}
		}
	private:
		Con_ _con;
	};
}
void priority_queueTest()
{
	bic::priority_queue<int> q1;
	q1.push(4);
	q1.push(1);
	q1.push(3);
	q1.push(6);
	q1.push(8);//����ѵķ�ʽ
	cout << q1.size() << endl;//5
	cout << q1.top() << endl;//8
	cout << q1.back() << endl;//4
	
	q1.pop();//�Ѷ�Ԫ�ر��6
	q1.pop();//�Ѷ�Ԫ�ر��4
	cout << q1.size() << endl;//3
	cout << q1.top() << endl;//4
	cout << q1.back() << endl;//3

	int array[] = { 4, 1, 3, 6, 8 };
	//����С�ѣ���ʾģ������б������е����Ͳ���
	bic::priority_queue<int, vector<int>, greater<int>> q2(array, array + sizeof(array) / sizeof(array[0]));
	cout << q2.size() << endl;//5
	cout << q2.top() << endl;//1
	cout << q2.back() << endl;//8

	//q2.pop();//�Ѷ�Ԫ�ر��3
	//q2.pop();//�Ѷ�Ԫ�ر��4
	//cout << q2.size() << endl;//3
	//cout << q2.top() << endl;//6
	//cout << q2.back() << endl;//3


}
int main()
{
	priority_queueTest();
	system("pause");
	return 0;
}
#endif
