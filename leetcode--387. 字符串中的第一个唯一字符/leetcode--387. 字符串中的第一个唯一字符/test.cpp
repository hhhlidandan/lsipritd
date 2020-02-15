#include<iostream>
#include<stdio.h>
#include<stdlib.h>
using namespace std;
//387. 字符串中的第一个唯一字符
//给定一个字符串，找到它的第一个不重复的字符，并返回它的索引。如果不存在，则返回 - 1。
//案例 :
//s = "leetcode"
//返回 0.
//
//s = "loveleetcode",
//返回 2.

class Solution {
public:
	int firstUniqChar(string s) {
		int count[256] = { 0 };
		//每一个字符出现了几次
		for (size_t i = 0; i<s.size(); i++)
		{
			count[s[i]]++;
		}
		//出现一次的
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