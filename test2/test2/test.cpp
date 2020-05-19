#include<iostream>
#include<string>
#include<stdlib.h>
using namespace std;
int main()
{
	string str;
	//as cdf ww
	getline(cin, str);
	int start = 0, pos = 0;
	for (size_t i = start; i < str.size(); i++)
	{
		if (str[i] != ' ') 
			pos++;
		else
		{
			cout << str.substr(start, pos - start + 1) << endl;
			start = pos + 1;
		}
	}
	cout << str.substr(start+1, pos - start + 1);
	/*int pos = 0;
	int start = 0;
	do
	{
	//asd asd asdf
		pos = str.find(' ',start);
		cout << str.substr(start, pos-start+1)<<endl;
		start = pos + 1;
	} while (pos != str.npos);*/
	system("pause");
	return 0;
}