////��Դ��ţ����
////NowCoderÿ��Ҫ��������ʼ����������������ռ����б��У���ʱ��ֻ�Ǳ����͡�����Ϊ��Щ���͵��ʼ���Ҫ�Ա��Լ����ռ����б�����ʼ��ͣ������Ҫ���˵���Щ��Ҫ���ʼ������ȴ�����Ҫ���ʼ���
////���ڸ���һ�������б������ж�Ŀ���û��Ƿ��ڳ����б��С�
////�������� :
////�����ж������ݣ�ÿ�����������С�
//
////��һ�г����б�����֮����һ�����Ÿ�������������а����ո�򶺺ţ�������������˫������ܳ��Ȳ�����512���ַ���
////�ڶ���ֻ����һ���������Ǵ����ҵ��û������֣�����Ҫ��ȫƥ�䣩�����Ȳ�����16���ַ���
//
////������� :
////����ڶ��е����ֳ������ռ����б��У��������Ignore������ʾ����ʼ�����Ҫ�����������Important!������ʾ����ʼ���Ҫ�����ȴ���
////ʾ��1
////����
////Joe, Kewell, Leon
////Joe
////"Letendre, Bruce", Joe, "Quan, William"
////William
////���
////Ignore
////Important!
//
// write your code here cpp
#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
using namespace std;
int main()
{
	string str;
	while (getline(cin, str))
	{
		vector<string> num;//�ѳ���"" ,֮����ַ��ŵ������У�Ȼ���ж��Ƿ����
		int pos = 0;
		while (pos<str.length())
		{
			if (str[pos] == '\"')
			{
				int end = str.find('\"', pos + 1);
				num.push_back(str.substr(pos + 1, end - pos - 1));
				pos = end + 2;//���� " ,
			}
			else
			{
				int end = str.find(',', pos);
				if (end == str.npos)
				{
					num.push_back(str.substr(pos, str.size()));
					break;
				}
				num.push_back(str.substr(pos, end - pos));
				pos = end + 1;
			}
		}
		getline(cin, str);
		if (num.end() == find(num.begin(), num.end(), str))
			cout << "Important!" << endl;
		else
			cout << "Ignore" << endl;
	}
	return 0;
}