#include<iostream>
#include<stdlib.h>
#include<vector>
using namespace std;

class Solution {
public:
	int minNumberInRotateArray(vector<int> rotateArray) {
		//�ǵݼ������� ����������󲻱䣩 �ȼ����������䣩 ����ͬ
		if (rotateArray.size() == 0)
			return 0;
		int min = rotateArray[0];
		for (int i = 1; i<rotateArray.size(); i++)
		{
			if (rotateArray[i]<rotateArray[i - 1])
				min = rotateArray[i];
			else continue;
		}
		return min;
	}
};
int main()
{
	system("pause");
	return 0;
}