#include<iostream>
#include<string>

using namespace std;
//1.��һ�������Str������������ִ�
//���磺
//���� abcd123aeheru45678cuv123456789
//��� 123456789
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
//2.��������һ�����ֳ��ֵĴ�������һ�����ҳ��������
