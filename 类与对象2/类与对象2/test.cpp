#include "test.h"

#if 0
class A
{
public:
	void Test()
	{
		cout << this << endl;
		cout << "Test()" << endl;
	}
protected:
	int _a;
};


int main()
{
	A* ps = nullptr;
	ps->Test();
	system("pause");
	return 0;
}
#endif

#if 0
#include<cstdio>
#include<cstdlib>
#include<iostream>
#pragma warning(disable:4996)
using namespace std;

//thisָ��
class Student
{
public:
	void InitStudent(Student* const this, char* name, char* gender, int sex)
	{
		strcpy(this->_name, name);
		strcpy(this->_gender, gender);
		this->_age = age;
	}
	void PrintStudent(Student* const this)
	{
		cout << this->_name << " " << this->_gender << " " << this->_age << endl;
	}
private:
	char _name[20];
	char _gender[5];
	int _age;
};

int main()
{
	Student s1;
	Student::InitStudent(&s1, "zhangsan", "��", 15);
	Student::PrintStudent(&s1);
	system("pause");
	return 0;
}
#endif

#if 1
void Student::InitStudent(char* name, char* gender, int age)
{
	strcpy(this->_name, name);
	strcpy(_gender, gender);
	_age = age;
}
void Student::PrintStudent()
{
	cout << _name << " " << _gender << " " << _age << endl;
}
int main()
{

	Student s1;
	s1.InitStudent("zhangsan", "��", 15);
	s1.PrintStudent();

	Student s2;
	s2.InitStudent("nihao", "Ů", 20);
	s2.PrintStudent();
	system("pause");
	return 0;
}
#endif

#if 0
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
#endif