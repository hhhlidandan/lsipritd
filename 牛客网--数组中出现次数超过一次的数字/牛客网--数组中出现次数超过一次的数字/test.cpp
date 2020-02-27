//题目描述
//数组中有一个数字出现的次数超过数组长度的一半，请找出这个数字。
//例如输入一个长度为9的数组{ 1, 2, 3, 2, 2, 2, 5, 4, 2 }。
//由于数字2在数组中出现了5次，超过数组长度的一半，因此输出2。如果不存在则输出0。

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main()
{
		vector<int> numbers{ 1, 2, 3, 2, 2, 2, 5, 4, 2 };
		int size = numbers.size();
		int half = size >> 1;
		sort(numbers.begin(), numbers.end());
		int count = 0;
		for (size_t i = 0; i<size; i++)
		{
			count++;
			if (numbers[i] == numbers[i + 1])
				continue;
			if (count>half)
			{
				cout << numbers[i] << endl;
				return numbers[i];
			}	
			count = 0;
		}
		if ((numbers[size - 2] == numbers[size - 1]) && (count == half))
		{
			cout << numbers[size - 1] << endl;;
			return numbers[size - 1];
		}
		cout << '0'<< endl;
		return 0;
};

//牛客网测试代码
class Solution {
public:
	int MoreThanHalfNum_Solution(vector<int> numbers) {
		int size = numbers.size();
		int half = size >> 1;
		sort(numbers.begin(), numbers.end());
		int count = 0;
		for (size_t i = 0; i<size; i++)
		{
			count++;
			if (numbers[i] == numbers[i + 1])
				continue;
			if (count>half)
				return numbers[i];
			count = 0;
		}
		if ((numbers[size - 2] == numbers[size - 1]) && (count == half))
			return numbers[size - 1];
		return 0;
	}
};