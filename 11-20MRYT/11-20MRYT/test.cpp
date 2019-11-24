#include<iostream>
#include<vector>
#include<string>

using namespace std;
int main()
{
	string str;
	string ret;
	bool flag = false;
	vector<string> s;
	while (getline(cin, str))
	{
		for (int i = 0; i < str.size(); i++)
		{
			if (flag)
			{
				if (str[i] != '\"')
					ret += str[i];
				else
					flag = false;
			}
			else
			{
				if (str[i] == ' ')
				{
					s.push_back(ret);
					ret = "";
				}
				else if (str[i] == '\"')
				{
					flag = true;
				}
				else
				{
					ret += str[i];
				}	
			}
		}
		s.push_back(ret);
		cout << s.size() << endl;
		for (auto i : ret)
		{
			cout << i << endl;
		}
	}
	return 0;
}