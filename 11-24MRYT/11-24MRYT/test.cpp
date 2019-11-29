////杨辉三角的变形
////->求第n行第1个偶数出现的位置
//
//#include<iostream>
//#include<vector>
//using namespace std;
////求第n行第一个偶数出现的位置
//int main()
//{
//	int n,m;
//	while (cin >> n)
//	{
//		m = 2 * n - 1;//每行的元素
//		//创建一个二维数组
//		vector < vector<int>> a(n, vector<int>(m, 0));
//		a[0][0] = 1;
//		for (int i = 1; i < n; i++)
//		{
//			a[i][0] = a[i][i] = 1;
//			for (int j = 1; j < i; j++)
//			{
//				//如果是第二列，就是两个元素之和
//				if (j == 1)
//				{
//					a[i][j] = a[i - 1][j - 1] + a[i - 1][j];
//				}
//				else
//				{//其它是上一行三列元素之和 j,j-1,j-2
//					a[i][j] = a[i - 1][j] + a[i - 1][j - 1] + a[i - 1][j - 2];
//				}
//			}
//		}
//		///////////////////////////////
//		//1          i=0
//		//1 1 1      i=1
//		//1 2 3 2 1  i=2   
//		//1 3 6 7 6 3 1
//
//		//行 n;
//		//多少个元素：2*n-1
//		int k = 0;
//		if (n <= 2)
//		{
//			cout << -1 << endl;
//		}
//		for (k = 0; k < m; k++)
//		{
//			if (a[n - 1][k] % 2 == 0 && a[n - 1][k] != 0)
//			{
//				cout << k + 1 << endl;
//				break;
//			}
//		}
//	}
//	system("pause");
//	return 0;
//}

//超长正整数相加