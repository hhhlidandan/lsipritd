#include<iostream>
#include<stdio.h>
#include<stdlib.h>
using namespace std;

#if 0
int main()
{
	//���뵥��Ԫ�ؿռ�
	//new+����
	int* p1 = new int;//����һ���������͵Ŀռ�
	//��������ת�����������ֽ���
	//
	int *p2 = new int(10);//���벢��ʼ��
	delete p1;//�ͷ�
	delete p2;

	//���������ռ�
	//int array[10];//int������������Ԫ�ص����ͣ�
	//�������ͣ�10�����Ϳռ�
	int* p3 = new int[10];//���������ռ�
	int* p4 = new int[4]{1, 2, 3, 4};//���벢��ʼ��
	delete[] p3;//�ͷ�
	delete[] p4;
	//Ϊʲônew������Ŀռ䲻��Ҫ����ת��
	//malloc�������ֽ�������֪����ʲô����
	//new����������ͣ������������ͣ�����Ҫǿת
	system("pause");
	return 0;
}
#endif

#if 1
class Test
{
public:
	Test() :_a(0)
	{
		cout << "Test():" << this << endl;
	}
	~Test()
	{
		cout << "`Test():" << this << endl;
	}
private:
	int _a;
};
void TestNewDelete()
{
	Test *p = (Test*)malloc(sizeof(Test));//����һ�δ�С��Test��ͬ�Ŀռ�
	new(p)Test;//���ù��캯���Կռ��ʼ��  
	//���캯���в�ʱ��Ҫ����

	//newһ��Test�Ķ���->��������  �ڶ���//���ù��캯��
	Test* pt1 = new Test;//����һ��Test���͵Ķ���
	Test* pt2 = new Test[10];//����10��Test���͵Ķ���
	delete pt1;//�ͷ�  �Զ�����������
	delete[] pt2;

	//�������졢�������� ���Դ����Ĳ��Ƕ���
	Test* pt11 = (Test*)malloc(sizeof(Test));
	if (pt11 == nullptr)
	{
		;
	}
	free(pt11);
}
int main()
{

	system("pause");
	return 0;
}
#endif

//int globalVar = 1; 
//static int staticGlobalVar = 1; 
//
//void Test() 
//{
//	static int staticVar = 1;
//	int localVar = 1;        
//	int num1[10] = { 1, 2, 3, 4 };    
//	char char2[] = "abcd";    
//	char* pChar3 = "abcd";   
//	int* ptr1 = (int*)malloc(sizeof (int)* 4);  
//	int* ptr2 = (int*)calloc(4, sizeof(int)); 
//	int* ptr3 = (int*)realloc(ptr2, sizeof(int)* 4);   
//	free(ptr1);   
//	free(ptr3); 
//}
