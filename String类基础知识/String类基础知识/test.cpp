#include<iostream>
#include<string>
using namespace std;
int main()
{
	//string s1;//������ַ���
	//string s2("hello");//����string�����s2
	//string s3(10, 'a');//string�������s3�а���10��a
	//string s4(s2, 2);//��s3�еĵ�2���ַ���ʼ�����µ�string�����s4
	//string s5(s2, 2, 2);//��s2�еĵ�2��λ�ÿ�ʼ��2��
	//cout << "s1:" << s1 << endl;//���յģ�
	//cout << "s2:" << s2 << endl;//hello
	//cout << "s3:" << s3 << endl;//aaaaaaaaaa
	//cout << "s4:" << s4 << endl;//llo
	//cout << "s5:" << s5 << endl;//ll

	//string s2("hello world!");//����string�����s2
	//cout << "s2:" << s2 << endl;
	//cout << s2.size() << endl;
	//cout << s2.length() << endl;
	//cout << s2.capacity() << endl;
	//s2.clear();//�����Ч�ַ�
	//cout << s2.size() << endl; // 0
	//cout << s2.length() << endl;//0
	//cout << s2.capacity() << endl;//15
	//s2.resize(10, 'a');//����Ч�ַ������ĳ�10��������Ŀռ���a���
	//cout << s2 << endl;
	//s2.reserve(100);
	//cout << s2.size() << endl; // 
	//cout << s2.length() << endl;//
	//cout << s2.capacity() << endl;
	//cout << s2 << endl;
	//s2.resize(15);//����Ч�ַ������ĳ�10��������Ŀռ���0���
	//cout << s2 << endl;


	string str;
	str.append("hello");//׷���ַ���"hello"
	str += ' ';//׷���ַ�' '
	str += 'w';//׷���ַ�'w'
	str += "orld";//׷���ַ���"orld"
	cout << str << endl;

	string file("hello.cpp");
	size_t pos = file.rfind('.');//��ȡfile�ĺ�׺
	string sre1=file.substr(pos, file.size() - pos);
	cout << sre1 << endl;//.cpp

	string url("htp://www.cplusplus.com/reference/string/string/find/");
	cout << url << endl;
	size_t poss = url.find("://");
	size_t start = poss + 3;
	size_t end = url.find('/', start);
	string strr = url.substr(start, end-start);//��pos��λ�ÿ�ʼ����ȡstart-end���ַ�
	cout << strr << endl;//www.cplusplus.com

	system("pause");
	return 0;
}