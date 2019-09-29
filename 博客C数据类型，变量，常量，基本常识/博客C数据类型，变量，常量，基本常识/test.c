//变量

//定义变量
//int age = 150;
//char ch = "w";

//变量的分类
//#include<stdio.h>
//int global = 2019;//全局变量
//int main()//代码块内部
//{
//	int local = 2018;//局部变量
//	int global = 2020;//显然，和代码块外部的变量相同
//	printf("global = %d\n", global);//2020（局部优先）
//	return 0;
//}

//变量的生命周期

//#include<stdio.h>
//int main()
//{//下面的age在这个代码块内使用，那么这个代码块就是它的作用域，生命周期也就从这里开始
//	int age = 10;
//	{//下面的age同理
//		int age = 5;//第二个age生命周期开始
//		printf("age = %d\n", age);//age = 5
//	}//第二个age生命周期结束
//	printf("%d\n", age);//10
//	return 0;
//}//第一个age出了代码块生命周期就结束了


//常量
//const 修饰的常变量
//#include<stdio.h>
//int main()
//{//不加const:
//	int num1 = 0;
//	num1 = 20;
//	printf("num1 = %d\n", num1);//num1 = 20
//	//加const之后：
//	const int num2 = 0;//加了const之后，num2就不能被修改啦
//	num2 = 20;
//	prinf("num2 = %d\n", num2);//num2=0
//
//	const int n = 10;
//	// int arr[n] = {0};//该句错误，数组中的n应为常量，在这里，n加了const,就成常变量(变量)了	
//	int arr[10] = { 0 };//改正是这样的
//
//}

//枚举常量

//#include<stdio.h>
//enum Sex//enum为枚举关键字
//{
//	MALE,//枚举常量//默认初始值，从0开始。0、1、2....
//	//如果 MALE 赋初始值，比如MALE=5,那么初始值就从5开始，5，6，7....
//	FEMALE,
//	SECRET
//};
