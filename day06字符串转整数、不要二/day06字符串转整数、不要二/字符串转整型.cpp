#include<iostream>
#include<stdlib.h>
#include<string>
using namespace std;
int main()
{
	string str;
	long long ret;
	int flag = 1;
	cin >> str;
	int i = 0;
	if (str[0] == '+') flag = 1;
	else if (str[0] == '-') flag = -1;
	else if (str[0] >= '0 '&& str[0] <= '9 ')
		ret = str[0] - '0';

	for (i = 1; i < str.size(); i++)
	{
		if (str[i] >= '0' && str[i] <= '9')
			ret = ret * 10 + str[i] - '0';
		else return 0;
	}

	return ret;
	system("pause");
	return 0;
}