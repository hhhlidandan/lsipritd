#include<map>
#include<string>
#include<iostream>
using namespace std;
int main()
{
	///////////map/////////////////////////////////
	map<string, string> m;
	//����
	m.insert(pair<string, string>("��","Ů"));//ͨ��pairģ��ֱ�ӹ������  //pair<>һ��
	m.insert(make_pair("��", "��"));//����һ���Ѿ����ڵ�key��size����
	m.insert(make_pair("��", "��"));//ͨ��ȫ���������죬ȫ��������pair����
	m.insert(make_pair("��", "��"));

	//Ԫ�ط��� ͨ���±������
	cout << m["��"] << endl;//��key,��value����
	cout << m.size() << endl;//3��
	for (auto it = m.begin(); it != m.end(); it++)
		cout << (*it).first << "----->" << it->second << endl;
	//���[]�е�key��map�в����ڵ�����£�map��<key,Ĭ��value>����һ����ֵ�Բ��뵽map�У�����Ĭ��value
	//cout << m["��"] << endl;//���ؿյ��ַ���
	//cout << m.size() << endl;

	//m.erase("��");

	return 0;
}