#include<iostream>
#include<stdio.h>
#include<stdlib.h>
using namespace std;
//387. �ַ����еĵ�һ��Ψһ�ַ�
//����һ���ַ������ҵ����ĵ�һ�����ظ����ַ���������������������������ڣ��򷵻� - 1��
//���� :
//s = "leetcode"
//���� 0.
//
//s = "loveleetcode",
//���� 2.

class Solution {
public:
	int firstUniqChar(string s) {
		int count[256] = { 0 };
		//ÿһ���ַ������˼���
		for (size_t i = 0; i<s.size(); i++)
		{
			count[s[i]]++;
		}
		//����һ�ε�
		for (size_t i = 0; i<s.size(); i++)
		{
			if (1 == count[s[i]])
			{
				return i;
			}
		}
		return -1;
	}
};
int main()
{
	Solution s;
	cout << s.firstUniqChar("leetcode") << endl;
	system("pause");
	return 0;
}