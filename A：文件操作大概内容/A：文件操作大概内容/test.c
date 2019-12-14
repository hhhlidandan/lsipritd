//动态内存管理复习
//在栈上定义的变量，系统开辟，系统释放
//动态内存申请  为什么  特征 概念 
//要求使用调用接口，直接在堆里。。。
//在堆上 自己申请，申请多大，自己释放，否则造成内存泄漏
//#################################################################
//#include<stdio.h>
//
////柔性数组
////1.是什么 结构体的最后一个元素大小允许是未知大小的数组 
////2.为什么要用 在结构内部需要变长数组时，使用柔性数组可以解决内存申请与释放的相关问题，
////   如申请时可以要多次申请，释放时可能要多次释放或申请、释放遗忘的问题(减小操作的难度)
////3.特点：
////结构体中的柔性数组成员前面必须至少有一个其他成员
////sizeof返回的这种结构大小不包括柔性数组的内存
///包含柔性数组成员的结构用malloc()函数进行内存的动态分配，并且分配的内存应该大于结构的大小，以适应柔性数组的预期大小
//typedef struct my_array
//{
//	int i;
//	int a[0];//柔性数组成员  柔性数组不占空间 
//}arr_t;

//
//int main()
//{
//	int num = 0;
//	printf("Please Enter#\n");
//	scanf("%d", &num);
//	//申请的时候一次申请 释放的时候一次释放
//	arr_t *arr = (arr_t*)malloc(sizeof(arr_t)+sizeof(int)*num);//sizeof(int)*num 给柔性数组申请了num个int空间
//	if (!arr)
//	{
//		printf("malloc error\n");
//		return 1;
//	}
//	arr->i = num;
//
//	system("pause");
//
////}

//文件
//关于文件，首先我们需要知道文件是在硬盘上放着，长时间不丢失，除非你删了
//一个文件要有一个唯一的文件标识（也就是我们说的文件名），以便用户识别和引用
//我们可以通过 文件名 标识文件，后缀标识文件类型，
//所以，文件名包含3部分：文件路径（可省略）+文件名主干+文件后缀
//文件类型：分为文本文件、二进制文件
//数据在内存中以二进制形式存储，
//如果不加转换的输出到外存，就是二进制文件
//如果在外存上以ASCII码形式存储,这个文件就是文本文件
//字符一律以ASCII形式存储，数值型数据既可以用ASCII形式存储，也可以使用二进制形式存储
//内存访问硬盘 
//文件=文件内容+文件属性
//把字符串往文件写不用+1 只要字符串 
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#pragma warning(disable:4996)

int main()
{
	//FILE *fp = fopen("test.txt", "wb");//以二进制的形式写
	//以w写文件时，在打开文件时，会将之前内容清空
	FILE *fp = fopen("test.txt", "w");//以读的方式打开,没有指路径，会在当前目录下
	if (NULL == fp)
	{
		printf("open error\n");
		return 1;
	}
	//特定的文件  一共要写多少个基本单位 每个基本单位多大   写的方式 
	//char *str = "abcdef";
	//fwrite(str,strlen(str),1,fp);//给fp里写str,写1个strlen(str)
	//char *a = "123abcdef";
	//while (*a)
	//{
	//	fputc(*a, fp);//把a中的内容写到fp里
	//	a++;//将字符串依次写如
	//}

	/*char buf[64];
	fgets(buf, 64, fp);
	printf("%s\n", buf);*/

	fprintf(fp, "hello %d,%s\n", 124, "good");//hello 124,good
	//fputs("hello\n", stdout);//将hello输出到标准输出流
	//puts("heool");//往显示器上显示消息
	//fclose(fp);//用完就要关掉文件
	//二进制写入内存数据和硬盘数据、文件数据保持一致



	//FILE *fp = fopen("test.txt", "w");
	//if (NULL == fp)//检测文件是否为空
	//{
	//	printf("fopen error\n");
	//	return 1;
	//}
	//int a[] = { 1, 2, 3, 4, 5, 6 };
	//fwirte(a, sizeof(a), 1, fp);
	//int b[20];

	//fread(b, sizeof(b), 1, fp);
	//fclose(fp);


	system("pause");
	return 0;

}