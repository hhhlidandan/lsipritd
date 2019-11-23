#include<iostream>
#include<string>
#include<vector>
using namespace std;

//两种排序方法

bool Is_dic(vector<string> &mystr)
{
	for (int i = 0; i < mystr.size() - 1; i++)
	{
		if (mystr[i]>mystr[i + 1])
			return false;
	}
	return true;
}
bool Is_len(vector<string> &mystr)
{
	
	for (int i = 0; i < mystr.size() - 1; i++)
	{
		if (mystr[i].size()>mystr[i + 1].size())
			return false;
	}
	return true;
}

int main()
{
	int n;
	cin >> n;
	cin.get();
	vector<string> mystr(n);
	int i = 0;
	for (i = 0; i < n; i++){
		getline(cin, mystr[i]);
	}

	if (Is_dic(mystr) && Is_len(mystr)){
		cout << "both" << endl;
	}
	else if (Is_dic(mystr)){
		cout << "lexicographically" << endl;
	}
	else if (Is_len(mystr)){
		cout << "lengths" << endl;
	}
	else{
		cout << "none" << endl;
	}
	system("pause");
	return 0;
}
//最小公倍数
//最小公倍数=两个整数乘积/最大公约数
//最大公约数： 辗转相除法
//
//int main()
//{
//	int a, b;
//	cin >> a >> b;
//	if (a>b)
//	{
//		if (a%b == 0)
//			cout << a << endl;
//		else
//			cout << a*b << endl;
//	}
//	else if (b>a)
//	{
//		if (b%a == 0)
//			cout << b << endl;
//		else
//			cout << a*b << endl;
//	}
//	else
//	{
//		cout << a << endl;
//	}
//	system("pause");
//	return 0;
//}


//int bignum(int a, int b)
//{
//	int c;
//	while (c != 0)
//	{
//		c = a%b;
//		a = b;
//		b = c;
//	}
//	return a;
//}
//int main()
//{
//	int a, b;
//	cin >> a >> b;
//	int ret = bignum(a, b);
//	cout << a*b / ret << endl;
//	return 0;
//}