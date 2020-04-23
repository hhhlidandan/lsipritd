#include<iostream>
#include<vector>
#include<stdlib.h>
#include<algorithm>
using namespace std;
int main()
{
	int n = 0;
	cin >> n;
	vector<int> v(n*3);
	for (int i = 0; i < 3 * n; i++)
		cin >> v[i];

	int count = 0;
	sort(v.begin(), v.end());
	for (int i = n; i <= 3 * n - 2; i+=2)
		count += v[i];
	cout << count << endl;
	system("pause");
	return 0;
}