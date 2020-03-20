#include<iostream>
using namespace std;

#if 0
class Person
{
public:
	virtual void BuyTickets()
	{
		cout << "成人票" << endl;
	}
};
class Student:public Person
{
public:
	virtual void BuyTickets()
	{
		cout << "学生票" << endl;
	}
};
void SellTickets(Person &p)
{
	p.BuyTickets();
}
int main()
{
	Person p;
	SellTickets(p);
	Student s;
	SellTickets(s);
	system("pause");
	return 0;
}
#endif
#if 0
//特例--协变
class A
{};
class B :public A
{};
class Person
{
public:
	//virtual Person* BuyTickets()
	virtual A* BuyTickets()
	{
		cout << "成人票" << endl;
		return nullptr;
	}
};
class Student :public Person
{
public:
	//virtual Student* BuyTickets()
	virtual B* BuyTickets()//只要对应的子类和基类是继承关系就行
	{
		cout << "学生票" << endl;
		return nullptr;
	}
};
void SellTickets(Person &p)
{
	p.BuyTickets();
}
int main()
{
	Person p;
	SellTickets(p);
	Student s;
	SellTickets(s);
	system("pause");
	return 0;
}
#endif

#if 1
class Person
{
public:
	virtual Person* BuyTickets()
	{
		cout << "成人票" << endl;
		return nullptr;
	}
	virtual ~Person()
	{
		cout << "~Person()" << endl;
	}
};
class Student :public Person
{
public:
	virtual Student* BuyTickets()
	{
		cout << "学生票" << endl;
		return nullptr;
	}
	virtual ~Student()
	{
		cout << "~Student()" << endl;
	}
};
void SellTickets(Person &p)
{
	p.BuyTickets();
}
int main()
{
	Person *p = new Person;//通过基类指针或引用去调用
	p->BuyTickets();
	delete p;
	
	p = new Student;
	p->BuyTickets();
	delete p;
	system("pause");
	return 0;
}
#endif