#include "test.h"
	void Stu::InitStudent(char* name, int age, char* gender)//Ҫ˵��PrintStudent��Stu����ĳ�Ա���� ����+�������޶���������
	{
		strcpy(_name, name);
		_age = age;
		strcpy(_gender, gender);
	}
	void Stu::PrintStudent()
	{
		cout << _name << " " << _age << " " << _gender << " " << endl;
	}
int main()
{
	Stu s;
	s.InitStudent("����", 15, "��");
	s.PrintStudent();
	//printf("%s %d %s\n", s._name,s._age,s._gender);

	system("pause");
	return 0;
}