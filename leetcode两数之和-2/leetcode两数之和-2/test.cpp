#include<iostream>
using namespace std;

class Solution {
public:
	vector<int> twoSum(vector<int> &nums, int target) {
		vector<int> ret(2);
		int num(nums.size());
		for (int i = 0; i<num - 1; i++)
		{
			for (int j = i + 1; j<num; j++)
			{
				if (nums[i] + nums[j] == target)
				{
					ret[0] = i;
					ret[1] = j;
					return ret;
				}
			}
		}
		return ret;
	}
};

