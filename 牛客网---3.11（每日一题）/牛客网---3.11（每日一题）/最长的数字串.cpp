//题目描述
//读入一个字符串str，输出字符串str中的连续最长的数字串
//输入描述 :
//个测试输入包含1个测试用例，一个字符串str，长度不超过255。
//输出描述 :
//在一行内输出str中里连续最长的数字串。
//示例1
//输入
//abcd12345ed125ss123456789
//输出
//123456789
#include<iostream>
#include<iostream>
#include<string>
using namespace std;
int main()
{
	string str, mid, ret;
	cin >> str;
	for (int i = 0; i <= str.size(); i++)
	{
		if (str[i] >= '0'&&str[i] <= '9')
			mid += str[i];
		else
		{
			if (ret.size()<mid.size())
				ret = mid;
			else
				mid.clear();
		}
	}
	cout << ret << endl;
	return 0;
}