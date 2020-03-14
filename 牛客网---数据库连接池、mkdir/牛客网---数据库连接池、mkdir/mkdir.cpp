// write your code here cpp
#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;
bool zichuan(string str1, string str2)
{
	if (str1[1] == str2[1])
	{
		str2 = str2.substr(0, str1.size());
		if (str1 == str2)
			return true;
	}
	return false;
}
void Mkdir(vector<string> v)
{
	int i = 0;
	string mk = "mkdir -p ";
	while (i<v.size() - 1)
	{
		if (zichuan(v[i], v[i + 1]) && v[i + 1][v[i].size()] == '/')
			v.erase(v.begin() + i);
		else
			i++;
	}
	for (auto &e : v)
		cout << mk << e << endl;
}
int main()
{
	int n;
	while (cin >> n)
	{
		vector<string> v;
		for (int i = 0; i<n; i++)
		{
			string str;
			cin >> str;
			v.push_back(str);
		}
		sort(v.begin(), v.end());
		Mkdir(v);
		cout << endl;
	}
	return 0;
}