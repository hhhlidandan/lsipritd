package test;

import java.util.Scanner;

public class s4 {
	public static void main(String[] args) {
		//Scanner sc=new Scanner(System.in);
		//while(sc.hasNext())
		//{//判断是否结束
		//	int score=sc.nextInt();			
		//}	
		
		Scanner scan=new Scanner(System.in);
		System.out.println("请输入你的名字：");
		String name =scan.nextLine();
		System.out.println("请输入你的年龄：");
		int age=scan.nextInt();
		System.out.println("请输入你的身高：");
		double stature=scan.nextDouble();
		System.out.println("数据接收完毕。。。");
		System.out.println(age+"岁的"+name+"在昨天晚上\n"+"身高"+stature+"米的他，也无法承受感冒");
	}
}
