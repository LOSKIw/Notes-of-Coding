package javaHomework;
import java.util.*;

public class Homework091802 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		int a[][]=new int[4][3];
		Scanner sc=new Scanner(System.in);
		int i,n,sum,average;
		for(i=0;i<a.length;i++) {
			System.out.println("�����"+(i+1)+"λͬѧ��Ӣ���ѧ��������ɼ�");
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
			System.out.println("��"+i+"λͬѧ�ܳɼ�Ϊ"+sum+",ƽ����λ"+sum/3);
		}
	}

}
