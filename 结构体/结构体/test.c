#include<stdio.h>
#include<windows.h>
#pragma warning(disable:4996)

//���Զ��岻ͬ���͵ı���
struct stu //����ṹ������
{
	//��Ա�б�
	char name[24];
	char sex[20];
	char id[20];
	int age;
};

struct stu1
{
	//��Ա�б�
	char name[24];
	char sex[20];
	char id[20];
	int age;

}tom,*p;//�����ﶨ�����tom������ṹ��ָ�����Ҳ����
struct stu1 jim;//������Ҳ���Զ������

typedef struct student //����ṹ��
{
	//��Ա�б�
	char name[24];
	char sex[20];
	char id[20];
	int age;

}stu_t;//��struct student������Ϊstu_t,����ṹ�����

typedef struct student //����ṹ��
{
	//��Ա�б�
	char name[24];
	char sex[20];
	char id[20];
	int age;

}stu_t,*stu_p;//��struct student������Ϊstu_t


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
}n1 = { 10, { 1, 2 }, NULL };//�ṹ��Ƕ�׳�ʼ��
int main()
{
	struct stu tom = {"zhangsan",'Ů',123456,19};//�������tom  �������ʼ��
	stu_t s = { "wangwu", 'Ů', 123456, 19 };
	stu_p p = &s;
	p = &tom;
	printf("%s ", tom.name);
	printf("%s ", tom.sex);
	printf("%s ", tom.id);
	printf("%d ", tom.age);
	system("pause");
	return 0;
}
