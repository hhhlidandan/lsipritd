#define _CRT_SECURE_NO_WARNINGS
//3. 写一个递归函数DigitSum(n)，输入一个非负整数，返回组成它的数字之和， 
//例如，调用DigitSum(1729)，则应该返回1 + 7 + 2 + 9，它的和是19
//个位 /10 百/10 %10
int digitsum(n)
{
	if (n == 0)
		return 0;
	else
		return n % 10 + digitsum(n / 10);
}
int main()
{
	int n = 0;
	int ret = 0;
	scanf("%d", &n);
	printf("%d",digitsum(n) );
	system("pause");
	return 0;
}