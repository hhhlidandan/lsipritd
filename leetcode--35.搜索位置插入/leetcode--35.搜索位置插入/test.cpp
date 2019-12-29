//����һ�����������һ��Ŀ��ֵ�����������ҵ�Ŀ��ֵ�������������������Ŀ��ֵ�������������У����������ᱻ��˳������λ�á�
//
//����Լ������������ظ�Ԫ�ء�
//
//ʾ�� 1:
//
//���� : [1, 3, 5, 6], 5
//��� : 2
//
//
//	 ʾ�� 2 :
//
// ���� : [1, 3, 5, 6], 2
//  ��� : 1
//
//
//	   ʾ�� 3 :
//
//   ���� : [1, 3, 5, 6], 7
//	��� : 4
//
//
//		 ʾ�� 4 :
//
//	 ���� : [1, 3, 5, 6], 0
//	  ��� : 0

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
		//������˵��û�����������ҵ�������С�������м�
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