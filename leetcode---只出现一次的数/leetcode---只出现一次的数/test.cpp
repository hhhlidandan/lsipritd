//260. ֻ����һ�ε����� III
//����һ���������� nums������ǡ��������Ԫ��ֻ����һ�Σ���������Ԫ�ؾ��������Ρ� �ҳ�ֻ����һ�ε�������Ԫ�ء�
//ʾ�� :
//���� : [1, 2, 1, 3, 2, 5]
//��� : [3, 5]
//	 ע�⣺
//	 ��������˳�򲢲���Ҫ��������������ӣ�[5, 3] Ҳ����ȷ�𰸡�
//	 ����㷨Ӧ�þ�������ʱ�临�Ӷȡ����ܷ��ʹ�ó����ռ临�Ӷ���ʵ�֣�

#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

	vector<int> singleNumber(vector<int>& nums) {
		vector<int> result;
		//���Ԫ��һ���������Ҳ�ͬ�������ֱ�ӷ���
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
				//�ŵ�һ��ֻ����һ�ε�Ԫ��
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