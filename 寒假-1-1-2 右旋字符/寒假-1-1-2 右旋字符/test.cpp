//189. 旋转数组
//给定一个数组，将数组中的元素向右移动 k 个位置，其中 k 是非负数。
//
//示例 1:
//
//输入 : [1, 2, 3, 4, 5, 6, 7] 和 k = 3
//输出 : [5, 6, 7, 1, 2, 3, 4]
// 解释 :
//	向右旋转 1 步 : [7, 1, 2, 3, 4, 5, 6]
//	向右旋转 2 步 : [6, 7, 1, 2, 3, 4, 5]
//	向右旋转 3 步 : [5, 6, 7, 1, 2, 3, 4]
//示例 2 :
//
// 输入 : [-1, -100, 3, 99] 和 k = 2
//  输出 : [3, 99, -1, -100]
//   解释 :
//	  向右旋转 1 步 : [99, -1, -100, 3]
//	  向右旋转 2 步 : [3, 99, -1, -100]
//  说明 :
//
//	 尽可能想出更多的解决方案，至少有三种不同的方法可以解决这个问题。
//	 要求使用空间复杂度为 O(1) 的 原地 算法。
//#include<iostream>
//#include<vector>
//暴力法：超出时间限制
//class Solution {
//public:
//	void rotate(vector<int>& nums, int k) {
//		//右旋
//		//旋转的方法
//		//右旋
//		if (k >= nums.size())
//		{
//			k = k%nums.size();
//		}
//		while (k--)
//		{
//			int tmp = nums[nums.size() - 1];
//			//右旋一次
//			for (int i = nums.size() - 1; i>0; i--)
//			{
//				nums[i] = nums[i - 1];
//			}
//			nums[0] = tmp;
//		}
//	}
//};
////////////////////////////////
//逆置
class Solution {
public:
	void rotate(vector<int>& nums, int k) {
		if (k >= nums.size())
		{
			k = k%nums.size();
		}
		if (k != 0)
		{
			//逆置
			reserve(nums, 0, nums.size() - 1 - k);
			reserve(nums, nums.size() - k, nums.size() - 1);
			reserve(nums, 0, nums.size() - 1);
		}
	}
	//reserve
	void reserve(vector<int>& a, int start, int end)
	{
		while (start<end)
		{
			a[start] ^= a[end];
			a[end] ^= a[start];
			a[start] ^= a[end];
			start++, end--;
		}
	}
};