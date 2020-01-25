#include "test.h"
	void Stu::InitStudent(char* name, int age, char* gender)//要说明PrintStudent是Stu类里的成员函数 类名+作用域限定符（：）
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
	s.InitStudent("张三", 15, "男");
	s.PrintStudent();
	//printf("%s %d %s\n", s._name,s._age,s._gender);

	system("pause");
	return 0;
}