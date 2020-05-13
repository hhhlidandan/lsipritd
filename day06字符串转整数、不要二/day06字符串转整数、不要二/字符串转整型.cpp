#include<iostream>
#include<stdlib.h>
#include<string>
using namespace std;
int Ret(string &str)
{
	long long ret = 0;//
	int flag = 0;//记录整数的正负
	cin >> str;
	if (str.empty()) return ret;
	else if (str[0] == '+') flag = 1;
	else if (str[0] == '-') flag = -1;
	else if (str[0] >= '0 '&& str[0] <= '9 ')
		ret = str[0] - '0';//数字字符转数字
	else
		return ret;

	int i = 0;
	for (i = 1; i < str.size(); i++)
	{
		if (str[i] >= '0' && str[i] <= '9')
			ret = ret * 10 + str[i] - '0';
		else return 0;
	}
	if (flag >= 0 && ret <= INT_MAX) return ret;
	else if (flag<0)
	{
		ret *= flag;
		if (ret >= INT_MIN) return ret;
	}
}
int main()
{
	string str;
	int ret = Ret(str);
	cout << ret << endl;
	system("pause");
	return 0;
}