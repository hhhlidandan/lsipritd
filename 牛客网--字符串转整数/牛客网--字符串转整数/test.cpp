//���ַ���ת������
//��Ŀ����
//��һ���ַ���ת����һ��������Ҫ����ʹ���ַ���ת�������Ŀ⺯���� ��ֵΪ0�����ַ�������һ���Ϸ�����ֵ�򷵻�0
//�������� :
//����һ���ַ���, ����������ĸ����, ����Ϊ��
//������� :
//����ǺϷ�����ֵ����򷵻ظ����֣����򷵻�0
//ʾ��1
//����
//����
//+ 2147483647
//1a33
//���
//����
//2147483647
//0

#include<iostream>
#include<string>

using namespace std;
	int ShortToInt(string str)
	{
		int num = 0;
		int flag = 1;
		//�Ȱѵ�һλ���ֵ����������
		//���������+ - �����֣����෵��0
		if (str[0] == '+')
			flag = 1;
		else if (str[0] == '-')
			flag = -1;
		else if (str[0] >= '0'&&str[0] <= '9')
			num = str[0] - '0';
		else return 0;
		//����ڶ�λ�������
		for (size_t i = 1; i < str.size(); i++)
		{
			if (str[i] >= '0'&&str[i] <= '9')
				num = 10 * num + str[i] - '0';//
			else
				return 0;
		}
		//�ж��Ƿ�Խ��  
		//Խ�磺�������ġ�С����С��
		if (flag >=0 && num <= INT_MAX)
			return num;
		if (flag < 0)
		{
			num *= flag;
			if (num >= INT_MIN)
				return num;
		}
		return 0;
	}	
int main()
{
	string str;
	cin >> str;
	cout << ShortToInt(str) << endl;
	system("pause");
	return 0;
}
