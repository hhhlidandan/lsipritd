#include<iostream>
#include<stdlib.h>
using namespace std;
//쳲�������
//��һ����N����������Ҫ���ٲ����Ա��쳲�������
//
//int main()
//{
//	int n;
//	int num = 0;
//	int a = 0, b = 1, c = 1;
//	cin >> n;
//	if (n <= 2)
//	{
//		num = 0;
//	}
//	else
//	{
//		while (c < n)
//		{
//			c = a + b;
//			num = b;
//			a = b;
//			b = c;
//		}
//		num = (n - num) >(c - n) ? (c - n) : (n - num);
//		cout << num << endl;
//	}
//	system("pause");
//	return 0;
//}

//�Ϸ����������ж�
class Parenthesis {
public:
	bool chkParenthesis(string A, int n) {
		int count = 0;
		if (A.size() % 2 != 0)
			return false;
		else{
			int i = 0;
			for (; i<A.size(); i++)
			{
				if (A[i] != '('&&A[i] != ')')
					return false;
				else{
					if (A[i] == '(')
						count++;
					else if (A[i] == ')')
						count--;
				}
			}
			if (count == 0)
				return true;
		}
		// write code here
	}
};