package javaHomework;
import java.io.*;
import java.util.*;

public class Homework092102 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		try {
			Scanner sc = new Scanner(System.in);
			System.out.println("有多少学生?");
			int m=sc.nextInt();
			System.out.println("有多少课程?");
			int n=sc.nextInt();
			int[][] list=new int[m][n];
			int i,j;
			for(i=0;i<m;i++) {
				System.out.println("输入第"+(i+1)+"位学生的"+n+"科成绩");
				for(j=0;j<n;j++)
					list[i][j]=sc.nextInt();
			}
			int sum;
			for(i=0;i<m;i++) {
				sum=0;
				for(j=0;j<n;j++)
					sum=sum+list[i][j];
				System.out.println("第"+(i+1)+"位学生的平均成绩为"+sum/n);
			}
		}
		catch(InputMismatchException e) {
			System.out.println("输入数据不匹配");
		}
		catch(ArithmeticException e) {
			System.out.println("输入数据不符合算述逻辑");
		}
		finally {
			System.out.println("结束");
		}
	}

}
