//给定一个字符串，验证它是否是回文串，只考虑字母和数字字符，可以忽略字母的大小写。
//说明：本题中，我们将空字符串定义为有效的回文串。
//示例 1:
//输入 : "A man, a plan, a canal: Panama"
//输出 : true
//	 示例 2 :
// 输入 : "race a car"
//  输出 : false
#include<string>
#include<iostream>
using namespace std;

#if 0
//这个在leetcode上运行，时间超出限制
string deleteNoNumberOrLetter(string& s)
{
	string str = "";
	for (size_t i = 0; i < s.size(); i++)
	{
		if (s[i] >= '0'&&s[i] <= '9')
		{
			str = str + s[i];
			continue;
		}	
		else if (s[i] >= 'a'&&s[i] <= 'z')
		{
			str = str + s[i];
			continue;
		}
		else if (s[i] >= 'A'&&s[i] <= 'Z')
		{
			s[i] += 32;
			str = str + s[i];
		}
		else
			continue;
	}
	return str;
}
bool isPalindrome(string s)
{
	s=deleteNoNumberOrLetter(s);//去掉除了字符和数字以外的符号
	if (s.empty())
		return true;
	int begin = 0;
	int end = s.size() - 1;
	while (begin < end)
	{
		if (s[begin] != s[end])
			return false;
		begin++, end--;
	}
	return true;
}
int main()
{
	return 0;
}

#endif



#if  0 //运行速度最快

bool isPalindrome(string s) {
	if (s.empty()) return true;//空字符串定义为有效的字符
	int begin = 0;
	int end = s.size() - 1;
	while (begin < end)
	{
		//一个从前往后找，一个从后往前找
		while (begin != end)
		{
			if (IsNumberOrLetter(s[begin]))
				break;
			begin++;
		}
		while (begin < end)
		{
			if (IsNumberOrLetter(s[end]))
				break;
			end--;
		}
		//判断忽略大小写后是否一样或数字是否相同	
		if (begin < end)
		{
			if ((s[begin]+32- 'a') % 32 == (s[end]+32 - 'a') % 32)//+32是为了都为正
				begin++, end--;
			else
				return false;
		}
	}
	return true;
}
bool IsNumberOrLetter(char c)
{
	if ((c >= '0'&&c <= '9') || (c >= 'a'&&c <= 'z') || (c >= 'A'&&c <= 'Z'))
		return true;
	return false;
}
int main()
{
	string s("hello");
	cout << isPalindrome(s) << endl;
	system("pause");
	return 0;
}
#endif



#if 0
class Solution {
public:
	bool isPalindrome(string s) {
		if (s.empty()) return true;
		//从前往后，从后往前一起
		int begin = 0;
		int end = s.size() - 1;
		//char* c=(char*)s.c_str();
		while (begin<end)
		{
			//从前往后，从后往前一起
			while (begin != end)
			{
				if (IsNumberOrLetter(s[begin]))
					break;
				begin++;
			}
			while (begin<end)
			{
				if (IsNumberOrLetter(s[end]))
					break;
				end--;
			}
			if (begin<end)
			{
				if ((s[begin] + 32 - 'a') % 32 != (s[end] + 32 - 'a') % 32)
					return false;
				begin++, end--;
			}
		}
		return true;
	}
	bool IsNumberOrLetter(char c)
	{
		if ((c >= '0'&&c <= '9') || (c >= 'a'&&c <= 'z') || (c >= 'A'&&c <= 'Z'))
			return true;
		return false;
	}

};
#endif

#if 0
//可以通过 ，运行时间较长
//在C库中   头文件<ctype.h>
//函数 int ispunct(int c)  检查所传的字符是否是标点符号字符
//函数 int isspace(int c)  检查一个字符串是否为空白字符
//函数 int tolower(int c)  大写字母转化为小写
bool isPalindrome(string s) {
	if (s.empty())
		return true;
	int begin = 0;
	int end = s.size() - 1;
	while (begin<end)
	{
		if (ispunct(s[begin]) || isspace(s[begin]))
		{
			begin++;
			continue;
		}
		else if (ispunct(s[end]) || isspace(s[end]))
		{
			end--;
			continue;
		}
		if (tolower(s[begin]) == tolower(s[end]))
		{
			begin++, end--;
			continue;
		}
		else return false;
	}
	return begin >= end ? true : false;

#endif