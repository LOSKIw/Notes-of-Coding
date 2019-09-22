package javaHomework;
import java.util.*;

abstract class shape{
	int len,wid;
	String shape;
	shape(int l,int w){
		len=l;
		wid=w;
	}
	shape(){}
	abstract double getArea();
	abstract double getLen();
}

class Circle extends shape{
	Circle(int r){
		len=r;
	}
	double getArea() {
		return 3.14*len*len;
	}
	double getLen() {
		return 2*3.14*len;
	}
}

class nSquare extends shape{
	nSquare(int l){
		len=l;
	}
	double getArea() {
		return len*len;
	}
	double getLen() {
		return 4*len;
	}
}

class Rectangle extends shape{
	Rectangle(int l,int w){
		len=l;
		wid=w;
	}
	double getArea() {
		return len*wid;
	}
	double getLen() {
		return 2*(len+wid);
	}
}

public class Homework091201 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner sc=new Scanner(System.in);
		int l,w;
		String a=new String();
		System.out.println("��Ҫ����ʲôͼ��?");
		a=sc.nextLine();
		if(a.equals("Circle")==true) {
			System.out.println("����뾶");
			l=sc.nextInt();
			Circle newShape=new Circle(l);
			System.out.println("���Ϊ"+newShape.getArea()+"���ܳ�Ϊ"+newShape.getLen());
		}
		else if(a.equals("Square")==true) {
			System.out.println("����߳�");
			l=sc.nextInt();
			nSquare newShape=new nSquare(l);
			System.out.println("���Ϊ"+newShape.getArea()+"���ܳ�Ϊ"+newShape.getLen());
		}
		else if(a.equals("Rectangle")==true) {
			System.out.println("���볤");
			l=sc.nextInt();
			System.out.println("�����");
			w=sc.nextInt();
			Rectangle newShape=new Rectangle(l,w);
			System.out.println("���Ϊ"+newShape.getArea()+"���ܳ�Ϊ"+newShape.getLen());
			
		}
		
	}

}
