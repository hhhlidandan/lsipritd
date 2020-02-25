//137. 只出现一次的数字 II
//给定一个非空整数数组，除了某个元素只出现一次以外，其余每个元素均出现了三次。找出那个只出现了一次的元素。
//说明：
//你的算法应该具有线性时间复杂度。 你可以不使用额外空间来实现吗？
//示例 1:
//输入 : [2, 2, 3, 2]
//输出 : 3
//	 示例 2 :
// 输入 : [0, 1, 0, 1, 0, 1, 99]
//  输出 : 99

//#include<iostream>
//using namespace std;
//class Solution {
//public:
//	int singleNumber(vector<int>& nums) {
//		if (nums.size() == 1)
//			return nums[0];
//
//		sort(nums.begin(), nums.end());
//		int count = 0;
//		for (size_t i = 0; i<nums.size() - 1; i++)
//		{
//			count++;
//			if (nums[i] != nums[i + 1] && count != 3)
//				return nums[i];
//			if (count == 3)
//				count = 0;
//		}
//		return nums[nums.size() - 1];
//	}
//};
