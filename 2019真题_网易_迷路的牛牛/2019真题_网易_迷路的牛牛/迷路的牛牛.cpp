//��Ŀ����
//ţţȥ�Ġ���ʦ�Ҳ��Σ����ŵ�ʱ�����򱱷���������������·�ˡ���Ȼ��������һ�ŵ�ͼ����������Ҫ֪���Լ������ĸ���������������
//�������� :
//ÿ���������һ������������
//ÿ�����������ĵ�һ�а���һ������������ʾת����Ĵ���N(N <= 1000)��
//��������һ�а���һ������ΪN���ַ�������L��R��ɣ�L��ʾ����ת��R��ʾ����ת��
//������� :
//���ţţ�������ķ���N��ʾ����S��ʾ�ϣ�E��ʾ����W��ʾ����
//ʾ��1
//���� 3 LRR
//���E
#include<iostream>
#include<string>
using namespace std;
int main()
{
	int n = 0;
	string str;
	cin >> n >> str;
	int count = 0;
	for (int i = 0; i<n; i++)
	{
		if (str[i] == 'L')	count--;
		else	count++;
	}
	count %= 4;
	switch (count)
	{
	case -4:
	case 0:
		cout << 'N' << endl;
		break;
	case -3:
	case 1:
		cout << 'E' << endl;
		break;
	case -2:
	case 2:
		cout << 'S' << endl;
		break;
	case -1:
	case 3:
		cout << 'W' << endl;
		break;
	}
	return 0;
}