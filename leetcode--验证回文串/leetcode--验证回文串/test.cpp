//����һ���ַ�������֤���Ƿ��ǻ��Ĵ���ֻ������ĸ�������ַ������Ժ�����ĸ�Ĵ�Сд��
//˵���������У����ǽ����ַ�������Ϊ��Ч�Ļ��Ĵ���
//ʾ�� 1:
//���� : "A man, a plan, a canal: Panama"
//��� : true
//	 ʾ�� 2 :
// ���� : "race a car"
//  ��� : false
#include<string>
#include<iostream>
using namespace std;

#if 0
//�����leetcode�����У�ʱ�䳬������
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
	s=deleteNoNumberOrLetter(s);//ȥ�������ַ�����������ķ���
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



#if  0 //�����ٶ����

bool isPalindrome(string s) {
	if (s.empty()) return true;//���ַ�������Ϊ��Ч���ַ�
	int begin = 0;
	int end = s.size() - 1;
	while (begin < end)
	{
		//һ����ǰ�����ң�һ���Ӻ���ǰ��
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
		//�жϺ��Դ�Сд���Ƿ�һ���������Ƿ���ͬ	
		if (begin < end)
		{
			if ((s[begin]+32- 'a') % 32 == (s[end]+32 - 'a') % 32)//+32��Ϊ�˶�Ϊ��
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
		//��ǰ���󣬴Ӻ���ǰһ��
		int begin = 0;
		int end = s.size() - 1;
		//char* c=(char*)s.c_str();
		while (begin<end)
		{
			//��ǰ���󣬴Ӻ���ǰһ��
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
//����ͨ�� ������ʱ��ϳ�
//��C����   ͷ�ļ�<ctype.h>
//���� int ispunct(int c)  ����������ַ��Ƿ��Ǳ������ַ�
//���� int isspace(int c)  ���һ���ַ����Ƿ�Ϊ�հ��ַ�
//���� int tolower(int c)  ��д��ĸת��ΪСд
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