//��Ŀ����
//����һ���ַ���str������ַ���str�е�����������ִ�
//�������� :
//�������������1������������һ���ַ���str�����Ȳ�����255��
//������� :
//��һ�������str��������������ִ���
//ʾ��1
//����
//abcd12345ed125ss123456789
//���
//123456789
#include<iostream>
#include<iostream>
#include<string>
using namespace std;
int main()
{
	string str, mid, ret;
	cin >> str;
	for (int i = 0; i <= str.size(); i++)
	{
		if (str[i] >= '0'&&str[i] <= '9')
			mid += str[i];
		else
		{
			if (ret.size()<mid.size())
				ret = mid;
			else
				mid.clear();
		}
	}
	cout << ret << endl;
	return 0;
}