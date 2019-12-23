class Solution {
public:
	int reverse(int x) {
		//vector<int> a;
		int num = 0;
		if (x>0)
			num = x;
		else
			num = (-1)*x;

		int k;
		while (num)
		{
			k = num % 10;
			num = num / 10;
			num = num * 10 + k;
		}
		if (x>0)
			return (-1)*num;
		else
			return num;
	}
};