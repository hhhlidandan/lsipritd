#include<iostream>
using namespace std;
//������
int main()
{
	double a, b, c;
	while (cin >> a >> b >> c)
	{
		//���������ߵĺʹ��ڵ�����
		//���������ߵĲ�С�ڵ�����
		if ((a + b)>c && (a + c)>b && (b + c)>a\
			&& (a - b)<c && (a - c)<b && (b - c)<a)
			cout << "Yes" << endl;
		else{
			cout << "No" << endl;
		}
	}
	return 0;
}
//���üӼ��˳����ӷ�
class Solution {
public:
	int Add(int num1, int num2)
	{
		if (num1 == 0)
			return num2;
		else if (num2 == 0)
			return num1;
		else
		{
			int n, s;
			do
			{
				n = num1^num2;
				s = (num1&num2) << 1;
				num2 = n;
				num1 = s;
			} while (s != 0);
			return n;
		}
	}
};