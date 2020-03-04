//150. �沨�����ʽ��ֵ
//�����沨����ʾ��������ʽ��ֵ��
//��Ч����������� + , -, *, / ��ÿ��������������������Ҳ��������һ���沨�����ʽ��
//˵����
//��������ֻ�����������֡�
//�����沨�����ʽ������Ч�ġ����仰˵�����ʽ�ܻ�ó���Ч��ֵ�Ҳ����ڳ���Ϊ 0 �������
//ʾ�� 1��
//
//���� : ["2", "1", "+", "3", "*"]
// ��� : 9
//  ���� : ((2 + 1) * 3) = 9
//	   ʾ�� 2��
//
//   ���� : ["4", "13", "5", "/", "+"]
//	��� : 6
//	 ���� : (4 + (13 / 5)) = 6
//		  ʾ�� 3��
//
//	  ���� : ["10", "6", "9", "3", "+", "-11", "*", "/", "*", "17", "+", "5", "+"]
//	   ��� : 22
//		���� :
//		   ((10 * (6 / ((9 + 3) * -11))) + 17) + 5
//		   = ((10 * (6 / (12 * -11))) + 17) + 5
//		   = ((10 * (6 / -132)) + 17) + 5
//		   = ((10 * 0) + 17) + 5
//		   = (0 + 17) + 5
//		   = 17 + 5
//		   = 22
#include<vector>
#include<stack>
#include<iostream>
using namespace std;
class Solution {
public:
	int evalRPN(vector<string>& tokens) {
		stack<int> s;
		for (size_t i = 0; i<tokens.size(); i++)
		{
			string& str = tokens[i];
			if (!("+" == str || "-" == str || "*" == str || "/" == str))
				s.push(atoi(str.c_str()));
			else
			{
				int right = s.top();
				s.pop();
				int left = s.top();
				s.pop();
				switch (str[0])
				{
				case '+':
					s.push(left + right);
					break;
				case '-':
					s.push(left - right);
					break;
				case '*':
					s.push(left*right);
					break;
				case '/':
					s.push(left / right);
					break;
				}
			}
		}
		return s.top();
	}
};