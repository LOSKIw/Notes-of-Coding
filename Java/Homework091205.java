package javaHomework;
import java.util.*;

abstract class nCAR{
	int cost;
	int num,day;
	nCAR(int n,int d){
		day=d;
		num=n;
	}
	nCAR(){}
	int cal() {
		return num*cost*day;
	}
}

class nCRV extends nCAR{
	int cost=600;
	nCRV(int n,int d){
		super(n,d);
	}
}

class nEscape extends nCAR{
	int cost=500;
	nEscape(int n,int d){
		super(n,d);
	}
}

class nHRV extends nCAR{
	int cost=400;
	nHRV(int n,int d){
		super(n,d);
	}
}

class nbus extends nCAR{
	int cost1=600,cost2=1000;
	int num1,num2;
	int day1,day2;
	nbus(int n1,int n2,int d1,int d2)
	{
		num1=n1;num2=n2;day1=d1;day2=d2;
	}
	nbus(){}
	int cal() {
		return num1*day1*cost1+num2*day2*cost2;
	}
}

class ntrack extends nCAR{
	int T,day,num,cost=50;
	ntrack(int t,int d,int n){
		T=t;day=d;num=n;
	}
	ntrack(){}
	int cal() {
		return T*day*num*cost;
	}
}

public class Homework091205 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner sc=new Scanner(System.in);int day,num,t,num1,day1;
		System.out.println("��������ҪCRV������:");
		num=sc.nextInt();
		System.out.println("��������ҪCRV������:");
		day=sc.nextInt();
		nCRV c=new nCRV(num,day);
		
		System.out.println("��������ҪEscape������:");
		num=sc.nextInt();
		System.out.println("��������ҪEscape������:");
		day=sc.nextInt();
		nEscape e=new nEscape(num,day);
		
		System.out.println("��������ҪHRV������:");
		num=sc.nextInt();
		System.out.println("��������ҪHRV������:");
		day=sc.nextInt();
		nHRV h=new nHRV(num,day);
		
		System.out.println("��������ҪС�ͳ�������:");
		num=sc.nextInt();
		System.out.println("��������ҪС�ͳ�������:");
		day=sc.nextInt();
		System.out.println("��������Ҫ��ͳ�������:");
		num1=sc.nextInt();
		System.out.println("��������Ҫ��ͳ�������:");
		day1=sc.nextInt();
		nbus b=new nbus(num,num1,day,day1);
		
		System.out.println("��������Ҫ����������:");
		num=sc.nextInt();
		System.out.println("��������Ҫ����������:");
		day=sc.nextInt();
		System.out.println("��������Ҫ�����Ķ���:");
		t=sc.nextInt();
		ntrack tr=new ntrack(t,day,num);
		
		double total=c.cal()+h.cal()+e.cal()+b.cal()+tr.cal();
		if(total>10000)
			total=total*0.9;
		else if(total>1000)
			total=total*0.95;
		
		System.out.println("������:"+total);
	}

}
