#include<iostream>
using namespace std;
class Test
{
public:
	Test()
	{
		_count++;
	}
	Test(const Test& a)
	{
		_count++;
	}
	static int GetCount()
	{
		return _count;
	}
	~Test()
	{
		_count--;
	}
private:
	int _a;
	static int _count;
};
int Test::_count = 0;
void count()
{
	Test c, d;
	cout << Test::GetCount() << endl;
}
int main()
{
	Test a, b;
	cout << Test::GetCount() << endl;
	cout << a.GetCount() << endl;

	count();
	cout << Test::GetCount() << endl;
	cout << a.GetCount() << endl;
	return 0;
}