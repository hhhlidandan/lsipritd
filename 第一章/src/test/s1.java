package test;

public class s1 {
	public static void main(String[] args) {
		  int i,j,k;
		  for(int num=100;num<=999;num++)
		  {
			  i=num%10;
			  j=num/10%10;
			  k=num/100;
			  if(i*i*i+j*j*j+k*k*k==num)
			  {
				  System.out.print(num+"\t");
			  }
				  
		  }
	}
}
