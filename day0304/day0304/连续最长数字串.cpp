////字符串中找出连续最长的数字串
////读入一个字符串str，输出字符串str中的连续最长的数字串 
////输入描述： 个测试输入包含1个测试用例，一个字符串str，长度不超过255。
////输出描述： 在一行内输出str中里连续最长的数字串。
////示例1 : 输入 abcd12345ed125ss123456789 输出 123456789
//#include<iostream>
//#include<string>
//#include<stdlib.h>
//using namespace std;
//int main()
//{
//	string str;
//	cin >> str;
//	string ret, temp;
//	for (size_t i = 0; i <= str.size(); i++)
//	{
//		if (str[i] >= '0'&&str[i] <= '9')
//			temp += str[i];
//		else
//		{
//			if (temp.size()>ret.size())
//				ret = temp;
//			temp.clear();
//		}
//	}
//	cout << ret << endl;
//	system("pause");
//	return 0;
//}