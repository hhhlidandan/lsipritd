#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

//反转字符串
#if 0
class Solution
{
public:
	string reverseString(string s)
	{
		if (s.empty())
			return s;
		size_t start = 0;
		size_t end = s.size() - 1;
		while (start < end)
		{
		swap(s[start], s[end]);
		start++, end--;
		}
		return s;
	}
};
int main()
{
	Solution s;
	cout << s.reverseString("hello") << endl;
	system("pause");
	return 0;
}
#endif
#if 0
int main()
{
	string s;
	//getline(cin, s);
	reverse(s.begin(), s.end());//方法1：调这个可以直接逆置
	//方法2 下标访问
	size_t start = 0;
	size_t end = s.size() - 1;
	while (start < end)
	{
	swap(s[start], s[end]);
	start++, end--;
	}
	cout << s << endl;

	//方法3 
	char* start1 = (char*)s.c_str();
	char* endd = start1 + s.size() - 1;
	while (start1 < endd)
	{
	swap(*start1, *endd);
	start1++, endd--;
	}
	cout << s << endl;

	system("pause");
	return 0;
}
#endif
	

	