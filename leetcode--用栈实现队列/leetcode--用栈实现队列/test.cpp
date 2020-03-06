//232. ��ջʵ�ֶ���
//ʹ��ջʵ�ֶ��е����в�����
//
//push(x) --��һ��Ԫ�ط�����е�β����
//pop() --�Ӷ����ײ��Ƴ�Ԫ�ء�
//peek() --���ض����ײ���Ԫ�ء�
//empty() --���ض����Ƿ�Ϊ�ա�
//ʾ�� :
//
//MyQueue queue = new MyQueue();
//
//queue.push(1);
//queue.push(2);
//queue.peek();  // ���� 1
//queue.pop();   // ���� 1
//queue.empty(); // ���� false
//˵��:
//
//��ֻ��ʹ�ñ�׼��ջ���� -- Ҳ����ֻ�� push to top, peek / pop from top, size, �� is empty �����ǺϷ��ġ�
//����ʹ�õ�����Ҳ��֧��ջ�������ʹ�� list ���� deque��˫�˶��У���ģ��һ��ջ��ֻҪ�Ǳ�׼��ջ�������ɡ�
//�������в���������Ч�� �����磬һ���յĶ��в������ pop ���� peek ��������

class MyQueue {
public:
	/** Initialize your data structure here. */
	MyQueue() {
	}
	void push(int x) {
		s1.push(x);
	}
	int pop() {
		while (!s1.empty())
		{
			s2.push(s1.top());
			s1.pop();
		}
		int top = s2.top();
		s2.pop();
		while (!s2.empty())
		{
			s1.push(s2.top());
			s2.pop();
		}
		return top;
	}
	/** Get the front element. */
	int peek() {
		while (!s1.empty())
		{
			s2.push(s1.top());
			s1.pop();
		}
		int top = s2.top();
		while (!s2.empty())
		{
			s1.push(s2.top());
			s2.pop();
		}
		return top;
	}

	bool empty() {
		if (s1.empty() && s2.empty())
			return true;
		return false;
	}
	stack<int> s1;
	stack<int> s2;
};
