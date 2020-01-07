//2、编写函数，其原型为：void index(int a[], int n,int & sub)。
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
 	cout<<"输入sub=";
   	cin>>sub;
   	index(b,n,sub);
  	if(sub!=-1)
	  {
	  	cout<<sub<<endl;
	  }
   	else
   	cout<<"未找到"<<endl;
   	return 0;
   	system("pause");
}
