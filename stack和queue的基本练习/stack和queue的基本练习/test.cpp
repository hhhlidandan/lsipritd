#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<queue>
#include<functional>
using namespace std;
//priority_queue
//void Priority_QueueTest()
//{
//	priority_queue<int> q1;//����յ����ȼ�����
//	int array[] = { 2, 5, 6, 7, 3, 0, 4, 9, 8, 5, 6 };
//	//Ĭ��������������Ǵ�ѣ��ײ㰴��С�ڵķ�ʽ�Ƚϣ�
//	priority_queue<int,vector<int>> q(array, array + sizeof(array) / sizeof(array[0]));//Ĭ�Ϸ�ʽ�ǰ��մ�Ѵ洢��
//
//	//����С�ѣ������մ��ڵķ�ʽ�Ƚϣ�  vectorΪ�ײ�洢���ݵ�����  greaterΪ�ȽϷ�ʽ
//	priority_queue<int, vector<int>, greater<int>> q2(array, array + sizeof(array) / sizeof(array[0]));
//}

class Date
{
public:
	Date(int year = 1900, int month = 1, int day = 1)
		:_year(year)
		, _month(month)
		, _day(day)
	{}
	bool operator<(const Date& d) const
	{
		return (_year < d._year) ||
			(_year == d._year&&_month < d._month) ||
			(_year == d._year&&_month == d._month&&_day < d._day);
	}
	bool operator>(const Date& d) const
	{
		return(_year>d._year) ||
			(_year == d._year&&_month>d._month) ||
			(_year == d._year&&_month == d._month&&_day>d._day);
	}
private:
	int _year;
	int _month;
	int _day;
};
int main()
{
	priority_queue<Date> q1;//Ĭ�ϴ��
	q1.push(Date(2018, 10, 29));
	q1.push(Date(2018, 10, 28));
	q1.push(Date(2018, 10, 27));
	priority_queue<Date, vector<Date>, greater<Date>> q2;//С��
	q2.push(Date(2018, 10, 29));
	q2.push(Date(2018, 10, 28));
	q2.push(Date(2018, 10, 27));
	system("pause");
	return 0; 
}