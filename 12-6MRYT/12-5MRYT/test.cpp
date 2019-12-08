#include<iostream>
using namespace std;
//三角形
int main()
{
	double a, b, c;
	while (cin >> a >> b >> c)
	{
		//任意两条边的和大于第三边
		//任意两条边的差小于第三边
		if ((a + b)>c && (a + c)>b && (b + c)>a\
			&& (a - b)<c && (a - c)<b && (b - c)<a)
			cout << "Yes" << endl;
		else{
			cout << "No" << endl;
		}
	}
	return 0;
}
//不用加减乘除做加法
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