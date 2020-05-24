//题目描述
//牛牛去犇犇老师家补课，出门的时候面向北方，但是现在他迷路了。虽然他手里有一张地图，但是他需要知道自己面向哪个方向，请你帮帮他。
//输入描述 :
//每个输入包含一个测试用例。
//每个测试用例的第一行包含一个正整数，表示转方向的次数N(N <= 1000)。
//接下来的一行包含一个长度为N的字符串，由L和R组成，L表示向左转，R表示向右转。
//输出描述 :
//输出牛牛最后面向的方向，N表示北，S表示南，E表示东，W表示西。
//示例1
//输入 3 LRR
//输出E
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