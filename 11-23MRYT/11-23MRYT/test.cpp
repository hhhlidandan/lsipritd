#include<iostream>
#include<cstdlib>
using namespace std;
//��ȫ������
int count(int n)
{
	int ret = 0;
	if (n>0 && n <= 500000)
	{

		for (int i = 2; i <= n; i++)
		{
			//����������Լ��֮��
			int sum = 0;
			for (int j = 1; j<i; j++)
			{
				if (i%j == 0)
				{
					sum += j;

				}
			}

			//Լ��֮���Ƿ���ڱ���
			if (sum == i)
			{
				ret++;
			}
		}
		return ret;
	}
	return -1;

}
int main()
{
	int n;
	while (cin >> n)
	{
		cout << count(n) << endl;
	}
	system("pause");
	return 0;
}

//�˿��ƴ�С
#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
int main()
{
	string line;
	while (getline(cin, line))
	{
		if (line.find("joker JOKER") != -1)
		{
			cout << "joker JOKER" << endl;
		}
		else
		{
			string str = "3456789JQKA2jokerJOKER";
			int k = line.find('-');
			//������
			string str1 = line.substr(0, k);
			string str2 = line.substr(k + 1);
			//�Ƶĸ���
			int s1 = count(str1.begin(), str1.end(), ' ');
			int s2 = count(str2.begin(), str2.end(), ' ');
			//�õ�һ����
			string first1 = str1.substr(0, str1.find(' '));
			string first2 = str2.substr(0, str2.find(' '));
			if (s1 == s2)
			{
				if (str.find(first1)>str.find(first2)){
					cout << str1 << endl;
				}
				else
				{
					cout << str2 << endl;
				}
			}
			else
			{
				if (s1 == 3)
					cout << str1 << endl;
				else if (s2 == 3)
					cout << str2 << endl;
				else
					cout << "ERROR" << endl;
			}
		}
	}
}