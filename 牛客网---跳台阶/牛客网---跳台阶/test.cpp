class Solution {
public:
	int jumpFloor(int number) {
		int a = 0;
		int b = 1;
		int n = 1;
		for (int i = 1; i <= number; i++)
		{
			n = a + b;
			a = b;
			b = n;
		}
		return n;
	}
};