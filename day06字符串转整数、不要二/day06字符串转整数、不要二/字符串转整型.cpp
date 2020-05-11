#include<iostream>
#include<stdlib.h>
#include<string>
using namespace std;
int main()
{
	string str;
	cin >> str;
	int i = 0;
	if (str[0] == '+' || str[0] == '-')
	{
		for (i = 1; i < str.size(); i++)
		{
			if (str[i] < '0'&&str[i] >= '9')
				return 0;
		}
		return str;
	}
	return 0;
	system("pause");
	return 0;
}