//��Ŀ����
//��������һ�����ֳ��ֵĴ����������鳤�ȵ�һ�룬���ҳ�������֡�
//��������һ������Ϊ9������{ 1, 2, 3, 2, 2, 2, 5, 4, 2 }��
//��������2�������г�����5�Σ��������鳤�ȵ�һ�룬������2����������������0��

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

//ţ�������Դ���
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