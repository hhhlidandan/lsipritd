#include<iostream>
using namespace std;
#if 0
class A
{
public:
	void Testfunc1()
	{}
protected:
	int _a;
};
//���๫�г�Ա����������Ȩ���Ѿ���ɱ�����
//�����ⲻ��ͨ�����������ֱ�ӷ��ʻ����Ա����
//���û����Ա�����������������Ա������ֱ�ӱ�����
class B :protected A
{
public:
	void Testfunc2()
	{
		Testfunc1();
	}
	
protected:
	int _b;
};
int main()
{
	A a;
	B b;
	//b.Testfunc1();
	return 0;
}
#endif

class A
{
public:
	void Testfunc1()
	{}
protected:
	int _a;
};
class B
{
public:
	void Testfunc2()
	{
		_a.Testfunc1();
	}

protected:
	A _a;
	int _b;
};
int main()
{
	A a;
	B b;
	return 0;
}