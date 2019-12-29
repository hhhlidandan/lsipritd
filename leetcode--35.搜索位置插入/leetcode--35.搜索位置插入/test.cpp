//给定一个排序数组和一个目标值，在数组中找到目标值，并返回其索引。如果目标值不存在于数组中，返回它将会被按顺序插入的位置。
//
//你可以假设数组中无重复元素。
//
//示例 1:
//
//输入 : [1, 3, 5, 6], 5
//输出 : 2
//
//
//	 示例 2 :
//
// 输入 : [1, 3, 5, 6], 2
//  输出 : 1
//
//
//	   示例 3 :
//
//   输入 : [1, 3, 5, 6], 7
//	输出 : 4
//
//
//		 示例 4 :
//
//	 输入 : [1, 3, 5, 6], 0
//	  输出 : 0

class Solution {
public:
	int searchInsert(vector<int>& nums, int target) {
		if (target<nums[0])
			return 0;
		if (target>nums[nums.size() - 1])
			return nums.size();

		int left = 0;
		int right = nums.size() - 1;
		int mid;
		while (left <= right)
		{
			mid = left + (right - left) / 2;
			if (target<nums[mid])
				right = mid - 1;
			else if (target>nums[mid])
				left = mid + 1;
			else if (target == nums[mid])
				return mid;
		}
		//到这里说明没有在数组里找到，但大小在数组中间
		if (target<nums[mid])
		{
			while (mid >= 0)
			{
				if (target>nums[mid])
					return mid + 1;
				mid--;
			}
		}
		else if (target>nums[mid])
		{
			while (mid<nums.size())
			{
				if (target<nums[mid])
					return mid;
				mid++;
			}
		}
		return mid;
	}
};