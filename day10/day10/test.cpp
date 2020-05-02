#include<stdio.h>
#include<iostream>
using namespace std;
//int Fun(int n)
//{
//	if (n == 5)
//		return 2;
//	else
//		return 2 * Fun(n + 1);
//}
//int main()
//{
//	cout << Fun(2) << endl;
//	return 0;
//}
int main() 
{
	int x=3,y=3;    
	switch(x%2) 
	{       
	case 1:            
		switch (y) 
		{        
		case 0:cout<<"first";        
		case 1:cout<<"second";break;        
		default: cout<<"hello";   
		} 
		break;
	case 2:cout<<"third";    
	} 
}
