//260. 只出现一次的数字 III
//给定一个整数数组 nums，其中恰好有两个元素只出现一次，其余所有元素均出现两次。 找出只出现一次的那两个元素。
//示例 :
//输入 : [1, 2, 1, 3, 2, 5]
//输出 : [3, 5]
//	 注意：
//	 结果输出的顺序并不重要，对于上面的例子，[5, 3] 也是正确答案。
//	 你的算法应该具有线性时间复杂度。你能否仅使用常数空间复杂度来实现？

#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

	vector<int> singleNumber(vector<int>& nums) {
		vector<int> result;
		//如果元素一共两个并且不同，插入后直接返回
		if (nums.size() == 2 && nums[0] != nums[1])
		{
			result.push_back(nums[0]);
			result.push_back(nums[1]);
			return result;
		}
		sort(nums.begin(), nums.end());
		int count = 0;
		for (size_t i = 0; i<nums.size() - 1; i++)
		{
			count++;
			if (result.size() == 2)
				return result;
			if (nums[i] != nums[i + 1] && count != 2)
			{
				//放第一个只出现一次的元素
				result.push_back(nums[i]);
				count = 0;
				continue;
			}
			if (count == 2)
				count = 0;
		}
		result.push_back(nums[nums.size() - 1]);
		return result;
	}
int main()
{
	int array[] = { 1, 2, 1, 3, 2, 5 };
	vector<int> nums(array, array + sizeof(array) / sizeof(array[0]));
	singleNumber(nums);
	auto it = nums.begin();
	while (it != nums.end())
	{
		cout <<*it << " ";
		it++;
	}
	cout << endl;
	system("pause");
	return 0;
}