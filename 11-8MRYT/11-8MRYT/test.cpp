#include<iostream>
#include<string>

using namespace std;
//1.在一行中输出Str中连续最长的数字串
//例如：
//输入 abcd123aeheru45678cuv123456789
//输出 123456789
int main()
{
	string str, ret, in;
	cin >> str;
	int i = 0;
	for (; i <= str.length(); i++)
	{
		if (str[i] >= '0'&&str[i] <= '9')
		{
			in = in + str[i];
		}
		else
		{
			if (in.size()>ret.size())
			{
				ret = in;
			}
			else{
				in.clear();
			}
		}
	}
	cout << ret << endl;
	return 0;
}
//2.数组中有一个数字出现的次数超过一半请找出这个数字
