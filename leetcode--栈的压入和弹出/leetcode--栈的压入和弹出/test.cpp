//��Ŀ����
//���������������У���һ�����б�ʾջ��ѹ��˳�����жϵڶ��������Ƿ����Ϊ��ջ�ĵ���˳�򡣼���ѹ��ջ���������־�����ȡ�
//��������1, 2, 3, 4, 5��ĳջ��ѹ��˳������4, 5, 3, 2, 1�Ǹ�ѹջ���ж�Ӧ��һ���������У�
//��4, 3, 5, 1, 2�Ͳ������Ǹ�ѹջ���еĵ������С���ע�⣺���������еĳ�������ȵģ�
#include<iostream>
#include<vector>
#include<stack>
using namespace std;

class Solution {
public:
	bool IsPopOrder(vector<int> pushV, vector<int> popV) {
		if (pushV.size() != popV.size())
			return false;
		stack<int> s;
		int index = 0;
		int outdex = 0;
		while (outdex<popV.size())
		{
			while (s.empty() || s.top() != popV[outdex])
			{
				if (index<pushV.size())
					s.push(pushV[index++]);
				else
					return false;
			}
			s.pop();
			outdex++;
		}
		return true;
	}
};