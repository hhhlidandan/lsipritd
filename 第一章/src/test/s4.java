package test;

import java.util.Scanner;

public class s4 {
	public static void main(String[] args) {
		//Scanner sc=new Scanner(System.in);
		//while(sc.hasNext())
		//{//�ж��Ƿ����
		//	int score=sc.nextInt();			
		//}	
		
		Scanner scan=new Scanner(System.in);
		System.out.println("������������֣�");
		String name =scan.nextLine();
		System.out.println("������������䣺");
		int age=scan.nextInt();
		System.out.println("�����������ߣ�");
		double stature=scan.nextDouble();
		System.out.println("���ݽ�����ϡ�����");
		System.out.println(age+"���"+name+"����������\n"+"���"+stature+"�׵�����Ҳ�޷����ܸ�ð");
	}
}
