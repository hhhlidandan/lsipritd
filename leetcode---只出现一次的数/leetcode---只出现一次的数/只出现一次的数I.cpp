#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
//����һ���ǿ��������飬����ĳ��Ԫ��ֻ����һ�����⣬����ÿ��Ԫ�ؾ��������Ρ��ҳ��Ǹ�ֻ������һ�ε�Ԫ�ء�
//˵����
//����㷨Ӧ�þ�������ʱ�临�Ӷȡ� ����Բ�ʹ�ö���ռ���ʵ����
//ʾ�� 1:
//���� : [2, 2, 1]
//��� : 1
//	 ʾ�� 2 :
// ���� : [4, 1, 2, 1, 2]
//  ��� : 4
//��Դ�����ۣ�LeetCode��
//int singleNumber(vector<int>& nums)
//{
//	int n = 0;
//	for (int i = 0; i < nums.size(); i++)
//		n ^= nums[i];
//	return n;
//}

//����2
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