#include "test.h"
	void Stu::InitStudent(char* name, int age, char* gender)//要说明PrintStudent是Stu类里的成员函数 类名+作用域限定符（：）
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
	s1.InitStudent("张三", 15, "男");
	s1.PrintStudent();
	Stu s2;
	s2.InitStudent("李四", 16, "男");
	s2.PrintStudent();
	//printf("%s %d %s\n", s._name,s._age,s._gender);

	system("pause");
	return 0;
}