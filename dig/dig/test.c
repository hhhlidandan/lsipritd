#define _CRT_SECURE_NO_WARNINGS
//3. дһ���ݹ麯��DigitSum(n)������һ���Ǹ����������������������֮�ͣ� 
//���磬����DigitSum(1729)����Ӧ�÷���1 + 7 + 2 + 9�����ĺ���19
//��λ /10 ��/10 %10
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