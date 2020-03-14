//#include<iostream>
//#include<string>
//#include<queue>
//using namespace std;
//int main()
//{
//	int n;
//	while (cin >> n)
//	{
//		int count = 0;
//		queue<char> num;
//		for (int i = 0; i<n; i++)
//		{
//			char name;
//			cin >> name;
//			string str;
//			cin >> str;
//			if (str == "connect")//入队列
//			{
//				num.push(name);
//			}
//			else
//			{
//				if (num.size()>count)
//					count = num.size();
//				else
//					count = count;
//				//count=num.size()>count?num.size():count;
//				num.pop();//出队列
//			}
//		}
//		cout << count << endl;
//	}
//	return 0;
//}