
public class test2 {
	public static void main(String[] args) {
		String str[]=new String[5];
		for(String s:str)
		{
			System.out.println(s+" ");
		}
		int[] arr;
		arr=new int[5];
		arr[0]=10;
		arr[1]=20;
		arr[2]=30;
		arr[3]=40;
		arr[4]=50;
		for(int i=0;i<arr.length;i++)
		{
			System.out.println("E at index"+i+":"+arr[i]);
		}
	}
}
