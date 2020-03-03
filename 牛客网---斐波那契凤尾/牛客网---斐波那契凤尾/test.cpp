#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
	int fib[100000];
	fib[0] = 1;
	fib[1] = 1;
	for (int i = 2; i <= 100000; i++)
	{
		fib[i] = fib[i - 1] + fib[i - 2];
		fib[i] = fib[i] % 1000000;//ºóÁùÎ»
	}
	int n;
	while (cin >> n)
	{
		if (n<29)
			printf("%d\n", fib[n]);
		else
			printf("%06d\n", fib[n]);
	}
	return 0;
}