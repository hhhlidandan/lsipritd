#include"iostream"
#include"algorithm"
#include"string.h"
using namespace std;
template <class ElemType>
void Asort(ElemType *a,int length)
{
	sort(a,a+length);
	cout << "sort finish" << endl ;
}
template <class ElemType>
ElemType max(ElemType *a,int length)
{
	return a[length-1];	
}
template <class ElemType>
ElemType sum(ElemType *a,int length)
{
	int i=0;
	ElemType sum=0;
	while(i<length)
	{
		sum=sum+a[i];
		i++;
	}
	return sum;
}
 
int main(void)
{
	int *a,length;
	cout << "元素个数为：" << endl ;
	cin >> length ;
	a=new int[length];
	cout << "请输入元素" << endl ;
	for(int i=0;i<length;i++)
		cin >> a[i];
	Asort(a,length);
	cout << "the max=" << max(a,length) << endl ;
	cout << "the sum=" << sum(a,length) << endl ;
}
