#include "test.h"

int main()
{
	//cout << sizeof(A) << endl;//4  ���Կ����������г�Ա�����ͷ���ʱ����С����Ա�����޹�
	//cout << sizeof(B) << endl;//1  ֻ�г�Ա������û�г�Ա����
	//cout << sizeof(C) << endl;//1  ����Ĵ�С��1��
	//���ռ0���ֽڣ��������Ķ������ͬһ��λ�ã���ì�ܣ����ԣ�ռ��һ���ֽڿ��������ഴ�����Ķ���
	cout << sizeof(A) << endl;//16
	cout << offsetof(A, _a) << endl;//  0
	cout << offsetof(A, _b) << endl;//8
	system("pause");
	return 0;
}