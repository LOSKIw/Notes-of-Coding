package javaHomework;

class Emploee{
	int num;
	String name;
	Emploee(int n,String na){
		num=n;
		name=na;
	}
	Emploee(){};
	void print() {
		System.out.println("Ա����Ϣ:");
		System.out.println("����:"+name);
		System.out.println("Ա����:"+num);
	}
}

class Manager extends Emploee{
	String department;
	Manager(int n,String na,String de){
		super(n,na);
		department=de;
	}
	void print() {
		System.out.println("Ա����Ϣ:");
		System.out.println("����:"+name);
		System.out.println("Ա����:"+num);
		System.out.println("���ܲ���:"+department);
	}
}

public class Homework090401 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Emploee Xia=new Emploee(10001,"���ͺ�");
		Xia.print();
		Manager Wu=new Manager(10002,"��Ͱ��","����");
		Wu.print();

	}

}
