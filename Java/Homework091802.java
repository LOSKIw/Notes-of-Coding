package javaHomework;
import java.util.*;

public class Homework091802 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		int a[][]=new int[4][3];
		Scanner sc=new Scanner(System.in);
		int i,n,sum,average;
		for(i=0;i<a.length;i++) {
			System.out.println("输入第"+(i+1)+"位同学的英语，数学，计算机成绩");
			for(n=0;n<3;n++) {
				a[i][n]=sc.nextInt();
			}
			sc.nextLine();
		}
		for(i=0;i<4;i++)
		{
			sum=0;
			for(n=0;n<3;n++)
			{
				sum+=a[i][n];
			}
			System.out.println("第"+i+"位同学总成绩为"+sum+",平均分位"+sum/3);
		}
	}

}
