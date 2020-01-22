#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Great_A_Less_B  //����������STL��ʹ�÷ǳ��㷺
{
	int m_nA;
	int m_nB;
public:
	Great_A_Less_B( int x, int y ) : m_nA( x ), m_nB( y ){}
	bool operator()( int c ) const //���ز�����()���ж�c�Ƿ����m_nA��С��m_nB
	{   return ( (c>m_nA) && (c<m_nB) );  }
};

class DivByA  //����������STL��ʹ�÷ǳ��㷺
{
	int m_nA;
public:
	DivByA( int x ) : m_nA( x ){}
	bool operator()( int c ) const //���ز�����()���ж�c�Ƿ���Ա�m_nA����
	{
		return ( c%m_nA == 0 );
	}
};
int main()
{
	Great_A_Less_B obj1(4,9);
	DivByA obj2(2);
	int a[] = {1,3,6,4,7,8,9,10,23,5};
	//��ӡa�д���4��С��9����
	for( int i = 0; i < sizeof(a)/sizeof(int); ++i ) 
//sizeof(a)/sizeof(int)Ϊ����a�е�Ԫ�ظ���
	{
		if( obj1( a[i] ) == true ) //�ж�a[i]�Ƿ����4��С��9
		{  cout << a[i] << '\t'; }
	}
	cout << endl;
	
//��ӡa�б�2��������
	for(  int i = 0; i < sizeof(a)/sizeof(int); ++i ) 
//sizeof(a)/sizeof(int)Ϊ����a�е�Ԫ�ظ���
	{
		if( obj2( a[i] ) == true ) //�ж�a[i]��2����
		{
			cout << a[i] << '\t';
		}
	}
	cout << endl;
	//���������Բ���
	cout << "//--------------------------------------------" << endl;
	vector<int> s; //STL�е�vector���������α��Զ�����
	vector<int>::iterator it; //������
	for(  i = 0; i < 10; ++i )
	{  		s.push_back( rand()%10 );   	}
	for( it = s.begin(); it != s.end(); ++it )  //��ӡs�е�����
	{     cout << *it << '\t';  	}
	cout << endl;
	int c1 = count_if( s.begin(), s.end(), obj1 ); //ͳ��s�д���4��С��9��������
	cout << c1 << endl;
	int c2 = count_if( s.begin(), s.end(), obj2 ); //ͳ��s�б�2������������
	cout << c2 << endl;
	return 0;
}
