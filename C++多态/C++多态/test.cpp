#include<iostream>
using namespace std;

#if 0
class Person
{
public:
	virtual void BuyTickets()
	{
		cout << "����Ʊ" << endl;
	}
};
class Student:public Person
{
public:
	virtual void BuyTickets()
	{
		cout << "ѧ��Ʊ" << endl;
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
//����--Э��
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
		cout << "����Ʊ" << endl;
		return nullptr;
	}
};
class Student :public Person
{
public:
	//virtual Student* BuyTickets()
	virtual B* BuyTickets()//ֻҪ��Ӧ������ͻ����Ǽ̳й�ϵ����
	{
		cout << "ѧ��Ʊ" << endl;
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
		cout << "����Ʊ" << endl;
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
		cout << "ѧ��Ʊ" << endl;
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
	Person *p = new Person;//ͨ������ָ�������ȥ����
	p->BuyTickets();
	delete p;
	
	p = new Student;
	p->BuyTickets();
	delete p;
	system("pause");
	return 0;
}
#endif