#include "test.h"
	void Stu::InitStudent(char* name, int age, char* gender)//Ҫ˵��PrintStudent��Stu����ĳ�Ա���� ����+�������޶���������
	{
		strcpy(_name, name);
		_age = age;
		strcpy(_gender, gender);
	}
	void Stu::PrintStudent()
	{
		cout << sizeof(Stu) << endl;
	}
int main()
{
	Stu s1;
	s1.InitStudent("����", 15, "��");
	s1.PrintStudent();
	Stu s2;
	s2.InitStudent("����", 16, "��");
	s2.PrintStudent();
	//printf("%s %d %s\n", s._name,s._age,s._gender);

	system("pause");
	return 0;
}