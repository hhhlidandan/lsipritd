#include<iostream>
#include<list>
using namespace std;
void PrintList(list<int>& l)
{
	list<int>::iterator it = l.begin();
	while (it != l.end())
	{
		cout << *it << " ";
		it++;
	}
	cout << endl;
}
void PrintList1(list<int>& l)
{
	list<int>::reverse_iterator it = l.rbegin();
	while (it != l.rend())
	{
		cout << *it << " ";
		it++;
	}
	cout << endl;
}
int main()
{
	list<int> l1;//�չ���
	list<int> l2(10, 5);//����10��ֵΪ5��Ԫ��
	PrintList(l2);
	cout << l2.size() << endl;

	//���乹��
	int array[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 0 };
	list<int> l3(array, array + sizeof(array)/sizeof(array[0]));
	PrintList(l3);

	list<int>l4(l3);//��������
	l4.front() = 10;//����һ������ֵ��Ϊ10
	l4.back() = 20;//���ڶ�������ֵ��Ϊ20
	cout << l4.front() << endl;//���ʵ�һ��Ԫ��
	cout << l4.back() << endl;//�������һ��Ԫ��
	PrintList1(l4);
	l4.push_back(100);
	l4.pop_front();
	PrintList(l4);

	l4.resize(5);
	PrintList(l4);
	l4.resize(15, 0);
	PrintList(l4);

	l4.insert(l4.begin(), 0);
	PrintList(l4);
	l4.erase(l4.begin());
	PrintList(l4);
	//l4.clear();
	//cout << l4.size() << endl;

	l4.sort();
	PrintList(l4);
	l4.unique();//���ظ���Ԫ��ɾ��
	PrintList(l4);
	system("pause");
	return 0;

}