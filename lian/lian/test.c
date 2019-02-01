#define _CRT_SECURE_NO_WARNINGS
//½±½ð·¢·Å
#include<stdio.h>
#include<math.h>
int main()
{
	float a, b;
	scanf("%f", &a);
	if (a <= 10)
	{
		b = a*0.1;
	}
	if (a>10 && a <= 20)
	{
		b = 1 + (a - 10)*0.075;
	}
	if (a>20 && a <= 40)
	{
		b = 1.75 + (a - 20)*0.05;
	}
	if (a>40 && a <= 60){
		b = 2.75 + (a - 40)*0.03;
	}
	if (a>60 && a <= 100)
	{
		b = 3.35 + (a - 60)*0.015;
	}
	if (a>100)
	{
		b = 3.95 + (a = 100)*0.01;
	}
	printf("%.2f\n", b);
	system("pause");
	return 0;
}
