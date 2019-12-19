#include<stdio.h>
#include<windows.h>
#pragma warning(disable:4996)

//可以定义不同类型的变量
struct stu //定义结构体类型
{
	//成员列表
	char name[24];
	char sex[20];
	char id[20];
	int age;
};

struct stu1
{
	//成员列表
	char name[24];
	char sex[20];
	char id[20];
	int age;

}tom,*p;//在这里定义变量tom，定义结构体指针变量也可以
struct stu1 jim;//在这里也可以定义变量

typedef struct student //定义结构体
{
	//成员列表
	char name[24];
	char sex[20];
	char id[20];
	int age;

}stu_t;//把struct student重命名为stu_t,定义结构体变量

typedef struct student //定义结构体
{
	//成员列表
	char name[24];
	char sex[20];
	char id[20];
	int age;

}stu_t,*stu_p;//把struct student重命名为stu_t


struct point
{
	int x;
	int y;
};
struct Node
{
	int data;
	struct point p;
	struct Node* next;
}n1 = { 10, { 1, 2 }, NULL };//结构体嵌套初始化
int main()
{
	struct stu tom = {"zhangsan",'女',123456,19};//定义变量tom  并对其初始化
	stu_t s = { "wangwu", '女', 123456, 19 };
	stu_p p = &s;
	p = &tom;
	printf("%s ", tom.name);
	printf("%s ", tom.sex);
	printf("%s ", tom.id);
	printf("%d ", tom.age);
	system("pause");
	return 0;
}
