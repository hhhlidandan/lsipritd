//namespace N1
//{
//	int a;//�������
//	int Add(int left, int right)//���庯��
//	{
//		return left + right;
//	}
//	namespace N2 //�������ռ�N1�Ƕ���������ռ�N2
//	{
//		int b;
//		int Sub(int left, int right)
//		{
//			return left - right;
//		}
//	}
//}
//namespace N1 // ��ͬ���Ƶ������ռ�N1������������ϳ�ͬһ�������ռ���
//{
//	int Mul(int left, int right)
//	{
//		return left*right;
//	}
//}
//
//
//int main()
//{
//	printf("%d\n", N::a);//�����ռ�ΪN
//	return 0;
//}
//
////2.��using�������ռ��г�Ա����
//
//using N::b;//˵��b�������ռ�N��ĳ�Ա
//int main()
//{
//	printf("%d\n", b);
//}
//
////3.ʹ��using namespace�����ռ���������
//
//using namespace N;//�����Ȱѿռ�����ʡ��
//int main()
//{
//	printf("%d\n", b);
//}

//C++����&���

//cin
//cout << "hello world" << endl;//���hello world
//cout << "hello world\n";

//cout
//cin >> a;//���a
//cin >> b >> c;//���b c

//#include<iostream>
//using namespace std;
//int main()
//{
//	int a;//����
//	double b;//˫���ȸ�����
//	char c;//�ַ���
//
//	cin >> a;
//	cin >> b >> c;
//
//	cout << a << endl;
//	cout << b << " " << c << endl;
//	return 0;
//}


//ȱʡ����
//void TestFunc(int a = 10, int b = 20, int c = 30)//���в������в���ֵ
//{
//	cout << "a= " << a << endl;
//	cout << "b= " << b << endl;
//	cout << "c= " << c << endl;
//}
//int main()
//{
//	TestFunc();//û�д���ʱ��ʹ��Ĭ�ϵĲ���ֵ
//	//����ʱ��ʹ��ָ���Ĳ��� 
//	TestFunc(1);// a=1,b=20,c=30
//	TestFunc(1, 2);//a=10,b=2,c=30
//	TestFunc(1, 2, 3);//a=1,b=2,c=3
//	return 0;
//}

//��ȱʡ����
//void TestFunc(int a, int b = 20, int c = 30)
//{
//	cout << "a= " << a << endl;
//	cout << "b= " << b << endl;
//	cout << "c= " << c << endl;
//}
//int main()
//{
//	//���ٴ�һ������
//	TestFunc(1);// a=1,b=20,c=30
//	TestFunc(1, 2);//a=10,b=2,c=30
//	TestFunc(1, 2, 3);//a=1,b=2,c=3
//	return 0;
//}
