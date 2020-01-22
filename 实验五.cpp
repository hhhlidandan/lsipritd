#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Great_A_Less_B  //函数对象，在STL中使用非常广泛
{
	int m_nA;
	int m_nB;
public:
	Great_A_Less_B( int x, int y ) : m_nA( x ), m_nB( y ){}
	bool operator()( int c ) const //重载操作符()，判断c是否大于m_nA且小于m_nB
	{   return ( (c>m_nA) && (c<m_nB) );  }
};

class DivByA  //函数对象，在STL中使用非常广泛
{
	int m_nA;
public:
	DivByA( int x ) : m_nA( x ){}
	bool operator()( int c ) const //重载操作符()，判断c是否可以被m_nA整除
	{
		return ( c%m_nA == 0 );
	}
};
int main()
{
	Great_A_Less_B obj1(4,9);
	DivByA obj2(2);
	int a[] = {1,3,6,4,7,8,9,10,23,5};
	//打印a中大于4且小于9的数
	for( int i = 0; i < sizeof(a)/sizeof(int); ++i ) 
//sizeof(a)/sizeof(int)为数组a中的元素个数
	{
		if( obj1( a[i] ) == true ) //判断a[i]是否大于4且小于9
		{  cout << a[i] << '\t'; }
	}
	cout << endl;
	
//打印a中被2整除的数
	for(  int i = 0; i < sizeof(a)/sizeof(int); ++i ) 
//sizeof(a)/sizeof(int)为数组a中的元素个数
	{
		if( obj2( a[i] ) == true ) //判断a[i]被2整除
		{
			cout << a[i] << '\t';
		}
	}
	cout << endl;
	//下面代码可以不看
	cout << "//--------------------------------------------" << endl;
	vector<int> s; //STL中的vector容器，线形表，自动增长
	vector<int>::iterator it; //迭代器
	for(  i = 0; i < 10; ++i )
	{  		s.push_back( rand()%10 );   	}
	for( it = s.begin(); it != s.end(); ++it )  //打印s中的内容
	{     cout << *it << '\t';  	}
	cout << endl;
	int c1 = count_if( s.begin(), s.end(), obj1 ); //统计s中大于4且小于9的数个数
	cout << c1 << endl;
	int c2 = count_if( s.begin(), s.end(), obj2 ); //统计s中被2整除的数个数
	cout << c2 << endl;
	return 0;
}
