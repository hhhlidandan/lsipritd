#include<iostream>
#include<cstdio>
#include<cstdlib>
using namespace std;
//������
class Date
{
public:
	//���캯��----��ɳ�ʼ������
	Date();//�޲ι��캯��
	Date(int year, int month, int day);//�вι��캯�� 

	void showDate();//��ʾ
	//void InitDate(int year, int month, int day);//��ʼ��
private:
	int _year;
	int _month;
	int _day;

};
