//��������
//int Add(int left, int right)
//{
//	return left + right;
//}
//double Add(double left, double right)
//{
//	return left + right;
//}


//����������
//short Add(short left, short right)
//{
//	return left + right;
//}
//short Add(int left, int right)
//{
//	return left + right;
//}

//extern C
//extern "C" int Add(double left, double right);//����C���Թ���������
//int main()
//{
//	Add(1, 2);
//	return 0;
//}

//����
//void TestRef()
//{
//	int a = 10;//���ö���ʱ�����ʼ��
//	int& b = a;
//	int& c = b;//һ�����������ж������
//
//	printf("%d\n", a);//10
//	printf("%d\n", b);//10
//	printf("%d\n", c);//10
//
//	int d = 20;
//	c = d;//��d����c����ֵ��������������Ŷ��
//	printf("%d\n", a);//20
//	printf("%d\n", b);//20
//	printf("%d\n", c);//20
//}

//������
//void ConstTestRef()
//{
//	const int a = 10;
//	//int& b = a;  �����b��a�ı�����û���޸�a��Ȩ��
//	const int& b = a;
//}

//void ConstTestRef()
//{
//	int a = 10;//�������ǿ����޸ĵ�
//	const int& b = a;//ֻ�������ܸ�Ŷ
//}


//ʹ�ó���
//������
//void Swap(int& left, int& right)// left,right�ֱ�Ϊa,b �ı���
//{
//	int temp = left;
//	left = right;
//	right = temp;
//}
//int main()
//{
//	int a = 1;
//	int b = 2;
//	Swap(a, b);
//	return 0;
//}

//��C���Ե�swap�����Ա�һ��
//void Swap(int* left, int* right)//��ָ�����
//{
//	int temp = *left;
//	*left = *right;
//	*right = temp;
//}
//int main()
//{
//	int a = 1;
//	int b = 2;
//	Swap(&a, &b);//����ַ
//	return 0;
//}

//������ֵ

//int TestRefReturn(int& a)//����������� int a ,��a�Ǿֲ����������������÷���
//{
//	a += 10;
//	return a;//���÷���
//}
//int main()
//{
//	int x = 10;
//	int y = TestRefReturn(x);
//	return 0;
//}
