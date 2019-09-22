package javaHomework;
import java.util.*;

interface Nshape{
	double getArea();
	double getLen();
}

class ncircle implements Nshape{
	int r;
	ncircle(int l){
		r=l;
	}
	ncircle(){}
	public double getArea() {
		return r*3.14*r;
	}
	public double getLen() {
		return 3.14*2*r;
	}
}

class nrectangle implements Nshape{
	int len,wid;
	nrectangle(int l,int w){
		len=l;
		wid=w;
	}
	nrectangle(){}
	public double getArea() {
		return len*wid;
	}
	public double getLen() {
		return 2*(len+wid);
	}
}

class newsquare extends nrectangle{
	newsquare(int l){
		len=l;
		wid=l;
	}
}

public class Homework091202 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner sc=new Scanner(System.in);
		int l,w;
		String a=new String();
		System.out.println("��Ҫ����ʲôͼ��?");
		a=sc.nextLine();
		if(a.equals("Circle")==true) {
			System.out.println("������뾶");
			l=sc.nextInt();
			ncircle nS=new ncircle(l);
			System.out.println("���Ϊ"+nS.getArea()+"���ܳ�Ϊ"+nS.getLen());
		}
		else if(a.equals("Square")==true) {
			System.out.println("������߳�");
			l=sc.nextInt();
			newsquare nS=new newsquare(l);
			System.out.println("���Ϊ"+nS.getArea()+"���ܳ�Ϊ"+nS.getLen());
		}
		else if(a.equals("Rectangle")==true) {
			System.out.println("�����볤");
			l=sc.nextInt();
			System.out.println("�������");
			w=sc.nextInt();
			nrectangle nS=new nrectangle(l,w);
			System.out.println("���Ϊ"+nS.getArea()+"���ܳ�Ϊ"+nS.getLen());
		}
	}

}
