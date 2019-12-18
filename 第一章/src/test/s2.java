package test;

import java.util.Scanner;

public class s2 {
	public static void main(String[] args) {
		int countP=0,countN=0;
		int num;
		Scanner SC=new Scanner(System.in);
		do
		{
			num=SC.nextInt();
			if(num>0)
			{
				countP++;
			}
			else if(num<0)
			{
				countN++;
			}
		}while(num!=0);
		System.out.println("the number p is"+countP);
		System.out.println("the number p is"+countP);	
	}
}
