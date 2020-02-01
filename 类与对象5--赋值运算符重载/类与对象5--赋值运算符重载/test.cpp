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
		if (this != &d)//�ų������Լ����Լ���ֵ
		{
			_year = d._year;
			_month = d._month;
			_day = d._day;
		}
		return *this;
	}
	//���������
	//+������
	Date operator+(int day)//this�൱��const Date& d,��һ������
	{
		//_day: *this+day//�ӺŲ��ı����Ҳ�������ֵ
		Date temp(*this);
		temp._day += day;//������ʱ������this����
		return temp;//���صĶ�����������Ҫ�Ⱥ������������ڳ�
		//���ԣ���ʱ�����Ͳ��������÷�����
	}
	//������Ϊ�����ķ���ֵ���ͣ�Ҫע�⣺���ܷ��غ���ջ�ϵĿռ�
	//ջ�ϵģ�����������ľֲ��������Ѿ���ϵͳ���գ�û������
	//
	Date& DateAdd(int day)
	{
		_day += day;
		return *this;
	}
	//����==
	bool operator==(const Date& d)//��������ߵĲ�������this������ֻ��Ҫ���ұߵĲ�����
	{
		return _year == d._year&&\
			_month == d._month&&\
			_day == d._day;
	}
	////����!=
	bool operator!=(const Date& d)
	{
		return !(*this == d);
	}
	//ǰ��++  d2 = ++d1
	Date& operator++()//ֱ�Ӽӵ�this�Ϸ��أ�����������
	{
		_day += 1;
		return *this;
	}
	//����++
	Date operator++(int)//����+��֮�����ֵ�����Բ��������ã�
	{
		Date temp = (*this);//�Ƚ�֮ǰ��ֵ��������
		_day += 1;
		return temp;//���غ����������˹�ͱ���������������
	}
	//ǰ��--
	Date& operator--()
	{
		_day -= 1;
		return *this;
	}
	//����--
	Date operator--(int)//�Ӳ�����Ϊ������ǰ�û��Ǻ���
	{
		Date temp = (*this);
		_day -= 1;
		return temp;
	}

	~Date()
	{
		cout << "`Date():" << this << endl;
	}
private:
	int _year;
	int _month;
	int _day;
};

void TestDate()
{
	Date d1(2019, 2, 22);
	d1.DateAdd(3);
	d1 = d1 + 3;///���� +  =
	

	Date d2(d1);//��������

	Date d3(2018, 2, 22);
	d3 = d1;//d1��ֵ��d3  ���� =
	d3.operator=(d1);//d3=d1 ʵ������������
	d1 = d2 = d3;
	//������ֵ
	d1.operator=(d2.operator = (d3));
	
	//ǰ��++������++
	d2 = d1++;
	d1 = ++d1;
	//ǰ��--������--
	d2 = d1--;
	d2 = --d1;

}
int main()
{
	TestDate();
	system("pause");
	return 0;
}