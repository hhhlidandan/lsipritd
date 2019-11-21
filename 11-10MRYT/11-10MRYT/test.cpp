#include<iostream>
#include<vector>
#pragma warning(disable:4996)
using namespace std;

//连续最大和

int main()
{
	int size;
	int ret = 0;
	cin >> size;
	vector<int> a(size);
	int i = 0;
	for (; i < size; i++)
	{
		cin >> a[i];
	}
	int max = a[0];
	int sum1 = 0;
	int sum2 = 0;

	for (size_t i = 0; i < a.size(); i++)
	{
		sum1 = sum2 >= 0 ? sum1 + a[i] : a[i];
		if (sum2>max)
			max = sum2;
		if (sum2 < 0)
			sum2 = 0;
		sum1 = sum2;
	}
	cout << max << endl;
	system("pause");
	return 0;
}




////统计回文
//bool IsHuiWen(string a)
//{
//	int length = a.length();
//	int i = 0;
//	for (; i < length; i++)
//	{
//		if (a[i] != a[length - 1])
//		{
//			return false;
//		}
//		length=length-1;
//	}
//	return true;
//}
//int main()
//{
//	string a, b;
//	int len = 0;
//	int i = 0;
//	int count = 0;
//	while (cin >> a >> b)
//	{
//		len = a.length() + 1;
//		a.insert(i, b);
//		for (; i < len; i++)
//		{	
//			if (IsHuiWen(a))
//			{
//				count++;
//			}
//		}
//		cout << count << endl;
//	}
//	return 0;
//}