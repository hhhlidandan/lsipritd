#include<iostream>
#include<string>
using namespace std;
int main()
{
	//string s1;//构造空字符串
	//string s2("hello");//构造string类对象s2
	//string s3(10, 'a');//string类对象上s3中包含10个a
	//string s4(s2, 2);//从s3中的第2个字符开始构造新的string类对象s4
	//string s5(s2, 2, 2);//从s2中的第2个位置开始找2个
	//cout << "s1:" << s1 << endl;//（空的）
	//cout << "s2:" << s2 << endl;//hello
	//cout << "s3:" << s3 << endl;//aaaaaaaaaa
	//cout << "s4:" << s4 << endl;//llo
	//cout << "s5:" << s5 << endl;//ll

	//string s2("hello world!");//构造string类对象s2
	//cout << "s2:" << s2 << endl;
	//cout << s2.size() << endl;
	//cout << s2.length() << endl;
	//cout << s2.capacity() << endl;
	//s2.clear();//清空有效字符
	//cout << s2.size() << endl; // 0
	//cout << s2.length() << endl;//0
	//cout << s2.capacity() << endl;//15
	//s2.resize(10, 'a');//将有效字符个数改成10个，多出的空间用a填充
	//cout << s2 << endl;
	//s2.reserve(100);
	//cout << s2.size() << endl; // 
	//cout << s2.length() << endl;//
	//cout << s2.capacity() << endl;
	//cout << s2 << endl;
	//s2.resize(15);//将有效字符个数改成10个，多出的空间用0填充
	//cout << s2 << endl;


	string str;
	str.append("hello");//追加字符串"hello"
	str += ' ';//追加字符' '
	str += 'w';//追加字符'w'
	str += "orld";//追加字符串"orld"
	cout << str << endl;

	string file("hello.cpp");
	size_t pos = file.rfind('.');//获取file的后缀
	string sre1=file.substr(pos, file.size() - pos);
	cout << sre1 << endl;//.cpp

	string url("htp://www.cplusplus.com/reference/string/string/find/");
	cout << url << endl;
	size_t poss = url.find("://");
	size_t start = poss + 3;
	size_t end = url.find('/', start);
	string strr = url.substr(start, end-start);//从pos的位置开始，截取start-end个字符
	cout << strr << endl;//www.cplusplus.com

	system("pause");
	return 0;
}