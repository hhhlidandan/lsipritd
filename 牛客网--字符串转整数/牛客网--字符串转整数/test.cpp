//把字符串转成整数
//题目描述
//将一个字符串转换成一个整数，要求不能使用字符串转换整数的库函数。 数值为0或者字符串不是一个合法的数值则返回0
//输入描述 :
//输入一个字符串, 包括数字字母符号, 可以为空
//输出描述 :
//如果是合法的数值表达则返回该数字，否则返回0
//示例1
//输入
//复制
//+ 2147483647
//1a33
//输出
//复制
//2147483647
//0

#include<iostream>
#include<string>

using namespace std;
	int ShortToInt(string str)
	{
		int num = 0;
		int flag = 1;
		//先把第一位出现的情况处理了
		//正常情况：+ - 或数字，其余返回0
		if (str[0] == '+')
			flag = 1;
		else if (str[0] == '-')
			flag = -1;
		else if (str[0] >= '0'&&str[0] <= '9')
			num = str[0] - '0';
		else return 0;
		//处理第二位及其后面
		for (size_t i = 1; i < str.size(); i++)
		{
			if (str[i] >= '0'&&str[i] <= '9')
				num = 10 * num + str[i] - '0';//
			else
				return 0;
		}
		//判断是否越界  
		//越界：大于最大的。小于最小的
		if (flag >=0 && num <= INT_MAX)
			return num;
		if (flag < 0)
		{
			num *= flag;
			if (num >= INT_MIN)
				return num;
		}
		return 0;
	}	
int main()
{
	string str;
	cin >> str;
	cout << ShortToInt(str) << endl;
	system("pause");
	return 0;
}
