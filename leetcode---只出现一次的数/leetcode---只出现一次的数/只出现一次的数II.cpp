//137. ֻ����һ�ε����� II
//����һ���ǿ��������飬����ĳ��Ԫ��ֻ����һ�����⣬����ÿ��Ԫ�ؾ����������Ρ��ҳ��Ǹ�ֻ������һ�ε�Ԫ�ء�
//˵����
//����㷨Ӧ�þ�������ʱ�临�Ӷȡ� ����Բ�ʹ�ö���ռ���ʵ����
//ʾ�� 1:
//���� : [2, 2, 3, 2]
//��� : 3
//	 ʾ�� 2 :
// ���� : [0, 1, 0, 1, 0, 1, 99]
//  ��� : 99

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
