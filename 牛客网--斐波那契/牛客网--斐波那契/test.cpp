//��Ҷ�֪��쳲��������У�����Ҫ������һ������n���������쳲��������еĵ�n���0��ʼ����0��Ϊ0���� 
//n <= 39
class Solution {
public:
	int Fibonacci(int n) {
		if (n == 0)
			return 0;
		if (n == 1)
			return 1;
		int a = 1;
		int b = 1;
		int num = 1;
		for (int i = 2; i<n; i++)
		{
			num = a + b;
			a = b;
			b = num;
		}
		return num;
	}
};