package javaHomework;
import java.io.*;
import java.util.*;

public class Homework092102 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		try {
			Scanner sc = new Scanner(System.in);
			System.out.println("�ж���ѧ��?");
			int m=sc.nextInt();
			System.out.println("�ж��ٿγ�?");
			int n=sc.nextInt();
			int[][] list=new int[m][n];
			int i,j;
			for(i=0;i<m;i++) {
				System.out.println("�����"+(i+1)+"λѧ����"+n+"�Ƴɼ�");
				for(j=0;j<n;j++)
					list[i][j]=sc.nextInt();
			}
			int sum;
			for(i=0;i<m;i++) {
				sum=0;
				for(j=0;j<n;j++)
					sum=sum+list[i][j];
				System.out.println("��"+(i+1)+"λѧ����ƽ���ɼ�Ϊ"+sum/n);
			}
		}
		catch(InputMismatchException e) {
			System.out.println("�������ݲ�ƥ��");
		}
		catch(ArithmeticException e) {
			System.out.println("�������ݲ����������߼�");
		}
		finally {
			System.out.println("����");
		}
	}

}
