//��Դ��ţ����
//���깫˾���Ľ�Ʒ�ر���������񽱵Ĺ��ȴ�����⣺
//1. ���ȣ�������Ա����һ��д���Լ����ֵ���������齱���У�
//2. ����������������ϣ�ÿ�˴�����ȡһ��������
//3. ����鵽��������д�ľ����Լ������֣���ô����ϲ�㣬�н��ˣ���
//���ڸ�����μ�������������������ж��ٸ��ʻ�������˻񽱣�
//�������� :
//��������������ݣ�ÿ�����ݰ���һ��������n��2��n��20����
//������� :
//��Ӧÿһ�����ݣ��ԡ�xx.xx%���ĸ�ʽ����������˻񽱵ĸ��ʡ�
//ʾ��1
//����
//2
//���
//50.00%
// write your code here cpp
#include<iostream>
#include<iomanip>
using namespace std;
double count(double n)
{
	if (n == 1)
		return 0;
	if (n == 2)
		return 1;
	return (n - 1)*(count(n - 1) + count(n - 2));
}
int main()
{
	double n;
	while (cin >> n)
	{
		double x = count(n);
		double num = 1;
		for (size_t i = 1; i <= n; i++)
			num *= i;
		x = x / num * 100;
		cout << setprecision(2) << fixed << x << '%' << endl;//setprecision(2) ��fixed����ʹ�ã�С�����ұߵĸ���Ϊ����
	}
	return 0;
}