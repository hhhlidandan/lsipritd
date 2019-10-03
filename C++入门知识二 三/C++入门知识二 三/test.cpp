//函数重载
//int Add(int left, int right)
//{
//	return left + right;
//}
//double Add(double left, double right)
//{
//	return left + right;
//}


//不构成重载
//short Add(short left, short right)
//{
//	return left + right;
//}
//short Add(int left, int right)
//{
//	return left + right;
//}

//extern C
//extern "C" int Add(double left, double right);//按照C语言规则来编译
//int main()
//{
//	Add(1, 2);
//	return 0;
//}

//引用
//void TestRef()
//{
//	int a = 10;//引用定义时必须初始化
//	int& b = a;
//	int& c = b;//一个变量可以有多个引用
//
//	printf("%d\n", a);//10
//	printf("%d\n", b);//10
//	printf("%d\n", c);//10
//
//	int d = 20;
//	c = d;//把d赋给c（赋值操作，不是引用哦）
//	printf("%d\n", a);//20
//	printf("%d\n", b);//20
//	printf("%d\n", c);//20
//}

//常引用
//void ConstTestRef()
//{
//	const int a = 10;
//	//int& b = a;  错误表达，b是a的别名，没有修改a的权力
//	const int& b = a;
//}

//void ConstTestRef()
//{
//	int a = 10;//在这里是可以修改的
//	const int& b = a;//只读，不能改哦
//}


//使用场景
//做参数
//void Swap(int& left, int& right)// left,right分别为a,b 的别名
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

//与C语言的swap函数对比一下
//void Swap(int* left, int* right)//用指针接收
//{
//	int temp = *left;
//	*left = *right;
//	*right = temp;
//}
//int main()
//{
//	int a = 1;
//	int b = 2;
//	Swap(&a, &b);//传地址
//	return 0;
//}

//做返回值

//int TestRefReturn(int& a)//如果（）里是 int a ,则a是局部变量，不能用引用返回
//{
//	a += 10;
//	return a;//引用返回
//}
//int main()
//{
//	int x = 10;
//	int y = TestRefReturn(x);
//	return 0;
//}
