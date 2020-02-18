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
	list<int> l1;//空构造
	list<int> l2(10, 5);//构造10个值为5的元素
	PrintList(l2);
	cout << l2.size() << endl;

	//区间构造
	int array[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 0 };
	list<int> l3(array, array + sizeof(array)/sizeof(array[0]));
	PrintList(l3);

	list<int>l4(l3);//拷贝构造
	l4.front() = 10;//将第一个结点的值改为10
	l4.back() = 20;//将第二个结点的值改为20
	cout << l4.front() << endl;//访问第一个元素
	cout << l4.back() << endl;//访问最后一个元素
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
	l4.unique();//将重复的元素删掉
	PrintList(l4);
	system("pause");
	return 0;

}