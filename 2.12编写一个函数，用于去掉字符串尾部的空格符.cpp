//12、编写一个函数，用于去掉字符串尾部的空格符
#include<iostream>
#include<cstring>
using namespace std;

char *myltrim(char *string)
{
	int i,len;
	len=strlen(string);
	for(i=0;i<len;i++)
	while(*string!='\0')
	{
		if(string[i]==' ')
		string++;
	}
	return string;
}
main()
{
	{
		int j;
		char str[j];
		cout << "输入一个字符串: ";
		cin >> str;
		char mytrim (char *string);
		cout << str; 
	} 
	cout <<"你好"; 
}
