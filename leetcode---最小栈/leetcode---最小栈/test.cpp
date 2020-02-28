//���һ��֧�� push��pop��top �����������ڳ���ʱ���ڼ�������СԪ�ص�ջ��
//
//push(x) --��Ԫ�� x ����ջ�С�
//pop() --ɾ��ջ����Ԫ�ء�
//top() --��ȡջ��Ԫ�ء�
//getMin() --����ջ�е���СԪ�ء�
//
//ʾ�� :
//MinStack minStack = new MinStack();
//minStack.push(-2);
//minStack.push(0);
//minStack.push(-3);
//minStack.getMin();   --> ���� - 3.
//minStack.pop();
//minStack.top();      --> ���� 0.
//minStack.getMin();   --> ���� - 2.
//��Դ�����ۣ�LeetCode��


#include<iostream>
#include<stack>
using namespace std;

class MinStack 
{
public:     
	MinStack()     {}     
	void push(int x) 
	{      
		_data.push(x);
		// ���xС��_min��ջ����Ԫ�أ���x��ѹ��_min��        
		if(_min.empty() || x <= _min.top())      
			_min.push(x);  
	}    
	void pop()  
	{    	 
		if (_min.top() == _data.top())
			_min.pop();           
		_data.pop();
	}        
	int top()    
	{       
		return _data.top();
	}       
	int getMin()    
	{       
		return _min.top();  
	}
private:  
	// ����ջ�е�Ԫ��  
	std::stack<int> _data;   
	// ����ջ����Сֵ   
	std::stack<int> _min;
};