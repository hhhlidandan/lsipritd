#include "Date.h"

Date::Date()//�޲ι��캯��
{
	_year = 1203;
	_month = 12;
	_day = 7;
}
//���캯��   ��ɳ�ʼ������
Date::Date(int year, int month, int day)//���캯��   ��ɳ�ʼ������
{
	_year = year;
	_month = month;
	_day = day;
}
//void Date::InitDate(int year, int month, int day)
//{
//	_year = year;
//	_month = month;
//	_day = day;
//}
void Date::showDate()
{
	cout << _year << "��" << _month << "��" << _day <<"��" <<endl;
}
int main()
{
	Date s1;//�����޲ι��캯��
	Date s2(2019, 12, 6);//�����вι��캯��
	//ע�⣺���ͨ���޲ι��캯����������ʱ��������治�����ţ�����ͳ��˺�������
	//
	//Date s3();//��������

	/*Date s1;
	s1.InitDate(2019, 12, 6);*/
	s1.showDate();
	s2.showDate();
	system("pause");
	return 0;
}