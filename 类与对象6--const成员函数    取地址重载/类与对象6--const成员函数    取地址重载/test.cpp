#include<iostream>
using namespace std;
class Date
{
public:
	Date(int year = 2019, int month = 6, int day = 8)
	{
		cout << "Date(int,int,int):" << this << endl;
		_year = year;
		_month = month;
		_day = day;
	}
	Date(const Date& d)
	{
		_year = d._year;
		_month = d._month;
		_day = d._day;
		cout << "Date& (int):" << this << endl;
	}
	//��ֵ���������
	Date& operator=(const Date& d)
	{
		if (this != &d)//�ų������Լ�������ֵ
		{
			_year = d._year;
			_month = d._month;
			_day = d._day;
		}
		return *this;
	}
	//ȡ��ַ����	//������ͨ���͵ĳ�Ա����
	Date* operator&()//���ض���ĵ�ַ
	{
		return this;
	}
	//constȡ��ַ����  //����const���͵ĳ�Ա����/
	// Date* p=&d2//���벻��ȫ������ͨ��p�޸Ŀռ��е�����
	const Date* operator&() const //�����޸ĵ�ǰ����ĳ�Ա����
	{
		return this;
	}
	void TestFunc1()
	{
		_day++;
	}
	//this�����ͣ�Date* const  //ָ��ָ�����޸�
	//const Date* const this  //ָ��ָ��Ŀռ�����ݲ����޸ģ������޸ĳ�Ա������
	//const����thisָ��
	void TestFunc2() const
	{
		//_day++;//���ܼӣ���Ϊ�����޸����г�Ա����
		this->_day;//����mutable���Ա��޸���
	}

	~Date()
	{
		cout << "`Date():" << this << endl;
	}
private:
	int _year;
	int _month;
	mutable int _day;//����mutable������const���ͳ�Ա�������ڱ��޸�
};

void TestDate()
{
	Date d1(2019,3,25);
	cout << &d1 << endl;//���о͹���

	const Date d2(2019,3,3);
	cout << &d2 << endl;
	//һ�㲻��Ҫȡ��ַ���أ������б����
}
int main()
{
	TestDate();
	system("pause");
	return 0;
}
