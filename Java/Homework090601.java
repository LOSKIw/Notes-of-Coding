package javaHomework;
import java.util.*;

class CAR{
	int cost;
	int num,day;
	CAR(int n,int d){
		day=d;
		num=n;
	}
	CAR(){}
	int cal() {
		return num*cost*day;
	}
}

class CRV extends CAR{
	int cost=600;
	CRV(int n,int d){
		super(n,d);
	}
}

class Escape extends CAR{
	int cost=500;
	Escape(int n,int d){
		super(n,d);
	}
}

class HRV extends CAR{
	int cost=400;
	HRV(int n,int d){
		super(n,d);
	}
}

class bus{
	int cost1=600,cost2=1000;
	int num1,num2;
	int day1,day2;
	bus(int n1,int n2,int d1,int d2)
	{
		num1=n1;num2=n2;day1=d1;day2=d2;
	}
	bus(){}
	int cal() {
		return num1*day1*cost1+num2*day2*cost2;
	}
}

class track{
	int T,day,num,cost=50;
	track(int t,int d,int n){
		T=t;day=d;num=n;
	}
	track(){}
	int cal() {
		return T*day*num*cost;
	}
}

public class Homework090601 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner sc=new Scanner(System.in);int day,num,t,num1,day1;
		System.out.println("��������ҪCRV������:");
		num=sc.nextInt();
		System.out.println("��������ҪCRV������:");
		day=sc.nextInt();
		CRV c=new CRV(num,day);
		
		System.out.println("��������ҪEscape������:");
		num=sc.nextInt();
		System.out.println("��������ҪEscape������:");
		day=sc.nextInt();
		Escape e=new Escape(num,day);
		
		System.out.println("��������ҪHRV������:");
		num=sc.nextInt();
		System.out.println("��������ҪHRV������:");
		day=sc.nextInt();
		HRV h=new HRV(num,day);
		
		System.out.println("��������ҪС�ͳ�������:");
		num=sc.nextInt();
		System.out.println("��������ҪС�ͳ�������:");
		day=sc.nextInt();
		System.out.println("��������Ҫ��ͳ�������:");
		num1=sc.nextInt();
		System.out.println("��������Ҫ��ͳ�������:");
		day1=sc.nextInt();
		bus b=new bus(num,num1,day,day1);
		
		System.out.println("��������Ҫ����������:");
		num=sc.nextInt();
		System.out.println("��������Ҫ����������:");
		day=sc.nextInt();
		System.out.println("��������Ҫ�����Ķ���:");
		t=sc.nextInt();
		track tr=new track(t,day,num);
		
		double total=c.cal()+h.cal()+e.cal()+b.cal()+tr.cal();
		if(total>10000)
			total=total*0.9;
		else if(total>1000)
			total=total*0.95;
		
		System.out.println("������:"+total);
	}

}

