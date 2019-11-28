#include<iostream>

using namespace std;
int Num(int month)
{
	int total = 1;
	int a = 1;
	int b = 1;
	for (int i = 3; i <= month; i++)
	{
		total = a + b;
		a = b;
		b = total;
	}
	return total;
}
int main()
{
	int month = 0;
	while (cin >> month)
	{
		cout << Num(month) << endl;
	}
	system("pause");
	return 0;
}