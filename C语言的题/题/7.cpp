////#include<stdio.h>
//#include<stdlib.h>
//#include<iostream>
//#include<vector>
//#include<algorithm>
//using namespace std;
//int main()
//{
//	int n;
//	cout << "输入元素个数：";
//	cin >> n;
//	vector<int> arr(n);
//	int i = 0;
//	int count = 0;
//	cout << "输入元素：";
//	while (n--)
//	{
//		cin >> arr[i];
//		count += arr[i];
//		i++;
//	}
//	int size = arr.size();
//	cout << "平均数" << count / size << endl;
//	sort(arr.begin(), arr.end());
//	if (size % 2 == 0)//偶数
//		cout << "中位数" << (arr[size / 2] + arr[size / 2 - 1]) / 2 << endl;
//	else//奇数
//		cout << "中位数" << arr[size / 2] << endl;	
//	system("pause");
//	return 0;
//}