//ÄæÖÃ×Ö·û´®
#include<iostream>
#include<algorithm>
#include<string>
using namespace std;

int main()
{
	string s = "";
	system("pause");
	return 0;
}


//#include<iostream>
//#include<vector>
//using namespace std;
//
////6
////1 2 3 2 2 1
////2
//int main()
//{
//	int n = 0;
//
//	while (1)
//	{
//		cin >> n;
//		vector<int> a;
//
//		a.resize(n+1);
//		//a[n] = 0;
//		//ÊäÈëÊı¾İ
//		int i = 0;
//		for (; i<n; i++)
//		{
//			cin >> a[i];
//		}
//
//		int count = 0;
//		i = 0;
//		while (i<n)
//		{
//			if (a[i] < a[i + 1])
//			{
//				while (i<n && a[i] <= a[i + 1])
//				{
//					i++;
//				}
//				i++;
//				count++;
//			}
//			else if(a[i] > a[i + 1])
//			{
//				while (i<n && a[i] >= a[i + 1])
//				{
//					i++;
//				}
//				i++;
//				count++;
//			}
//			else
//			{
//				i++;
//			}
//		}
//		cout << count << endl;
//		break;
//	}
//	system("pause");
//	return 0;
//}