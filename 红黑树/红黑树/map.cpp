#include<map>
#include<string>
#include<iostream>
using namespace std;
int main()
{
	///////////map/////////////////////////////////
	map<string, string> m;
	//构造
	m.insert(pair<string, string>("李","女"));//通过pair模板直接构造插入  //pair<>一对
	m.insert(make_pair("李", "男"));//插入一个已经存在的key，size不变
	m.insert(make_pair("闻", "男"));//通过全军函数构造，全军函数调pair的类
	m.insert(make_pair("冯", "雨"));

	//元素访问 通过下标运算符
	cout << m["闻"] << endl;//给key,将value返回
	cout << m.size() << endl;//3个
	for (auto it = m.begin(); it != m.end(); it++)
		cout << (*it).first << "----->" << it->second << endl;
	//如果[]中的key在map中不存在的情况下，map将<key,默认value>构成一个键值对插入到map中，返回默认value
	//cout << m["红"] << endl;//返回空的字符串
	//cout << m.size() << endl;

	//m.erase("闻");

	return 0;
}