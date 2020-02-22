#include<iostream>
#include<functional>
#include<vector>
#include<deque>

using namespace std;
#if 0
namespace bid
{
//模拟实现栈
	template<class T, class Container = deque<T>>
	class Stack//栈
	{
	public:

		Stack(){}//后进先出
		//入栈  //直接调容器里面的方法就行	
		void push(const T& x){	_s.push_back(x);}
		void pop(){	_s.pop_back();}//出栈
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
	//模拟实现队列
	template<class T, class Con = deque<T>>//用的是双端队列，也可list
	class Queue//队列
	{//先进先出
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
	//模拟实现优先级队列
	template<class T,class Con_ =vector<T> ,class Compare=less<T>>
	
	class priority_queue
	{
	public:
		priority_queue()//空构造
		{}
		//为区间构造
		template<class Iterator>
		priority_queue(Iterator first, Iterator last)
		{
			while (first != last)
				push(*first++);
		}
		void push(const T& x)
		{
			_con.push_back(x);
			//向上调整
			_AdjustUp(_con.size() - 1);
		}
		void pop()
		{
			if (empty())
				return;

			_con.front() = _con.back();//把堆顶元素用堆尾覆盖掉
			_con.pop_back();//删除堆尾元素
			_AdjustDown(0);//再把堆顶元素向下调整好
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
		void _AdjustDown(size_t parent)//parent已知
		{
			size_t child = parent * 2 + 1;
			// 因为默认是大堆
			while (child < _con.size())
			{
				//找出左右孩子中最大的孩子 
				//先要保证孩子存在  再比较哪个孩子大
				if (child + 1 < _con.size() && Compare()(_con[child], _con[child + 1]))
					child += 1;
				//检查parent是否满足堆的特性
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
				//插入前就是堆，所以左孩子与右孩子不用比较
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
	q1.push(8);//按大堆的方式
	cout << q1.size() << endl;//5
	cout << q1.top() << endl;//8
	cout << q1.back() << endl;//4
	
	q1.pop();//堆顶元素变成6
	q1.pop();//堆顶元素变成4
	cout << q1.size() << endl;//3
	cout << q1.top() << endl;//4
	cout << q1.back() << endl;//3

	int array[] = { 4, 1, 3, 6, 8 };
	//创建小堆，显示模板参数列表中所有的类型参数
	bic::priority_queue<int, vector<int>, greater<int>> q2(array, array + sizeof(array) / sizeof(array[0]));
	cout << q2.size() << endl;//5
	cout << q2.top() << endl;//1
	cout << q2.back() << endl;//8

	//q2.pop();//堆顶元素变成3
	//q2.pop();//堆顶元素变成4
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
