#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
//给定一个非空整数数组，除了某个元素只出现一次以外，其余每个元素均出现两次。找出那个只出现了一次的元素。
//说明：
//你的算法应该具有线性时间复杂度。 你可以不使用额外空间来实现吗？
//示例 1:
//输入 : [2, 2, 1]
//输出 : 1
//	 示例 2 :
// 输入 : [4, 1, 2, 1, 2]
//  输出 : 4
//来源：力扣（LeetCode）
//int singleNumber(vector<int>& nums)
//{
//	int n = 0;
//	for (int i = 0; i < nums.size(); i++)
//		n ^= nums[i];
//	return n;
//}

//方法2
//int singleNumber1(vector<int>& nums)
//{
//	if (nums.size() == 1)
//		return nums[0];
//
//	sort(nums.begin(), nums.end());
//	int count = 0;
//	for (size_t i = 0; i < nums.size()-1; i++)
//	{
//		count++;
//		if (nums[i] != nums[i + 1]&&count!=2)
//			return nums[i];
//		if (count == 2)
//			count = 0;	
//	}
//	return nums[nums.size() - 1];
//}

//int main()
//{
//	vector<int> s{ 1, 1, 2, 2, 3 };
//	cout << singleNumber1(s) << endl;
//	system("pause");
//	return 0;
//}