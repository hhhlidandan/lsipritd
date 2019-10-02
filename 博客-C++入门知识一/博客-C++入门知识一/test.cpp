//namespace N1
//{
//	int a;//定义变量
//	int Add(int left, int right)//定义函数
//	{
//		return left + right;
//	}
//	namespace N2 //在命名空间N1里，嵌套了命名空间N2
//	{
//		int b;
//		int Sub(int left, int right)
//		{
//			return left - right;
//		}
//	}
//}
//namespace N1 // 相同名称的命名空间N1，编译器最后会合成同一个命名空间中
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
//	printf("%d\n", N::a);//命名空间为N
//	return 0;
//}
//
////2.用using将命名空间中成员引入
//
//using N::b;//说明b是命名空间N里的成员
//int main()
//{
//	printf("%d\n", b);
//}
//
////3.使用using namespace命名空间名称引入
//
//using namespace N;//这里先把空间内容省略
//int main()
//{
//	printf("%d\n", b);
//}

//C++输入&输出

//cin
//cout << "hello world" << endl;//输出hello world
//cout << "hello world\n";

//cout
//cin >> a;//输出a
//cin >> b >> c;//输出b c

//#include<iostream>
//using namespace std;
//int main()
//{
//	int a;//整形
//	double b;//双精度浮点型
//	char c;//字符型
//
//	cin >> a;
//	cin >> b >> c;
//
//	cout << a << endl;
//	cout << b << " " << c << endl;
//	return 0;
//}


//缺省参数
//void TestFunc(int a = 10, int b = 20, int c = 30)//所有参数都有参数值
//{
//	cout << "a= " << a << endl;
//	cout << "b= " << b << endl;
//	cout << "c= " << c << endl;
//}
//int main()
//{
//	TestFunc();//没有传参时，使用默认的参数值
//	//传参时，使用指定的参数 
//	TestFunc(1);// a=1,b=20,c=30
//	TestFunc(1, 2);//a=10,b=2,c=30
//	TestFunc(1, 2, 3);//a=1,b=2,c=3
//	return 0;
//}

//半缺省参数
//void TestFunc(int a, int b = 20, int c = 30)
//{
//	cout << "a= " << a << endl;
//	cout << "b= " << b << endl;
//	cout << "c= " << c << endl;
//}
//int main()
//{
//	//至少传一个参数
//	TestFunc(1);// a=1,b=20,c=30
//	TestFunc(1, 2);//a=10,b=2,c=30
//	TestFunc(1, 2, 3);//a=1,b=2,c=3
//	return 0;
//}
