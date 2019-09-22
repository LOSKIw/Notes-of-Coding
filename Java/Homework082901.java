package javaHomework;
import java.util.Scanner;

public class Homework082901 {
	
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner sc = new Scanner(System.in);
		int x = sc.nextInt();
        int y = sc.nextInt();
        int temp1=x;
        int temp2=y;
        int temp_r;
        while(temp2!=0)
        {
        	temp_r=temp1%temp2;
        	temp1=temp2;
        	temp2=temp_r;
        }
        System.out.println("最大公约数是"+temp1);
        int result2=x*y/temp1;
        System.out.println("最小公倍数是"+result2);
	}

}
