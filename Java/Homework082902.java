package javaHomework;

public class Homework082902 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		int i=101;
		int j;
		search:
		for(;i<=199;i++)
		{
			for(j=2;j<=i/2;j++)
			{
				if(i%j==0)
					continue search;
			}
			System.out.println(i);
		}
	}

}
