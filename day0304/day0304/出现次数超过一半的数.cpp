//2. ���⣺n��������ִ������ڵ���n / 2����
//����n��������������ִ������ڵ������鳤��һ������� 
//���������� ÿ������������� n���ո�ָ��n��������n������100��������һ���������ִ������ڵ���n / 2��
//��������� ������ִ������ڵ���n / 2������ ʾ��1 : ���� 3 9 3 2 5 6 7 3 2 3 3 3 ��� 3
#include<iostream>
#include<stdlib.h>
#include<vector>
#include<algorithm>
using namespace std;
int main()
{
	int n;
	vector<int> array;
	while (cin >> n)
		array.push_back(n);
	sort(array.begin(), array.end());
	cout << array[array.size() / 2 - 1] << endl;
	system("pause");
	return 0;
}