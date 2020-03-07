#include<iostream>
#include<string>
using namespace std;
int main()
{
	int n;
	while (cin >> n)
	{
		cin.get();//获取cin的回车
		string str;
		for (int i = 0; i<n; i++)
		{
			getline(cin, str);
			if (i != n - 1)
			{
				if (str.find(',') != str.npos || str.find(' ') != str.npos)
					cout << '\"' << str << '\"' << ',' << ' ';
				else
					cout << str << ',' << ' ';
			}
			else
			{
				if (str.find(',') != str.npos || str.find(' ') != str.npos)
					cout << '\"' << str << '\"' << endl;
				else
					cout << str << endl;
			}
		}
	}
	return 0;
}