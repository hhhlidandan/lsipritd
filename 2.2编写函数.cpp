//2����д��������ԭ��Ϊ��void index(int a[], int n,int & sub)��
#include<iostream>
using namespace std;
void index(int a[],int n,int & sub)
{
	int i;
 	for(i=0;i<=n;i++)
 	{
 		if(a[i]==sub)
 		{
			sub=i;
 	 		break;
		}
	}	
   if(i>n)
   sub=-1;
} 
main()
{ 
	int i;
 	int b[]={1,2,3,4,5,6};
 	int n=6,sub;
 	cout<<"����sub=";
   	cin>>sub;
   	index(b,n,sub);
  	if(sub!=-1)
	  {
	  	cout<<sub<<endl;
	  }
   	else
   	cout<<"δ�ҵ�"<<endl;
   	return 0;
   	system("pause");
}
